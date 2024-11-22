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
