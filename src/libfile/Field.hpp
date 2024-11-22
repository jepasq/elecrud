#ifndef __FIELD_HPP__
#define __FIELD_HPP__

#include <fox-1.6/fx.h>

typedef int FieldType;

/** A field (also called a column in a database context) with a name and a type
 *
 * A Collection typically consists of multiple fields.
 *
 */
class Field
{
public:
  Field(const FXString&);

  const FXString& getName() const;
  
private:
  /** The unique name of this field
   *
   */
  FXString name;
  /** The type of this field. May come froms a factory
   *
   */
  FieldType* type;
};

#endif // !__FIELD_HPP__

