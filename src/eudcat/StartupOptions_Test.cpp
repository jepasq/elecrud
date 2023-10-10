#include <boost/test/unit_test.hpp>

#include "StartupOptions.hpp"

/// At leastn printAll must be set by default
BOOST_AUTO_TEST_CASE( StartupOptions_defaultValues )
{
  StartupOptions so;
  BOOST_REQUIRE_EQUAL( so.printAll, true );
}

/// Wich default values, check must pass
BOOST_AUTO_TEST_CASE( StartupOptions_check_default )
{
  StartupOptions so;
  BOOST_REQUIRE_EQUAL( so.check(), true );
}

