#include <boost/test/unit_test.hpp>

#include <stdexcept> // USES std::invalid_argument

#include "Field.hpp"


BOOST_AUTO_TEST_CASE( Field_name )
{
  FXString n("nAmE");
  Field f(n);
  BOOST_REQUIRE( f.getName() == n );
}

BOOST_AUTO_TEST_CASE( Field_name_empty )
{
  BOOST_REQUIRE_THROW( new Field(""), std::invalid_argument );

  Field f("aze");
  BOOST_REQUIRE_THROW( f.setName(""), std::invalid_argument );
}

BOOST_AUTO_TEST_CASE( Field_description )
{
  Field f("aaa");
  FXString d = "des";
  f.setDescription(d);
  BOOST_REQUIRE( f.getDescription() == d );
}

BOOST_AUTO_TEST_CASE( Field_oneliner )
{
  Field f("a");
  f.setDescription("bbb");
  // setType
  BOOST_REQUIRE( f.getOneLiner() == "int a (bbb)" );
}



