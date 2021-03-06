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
#ifndef CPP_REF_IMPL_CPP_MODEL_TYPES_CLASS_C_HPP
#define CPP_REF_IMPL_CPP_MODEL_TYPES_CLASS_C_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "cpp_ref_impl/cpp_model/serialization/class_c_fwd_ser.hpp"

namespace cpp_ref_impl {
namespace cpp_model {

class class_c final {
public:
    class_c() = default;
    class_c(const class_c&) = default;
    class_c(class_c&&) = default;
    ~class_c() = default;
    class_c& operator=(const class_c&) = default;

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::cpp_model::class_c& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::cpp_model::class_c& v, unsigned int version);

public:
    bool operator==(const class_c& rhs) const;
    bool operator!=(const class_c& rhs) const {
        return !this->operator==(rhs);
    }

};

} }

#endif
