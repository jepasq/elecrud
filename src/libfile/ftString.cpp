#include "ftString.hpp"

/** Create a field type with empty string value
 *
 */
FieldTypeString::FieldTypeString():
  mValue("")
{

}

/** Create a field type with the given string value
 *
 *  @param val The string value.
 *
 */
FieldTypeString::FieldTypeString(const FXString& val):
  mValue(val)
{

}

/// The field destructor
FieldTypeString::~FieldTypeString()
{

}

/** Return this type typebname as a string
 *
 * @return Always return the string 'string'.
 *
 */
std::string
FieldTypeString::typeName() const
{
  return "string";
}

/** Return the current type value as a string
 *
 *  @return The actual string.
 *
 */
FXString
FieldTypeString::toString() const
{
  return mValue;
}

/** Return a new instance of itself
 *
 *  @return A new instance as a FieldType abstract/generic class.
 *
 */
FieldType*
FieldTypeString::newInstance() const
{
  return new FieldTypeString();
}

/** Change the current value
 *
 *  @param v The new string.
 *
 */
void
FieldTypeString::setValue(const FXString& v)
{
  mValue = v;
}

/** Change the current value
 *
 *  @return The current value as string.
 *
 */
FXString
FieldTypeString::getValue()
{
  return mValue;
}

