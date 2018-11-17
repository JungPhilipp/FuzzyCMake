#define CATCH_CONFIG_RUNNER
#include <catch/catch.hpp>

#include <easyloggingpp/easylogging++.h>
INITIALIZE_EASYLOGGINGPP

int main( int argc, char* argv[] )
{
  el::Configurations defaultConf;
  defaultConf.setToDefault();
  defaultConf.setGlobally(el::ConfigurationType::Format, "%levshort [%fbase:%line] %msg");
  defaultConf.setGlobally(el::ConfigurationType::Enabled, "true");
  defaultConf.setGlobally(el::ConfigurationType::ToFile, "false");
  defaultConf.setGlobally(el::ConfigurationType::Filename, "logs/out.log");
  defaultConf.setGlobally(el::ConfigurationType::ToStandardOutput, "true");
  defaultConf.setGlobally(el::ConfigurationType::PerformanceTracking, "true");
  defaultConf.setGlobally(el::ConfigurationType::SubsecondPrecision, "6");
  el::Loggers::reconfigureLogger("default", defaultConf);
  el::Loggers::reconfigureAllLoggers(defaultConf);
  el::Loggers::setVerboseLevel(9);
  el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
  el::Loggers::addFlag(el::LoggingFlag::DisableApplicationAbortOnFatalLog);

  int result = Catch::Session().run( argc, argv );
  return ( result < 0xff ? result : 0xff );
}
