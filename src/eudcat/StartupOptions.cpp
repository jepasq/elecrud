/** \file StartupOptions.cpp
  * The command line arguments handling class implementation.
  *
  */

#include "StartupOptions.hpp"

#include "IncompatibleArguments.hpp"

#include <algorithm>   // USES std::find()

/** Default constructor
  *
  */
StartupOptions::StartupOptions():
  printAll(true),
  printHelp(false),
  printSet(false)
{

}

/** Check if the selected options are compatible
  *
  * \return true if all options are compatible and the execution can continue.
  *
  */
bool
StartupOptions::check()
{
  return true;
}

/** Usesd to test the existance of two versions of the same item in the list
  *
  *
  *
  */
bool
StartupOptions::contains(tStringList& l, const std::string& s1,
			 const std::string& s2) const
{
  if (std::find(l.begin(), l.end(), s1) != l.end())
    {
      l.remove(s1);
      return true;
    }

  if (std::find(l.begin(), l.end(), s2) != l.end())
    {
      l.remove(s2);
      return true;
    }

  return false;
}


/** Modify the given arg list and set current instance's attributes
  *
  * Will modify the given list. Will remove the first element known as progname.
  *
  * It will not handle char** so you need to create a tStringList based on it.
  *
  */
void
StartupOptions::consume(tStringList& argv)
{
  // Removes the first element : always the progname
  argv.pop_front();
  if (contains(argv, "-h", "--help"))
      printHelp = true;

  if (contains(argv, "-a", "--all"))
    printAll = true;

  if (contains(argv, "-s", "--set"))
    {
      printSet = true;
      printAll = false; // Removes the default printAll flag
    }
  
  if (printAll && printSet)
    throw IncompatibleArguments("--set et --all are mutually exclusive arguments");
}

