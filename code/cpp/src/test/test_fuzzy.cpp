#include <fl/Headers.h>
#include "../libraries/debug/debug.h"

#include <unistd.h>
#include <iostream>

using namespace fl;


int main(){

    Engine* engine = new Engine;
    engine->setName("fuzzy");

    InputVariable* position = new InputVariable;
    position->setEnabled(true);
    position->setName("position");
    position->setRange(-20.000, 20.000);
    position->addTerm(new Ramp("left",-2.000,-12.000));
    position->addTerm(new Triangle("center", -6.000, 0.000, 6.000));
    position->addTerm(new Ramp("right", 2.000, 12.000));
    engine->addInputVariable(position);

    InputVariable* alfa = new InputVariable;
    alfa->setEnabled(true);
    alfa->setName("alfa");
    alfa->setRange(-90.000, 90.000);
    alfa->addTerm(new ZShape("negative", -54.000, -9.000));
    alfa->addTerm(new Gaussian("zero", 0.000, 13.500));
    alfa->addTerm(new SShape("positive", 9.000, 54.000));
    engine->addInputVariable(alfa);

    InputVariable* ir_right = new InputVariable;
    ir_right->setEnabled(true);
    ir_right->setName("ir_right");
    ir_right->setRange(0.000, 1800.000);
    ir_right->addTerm(new Gaussian("close", 1647.000, 77.400));
    ir_right->addTerm(new Gaussian("medium", 1350.000, 153.000));
    ir_right->addTerm(new Gaussian("far", 747.000, 300.600));
    engine->addInputVariable(ir_right);

    InputVariable* ir_left = new InputVariable;
    ir_left->setEnabled(true);
    ir_left->setName("ir_left");
    ir_left->setRange(0.000, 1800.000);
    ir_left->addTerm(new Gaussian("close", 1647.000, 77.400));
    ir_left->addTerm(new Gaussian("medium", 1350.000, 153.000));
    ir_left->addTerm(new Gaussian("far", 747.000, 300.600));
    engine->addInputVariable(ir_left);

    OutputVariable* advance = new OutputVariable;
    advance->setEnabled(true);
    advance->setName("advance");
    advance->setRange(0.000, 700.000);
    advance->fuzzyOutput()->setAccumulation(new Maximum);
    advance->setDefuzzifier(new SmallestOfMaximum);
    advance->setDefaultValue(fl::nan);
    advance->addTerm(new Ramp("null", 120.000, 100.000));
    advance->addTerm(new Triangle("short", 100.000, 300.000, 500.000));
    advance->addTerm(new Ramp("long", 300.000, 500.000));
    engine->addOutputVariable(advance);

    OutputVariable* rotation = new OutputVariable;
    rotation->setEnabled(true);
    rotation->setName("rotation");
    rotation->setRange(-90.000, 90.000);
    rotation->fuzzyOutput()->setAccumulation(new Maximum); //aggregation
    rotation->setDefuzzifier(new Centroid);
    rotation->addTerm(new Ramp("left", 0.000, -40.000));
    rotation->addTerm(new Triangle("center", -25.000, 0.000, 25.000));
    rotation->addTerm(new Ramp("right", 0.000, 40.000));
    engine->addOutputVariable(rotation);

    RuleBlock* ruleBlock = new RuleBlock;
    ruleBlock->setEnabled(true);
    ruleBlock->setName("navigation");
    ruleBlock->setConjunction(new Minimum); //correcto
    ruleBlock->setDisjunction(new Maximum);
    ruleBlock->setActivation(new Minimum);

    ruleBlock->addRule(fl::Rule::parse("if position is left and alfa is negative then advance is null and rotation is left", engine));
    ruleBlock->addRule(fl::Rule::parse("if position is left and alfa is zero then advance is short and rotation is left", engine));
    ruleBlock->addRule(fl::Rule::parse("if position is left and alfa is positive then advance is long and rotation is center", engine));

    ruleBlock->addRule(fl::Rule::parse("if position is center and alfa is negative then advance is short and rotation is left", engine));
    ruleBlock->addRule(fl::Rule::parse("if position is center and alfa is zero then advance is long and rotation is center", engine));
    ruleBlock->addRule(fl::Rule::parse("if position is center and alfa is positive then advance is short and rotation is right", engine));

    ruleBlock->addRule(fl::Rule::parse("if position is right and alfa is negative then advance is long and rotation is center", engine));
    ruleBlock->addRule(fl::Rule::parse("if position is right and alfa is zero then advance is short and rotation is right", engine));
    ruleBlock->addRule(fl::Rule::parse("if position is right and alfa is positive then advance is null and rotation is right", engine));

    ruleBlock->addRule(fl::Rule::parse("if ir_left is close then advance is null", engine));
    ruleBlock->addRule(fl::Rule::parse("if ir_left is medium then advance is short", engine));

    ruleBlock->addRule(fl::Rule::parse("if ir_right is close then advance is null", engine));
    ruleBlock->addRule(fl::Rule::parse("if ir_right is medium then advance is short", engine));

    ruleBlock->addRule(fl::Rule::parse("if ir_right is close and ir_left is far then rotation is left", engine));
    ruleBlock->addRule(fl::Rule::parse("if ir_right is far and ir_left is close then rotation is right", engine));

    ruleBlock->activate();
    engine->addRuleBlock(ruleBlock);



    //TEST DE FUZZYONAMIENTO

    position->setInputValue(0);
    alfa->setInputValue(0);
    ir_left->setInputValue(300);
    ir_right->setInputValue(1200);

    engine->process();

    int advance_out=advance->getOutputValue();
    int rotation_out=rotation->getOutputValue();


    report("\n\n\n\n\n\n\n\n");
    report(INFO,"position: "+to_string(position->getInputValue()));
    report(INFO,"alfa: "+to_string(alfa->getInputValue()));
    report(INFO,"IR left: "+to_string(ir_left->getInputValue()));
    report(INFO,"IR right: "+to_string(ir_right->getInputValue()));

    report(OK,"avance: "+to_string(advance_out));
    report(OK,"giro: "+to_string(rotation_out));


}

