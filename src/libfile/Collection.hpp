#ifndef __COLLECTION_HPP__
#define __COLLECTION_HPP__

#include <fox-1.6/fx.h>

#include <vector>

// TODO: replace witrh a real class xD
typedef int Field; //!< A collection field, with type and name at least

/** A collection is the definition of an ordered collection of fields
 *
 * This can become a database table or a mongodb collection.
 * Trying to work directly with FX types to avoid constant casts.
 *
 */
class Collection
{
public:
  Collection(const FX::FXString&);

  void                setName(const FX::FXString&);
  const FX::FXString& getName() const;

  void                setDescription(const FX::FXString&);
  const FX::FXString& getDescription() const;

private:
  FX::FXString       name;        //!< The collection name
  FX::FXString       description; //!< An optional multiline description
  std::vector<Field> fields; //!< The list of fields for this collection
};

#endif // !__COLLECTION_HPP__


