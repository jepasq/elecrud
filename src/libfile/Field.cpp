#include "Field.hpp"

#include <stdexcept>

#include "FieldType.hpp"

Field::Field(const FXString& vName):
  type(nullptr)
{
  setName(vName);
}

const FXString&
Field::getName() const
{
  return name;
}

void
Field::setName(const FXString& n)
{
  if (n.empty())
    throw std::invalid_argument("New Field name can't be empty");
  
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

void
Field::setType(FieldType* t)
{
  type = t;
}



FX::FXString
Field::getOneLiner() const
{
  FXString t = "";

  if (type)
    {
      t = FXString(type->typeName().c_str()).trunc(3);
      t += " ";
    }

  t += name;

  if (!description.empty())
    {
      t+= " (" + description + ")";

    }
    
  return t;
}


