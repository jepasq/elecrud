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
