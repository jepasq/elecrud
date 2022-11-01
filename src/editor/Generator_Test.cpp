#include <boost/test/unit_test.hpp>

#include "Generator.hpp"

#include <string>

/// Used to instantiate and test the abstract Generator class
class TestableGenerator : public Generator {

public:
  void generate(){};
  
};

BOOST_AUTO_TEST_CASE( TestaableGenerator_can_be_instantiated )
{
  TestableGenerator* tg = new TestableGenerator();
  BOOST_REQUIRE_NE( tg, nullptr);
  delete tg;
}

BOOST_AUTO_TEST_CASE( TestaableGenerator_get_output_dir )
{
  TestableGenerator tg;
  BOOST_REQUIRE( tg.getOutputDir().empty());
}