#include <boost/test/unit_test.hpp>

#include "NewFieldDialog.hpp"

#include <stdexcept>

/// Should be equal to the PID so, everything but 0
BOOST_AUTO_TEST_CASE( NewFieldDialog_invalid_parent )
{
  BOOST_REQUIRE_THROW( NewFieldDialog::checkCollection(nullptr),
		       std::invalid_argument); 
}
