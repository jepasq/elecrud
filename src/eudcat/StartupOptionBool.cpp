#include "StartupOptionBool.hpp"

/** Constructor with given default value
  *
  * \param v The initial default value.
  *
  */
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

/** Get the underlying boolean value
  *
  * \return The value as boolean.
  *
  */
bool
StartupOptionBool::getValue() const
{
  return value;
}

/** Get the underlying type
  *
  * \return The type.
  *
  */
StartupOptionType
StartupOptionBool::getType() const
{
  return type;
}
