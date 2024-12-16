#include <boost/test/unit_test.hpp>

#include "FieldTypeFactory.hpp"
#include "FieldType.hpp"

#include <string>

BOOST_AUTO_TEST_CASE( FieldTypeFactoru_instance )
{
  FieldTypeFactory ftf;
  auto t = ftf.newInstance("integer");
  
  BOOST_REQUIRE_EQUAL( t->typeName(), "integer" );
}

BOOST_AUTO_TEST_CASE( FieldTypeFactoru_getKeys )
{
  FieldTypeFactory ftf;
  auto l = ftf.getKeys();
  
  BOOST_REQUIRE( !l.empty() );
}

BOOST_AUTO_TEST_CASE( FieldTypeFactoru_unknownKey )
{
  FieldTypeFactory ftf;

  // Could you spot the typo ? ?
  BOOST_REQUIRE_THROW(ftf.newInstance("intrrrreger"), std::invalid_argument);
}


