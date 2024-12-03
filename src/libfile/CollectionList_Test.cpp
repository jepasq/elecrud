#include <boost/test/unit_test.hpp>

#include "Collection.hpp"
#include "CollectionList.hpp"

#include <memory>  // USES shared_ptr

using namespace std;

/// Creating an empty list
BOOST_AUTO_TEST_CASE( Collection_size_0 )
{
  CollectionList cl;
  BOOST_REQUIRE( cl.size() == 0 );
}

/// Creating an empty list
BOOST_AUTO_TEST_CASE( Collection_push_back )
{
  CollectionList cl;
  Collection c("namecoll1");
  cl.push_back(make_shared<Collection>(c));
  BOOST_REQUIRE( cl.size() == 1 );

  cl.push_back(make_shared<Collection>("name2"));
  BOOST_REQUIRE( cl.size() == 2 );
}

/// Adding the same collection name twice
BOOST_AUTO_TEST_CASE( Collection_name_collision )
{
  CollectionList cl;
  Collection c("name1");
  cl.push_back(make_shared<Collection>(c));
  BOOST_REQUIRE(cl.isNameInUse("name1"));
  BOOST_REQUIRE(!cl.isNameInUse("name2"));
}

