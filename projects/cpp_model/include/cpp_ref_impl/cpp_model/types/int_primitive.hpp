/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012-2015 Marco Craveiro <marco.craveiro@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#ifndef CPP_REF_IMPL_CPP_MODEL_TYPES_INT_PRIMITIVE_HPP
#define CPP_REF_IMPL_CPP_MODEL_TYPES_INT_PRIMITIVE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "cpp_ref_impl/cpp_model/serialization/int_primitive_fwd_ser.hpp"

namespace cpp_ref_impl {
namespace cpp_model {
/**
 * @brief Test a primitive with an underlying int.
 */
class int_primitive final {
public:
    int_primitive() = default;
    int_primitive(const int_primitive&) = default;
    int_primitive(int_primitive&&) = default;
    ~int_primitive() = default;
public:
    explicit int_primitive(const int value);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::cpp_model::int_primitive& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::cpp_model::int_primitive& v, unsigned int version);

public:
    /**
     * @brief Obtain the underlying value.
     */
    /**@{*/
    int value() const;
    void value(const int v);
    /**@}*/

public:
    explicit operator int() const {
        return value_;
    }

public:
    bool operator==(const int_primitive& rhs) const;
    bool operator!=(const int_primitive& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(int_primitive& other) noexcept;
    int_primitive& operator=(int_primitive other);

private:
    int value_;
};

} }

namespace std {

template<>
inline void swap(
    cpp_ref_impl::cpp_model::int_primitive& lhs,
    cpp_ref_impl::cpp_model::int_primitive& rhs) {
    lhs.swap(rhs);
}

}

#endif
