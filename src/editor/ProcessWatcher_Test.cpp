#include <boost/test/unit_test.hpp>

#include "ProcessWatcher.hpp"

/// Should be equal to the PID so, everything but 0
BOOST_AUTO_TEST_CASE( ProcessWatcher_instantiate )
{
  ProcessWatcher pw;
  auto ret = pw.fork_process("ls -h");
  BOOST_REQUIRE_NE( ret, 0); 
}
