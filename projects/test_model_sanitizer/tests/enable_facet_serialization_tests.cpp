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
#include <boost/test/unit_test.hpp>
#include "cpp_ref_impl/utility/io/vector_io.hpp"
#include "cpp_ref_impl/utility/test/logging.hpp"
#include "cpp_ref_impl/utility/test/macros.hpp"
#include "cpp_ref_impl/utility/test/canned_tests.hpp"
#include "cpp_ref_impl/enable_facet_serialization/serialization/all_ser.hpp"
#include "cpp_ref_impl/enable_facet_serialization/types/all.hpp"
#include "dogen/test_models/test_model_sanitizer/register_types.hpp"

namespace {

const std::string empty;
const std::string test_module("test_model_sanitizer");
const std::string test_suite("enable_facet_serialization_tests");

class first_class_generator {
public:
    typedef cpp_ref_impl::enable_facet_serialization::package1::first_class result_type;

public:
    result_type operator()() {
        result_type r;
        r.public_attribute(15 + pos_++);
        return r;
    }

private:
    unsigned int pos_ = 0;
};

}

namespace cpp_ref_impl {
namespace enable_facet_serialization {
namespace package1 {

std::ostream& operator<<(std::ostream& o, const first_class& v) {
    o << "outputting first class: " << v.public_attribute() << std::endl;
    return o;
}

} } }

using namespace cpp_ref_impl::enable_facet_serialization;
using namespace cpp_ref_impl::enable_facet_serialization::package1;
using namespace cpp_ref_impl::utility::test;

BOOST_AUTO_TEST_SUITE(enable_facet_serialization_tests)

BOOST_AUTO_TEST_CASE(validate_equality) {
    SETUP_TEST_LOG("validate_equality");
    test_equality<first_class_generator>();
}

BOOST_AUTO_TEST_CASE(validate_serialisation) {
    SETUP_TEST_LOG("validate_serialisation");
    roundtrip_type<first_class_generator>();
}

BOOST_AUTO_TEST_CASE(validate_swap) {
    SETUP_TEST_LOG("validate_swap");
    test_swap<first_class_generator>();
}

BOOST_AUTO_TEST_CASE(validate_move_assignment_copy) {
    SETUP_TEST_LOG("validate_move_assignment_copy");
    test_move_assignment_copy<first_class_generator>();
}

BOOST_AUTO_TEST_SUITE_END()
