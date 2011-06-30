#ifndef MPLLIBS_METAPARSE_SPACES_HPP
#define MPLLIBS_METAPARSE_SPACES_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/any1.hpp>
#include <mpllibs/metaparse/space.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    typedef any1<space> spaces;
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(mpllibs::metaparse::spaces, "spaces")

#endif

