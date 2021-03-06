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
#include "cpp_ref_impl/cpp_model/test_data/base_td.hpp"
#include "cpp_ref_impl/cpp_model/test_data/descendant2_td.hpp"
#include "cpp_ref_impl/cpp_model/test_data/descendant3_td.hpp"
#include "cpp_ref_impl/cpp_model/test_data/non_final_leaf_td.hpp"

namespace cpp_ref_impl {
namespace cpp_model {

void base_generator::
populate(const unsigned int /*position*/, result_type& /*v*/) {
}

base_generator::result_type*
base_generator::create_ptr(const unsigned int position) {
    if ((position % 2) == 0)
        return cpp_ref_impl::cpp_model::descendant3_generator::create_ptr(position);
    if ((position % 2) == 1)
        return cpp_ref_impl::cpp_model::non_final_leaf_generator::create_ptr(position);
    return cpp_ref_impl::cpp_model::descendant2_generator::create_ptr(position);
}

} }
