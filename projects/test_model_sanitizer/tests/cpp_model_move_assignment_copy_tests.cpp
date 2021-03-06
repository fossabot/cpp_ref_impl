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
#include <boost/exception/diagnostic_information.hpp>
#include "cpp_ref_impl/utility/io/vector_io.hpp"
#include "cpp_ref_impl/utility/test/logging.hpp"
#include "cpp_ref_impl/utility/test/canned_tests.hpp"
#include "cpp_ref_impl/cpp_model/types/all.hpp"
#include "cpp_ref_impl/cpp_model/io/all_io.hpp"
#include "cpp_ref_impl/cpp_model/serialization/all_ser.hpp"
#include "cpp_ref_impl/cpp_model/test_data/all_td.hpp"
#include "cpp_ref_impl/cpp_model/hash/all_hash.hpp"
#include "dogen/test_models/test_model_sanitizer/register_types.hpp"

namespace {

const std::string empty;
const std::string test_module("test_model_sanitizer");
const std::string test_suite("cpp_model_tests");

}

using namespace cpp_ref_impl::cpp_model;
using namespace cpp_ref_impl::utility::test;

BOOST_AUTO_TEST_SUITE(cpp_model_move_assignment_copy_tests)

BOOST_AUTO_TEST_CASE(validate_move_assignment_copy) {
    SETUP_TEST_LOG("validate_move_assignment_copy");
    test_move_assignment_copy<a_class_generator>();

    test_move_assignment_copy<package_1::class_1_generator>();
    test_move_assignment_copy<package_1::class_2_generator>();
    test_move_assignment_copy<package_1::class_3_generator>();
    test_move_assignment_copy<package_1::class_4_generator>();
    test_move_assignment_copy<package_1::class_5_generator>();

    test_move_assignment_copy<book_types_generator>();
    test_move_assignment_copy<colour_types_generator>();
    test_move_assignment_copy<package_4::shape_types_generator>();
    test_move_assignment_copy<a_class_generator>();

    test_move_assignment_copy<short_primitive_generator>();
    test_move_assignment_copy<ushort_primitive_generator>();
    test_move_assignment_copy<long_primitive_generator>();
    test_move_assignment_copy<ulong_primitive_generator>();
    test_move_assignment_copy<int_primitive_generator>();
    test_move_assignment_copy<uint_primitive_generator>();
    test_move_assignment_copy<char_primitive_generator>();
    test_move_assignment_copy<uchar_primitive_generator>();
    test_move_assignment_copy<double_primitive_generator>();
    test_move_assignment_copy<float_primitive_generator>();
    // FIXME: commented out due to the well-known oscillation problems
    // with booleans.
    // test_move_assignment_copy<bool_primitive_generator>();
    test_move_assignment_copy<immutable_primitive_generator>();

    test_move_assignment_copy<consumer_generator>();

    // NOTE: skipping immutable_one_builtin because boolean types
    // don't play well with our requirement that the parameter passed
    // in must not be equal to a default constructed type.
    test_move_assignment_copy<value_generator>();
    test_move_assignment_copy<immutable_four_generator>();
    test_move_assignment_copy<immutable_one_non_builtin_generator>();
    test_move_assignment_copy<immutable_two_generator>();
    test_move_assignment_copy<fluent_generator>();
    test_move_assignment_copy<fluent_generator>();

    test_move_assignment_copy<simple_object_template_instance_generator>();
    test_move_assignment_copy<base_object_template_instance_generator>();
    test_move_assignment_copy<descendant_object_template_instance_generator>();
    test_move_assignment_copy<multiple_parents_object_template_instance_generator>();
    test_move_assignment_copy<multi_object_template_instance_generator>();
    test_move_assignment_copy<further_inherited_generator>();

    test_move_assignment_copy<class_a_generator>();
    test_move_assignment_copy<class_b_generator>();

    test_move_assignment_copy<child_with_members_generator>();
    test_move_assignment_copy<second_child_without_members_generator>();
    test_move_assignment_copy<child_of_a_child1_generator>();
    test_move_assignment_copy<child_of_a_child2_generator>();
    test_move_assignment_copy<package_6::child_generator>();
    test_move_assignment_copy<package_8::child_generator>();
    test_move_assignment_copy<package_9::child_generator>();
    test_move_assignment_copy<move_ctor_descendant_generator>();
    test_move_assignment_copy<move_ctor_empty_descendant_generator>();
    test_move_assignment_copy<child_via_settings_generator>();
    test_move_assignment_copy<package_6::child_via_settings_generator>();
    test_move_assignment_copy<package_8::child_via_settings_generator>();
    test_move_assignment_copy<package_9::child_via_settings_generator>();
    test_move_assignment_copy<non_final_leaf_generator>();
    test_move_assignment_copy<non_final_orphan_generator>();
    test_move_assignment_copy<descendant2_generator>();
    test_move_assignment_copy<descendant3_generator>();
}

BOOST_AUTO_TEST_SUITE_END()
