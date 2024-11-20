#include "Collection.hpp"

/** Named constructor
 *
 *  @param vName The initial name field value.
 *
 */
Collection::Collection(const FX::FXString& vName)
{
  name = vName;
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

