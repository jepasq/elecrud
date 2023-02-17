#include <boost/test/unit_test.hpp>

#include "Generator.hpp"
#include "TestableGenerator.hpp"

#include <string>

using std::string;

BOOST_AUTO_TEST_CASE( TestableGenerator_can_be_instantiated )
{
  TestableGenerator* tg = new TestableGenerator();
  BOOST_REQUIRE_NE( tg, nullptr);
  delete tg;
}

BOOST_AUTO_TEST_CASE( TestableGenerator_get_output_dir )
{
  TestableGenerator tg;
  BOOST_REQUIRE( tg.getOutputDir().empty());
}

BOOST_AUTO_TEST_CASE( TestableGenerator_setOutputDir )
{
  TestableGenerator tg;
  auto od = tg.getOutputDir();
  tg.setOutputDir("newone");
  BOOST_REQUIRE( tg.getOutputDir() != od);
}

BOOST_AUTO_TEST_CASE( TestableGenerator_directoryExists )
{
  TestableGenerator tg;
  auto dirname= "improbableDirectory_name";
  BOOST_REQUIRE( !tg._directoryExists(dirname) );

  dirname= "CMakeFiles";
  BOOST_REQUIRE( tg._directoryExists(dirname) );
}

BOOST_AUTO_TEST_CASE( TestableGenerator_createDirectory )
{
  TestableGenerator tg;
  auto dirname= "tobecreated_Directory";
  BOOST_REQUIRE( !tg._directoryExists(dirname) );

  tg._createDirectory(dirname);
  BOOST_REQUIRE( tg._directoryExists(dirname) );

  // then, remove
  tg._removeDirectory(dirname);
  BOOST_REQUIRE( !tg._directoryExists(dirname) );
}

/// Be sure the variables map is empty
BOOST_AUTO_TEST_CASE( TestableGenerator_varsAreEmpty )
{
  TestableGenerator tg;
  auto vars= tg.getVariables();
  BOOST_REQUIRE( vars.empty() );
}

BOOST_AUTO_TEST_CASE( TestableGenerator_addVar )
{
  TestableGenerator tg;
  auto c1= tg.getVariables().size();

  tg.addVariable("key1", "val1");
  
  BOOST_REQUIRE( !tg.getVariables().empty() );
  BOOST_REQUIRE( c1 != tg.getVariables().size() );
}

BOOST_AUTO_TEST_CASE( TestableGenerator_replaceVars )
{
  TestableGenerator tg;
  tg.addVariable("key1", "val1");
  BOOST_REQUIRE( tg._replaceVars("{{key1}}") == "val1" );
  BOOST_REQUIRE( tg._replaceVars("AAA{{key1}}AAA") == "AAAval1AAA" );
}


/// Test if a file exist
BOOST_AUTO_TEST_CASE( TestableGenerator_fileExists )
{
  TestableGenerator tg;
  BOOST_REQUIRE( tg._fileExists("CMakeCache.txt" ) );
  BOOST_REQUIRE( !tg._fileExists("CMakeCache.txt_inexistantFile;;" ) );  
}

/// Test the contain function with an EOF
BOOST_AUTO_TEST_CASE( TestableGenerator_fileContains_eof )
{
  TestableGenerator tg;
  BOOST_REQUIRE( !tg._fileContains("CMakeCache.txt", "AAAbbbCCCdDdD" ) );  
}

/// Test if a file contains a given test
BOOST_AUTO_TEST_CASE( TestableGenerator_fileContains )
{
  TestableGenerator tg;
  BOOST_REQUIRE( tg._fileContains("CMakeCache.txt", "EXTERNAL" ) );
  BOOST_REQUIRE( !tg._fileContains("CMakeCache.txt", "AAAbbbCCCdDdD" ) );  
}

/// Test that we can have the content of a file as a string
BOOST_AUTO_TEST_CASE( TestableGenerator_getFileContent )
{
  TestableGenerator tg;

  // If file doesn't exist, throw an exceptino
  BOOST_CHECK_THROW(tg._getFileContent("CMakeCache.txt_CantBeFound"),
		    std::runtime_error);
  

  auto content = tg._getFileContent("CMakeCache.txt");
  BOOST_REQUIRE( !content.empty() );
}

/// Test if a file contains a given test
BOOST_AUTO_TEST_CASE( TestableGenerator_copyFile )
{
  TestableGenerator tg;
  tg._copyFile("CMakeCache.txt", "CMakeCache.txt_copied");
  BOOST_REQUIRE( tg._fileExists("CMakeCache.txt_copied" ) );
}

