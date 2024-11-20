#include "CollectionList.hpp"

using namespace std;

/** Returns the size of the collection
  *
  * @return The size in number of elements of the container.
  *
  */
size_t
CollectionList::size() const
{
  return collections.size();
}

/** Add the given collection to the end of the collection
  *
  * @param c The  collection object to be added.
  *
  */
void
CollectionList::push_back(Collection* c)
{
  collections.push_back(make_shared<Collection>(c));
}

/** Is the given collection name already in use ?
 *
 *  It is used to check if a to-be-added collection name is unique.
 *
 *  @param vName The collection name to be tested.
 *
 */
bool
CollectionList::isNameInUse(const FXString& vName) const
{
  for (auto c : collections)
    if (c->getName() == vName)
      return true;
  
  return false;
}
