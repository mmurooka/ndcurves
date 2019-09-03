/**
* \file bezier_curve.h
* \brief class allowing to create a Bezier curve of dimension 1 <= n <= 3.
* \author Steve T.
* \version 0.1
* \date 06/17/2013
*/

#ifndef _BEZIER_POLY_CONVERSION
#define _BEZIER_POLY_CONVERSION

#include "curve_abc.h"
#include "bernstein.h"
#include "curve_constraint.h"

#include "MathDefs.h"

#include <vector>
#include <stdexcept>

#include <iostream>

namespace curves
{

/// \brief Converts a Bezier curve to a polynomial.
/// \param bezier   : the Bezier curve to convert.
/// \return the equivalent polynomial.
template<typename Bezier, typename Polynomial>
Polynomial from_bezier(const Bezier& curve)
{
    typedef typename Polynomial::t_point_t    t_point_t;
    typedef typename Polynomial::num_t    num_t;
    t_point_t coefficients;
    Bezier current (curve);
    coefficients.push_back(curve(0.));
    num_t fact = 1;
    for(std::size_t i = 1; i<= curve.degree_; ++i)
    {
        current = current.compute_derivate(1);
        fact *= (num_t)i;
        coefficients.push_back(current(0.)/fact);
    }
    return Polynomial(coefficients,curve.min(),curve.max());
}

/*
/// \brief Converts a polynomial to a Bezier curve.
/// \param polynomial : the polynomial to convert.
/// \return the equivalent Bezier curve.
template<typename Bezier, typename Polynomial>
Bezier from_polynomial(const Polynomial& polynomial)
{
    typedef Bezier::point_t 	point_t;
    typedef Bezier::time_t 	time_t;
    typedef Bezier::num_t	num_t;
    typedef Bezier::curve_constraints_t    curve_constraints_t;
    typedef Bezier::t_point_t    t_point_t;
    typedef Bezier::cit_point_t    cit_point_t;
    typedef Bezier::bezier_curve_t   bezier_curve_t;
}
*/
} // namespace curves
#endif //_BEZIER_POLY_CONVERSION
