#include "Field.hpp"

#include <stdexcept>

#include "FieldType.hpp"
#include "FieldTypeFactory.hpp"

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

/** Save this field to the given stream
 *
 */
void
Field::save(FXStream& s) const
{
  if (s.direction() != FXStreamSave)
    throw std::invalid_argument("Stream in wrong direction to save() field");
  
  s << name;
  s << description;
  if (type == nullptr)
    s << FXString("null");
  else
    s << FXString(type->typeName().c_str());
  /*
    {
      FXString fxs(type->typeName().c_str());
      std::cout << "------> FXString: " << fxs.text() << std::endl;
      s << fxs;
    }
  */
  
}

/** Load and override this field's member from the given stream
 *
 */
void
Field::load(FXStream& s)
{
  if (s.direction() != FXStreamLoad)
    throw std::invalid_argument("Stream in wrong direction to load() field");

  FXString typestr;
  
  s >> name;
  s >> description;

  s >> typestr;

  if (typestr == "null")
    type = nullptr;
  else
    {
      FieldTypeFactory ftf;
      type = ftf.newInstance(typestr.text());
    }
}

/** Get a const pointer to the FieldType instance
 *
 * @return A pointer to the type. May be nullptr.
 *
 */
const FieldType*
Field::getType() const
{
  return type;
}
