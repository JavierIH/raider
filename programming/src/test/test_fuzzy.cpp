#include "fl/Headers.h"

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
}
