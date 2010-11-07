// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/digit.h>
#include <mpllibs/metaparse/nothing.h>
#include <mpllibs/metaparse/util/is_nothing.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("digit");

  typedef
    mpllibs::metaparse::util::is_nothing<
      boost::mpl::apply<mpllibs::metaparse::digit, str_hello>
    >
    TestWithText;
  
  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::metaparse::digit, str_1983>::type::first,
      char_1
    >
    TestWithNumber;
  
  typedef
    mpllibs::metaparse::util::is_nothing<
      boost::mpl::apply<mpllibs::metaparse::digit, str_>
    >
    TestWithEmptyString;
}

MPLLIBS_ADD_TEST(suite, TestWithText)
MPLLIBS_ADD_TEST(suite, TestWithNumber)
MPLLIBS_ADD_TEST(suite, TestWithEmptyString)


