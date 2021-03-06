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
#ifndef CPP_REF_IMPL_CPP_MODEL_TYPES_BASE_OBJECT_TEMPLATE_INSTANCE_HPP
#define CPP_REF_IMPL_CPP_MODEL_TYPES_BASE_OBJECT_TEMPLATE_INSTANCE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "cpp_ref_impl/cpp_model/serialization/base_object_template_instance_fwd_ser.hpp"

namespace cpp_ref_impl {
namespace cpp_model {

/**
 * @brief This class instantiates the BaseObjectTemplate.
 */
class base_object_template_instance final {
public:
    base_object_template_instance(const base_object_template_instance&) = default;
    base_object_template_instance(base_object_template_instance&&) = default;
    ~base_object_template_instance() = default;

public:
    base_object_template_instance();

public:
    explicit base_object_template_instance(const int prop_0);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::cpp_model::base_object_template_instance& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::cpp_model::base_object_template_instance& v, unsigned int version);

public:
    /**
     * @brief Property in the base object template.
     */
    /**@{*/
    int prop_0() const;
    void prop_0(const int v);
    /**@}*/

public:
    bool operator==(const base_object_template_instance& rhs) const;
    bool operator!=(const base_object_template_instance& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(base_object_template_instance& other) noexcept;
    base_object_template_instance& operator=(base_object_template_instance other);

private:
    int prop_0_;
};

} }

namespace std {

template<>
inline void swap(
    cpp_ref_impl::cpp_model::base_object_template_instance& lhs,
    cpp_ref_impl::cpp_model::base_object_template_instance& rhs) {
    lhs.swap(rhs);
}

}

#endif
