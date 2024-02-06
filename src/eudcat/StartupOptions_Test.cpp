#include <boost/test/unit_test.hpp>

#include "StartupOptions.hpp"

/// At least printAll must be set by default
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

BOOST_AUTO_TEST_CASE( StartupOptions_consume_remove_used )
{
  tStringList o = { "progname", "-a", "file.eud"};
  StartupOptions so;
  so.consume(o);
  auto found = std::find(o.begin(), o.end(), "-a") != o.end();
  BOOST_REQUIRE_EQUAL( found, false );
}

/// Tests that using the 'set' argument removes the default 'all' one
/// This prevent the main script to fire an 'IncompatibleArguments' exception
BOOST_AUTO_TEST_CASE( StartupOptions_set_remove_all )
{
  tStringList o = { "progname", "-s", "file.eud"};
  StartupOptions so;
  BOOST_REQUIRE_EQUAL( so.printAll, true ); // True by default
  
  so.consume(o);    // Consume the -s flag and make set equal true

  BOOST_REQUIRE_EQUAL( so.printAll, false ); // Toggled by -s
  
}
