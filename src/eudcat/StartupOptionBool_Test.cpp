#include <boost/test/unit_test.hpp>

#include "StartupOptionBool.hpp"

#include "IncompatibleArguments.hpp"

/// At least printAll must be set by default
BOOST_AUTO_TEST_CASE( StartupOptionBool_default )
{
  StartupOptionBool sob(true);
  BOOST_REQUIRE_EQUAL( sob.getValue(), true );
  BOOST_REQUIRE_EQUAL( sob.getType(), SOT_DEFAULT );
}
