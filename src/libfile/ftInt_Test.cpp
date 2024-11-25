#include <boost/test/unit_test.hpp>

#include "ftInt.hpp"

#include <string>

BOOST_AUTO_TEST_CASE( FieldTypeInt_typeName )
{
  FieldTypeInt fti;
  auto fn = fti.typeName();
  BOOST_REQUIRE_EQUAL( fn.empty(), false );
}
