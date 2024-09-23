#include <boost/test/unit_test.hpp>

#include "Collection.hpp"

BOOST_AUTO_TEST_CASE( Collection_name )
{
  FXString n("nAmE");
  Collection c(n);
  BOOST_REQUIRE( c.getName() == n );
}

BOOST_AUTO_TEST_CASE( Collection_setName )
{
  FXString n("nAmE");
  FXString n2("nAmE updateeed");
  Collection c(n);
  c.setName(n2);
  BOOST_REQUIRE( c.getName() == n2 );
}
