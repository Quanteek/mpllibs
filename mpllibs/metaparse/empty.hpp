#ifndef MPLLIBS_METAPARSE_EMPTY_HPP
#define MPLLIBS_METAPARSE_EMPTY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/fail.hpp>
#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/error.hpp>

#include <mpllibs/metamonad/meta_atom.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/empty.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      MPLLIBS_DEFINE_META_ATOM(
        mpllibs::metaparse::error_tag,
        end_of_input_expected
      )
    }
    
    template <class Result>
    struct empty
    {
      typedef empty type;
      
      template <class S, class Pos>
      struct apply :
        boost::mpl::apply_wrap2<
          typename boost::mpl::if_<
            boost::mpl::empty<S>,
            return_<Result>,
            fail<mpllibs::metaparse::errors::end_of_input_expected>
          >::type,
          S,
          Pos
        >
      {};

      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "empty<";
          mpllibs::metatest::to_stream_argument_list<Result>::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

