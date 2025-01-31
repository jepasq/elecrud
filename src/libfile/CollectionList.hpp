#ifndef __COLLECTION_LIST_HPP__
#define __COLLECTION_LIST_HPP__

/** \file CollectionList.hpp
  * The CollectionList class header.
  *
  */

#include <vector> // USES std::vector
#include <memory> // USES shared_ptr

#include "Collection.hpp"

/** A list (or vector) of collections (or tables) as shown in the editor
 *
 * You can check if a name is unique using isNameInUse() function.
 *
 * Note: You can't use range-based loop on this, please use legacy for loop
 * with the at() function.
 *
 */
class CollectionList
{
public:
  size_t size() const;

  void push_back(std::shared_ptr<Collection>);
  /*
  //Removes cause it leaks memory if raw pointer is later deleted
  void push_back(Collection*);  */

  std::shared_ptr<Collection> at(size_t) const;
  
  bool isNameInUse(const FXString&) const;
  
private:
  // Trying with a vector so we can size to the nitem number it at load
  std::vector<std::shared_ptr<Collection>> collections;
};

#endif // !__COLLECTION_LIST_HPP__
