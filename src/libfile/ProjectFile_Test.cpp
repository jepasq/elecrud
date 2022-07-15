#include <boost/test/unit_test.hpp>

#include "ProjectFile.hpp"

BOOST_AUTO_TEST_CASE( ProjectFile_ )
{
  ProjectFile pf;
  auto fn = pf.getFilename();
  BOOST_REQUIRE_EQUAL( fn.empty(), true );
}
