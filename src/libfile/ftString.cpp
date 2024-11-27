#include "ftString.hpp"

FieldTypeString::FieldTypeString():
  mValue("")
{

}

FieldTypeString::FieldTypeString(const FXString& val):
  mValue(val)
{

}

FieldTypeString::~FieldTypeString()
{

}

std::string
FieldTypeString::typeName() const
{
  return mValue.text();
}
  
FXString
FieldTypeString::toString() const
{
  return mValue;
}

FieldType*
FieldTypeString::newInstance() const
{
  return new FieldTypeString();
}
