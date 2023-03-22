#include <boost/test/unit_test.hpp>

#include "ProjectFile.hpp"

BOOST_AUTO_TEST_CASE( ProjectFile_empty_filename )
{
  ProjectFile pf;
  auto fn = pf.getFilename();
  BOOST_REQUIRE_EQUAL( fn.empty(), true );
}

BOOST_AUTO_TEST_CASE( ProjectFile_setFilename )
{
  ProjectFile pf;
  std::string nf = "newName";
  pf.setFilename(nf);
  auto fn = pf.getFilename();
  BOOST_REQUIRE_EQUAL( fn.empty(), false );
  BOOST_REQUIRE_EQUAL( fn, nf );
}

BOOST_AUTO_TEST_CASE( ProjectFile_has_FXString_filename_setter )
{
  ProjectFile pf;
  FX::FXString nf = "newName";
  pf.setFilename(nf);
  auto fn = pf.getFilename();
  BOOST_REQUIRE_EQUAL( fn.empty(), false );
  //  BOOST_REQUIRE_EQUAL( fn, nf );
}

BOOST_AUTO_TEST_CASE( ProjectFile_has_save_function )
{
  ProjectFile pf;
  pf.setFilename("");
  // If filename is empty, must throw an exception
  BOOST_REQUIRE_THROW(pf.save(), std::exception);

  // But if filename is not empty, it should work
  FXString fn = "test.eud";
  pf.setFilename(fn);
  pf.save();
  BOOST_REQUIRE_EQUAL( file_exists(fn), true );
}

BOOST_AUTO_TEST_CASE( ProjectFile_has_load_function )
{
  ProjectFile pf;
  pf.setFilename("");
  // If filename is empty, must throw an exception
  BOOST_REQUIRE_THROW(pf.load(), std::exception);

  // But if filename is not empty, it should work
  FXString fn = "test_THAT_DOESNT_EXIST.eud";
  pf.setFilename(fn);
  // If filename doesn't exist , must throw an exception
  BOOST_REQUIRE_THROW(pf.load(), std::exception);

  // Finally!!!
  FXString fn2 = "test.eud";
  pf.setFilename(fn2);
  pf.load();
}

BOOST_AUTO_TEST_CASE( ProjectFile_has_dirty_flag )
{
  ProjectFile pf;
  // False by default
  BOOST_REQUIRE_EQUAL( pf.isDirty(), false );

  pf.setDirty(true);
  BOOST_REQUIRE_EQUAL( pf.isDirty(), true );
}
