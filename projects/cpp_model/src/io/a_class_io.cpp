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
#include <ostream>
#include "cpp_ref_impl/cpp_model/io/a_class_io.hpp"
#include "cpp_ref_impl/cpp_model/io/book_types_io.hpp"
#include "cpp_ref_impl/cpp_model/io/colour_types_io.hpp"
#include "cpp_ref_impl/cpp_model/io/package_4/shape_types_io.hpp"

namespace cpp_ref_impl {
namespace cpp_model {

std::ostream& operator<<(std::ostream& s, const a_class& v) {
    s << " { "
      << "\"__type__\": " << "\"cpp_ref_impl::cpp_model::a_class\"" << ", "
      << "\"colour_type\": " << v.colour_type() << ", "
      << "\"book_type\": " << v.book_type() << ", "
      << "\"shape_type\": " << v.shape_type()
      << " }";
    return(s);
}

} }
