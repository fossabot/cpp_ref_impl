#include "cpp_ref_impl/cpp_98/test_data/an_enumeration_td.hpp"

namespace cpp_ref_impl {
namespace cpp_98 {

an_enumeration_generator::an_enumeration_generator() : position_(0) { }
void an_enumeration_generator::
populate(const unsigned int position, result_type& v) {
    v = static_cast<an_enumeration>(position % 3);
}

an_enumeration_generator::result_type
an_enumeration_generator::create(const unsigned int  position) {
    result_type r;
    an_enumeration_generator::populate(position, r);
    return r;
}

an_enumeration_generator::result_type
an_enumeration_generator::operator()() {
    return create(position_++);
}

} }
