#ifndef CPP_REF_IMPL_CPP_98_SERIALIZATION_PARENT_SER_HPP
#define CPP_REF_IMPL_CPP_98_SERIALIZATION_PARENT_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include "cpp_ref_impl/cpp_98/types/parent.hpp"

BOOST_SERIALIZATION_SPLIT_FREE(cpp_ref_impl::cpp_98::parent)
BOOST_SERIALIZATION_ASSUME_ABSTRACT(cpp_ref_impl::cpp_98::parent)

namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const cpp_ref_impl::cpp_98::parent& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, cpp_ref_impl::cpp_98::parent& v, unsigned int version);

} }

#endif
