/**
 * @brief To avoid name clashes use the /path/to/file within the include guards
 */
#ifndef LIBFUZZY_SAXPY_H_
#define LIBFUZZY_SAXPY_H_

#include <Eigen/Dense>

/**
 * @brief Always use namespaces to separate your code
 */
namespace fuzzy {

/**
 * @brief Compute cwise a * x + y
 * @param a         coeff matrix
 * @param x         x matrix with same dimensions as a and y
 * @param y         coeff matrix
 * @param result    a*x+y
 */
template<
    typename DerivedA,
    typename DerivedX,
    typename DerivedY>
void saxpy(
    const Eigen::MatrixBase<DerivedA> &a,
    const Eigen::MatrixBase<DerivedX> &x,
    const Eigen::MatrixBase<DerivedY> &y,
    DerivedY &result);

}

#include "saxpy.cpp"

#endif //LIBFUZZY_SAXPY_H_
