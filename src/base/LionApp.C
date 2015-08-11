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

LionApp::LionApp(InputParameters parameters) :
    MooseApp(parameters)
{

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
