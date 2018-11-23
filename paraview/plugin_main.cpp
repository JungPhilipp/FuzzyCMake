#include <easyloggingpp/easylogging++.h>
INITIALIZE_EASYLOGGINGPP

#define TO_STR2(x) #x
#define TO_STR(x) TO_STR2(x)



#ifdef FUZZY_ENABLE_OPENMP
# include <omp.h>
#endif
#include <Eigen/Dense>

namespace
{
class dynamic_library_load_unload_handler {
 public:
  // called when library is loaded
  dynamic_library_load_unload_handler(){
    el::Configurations defaultConf;
    defaultConf.setToDefault();
    defaultConf.setGlobally(el::ConfigurationType::Format, TO_STR(FUZZY_CURRENT_PLUGIN_NAME) "::%level (%datetime{%H:%m:%s}) [%fbase:%line] %msg");
    defaultConf.setGlobally(el::ConfigurationType::Enabled, "true");
    defaultConf.setGlobally(el::ConfigurationType::ToFile, "false");
    defaultConf.setGlobally(el::ConfigurationType::ToStandardOutput, "true");
    defaultConf.setGlobally(el::ConfigurationType::PerformanceTracking, "true");
    defaultConf.setGlobally(el::ConfigurationType::SubsecondPrecision, "6");
    el::Loggers::reconfigureLogger("default", defaultConf);
    el::Loggers::reconfigureAllLoggers(defaultConf);
    el::Loggers::setVerboseLevel(9);
    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
    el::Loggers::addFlag(el::LoggingFlag::DisableApplicationAbortOnFatalLog);
    LOG(INFO) << "Plugin loaded.";
#   ifdef FUZZY_ENABLE_OPENMP
      VLOG(1) << "OpenMP Threads: " << omp_get_max_threads();
#   else
      VLOG(1) << "OpenMP: disabled";
#   endif
    VLOG(1) << "Eigen: " << EIGEN_WORLD_VERSION << "." << EIGEN_MAJOR_VERSION << "." << EIGEN_MINOR_VERSION
            << " " << Eigen::SimdInstructionSetsInUse();
  }
  // called when library is unloaded
  ~dynamic_library_load_unload_handler(){
    LOG(INFO) << "Plugin unloaded.";
  }
} dynamic_library_load_unload_handler_hook;
}

