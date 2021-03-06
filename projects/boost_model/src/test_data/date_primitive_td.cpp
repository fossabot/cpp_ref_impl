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
#include "cpp_ref_impl/boost_model/test_data/date_primitive_td.hpp"

namespace {

boost::gregorian::date
create_boost_gregorian_date(const unsigned int position) {
    unsigned int day(1 + (position % 27));
    boost::gregorian::date r(2002, 2, day);
    return r;
}

}

namespace cpp_ref_impl {
namespace boost_model {

date_primitive_generator::date_primitive_generator() : position_(0) { }

void date_primitive_generator::
populate(const unsigned int position, result_type& v) {
    v.value(create_boost_gregorian_date(position + 1));
}

date_primitive_generator::result_type
date_primitive_generator::create(const unsigned int position) {
    date_primitive r;
    date_primitive_generator::populate(position, r);
    return r;
}

date_primitive_generator::result_type*
date_primitive_generator::create_ptr(const unsigned int position) {
    date_primitive* r = new date_primitive();
    date_primitive_generator::populate(position, *r);
    return r;
}

date_primitive_generator::result_type
date_primitive_generator::operator()() {
    return create(position_++);
}

} }
