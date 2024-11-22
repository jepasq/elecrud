#include "Collection.hpp"

/** Defines the maximum number of characters of the description we include in
 *  the oneLiner result.
 *
 */
constexpr unsigned int ONELINER_DECRIPTION_CHARS = 8;

/** Named constructor
 *
 *  @param vName The initial name field value.
 *
 */
Collection::Collection(const FX::FXString& vName):
  name(vName)
{
}

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

