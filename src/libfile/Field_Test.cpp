#include <boost/test/unit_test.hpp>

#include "Field.hpp"

BOOST_AUTO_TEST_CASE( Field_name )
{
  FXString n("nAmE");
  Field f(n);
  BOOST_REQUIRE( f.getName() == n );
}
