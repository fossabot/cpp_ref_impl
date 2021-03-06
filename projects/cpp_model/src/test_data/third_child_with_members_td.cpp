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
#include "cpp_ref_impl/cpp_model/test_data/child_of_a_child1_td.hpp"
#include "cpp_ref_impl/cpp_model/test_data/child_of_a_child2_td.hpp"
#include "cpp_ref_impl/cpp_model/test_data/parent_with_members_td.hpp"
#include "cpp_ref_impl/cpp_model/test_data/third_child_with_members_td.hpp"

namespace {

unsigned int create_unsigned_int(const unsigned int position) {
    return static_cast<unsigned int>(position);
}

}

namespace cpp_ref_impl {
namespace cpp_model {

void third_child_with_members_generator::
populate(const unsigned int position, result_type& v) {
    cpp_ref_impl::cpp_model::parent_with_members_generator::populate(position, v);
    v.prop_1(create_unsigned_int(position + 0));
}

third_child_with_members_generator::result_type*
third_child_with_members_generator::create_ptr(const unsigned int position) {
    if ((position % 1) == 0)
        return cpp_ref_impl::cpp_model::child_of_a_child2_generator::create_ptr(position);
    return cpp_ref_impl::cpp_model::child_of_a_child1_generator::create_ptr(position);
}

} }
