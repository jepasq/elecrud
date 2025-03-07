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
CollectionList::push_back(std::shared_ptr<Collection> c)
{
  collections.push_back(c);
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

/** Get the collection at a given index
 *
 * @param pos The index of the Collection to get
 *
 * @return A shared_ptr to a Collection object if in range
 *
 * @throws std::out_of_range If the given position is out of the
 *   collection list bounds
 *
 */
std::shared_ptr<Collection>
CollectionList::at(size_t pos) const
{
  return collections.at(pos);
}
