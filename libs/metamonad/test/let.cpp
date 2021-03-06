// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/let.hpp>

#include <mpllibs/metatest/test.hpp>

#include "common.hpp"

using boost::mpl::equal_to;
using boost::mpl::plus;

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::let;

namespace
{
  const suite_path suite("let");

  typedef
    equal_to<
      int13,
      let<
        x, int13,
        x
      >::type
    >
    test_let_name;

  typedef
    equal_to<
      int11,
      let<
        x, int13,
        int11
      >::type
    >
    test_let_not_name;
  
  typedef
    equal_to<
      int26,
      let<
        x, int13,
        double_value<x>
      >::type
    >
    test_template;

  typedef
    equal_to<
      int24,
      let<
        x, int13,
        let<
          y, int11,
          plus<x, y>
        >::type
      >::type::type
    >
    test_nested_let;
  
  typedef
    equal_to<
      int37,
      let<
        x, int13,
        double_lazy_plus<
          x,
          let<
            x, int11,
            plus<x, int13>
          >
        >
      >::type::type
    >
    test_shadowing;
}

MPLLIBS_ADD_TEST(suite, test_let_name)
MPLLIBS_ADD_TEST(suite, test_let_not_name)
MPLLIBS_ADD_TEST(suite, test_template)
MPLLIBS_ADD_TEST(suite, test_nested_let)
MPLLIBS_ADD_TEST(suite, test_shadowing)




