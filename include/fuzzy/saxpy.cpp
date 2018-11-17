#include "saxpy.h"

namespace fuzzy {
template<
    typename DerivedA,
    typename DerivedX,
    typename DerivedY>
void saxpy(
    const Eigen::MatrixBase<DerivedA> &a,
    const Eigen::MatrixBase<DerivedX> &x,
    const Eigen::MatrixBase<DerivedY> &y,
    DerivedY &result) {
  ///Add some asserts for things you expect to be true
  ///Eases debugging considerably!
  ///Using "and "some message" prints the message when the assert is triggered
  assert(a.cols() == x.cols() and a.rows() == x.rows() and
      "Dimensions of a and x do not match");
  assert(y.cols() == x.cols() and y.rows() == x.rows() and
      "Dimensions of a and y do not match");

  result = a.cwiseProduct(x) + y;
}
}