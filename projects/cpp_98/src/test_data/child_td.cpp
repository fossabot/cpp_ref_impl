#include "cpp_ref_impl/cpp_98/test_data/child_td.hpp"
#include "cpp_ref_impl/cpp_98/test_data/parent_td.hpp"

namespace {

int create_int(const unsigned int position) {
    return static_cast<int>(position);
}

}

namespace cpp_ref_impl {
namespace cpp_98 {

child_generator::child_generator() : position_(0) { }

void child_generator::
populate(const unsigned int position, result_type& v) {
    cpp_ref_impl::cpp_98::parent_generator::populate(position, v);
    v.prop_1(create_int(position + 0));
}

child_generator::result_type
child_generator::create(const unsigned int position) {
    child r;
    child_generator::populate(position, r);
    return r;
}

child_generator::result_type*
child_generator::create_ptr(const unsigned int position) {
    child* p = new child();
    child_generator::populate(position, *p);
    return p;
}

child_generator::result_type
child_generator::operator()() {
    return create(position_++);
}

} }
