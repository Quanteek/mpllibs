#ifndef MPLLIBS_METATEST_HAS_TYPE_VALUE_HPP
#define MPLLIBS_METATEST_HAS_TYPE_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <mpllibs/metatest/has_value.hpp>
#include <mpllibs/metatest/get_type.hpp>

namespace mpllibs
{
  namespace metatest
  {
    template <class T, class ValueType>
    struct has_type_value :
      has_value<typename get_type<T, int>::type, ValueType>
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "has_type_value<";
          to_stream_argument_list<T, ValueType>::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

