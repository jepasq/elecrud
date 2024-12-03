#include "Field.hpp"

Field::Field(const FXString& vName):
  name(vName),
  
  type(nullptr)
{

}

const FXString&
Field::getName() const
{
  return name;
}

void
Field::setName(const FXString& n)
{
  name = n;
}

void
Field::setDescription(const FXString& d)
{
  description = d;
}

const FXString&
Field::getDescription() const
{
  return description;
}


FX::FXString
Field::getOneLiner() const
{
  return "";
}
