#include <boost/test/unit_test.hpp>

#include "GeneratorV1.hpp"
#include "TestableGenerator.hpp"

BOOST_AUTO_TEST_CASE( GeneratorV1_can_be_instantiated )
{
  auto tg = new GeneratorV1();
  BOOST_REQUIRE_NE( tg, nullptr);
  delete tg;
}

/// Copy index.html in the outputDir
BOOST_AUTO_TEST_CASE( GeneratorV1_copy_index )
{
  std::string dirname = "newone";
  auto filename = "" + dirname + "/index.html";
  auto gen_appname = "generated_appname";

  GeneratorV1 g1;
  TestableGenerator tg; // Just to test
  g1.addVariable("APPNAME", gen_appname);
  tg._removeDirectory(dirname);
  g1.setOutputDir(dirname);

  g1.generate();
  
  BOOST_REQUIRE( tg._directoryExists(dirname) );
  BOOST_REQUIRE( tg._fileExists(filename ) );
  BOOST_REQUIRE( tg._fileContains(filename, gen_appname ));
  tg._removeDirectory(dirname);
}

// Check than the copied package.json file doesn't contain APPNAME variable
BOOST_AUTO_TEST_CASE( GeneratorV1_copiedPackage_noAPPNAME )
{
  std::string dirname = "newone";
  auto filename = "" + dirname + "/package.json";
  auto gen_appname = "generated_appname";

  GeneratorV1 g1;
  TestableGenerator tg; // Just to test
  g1.addVariable("APPNAME", gen_appname);
  tg._removeDirectory(dirname);
  g1.setOutputDir(dirname);

  g1.generate();
  
  BOOST_REQUIRE( !tg._fileContains(filename, "APPNAME" ));  
  //  tg._removeDirectory(dirname);
}

/// Check that package.json file is copied and contains APPNAME replaced var
BOOST_AUTO_TEST_CASE( GeneratorV1_copy_package_json )
{
  std::string dirname = "newone";
  auto filename = "" + dirname + "/package.json";
  auto gen_appname = "generated_appname";

  GeneratorV1 g1;
  TestableGenerator tg; // Just to test
  g1.addVariable("APPNAME", gen_appname);
  tg._removeDirectory(dirname);
  g1.setOutputDir(dirname);

  g1.generate();
  
  BOOST_REQUIRE( tg._directoryExists(dirname) );
  BOOST_REQUIRE( tg._fileExists(filename ) );
  BOOST_REQUIRE( tg._fileContains(filename, gen_appname ));
  //  tg._removeDirectory(dirname);
}


