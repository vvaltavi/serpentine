#include "SerpentineApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<SerpentineApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

SerpentineApp::SerpentineApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  SerpentineApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  SerpentineApp::associateSyntax(_syntax, _action_factory);
}

SerpentineApp::~SerpentineApp()
{
}

// External entry point for dynamic application loading
extern "C" void SerpentineApp__registerApps() { SerpentineApp::registerApps(); }
void
SerpentineApp::registerApps()
{
  registerApp(SerpentineApp);
}

// External entry point for dynamic object registration
extern "C" void SerpentineApp__registerObjects(Factory & factory) { SerpentineApp::registerObjects(factory); }
void
SerpentineApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void SerpentineApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { SerpentineApp::associateSyntax(syntax, action_factory); }
void
SerpentineApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
