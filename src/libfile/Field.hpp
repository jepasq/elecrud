#ifndef __FIELD_HPP__
#define __FIELD_HPP__

#include <fox-1.6/fx.h>

// Forward declatations
class FieldType;
// End of forward declatations

/** A field (also called a column in a database context) with a name and a type
 *
 * A Collection typically consists of multiple fields.
 *
 */
class Field
{
public:
  Field(const FXString&);

  void  setName(const FXString&);
  const FXString& getName() const;

  void  setDescription(const FXString&);
  const FXString& getDescription() const;

  void setType(FieldType*);
  
  
  FX::FXString getOneLiner() const;
  
private:
  /** The unique name of this field. Can't be empty.
   *
   */
  FXString name;

  /** The, eventually multiline, field description.
   *
   */
  FXString description;

  /** The type of this field. May come froms a factory
   *
   */
  FieldType* type;
};

#endif // !__FIELD_HPP__

