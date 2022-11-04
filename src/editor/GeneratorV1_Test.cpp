#include <boost/test/unit_test.hpp>

#include "GeneratorV1.hpp"

BOOST_AUTO_TEST_CASE( TestableGeneratorV1_can_be_instantiated )
{
  auto tg = new GeneratorV1();
  BOOST_REQUIRE_NE( tg, nullptr);
  delete tg;
}
