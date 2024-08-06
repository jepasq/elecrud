#include <boost/test/unit_test.hpp>

#include "ProcessWatcher.hpp"

/// Should be equal to the PID so, everything but 0
BOOST_AUTO_TEST_CASE( ProcessWatcher_instantiate )
{
  ProcessWatcher pw;
  auto ret = pw.forkProcess("/usr/bin/ls");
  BOOST_REQUIRE_NE( ret, 0); 
}

/// It seems it can fail, thinking the full command including args is
/// interpreted as the command filename
BOOST_AUTO_TEST_CASE( ProcessWatcher_fork_with_args )
{
  ProcessWatcher pw;
  auto ret = pw.forkProcess("/usr/bin/ls", "-lh");
  BOOST_REQUIRE_NE( ret, 0); 
}

