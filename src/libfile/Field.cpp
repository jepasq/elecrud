#include "Field.hpp"

#include <stdexcept>

#include "FieldType.hpp"
#include "FieldTypeFactory.hpp"

/** A null-type named constructor
 *
 * The intername type will be set to nullptr.
 *
 *  @param vName The type name.
 *
 */
Field::Field(const FXString& vName):
  type(nullptr)
{
  setName(vName);
}

/** Return the type name
 *
 *  @return The name as FXString.
 *
 */
const FXString&
Field::getName() const
{
  return name;
}

/** Change the current name
 *
 * @param n The new name to assign to the Field.
 * @throw std::invalid_argument Thrown if the new name is empty. 
 *
 */
void
Field::setName(const FXString& n)
{
  if (n.empty())
    throw std::invalid_argument("New Field name can't be empty");
  
  name = n;
}

/** Change the current description
 *
 * The new description can be an empty string.
 *
 * @param d The new description.
 *
 */
void
Field::setDescription(const FXString& d)
{
  description = d;
}

/**
 * @brief Retrieves the description of the Field.
 *
 * This method returns the description of the Field object.
 *
 * @return const FXString& The description of the Field.
 */
const FXString&
Field::getDescription() const
{
  return description;
}

/**
 * @brief Sets the type of the Field.
 *
 * This method assigns a new type to the Field object.
 *
 * @param t The new type to assign to the Field.
 */
void Field::setType(FieldType* t) {
  type = t;
}

/**
 * @brief Retrieves a one-line summary of the Field.
 *
 * This method returns a one-line summary of the Field, including its type
 * abbreviation, name, and optionally its description if it is not empty.
 *
 * @return FX::FXString A one-line summary of the Field.
 *
 */
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

  if (typestr == "null" || typestr.empty())
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
