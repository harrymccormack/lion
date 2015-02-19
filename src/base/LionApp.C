#include "LionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<LionApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

LionApp::LionApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  LionApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  LionApp::associateSyntax(_syntax, _action_factory);
}

LionApp::~LionApp()
{
}

extern "C" void LionApp__registerApps() { LionApp::registerApps(); }
void
LionApp::registerApps()
{
  registerApp(LionApp);
}

void
LionApp::registerObjects(Factory & factory)
{
}

void
LionApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
