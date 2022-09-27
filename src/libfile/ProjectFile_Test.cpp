#include <boost/test/unit_test.hpp>

#include "ProjectFile.hpp"

#include <fstream>

// From https://stackoverflow.com/a/19841704
bool is_file_exist(const FX::FXString& filename)
{
  std::ifstream infile(filename.text());
  return infile.good();
}


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
  BOOST_REQUIRE_EQUAL( false, true );

  ProjectFile pf;
  pf.setFilename("");
  // If filename is empty, must throw an exception
  BOOST_REQUIRE_THROW(pf.save(), std::exception);

  // But if filename is not empty, it should work
  FXString fn = "test.eud";
  pf.setFilename(fn);
  pf.save();
  BOOST_REQUIRE_EQUAL( is_file_exist(fn), true );
}
