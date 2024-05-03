#include <boost/test/unit_test.hpp>

#include "ProcessWatcher.hpp"

BOOST_AUTO_TEST_CASE( ProcessWatcher_instantiate )
{
  ProcessWatcher pw;
  auto ret = pw.fork_process("ls -h");
  BOOST_REQUIRE_EQUAL( ret, 0);

}
