#ifndef __COLLECTION_HPP__
#define __COLLECTION_HPP__

/** \file Collection.hpp
  * The libfile's Collection class header.
  *
  */

#include <fox-1.6/fx.h>

#include <vector>
#include <memory>

#include "Field.hpp"

typedef std::vector<std::shared_ptr<Field>> tFieldList;

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
  Collection(const FX::FXString&, const FX::FXString&);
  Collection(const Collection*);

  void                setName(const FX::FXString&);
  const FX::FXString& getName() const;

  void                setDescription(const FX::FXString&);
  const FX::FXString& getDescription() const;

  FX::FXString      getOneLiner() const;
  
  void              appendField(std::shared_ptr<Field>);
  const tFieldList& getFields() const;
  bool              isFieldNameInUse(const FXString&);

  void save(FXStream&) const;
  void load(FXStream&);
  
private:
  FX::FXString       name;        //!< The collection name
  FX::FXString       description; //!< An optional multiline description
  tFieldList fields; //!< The list of fields for this collection
};

#endif // !__COLLECTION_HPP__


