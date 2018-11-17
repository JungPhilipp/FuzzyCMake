#include <fuzzy/saxpy.h>

#include <Eigen/Dense>

#include <vector>

#include <easyloggingpp/easylogging++.h>
INITIALIZE_EASYLOGGINGPP

void initLogging();

constexpr int D = 2000;
constexpr double y_value = 5;
constexpr long runs = 100;

void run(std::vector<Eigen::MatrixXd> &c) {
  for (long i = 0; i < runs; ++i) {
    Eigen::MatrixXd a = Eigen::MatrixXd::Random(D, D);
    Eigen::MatrixXd x = Eigen::MatrixXd::Random(D, D);
    Eigen::MatrixXd y = Eigen::MatrixXd::Constant(D, D, y_value);
    fuzzy::saxpy(a, x, y, c[i]);
  }
}

int main() {
  initLogging();

  {
    TIMED_SCOPE(_timer, "Saxpy Without OpenMP");

    std::vector<Eigen::MatrixXd> save(runs);
    run(save);
    for (auto &a :save) {
      std::cout << a.size();
    }
    std::cout << std::endl;
  }

  return 0;
}

void initLogging() {
  el::Configurations defaultConf;
  defaultConf.setToDefault();
  defaultConf.setGlobally(el::ConfigurationType::Format, "%level (%datetime{%H:%m:%s}) [%fbase:%line] %msg");
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
}

