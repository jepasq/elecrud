#include "Collection.hpp"

/** \file Collection.cpp
  * The libfile's Collection class implementation.
  *
  */

/** Defines the maximum number of characters of the description we include in
 *  the oneLiner result.
 *
 */
constexpr unsigned int ONELINER_DECRIPTION_CHARS = 8;

/** Named constructor
 *
 *  Description is empty.
 *
 *  @param vName The initial name field value.
 *
 */
Collection::Collection(const FX::FXString& vName):
  name(vName)
{
}

/** Named constructor
 *
 *  @param vName The initial name field value.
 *  @param vDesc The collection description.
 *
 */
Collection::Collection(const FX::FXString& vName, const FX::FXString& vDesc):
  name(vName),
  description(vDesc)
{

}


// Needed by std::make_shared
Collection::Collection(const Collection*c)
{
  name = c->getName();
  description = c->getDescription();
}


/** Change the collection name
 *
 *  @param vName The new name field value.
 *
 */
void
Collection::setName(const FX::FXString& vName)
{
  name = vName;
}

/** Return the collection name
 *
 *  @return The name field value.
 *
 */
const FX::FXString&
Collection::getName() const
{
  return name;
}

/** Change the description value
  *
  * @param d The new collection description.
  *
  */
void
Collection::setDescription(const FX::FXString& d)
{
  description = d;
}

/** Return the current description
 *
 *  @return The description value.
 *
 */
const FX::FXString&
Collection::getDescription() const
{
  return description;
}

/** Get a single line string that represents this collection
  *
  * It may be used to be logged or to be added to the collection list UI. It may
  * include a several-chars subset of the description.
  *
  * @param d The opened dialog instance.
  *
  * @return A single string containing the collection name and at least a
  *         part of the multiline description.
  *
  */
FX::FXString
Collection::getOneLiner() const
{
  if (description.empty())
    return name;
  
  FXString ret = name;
  // Here we replace all occurences of newline char with a regular space
  // to get a one line representation
  FXString desc = description;
  desc = desc.substitute('\n', ' ');
  
  if (desc.length() > ONELINER_DECRIPTION_CHARS)
    desc = desc.trunc(5) + "...";
    
  ret += " (" + desc + ")";
  return ret;
}

/** Return the actual fields list
 *
 *  @return A reference to the list.
 *
 */
const tFieldList&
Collection::getFields() const
{
  return fields;
}

/** Check if the given field name is already used
 *
 * @param n The name to be checked.
 *
 * @return true if the string is already used as field name.
 *
 */
bool
Collection::isFieldNameInUse(const FXString& n)
{
  for (auto const& f : fields)
    if (f->getName() == n)
      return true;
  
  return false;
}

/** Append the given field
  *
  * @param f The field to be appened.
  *
  * @return The inserted shared ptr to enable chain statements.
  *
  */
std::shared_ptr<Field>
Collection::appendField(std::shared_ptr<Field> f)
{
  fields.push_back(f);
  return f;
}

/** Save the collection and all its fields to the given stream
 *
 *  @param s The stream to save the current collection to.
 *
 */
void
Collection::save(FXStream& s) const
{
  s << fields.size();
  for (auto const& f : fields)
    f->save(s);
}


void
Collection::load(FXStream& s)
{

  int fieldsNumber;
  s >> fieldsNumber;

  for (int i=0; i < fieldsNumber; ++i)
    {
      auto f = this->appendField(std::make_shared<Field>("aa"));
      f->load(s);
    }
}

