#include <boost/test/unit_test.hpp>

#include <stdexcept> // USES std::invalid_argument

#include "Field.hpp"
#include "FieldTypeFactory.hpp"


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

BOOST_AUTO_TEST_CASE( Field_oneliner_notype )
{
  Field f("a");
  f.setDescription("bbb");
  // setType
  BOOST_REQUIRE( f.getOneLiner() == "a (bbb)" );
}

BOOST_AUTO_TEST_CASE( Field_oneliner_nodesc )
{
  Field f("a");
  f.setDescription("");
  // setType
  BOOST_REQUIRE( f.getOneLiner() == "a" );
}

BOOST_AUTO_TEST_CASE( Field_oneliner_int )
{
  Field f("a");
  f.setDescription("bbb");

  FieldTypeFactory ftf;
  f.setType(ftf.newInstance("integer"));
  
  // setType
  auto r = f.getOneLiner();
  std::cout << "Field::getOneLiner returns " << r.text() << std::endl;
  BOOST_REQUIRE( f.getOneLiner() == "int a (bbb)" );
}

BOOST_AUTO_TEST_CASE( Field_saveToStream )
{
  FXMemoryStream ms;
  
  Field f("a");
  f.setDescription("bbb");
  f.save(ms);

  Field f2("cc");
  f2.load(ms);

  BOOST_REQUIRE( f2.getName() == "a" );
  BOOST_REQUIRE( f2.getDescription() == "bbb" );
}

