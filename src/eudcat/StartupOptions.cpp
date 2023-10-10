
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
