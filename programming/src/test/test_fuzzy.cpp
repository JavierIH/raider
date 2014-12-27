/*#include "fl/Headers.h"

//check laundry example

int main(){
    using namespace fl;
    Engine* engine = new Engine("navigation");

    InputVariable* posicion = new InputVariable;
    posicion->setName("distance");
    posicion->setRange(0.000, 1.000);
    posicion->addTerm(new Triangle("IZQUIERDA", 0.000, 0.500));
    posicion->addTerm(new Triangle("CENTRO", 0.250, 0.750));
    posicion->addTerm(new Triangle("DERECHA", 0.500, 1.000));
    engine->addInputVariable(posicion);

    InputVariable* alfa = new InputVariable;
    alfa->setName("alfa");
    alfa->setRange(0.000, 1.000);
    alfa->addTerm(new Triangle("NEGATIVO", 0.000, 0.500));
    alfa->addTerm(new Triangle("CERO", 0.250, 0.750));
    alfa->addTerm(new Triangle("POSITIVO", 0.500, 1.000));
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
    ruleblock->addRule(Rule::parse("if alfa is NEGATIVO then correccion is II", engine));
    engine->addRuleBlock(ruleblock);

    engine->configure("", "", "Minimum", "Maximum", "Centroid");

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
    engine->setName("Laundry");

    InputVariable* inputVariable1 = new InputVariable;
    inputVariable1->setEnabled(true);
    inputVariable1->setName("Load");
    inputVariable1->setRange(0.000, 6.000);
    inputVariable1->addTerm(Discrete::create("small", 8, 0.000, 1.000, 1.000, 1.000, 2.000, 0.800, 5.000, 0.000));
    inputVariable1->addTerm(Discrete::create("normal", 6, 3.000, 0.000, 4.000, 1.000, 6.000, 0.000));
    engine->addInputVariable(inputVariable1);

    InputVariable* inputVariable2 = new InputVariable;
    inputVariable2->setEnabled(true);
    inputVariable2->setName("Dirt");
    inputVariable2->setRange(0.000, 6.000);
    inputVariable2->addTerm(Discrete::create("low", 6, 0.000, 1.000, 2.000, 0.800, 5.000, 0.000));
    inputVariable2->addTerm(Discrete::create("high", 8, 1.000, 0.000, 2.000, 0.200, 4.000, 0.800, 6.000, 1.000));
    engine->addInputVariable(inputVariable2);

    OutputVariable* outputVariable1 = new OutputVariable;
    outputVariable1->setEnabled(true);
    outputVariable1->setName("Detergent");
    outputVariable1->setRange(0.000, 80.000);
    outputVariable1->fuzzyOutput()->setAccumulation(new Maximum);
    outputVariable1->setDefuzzifier(new Centroid);
    outputVariable1->setDefaultValue(fl::nan);
    outputVariable1->setLockPreviousOutputValue(false);
    outputVariable1->setLockOutputValueInRange(false);
    outputVariable1->addTerm(Discrete::create("less", 6, 10.000, 0.000, 40.000, 1.000, 50.000, 0.000));
    outputVariable1->addTerm(new Triangle("normal", 0.250, 0.750));
    outputVariable1->addTerm(Discrete::create("more", 4, 50.000, 0.000, 80.000, 1.000));
    engine->addOutputVariable(outputVariable1);

    OutputVariable* outputVariable2 = new OutputVariable;
    outputVariable2->setEnabled(true);
    outputVariable2->setName("Cycle");
    outputVariable2->setRange(0.000, 20.000);
    outputVariable2->fuzzyOutput()->setAccumulation(new Maximum); //aggregation
    //outputVariable2->setDefuzzifier(new MeanOfMaximum(500));
    outputVariable2->setDefuzzifier(new Centroid);
    //outputVariable2->setDefaultValue(fl::nan);
    //outputVariable2->setLockPreviousOutputValue(false);
    //outputVariable2->setLockOutputValueInRange(false);
    outputVariable2->addTerm(Discrete::create("short", 6, 0.000, 1.000, 10.000, 1.000, 20.000, 0.000));
    outputVariable2->addTerm(Discrete::create("long", 4, 10.000, 0.000, 20.000, 1.000));
    engine->addOutputVariable(outputVariable2);

    RuleBlock* ruleBlock = new RuleBlock;
    ruleBlock->setEnabled(true);
    ruleBlock->setName("");
    ruleBlock->setConjunction(new Minimum); //correcto
    ruleBlock->setDisjunction(new Maximum);
    ruleBlock->setActivation(new Minimum);
    ruleBlock->addRule(fl::Rule::parse("if Load is small and Dirt is not high then Detergent is less", engine));
    ruleBlock->addRule(fl::Rule::parse("if Load is small and Dirt is high then  Detergent is normal", engine));
    //ruleBlock->addRule(fl::Rule::parse("if Load is normal and Dirt is low then Detergent is less", engine));
    ruleBlock->addRule(fl::Rule::parse("if Load is normal and Dirt is high then Detergent is more", engine));
    ruleBlock->addRule(fl::Rule::parse("if Detergent is normal or Detergent is less then Cycle is short", engine));
    ruleBlock->addRule(fl::Rule::parse("if Detergent is more then Cycle is long", engine));
    ruleBlock->activate();
    engine->addRuleBlock(ruleBlock);


    for (int i = 0; i < 50; ++i){
        scalar input1 = inputVariable1->getMinimum() + i * (inputVariable1->range() / 50);
        inputVariable1->setInputValue(2.456);

        scalar input2 = inputVariable2->getMaximum() - i * (inputVariable2->range() / 50);
        inputVariable2->setInputValue(input2);

        engine->process();

        report("\n\n\n\n\n\n\n\n");
        report(INFO,"Input 1: "+to_string(inputVariable1->getInputValue()));
        report(INFO,"Input 2: "+to_string(inputVariable2->getInputValue()));
        report(OK,"Output 1: "+to_string(outputVariable1->getOutputValue()));
        report(OK,"Output 2: "+to_string(outputVariable2->getOutputValue()));

        usleep(1000000/2);

    }

}

