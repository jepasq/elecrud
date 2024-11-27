#include "ftInt.hpp"

#include <FXString.h>

FieldTypeInt::FieldTypeInt():
  mValue(0)
{

}

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
  
/// Return the internal value to string
FXString
FieldTypeInt::toString() const
{
  // Second arg to FXString::value can be the base (default to 10)
  return FXStringVal(mValue);
}

FieldType*
FieldTypeInt::newInstance() const
{
  return new FieldTypeInt();
}

void
FieldTypeInt::setValue(int val)
{
  mValue = val;
}

int
FieldTypeInt::getValue()
{
  return mValue;
}

