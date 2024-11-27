#include <boost/test/unit_test.hpp>

#include "ftInt.hpp"

#include <string>

BOOST_AUTO_TEST_CASE( FieldTypeInt_typeName )
{
  FieldTypeInt fti;
  auto fn = fti.typeName();
  BOOST_REQUIRE_EQUAL( fn.empty(), false );
}

BOOST_AUTO_TEST_CASE( FieldTypeInt_defaultValue )
{
  FieldTypeInt fti;
  BOOST_REQUIRE_EQUAL( fti.getValue(), 0 );
}

BOOST_AUTO_TEST_CASE( FieldTypeInt_toString )
{
  FieldTypeInt fti(24);
  BOOST_REQUIRE( fti.toString() ==  "24" );
}

BOOST_AUTO_TEST_CASE( FieldTypeInt_setValue )
{
  FieldTypeInt fti;
  fti.setValue(32);
  BOOST_REQUIRE( fti.toString() ==  "32" );
}


