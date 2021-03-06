#ifndef MPLLIBS_METAMONAD_RIGHT_HPP
#define MPLLIBS_METAMONAD_RIGHT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tag_tag.hpp>
#include <mpllibs/metamonad/get_data.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/equal_to.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DEFINE_TAG(right_tag)
    
    template <class T>
    struct right
    {
      typedef right type;
      typedef right_tag tag;
      typedef typename T::type data;
      struct to_stream
      {
        static std::ostream& run(std::ostream& o_)
        {
          o_ << "right<";
          mpllibs::metatest::to_stream<T>::run(o_);
          return o_ << ">";
        }
      };
    };
    
    template <>
    struct get_data_impl<right_tag>
    {
      template <class T>
      struct apply
      {
        typedef typename T::data type;
      };
    };
  }
}

namespace boost
{
  namespace mpl
  {
    template <class A, class B>
    struct equal_to_impl;

    template <>
    struct
      equal_to_impl<
        mpllibs::metamonad::right_tag,
        mpllibs::metamonad::right_tag
      >
    {
      template <class A, class B>
      struct apply :
        equal_to<
          typename mpllibs::metamonad::get_data<A>::type,
          typename mpllibs::metamonad::get_data<B>::type
        >
      {};
    };
  }
}

#endif

