///\file

/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/ETLCPP/etl
https://www.etlcpp.com

Copyright(c) 2018 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef ETL_STL_ALTERNATE_LIMITS_INCLUDED
#define ETL_STL_ALTERNATE_LIMITS_INCLUDED

#include "../../platform.h"
#include "../../type_traits.h"
#include "../../char_traits.h"
#include "../../integral_limits.h"

#include <limits.h>
#include <stdint.h>
#include <float.h>

#define ETL_LOG2(x) (((x) * 301) / 1000)

#if defined(ETL_IN_UNIT_TEST)
  #if !defined(ETLSTD)
    #define ETLSTD etlstd
  #endif
  namespace etlstd
#else
  #if !defined(ETLSTD)
    #define ETLSTD std
  #endif
  namespace std
#endif
{
  template<class T> class numeric_limits;

  enum float_round_style
  {
    round_indeterminate       = -1,
    round_toward_zero         = 0,
    round_to_nearest          = 1,
    round_toward_infinity     = 2,
    round_toward_neg_infinity = 3,
  };

  enum float_denorm_style
  {
    denorm_indeterminate = -1,
    denorm_absent        = 0,
    denorm_present       = 1
  };

  //***************************************************************************
  // Base for integral types.
  template <typename T>
  class etl_integral_type
  {
  public:
    static const bool is_specialized;

    static const int max_digits10;

    static const bool is_integer;
    static const bool is_exact;

    static const int radix;
    static ETL_CONSTEXPR T epsilon() { return 0; }
    static ETL_CONSTEXPR T round_error() { return 0; }

    static const int digits;
    static const int digits10;

    static const bool is_signed;

    static const int min_exponent;
    static const int min_exponent10;
    static const int max_exponent;
    static const int max_exponent10;

    static const bool has_infinity;
    static const bool has_quiet_NaN;
    static const bool has_signaling_NaN;
    static const float_denorm_style has_denorm;
    static const bool has_denorm_loss;

    static ETL_CONSTEXPR T infinity() { return 0; }
    static ETL_CONSTEXPR T quiet_NaN() { return 0; }
    static ETL_CONSTEXPR T signaling_NaN() { return 0; }
    static ETL_CONSTEXPR T denorm_min() { return 0; }

    static const bool is_iec559;
    static const bool is_bounded;
    static const bool is_modulo;

    static const bool traps;
    static const bool tinyness_before;
    static const float_round_style round_style;
  };

  template <typename T> const bool etl_integral_type<T>::is_specialized = true;
  template <typename T> const int etl_integral_type<T>::digits = (CHAR_BIT * sizeof(T)) - (etl::is_signed<T>::value ? 1 : 0);
  template <typename T> const int etl_integral_type<T>::digits10 = ETL_LOG2(digits);
  template <typename T> const int etl_integral_type<T>::max_digits10 = 0;
  template <typename T> const bool etl_integral_type<T>::is_signed = etl::is_signed<T>::value;
  template <typename T> const bool etl_integral_type<T>::is_integer = true;
  template <typename T> const bool etl_integral_type<T>::is_exact = true;
  template <typename T> const int etl_integral_type<T>::radix = 2;
  template <typename T> const int etl_integral_type<T>::min_exponent = 0;
  template <typename T> const int etl_integral_type<T>::min_exponent10 = 0;
  template <typename T> const int etl_integral_type<T>::max_exponent = 0;
  template <typename T> const int etl_integral_type<T>::max_exponent10 = 0;
  template <typename T> const bool etl_integral_type<T>::has_infinity = false;
  template <typename T> const bool etl_integral_type<T>::has_quiet_NaN = false;
  template <typename T> const bool etl_integral_type<T>::has_signaling_NaN = false;
  template <typename T> const float_denorm_style etl_integral_type<T>::has_denorm = denorm_absent;
  template <typename T> const bool etl_integral_type<T>::has_denorm_loss = false;
  template <typename T> const bool etl_integral_type<T>::is_iec559 = false;
  template <typename T> const bool etl_integral_type<T>::is_bounded = true;
  template <typename T> const bool etl_integral_type<T>::is_modulo = etl::is_unsigned<T>::value;
  template <typename T> const bool etl_integral_type<T>::traps = false;
  template <typename T> const bool etl_integral_type<T>::tinyness_before = false;
  template <typename T> const float_round_style etl_integral_type<T>::round_style = round_toward_zero;

  //***************************************************************************
  // Base for floating point types.
  template <typename T>
  class etl_floating_point_type
  {
  public:
    static const bool is_specialized;

    static const bool is_signed;
    static const bool is_integer;
    static const bool is_exact;

    static const int radix;

    static const bool has_infinity;
    static const bool has_quiet_NaN;
    static const bool has_signaling_NaN;
    static const float_denorm_style has_denorm;
    static const bool has_denorm_loss;

    static const bool is_iec559;
    static const bool is_bounded;
    static const bool is_modulo;

    static ETL_CONSTEXPR T round_error() { return T(0.5); }
    static ETL_CONSTEXPR T infinity() { return 0; }
    static ETL_CONSTEXPR T quiet_NaN() { return 0; }
    static ETL_CONSTEXPR T signaling_NaN() { return 0; }

    static const bool traps;
    static const bool tinyness_before;
    static const float_round_style round_style;
  };

  template <typename T> const bool etl_floating_point_type<T>::is_specialized = true;
  template <typename T> const bool etl_floating_point_type<T>::is_signed = true;
  template <typename T> const bool etl_floating_point_type<T>::is_integer = false;
  template <typename T> const bool etl_floating_point_type<T>::is_exact = false;
  template <typename T> const int etl_floating_point_type<T>::radix = 2;
  template <typename T> const bool etl_floating_point_type<T>::has_infinity = false;
  template <typename T> const bool etl_floating_point_type<T>::has_quiet_NaN = false;
  template <typename T> const bool etl_floating_point_type<T>::has_signaling_NaN = false;
  template <typename T> const float_denorm_style etl_floating_point_type<T>::has_denorm = denorm_present;
  template <typename T> const bool etl_floating_point_type<T>::has_denorm_loss = true;
  template <typename T> const bool etl_floating_point_type<T>::is_iec559 = true;
  template <typename T> const bool etl_floating_point_type<T>::is_bounded = true;
  template <typename T> const bool etl_floating_point_type<T>::is_modulo = false;
  template <typename T> const bool etl_floating_point_type<T>::traps = false;
  template <typename T> const bool etl_floating_point_type<T>::tinyness_before = true;
  template <typename T> const float_round_style etl_floating_point_type<T>::round_style = round_to_nearest;
}

#endif
