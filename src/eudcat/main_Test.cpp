#include <boost/test/unit_test.hpp>

#include <cstdlib> // USES system()

#define EUDC "./eudcat "

/// It seems that running eudcap with options doesn't correctly
/// consume options even with 
BOOST_AUTO_TEST_CASE( eudcat_RunningWithOptions )
{
  // First, test a normal call works because system() should return
  // command exit status
  int rv = system(EUDC"test.eud");
  BOOST_REQUIRE_EQUAL( rv, 0 );

  // Then, test with an inexistant project file
  rv = system(EUDC"surelyAnExistantEUDfileIswear.eud");
  BOOST_REQUIRE_EQUAL( rv, 134 );

  // Now, running on the first file (that exists), shouldn't return 134
  rv = system(EUDC"-a test.eud");
  BOOST_REQUIRE_EQUAL( rv, 0 );

}
