#include <boost/test/unit_test.hpp>

#include "GeneratorV1.hpp"
#include "TestableGenerator.hpp"

BOOST_AUTO_TEST_CASE( GeneratorV1_can_be_instantiated )
{
  auto tg = new GeneratorV1();
  BOOST_REQUIRE_NE( tg, nullptr);
  delete tg;
}

/// Copy index.html in the 
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
}
