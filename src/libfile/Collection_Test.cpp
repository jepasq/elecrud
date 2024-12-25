#include <boost/test/unit_test.hpp>

#include "Collection.hpp"

#include <memory> // USES std::make_shared

BOOST_AUTO_TEST_CASE( Collection_name )
{
  FXString n("nAmE");
  Collection c(n);
  BOOST_REQUIRE( c.getName() == n );
}

BOOST_AUTO_TEST_CASE( Collection_copy_ctor )
{
  FXString n("nAmE");
  Collection c(n);

  Collection c2(&c);

  BOOST_REQUIRE( c.getName() == c2.getName() );
  BOOST_REQUIRE( c.getDescription() == c2.getDescription() );
}


BOOST_AUTO_TEST_CASE( Collection_setName )
{
  FXString n("nAmE");
  FXString n2("nAmE updateeed");
  Collection c(n);
  c.setName(n2);
  BOOST_REQUIRE( c.getName() == n2 );
}

/// Check that the description is empty by default
BOOST_AUTO_TEST_CASE( Collection_ctor_descr_empty )
{
  FXString n("nAmE");
  Collection c(n);
  BOOST_REQUIRE(c.getDescription().empty());
}

/// Check that the description effectively change underlying field
BOOST_AUTO_TEST_CASE( Collection_ctor_descr_setter )
{
  FXString n("nAmE");
  Collection c(n);
  FXString dscr = "Descr value\npossibly multiline";
  BOOST_REQUIRE(c.getDescription().empty());
}

/// Check that the description effectively change underlying field
BOOST_AUTO_TEST_CASE( Collection_one_liner )
{
  Collection c("Name", "Desc");
  BOOST_REQUIRE(!c.getOneLiner().empty());
}

BOOST_AUTO_TEST_CASE( Collection_append_field )
{
  Collection c("Name", "Desc");
  BOOST_REQUIRE(c.getFields().size() == 0); // Empty by default

  c.appendField(std::make_shared<Field>("aze"));
  BOOST_REQUIRE(c.getFields().size() == 1); // Added worked
}


BOOST_AUTO_TEST_CASE( Collection_field_name_duplicate )
{
  Collection c("Name", "Desc");
  BOOST_REQUIRE(c.isFieldNameInUse("aze") == false);
  
  c.appendField(std::make_shared<Field>("aze"));

  BOOST_REQUIRE(c.isFieldNameInUse("aze") == true);
}

/// If no description provided, do not add empty parenthesis
BOOST_AUTO_TEST_CASE( Collection_one_liner_emptyDesc )
{
  Collection c1("Name", "DDD");
  BOOST_REQUIRE(c1.getOneLiner() == "Name (DDD)");
  Collection c2("Name");
  BOOST_REQUIRE(c2.getOneLiner() == "Name");
}

BOOST_AUTO_TEST_CASE( Collection_saveFieldList_len )
{
  FXMemoryStream ms;
  constexpr auto sz = 180;
  FXuchar buffer[sz];

  Collection c("Name", "Desc");
  c.appendField(std::make_shared<Field>("aze"));
  ms.open(FXStreamSave, buffer);
  c.save(ms);
  ms.close();
  
  
  Collection c2("Name", "Desc");
  ms.open(FXStreamLoad, buffer);
  c2.load(ms);
  ms.close();

  BOOST_REQUIRE(c2.getFields().size() == 1); // Load added one field
}
