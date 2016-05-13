#ifndef SERPENTINEAPP_H
#define SERPENTINEAPP_H

#include "MooseApp.h"

class SerpentineApp;

template<>
InputParameters validParams<SerpentineApp>();

class SerpentineApp : public MooseApp
{
public:
  SerpentineApp(InputParameters parameters);
  virtual ~SerpentineApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* SERPENTINEAPP_H */
