#include <boost/test/unit_test.hpp>

#include "Collection.hpp"

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

