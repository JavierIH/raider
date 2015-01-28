/*#include "fl/Headers.h"

//check laundry example

int main(){
    using namespace fl;
    Engine* engine = new Engine("navigation");

    InputVariable* position = new InputVariable;
    position->setName("distance");
    position->setRange(0.000, 1.000);
    position->addTerm(new Triangle("izquierda", 0.000, 0.500));
    position->addTerm(new Triangle("centro", 0.250, 0.750));
    position->addTerm(new Triangle("derecha", 0.500, 1.000));
    engine->addInputVariable(position);

    InputVariable* alfa = new InputVariable;
    alfa->setName("alfa");
    alfa->setRange(0.000, 1.000);
    alfa->addTerm(new Triangle("negativo", 0.000, 0.500));
    alfa->addTerm(new Triangle("cero", 0.250, 0.750));
    alfa->addTerm(new Triangle("positivo", 0.500, 1.000));
    engine->addInputVariable(alfa);

    OutputVariable* correccion = new OutputVariable;
    correccion->setName("correccion");
    correccion->setRange(-45.000, 45.000);
    correccion->setDefaultValue(fl::nan);
    correccion->addTerm(new Triangle("II", -45.000, -9.000));
    correccion->addTerm(new Triangle("I", -27.000, -9.000));
    correccion->addTerm(new Triangle("C", -9.000, 9.000));
    correccion->addTerm(new Triangle("D", 9.000, 27.000));
    correccion->addTerm(new Triangle("DD", 27.000, 45.000));
    engine->addOutputVariable(correccion);

    RuleBlock* ruleblock = new RuleBlock;
    ruleblock->addRule(Rule::parse("if alfa is negativo then correccion is II", engine));
    engine->addRuleBlock(ruleblock);

    engine->configure("", "", "Minimum", "Maximum", "centroid");

    std::string status;
    if (not engine->isReady(&status))
        throw Exception("Engine not ready. "
            "The following errors were encountered:\n" + status, FL_AT);

    for (int i = 0; i < 50; ++i){
        scalar light = alfa->getMinimum() + i * (alfa->range() / 50);
        alfa->setInputValue(light);
        engine->process();
        FL_LOG("Ambient.input = " << Op::str(light) << " -> " <<
            "Power.output = " << Op::str(correccion->getOutputValue()));
    }
}*/



#include <fl/Headers.h>
#include "../libraries/debug/debug.h"

#include <unistd.h>
#include <iostream>

int main(){
    using namespace fl;

    Engine* engine = new Engine;
    engine->setName("fuzzy");

    InputVariable* position = new InputVariable;
    position->setEnabled(true);
    position->setName("position");
    position->setRange(0.000, 10.000);
    position->addTerm(new Triangle("left", 0.000, 5));
    position->addTerm(new Triangle("center", 2.5, 7.5));
    position->addTerm(new Triangle("right", 5, 10));
    engine->addInputVariable(position);

    InputVariable* alfa = new InputVariable;
    alfa->setEnabled(true);
    alfa->setName("alfa");
    position->setRange(0.000, 10.000);
    alfa->addTerm(new Triangle("negative", 0.000, 5));
    alfa->addTerm(new Triangle("neutral", 2.5, 7.5));
    alfa->addTerm(new Triangle("positive", 5, 10));
    engine->addInputVariable(alfa);

    InputVariable* ir_right = new InputVariable;
    ir_right->setEnabled(true);
    ir_right->setName("ir_right");
    position->setRange(0.000, 10.000);
    ir_right->addTerm(new Triangle("close", 0.000, 5));
    ir_right->addTerm(new Triangle("medium", 2.5, 7.5));
    ir_right->addTerm(new Triangle("far", 5, 10));
    engine->addInputVariable(ir_right);

    InputVariable* ir_left = new InputVariable;
    ir_left->setEnabled(true);
    ir_left->setName("ir_left");
    position->setRange(0.000, 10.000);
    ir_left->addTerm(new Triangle("close", 0.000, 5));
    ir_left->addTerm(new Triangle("medium", 2.5, 7.5));
    ir_left->addTerm(new Triangle("far", 5, 10));
    engine->addInputVariable(ir_left);

    OutputVariable* advance = new OutputVariable;
    advance->setEnabled(true);
    advance->setName("advance");
    advance->setRange(0.000, 10.000);
    advance->fuzzyOutput()->setAccumulation(new Maximum);
    advance->setDefuzzifier(new Centroid);
    advance->setDefaultValue(fl::nan);
    advance->addTerm(new Triangle("null", 0.000, 5));
    advance->addTerm(new Triangle("short", 2.5, 7.5));
    advance->addTerm(new Triangle("long", 5, 10));
    engine->addOutputVariable(advance);

    OutputVariable* rotation = new OutputVariable;
    rotation->setEnabled(true);
    rotation->setName("rotation");
    rotation->setRange(0.000, 10.000);
    rotation->fuzzyOutput()->setAccumulation(new Maximum); //aggregation
    rotation->setDefuzzifier(new Centroid);
    rotation->addTerm(new Triangle("left", 0.000, 5));
    rotation->addTerm(new Triangle("center", 2.5, 7.5));
    rotation->addTerm(new Triangle("right", 5, 10));
    engine->addOutputVariable(rotation);

    RuleBlock* ruleBlock = new RuleBlock;
    ruleBlock->setEnabled(true);
    ruleBlock->setName("navigation");
    ruleBlock->setConjunction(new Minimum); //correcto
    ruleBlock->setDisjunction(new Maximum);
    ruleBlock->setActivation(new Minimum);

    ruleBlock->addRule(fl::Rule::parse("if position is left and alfa is negative then advance is null and rotation is left", engine));
    ruleBlock->addRule(fl::Rule::parse("if position is left and alfa is neutral then advance is short and rotation is left", engine));
    ruleBlock->addRule(fl::Rule::parse("if position is left and alfa is positive then advance is long and rotation is center", engine));

    ruleBlock->addRule(fl::Rule::parse("if position is center and alfa is negative then advance is short and rotation is left", engine));
    ruleBlock->addRule(fl::Rule::parse("if position is center and alfa is neutral then advance is long and rotation is center", engine));
    ruleBlock->addRule(fl::Rule::parse("if position is center and alfa is positive then advance is short and rotation is right", engine));

    ruleBlock->addRule(fl::Rule::parse("if position is right and alfa is negative then advance is long and rotation is right", engine));
    ruleBlock->addRule(fl::Rule::parse("if position is right and alfa is negative then advance is long and rotation is center", engine));
    ruleBlock->addRule(fl::Rule::parse("if position is right and alfa is neutral then advance is short and rotation is right", engine));
    ruleBlock->addRule(fl::Rule::parse("if position is right and alfa is positive then advance is null and rotation is right", engine));

    ruleBlock->addRule(fl::Rule::parse("if ir_left is close then advance is null", engine));
    ruleBlock->addRule(fl::Rule::parse("if ir_left is medium then advance is short", engine));

    ruleBlock->addRule(fl::Rule::parse("if ir_right is close then advance is null", engine));
    ruleBlock->addRule(fl::Rule::parse("if ir_right is medium then advance is short", engine));

    ruleBlock->activate();
    engine->addRuleBlock(ruleBlock);




    for (float i = 0; i < 10; i+=0.01){
        //scalar input1 = position->getMinimum() + i * (position->range() / 50);
        position->setInputValue(5);

        //scalar input2 = alfa->getMaximum() - i * (alfa->range() / 50);
        alfa->setInputValue(5);
        ir_left->setInputValue(0.1);
        ir_right->setInputValue(0.1);

        engine->process();

        report("\n\n\n\n\n\n\n\n");
        report(INFO,"Input 1: "+to_string(position->getInputValue()));
        report(INFO,"Input 2: "+to_string(alfa->getInputValue()));
        report(OK,"avance: "+to_string(advance->getOutputValue()));
        report(OK,"giro: "+to_string(rotation->getOutputValue()));

        usleep(100000/2);

    }

}

