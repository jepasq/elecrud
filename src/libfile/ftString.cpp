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
  return "string";
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
