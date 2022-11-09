#include <boost/test/unit_test.hpp>

#include "Generator.hpp"

#include <string>

/// Used to instantiate and test the abstract Generator class
class TestableGenerator : public Generator {

public:
  void generate(){};

  bool _directoryExists(const std::string&d){ return directoryExists(d); } 
  void _createDirectory(const std::string&d){ createDirectory(d); } 
  void _removeDirectory(const std::string&d){ removeDirectory(d); } 

  
};

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
