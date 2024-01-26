#include <boost/test/unit_test.hpp>

#include <cstdlib> // USES system()

#define EUDC "./eudcat "

/** Exit status returned by eudcat program execution
  *
  * Some constants may have the same values as it(s based on the main
  * program exit values.
  *
  */
namespace exec {
  constexpr int SUCCESS = 0;          //!< Exit without error
  constexpr int FILE_NOT_FOUND = 134; //!< Or another exception
  constexpr int INCOMPATIBLE_ARGS = 134;      //!< Maybe an Invali
  
}

/// It seems that running eudcap with options doesn't correctly
/// consume options even with 
BOOST_AUTO_TEST_CASE( eudcat_RunningWithOptions )
{
  // First, test a normal call works because system() should return
  // command exit status
  int rv = system(EUDC"test.eud");
  BOOST_REQUIRE_EQUAL( rv, exec::SUCCESS );

  // Then, test with an inexistant project file
  rv = system(EUDC"surelyAnExistantEUDfileIswear.eud");
  BOOST_REQUIRE_EQUAL( rv, exec::FILE_NOT_FOUND );

  // Now, running on the first file (that exists), shouldn't return 134
  rv = system(EUDC"-a test.eud");
  BOOST_REQUIRE_NE( rv, exec::FILE_NOT_FOUND );

  // Now, running on the first file (that exists), shouldn't return 134
  rv = system(EUDC"-s test.eud");
  BOOST_REQUIRE_NE( rv, exec::INCOMPATIBLE_ARGS );
}
