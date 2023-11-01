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

/// Wich default values, check must pass
BOOST_AUTO_TEST_CASE( StartupOptions_consume_remove_first )
{
  tStringList o = { "progname", "aze"};
  StartupOptions so;
  // Should remove progname
  so.consume(o);
  BOOST_REQUIRE_EQUAL( o.size(), 1 );
  BOOST_REQUIRE_EQUAL( *o.begin(), "aze" );
}

/// Wich default values, check must pass
BOOST_AUTO_TEST_CASE( StartupOptions_consume_printHelp_short )
{
  tStringList o = { "progname", "-h"};
  StartupOptions so;
  BOOST_REQUIRE_EQUAL( so.printHelp, false );

  so.consume(o);
  BOOST_REQUIRE_EQUAL( so.printHelp, true );
}

BOOST_AUTO_TEST_CASE( StartupOptions_consume_printHelp_long )
{
  tStringList o = { "progname", "--help"};
  StartupOptions so;
  BOOST_REQUIRE_EQUAL( so.printHelp, false );

  so.consume(o);
  BOOST_REQUIRE_EQUAL( so.printHelp, true );
}

BOOST_AUTO_TEST_CASE( StartupOptions_incompatible_SetAll )
{
  tStringList o = { "progname", "-s", "-a"};
  StartupOptions so;
  BOOST_CHECK_THROW( so.consume(o), IncompatibleArguments );
}





