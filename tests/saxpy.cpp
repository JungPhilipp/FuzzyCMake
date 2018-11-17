#include <catch/catch.hpp>
#include <easyloggingpp/easylogging++.h>

#include <Eigen/Dense>

#include <fuzzy/saxpy.h>

TEST_CASE("Saxpy Unit Test") {

  Eigen::MatrixXd a = Eigen::MatrixXd::Constant(3, 3, 3);
  Eigen::MatrixXd x = Eigen::MatrixXd::Random(3, 3);
  Eigen::MatrixXd y = Eigen::MatrixXd::Constant(3, 3, 2);
  Eigen::MatrixXd result(3, 3);

  fuzzy::saxpy(a, x, y, result);

  CHECK(result(0, 0) == x(0, 0) * 3 + 2);
  REQUIRE(result(1, 1) == x(1, 1) * 3 + 2);

  LOG(INFO) << result;
}