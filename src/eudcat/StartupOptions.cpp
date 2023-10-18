
#include "StartupOptions.hpp"

StartupOptions::StartupOptions():
  printAll(true),
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
}

