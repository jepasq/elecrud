#include "CollectionList.hpp"

using namespace std;

size_t
CollectionList::size() const
{
  return collections.size();
}

void
CollectionList::push_back(Collection* c)
{
  collections.push_back(make_shared<Collection>(c));
}

bool
CollectionList::isNameInUse(const FXString&) const
{
  return false;
}
