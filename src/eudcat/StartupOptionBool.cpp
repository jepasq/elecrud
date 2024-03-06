#include "StartupOptionBool.hpp"

StartupOptionBool::StartupOptionBool(bool v):
  type(SOT_DEFAULT),
  value(v)
{
  
}

/** Change the value and set the type to Manual
  *
  * \param v The new value.
  *
  */
void
StartupOptionBool::setValue(bool v)
{
  type=SOT_MANUAL;
  value = v;
}

bool
StartupOptionBool::getValue() const
{
  return value;
}

StartupOptionType
StartupOptionBool::getType() const
{
  return type;
}
