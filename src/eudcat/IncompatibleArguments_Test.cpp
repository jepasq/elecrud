#include <boost/test/unit_test.hpp>

#include "IncompatibleArguments.hpp"

/// At least printAll must be set by default
BOOST_AUTO_TEST_CASE( IncompatibleArguments_defaultValues )
{
  IncompatibleArguments ia;
  BOOST_REQUIRE_EQUAL( ia.what(), "" );
}

/// Passing a what arg change member's value
BOOST_AUTO_TEST_CASE( IncompatibleArguments_whatArg )
{
  IncompatibleArguments ia("Aze");
  BOOST_REQUIRE_EQUAL( ia.what(), "Aze" );
}

