#include "ftInt.hpp"

#include <FXString.h>

/** Default constructor
 *
 * Internal value is set to 0.
 *
 */
FieldTypeInt::FieldTypeInt():
  mValue(0)
{

}

/** Value-based constructor
 *
 * Internal value is set tothe given value.
 *
 * @param val The integer value to set the internal value to.
 *
 */
FieldTypeInt::FieldTypeInt(int val):
  mValue(val)
{

}

/// Returns this typename to string
std::string
FieldTypeInt::typeName() const
{
  return "integer";
}
  
/** Return the internal value to string
 *
 * @return The value as FX string.
 *
 */
FXString
FieldTypeInt::toString() const
{
  // Second arg to FXString::value can be the base (default to 10)
  return FXStringVal(mValue);
}

/** Return a new instance of the same type
 *
 * @return A new FieldTypeInt.
 *
 */
FieldType*
FieldTypeInt::newInstance() const
{
  return new FieldTypeInt();
}

/** Change the internal value
 *
 *  @param val The new internal value.
 *
 */
void
FieldTypeInt::setValue(int val)
{
  mValue = val;
}

/** Get the internal value
 *
 * @return The internal integer value.
 *
 */
int
FieldTypeInt::getValue()
{
  return mValue;
}

