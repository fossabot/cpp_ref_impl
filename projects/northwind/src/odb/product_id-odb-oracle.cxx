// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "dogen/test_models/northwind/odb/product_id-odb-oracle.hxx"

#include <cassert>
#include <cstring>  // std::memcpy

#include <odb/schema-catalog-impl.hxx>

#include <odb/oracle/traits.hxx>
#include <odb/oracle/database.hxx>
#include <odb/oracle/transaction.hxx>
#include <odb/oracle/connection.hxx>
#include <odb/oracle/statement.hxx>
#include <odb/oracle/statement-cache.hxx>
#include <odb/oracle/container-statements.hxx>
#include <odb/oracle/exceptions.hxx>

namespace odb
{
  // product_id
  //

  void access::composite_value_traits< ::dogen::test_models::northwind::product_id, id_oracle >::
  bind (oracle::bind* b,
        image_type& i,
        oracle::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (b);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace oracle;

    std::size_t n (0);
    ODB_POTENTIALLY_UNUSED (n);

    // value_
    //
    b[n].type = oracle::bind::integer;
    b[n].buffer = &i.value_value;
    b[n].capacity = 4;
    b[n].size = 0;
    b[n].indicator = &i.value_indicator;
    n++;
  }

  void access::composite_value_traits< ::dogen::test_models::northwind::product_id, id_oracle >::
  init (image_type& i,
        const value_type& o,
        oracle::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace oracle;

    // value_
    //
    {
      int const& v =
        o.value ();

      bool is_null (false);
      oracle::value_traits<
          int,
          oracle::id_int32 >::set_image (
        i.value_value, is_null, v);
      i.value_indicator = is_null ? -1 : 0;
    }
  }

  void access::composite_value_traits< ::dogen::test_models::northwind::product_id, id_oracle >::
  init (value_type& o,
        const image_type&  i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // value_
    //
    {
      int v;

      oracle::value_traits<
          int,
          oracle::id_int32 >::set_value (
        v,
        i.value_value,
        i.value_indicator == -1);

      o.value (v);
    }
  }
}

#include <odb/post.hxx>
