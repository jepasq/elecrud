#ifndef __COLLECTION_LIST_HPP__
#define __COLLECTION_LIST_HPP__

#include <vector> // USES std::vector
#include <memory> // USES shared_ptr

#include "Collection.hpp"

class CollectionList
{
public:
  size_t size() const;

  void push_back(Collection*);
  
private:
  // Trying with a vector so we can size to the nitem number it at load
  std::vector<std::shared_ptr<Collection>> collections;
};

#endif // !__COLLECTION_LIST_HPP__