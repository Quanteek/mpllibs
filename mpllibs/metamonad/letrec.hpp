#ifndef MPLLIBS_METAMONAD_LETREC_HPP
#define MPLLIBS_METAMONAD_LETREC_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/let.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class A, class E1, class E2>
    struct letrec : let<A, letrec<A, E1, E1>, E2>
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "letrec<";
          mpllibs::metatest::to_stream_argument_list<A, E1, E2>::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

