#include __FIELD_TYPE_HPP__
#define __FIELD_TYPE_HPP__

#include <fox-1.6/fx.h>

/** An abstract type used as base of all Field types
 *
 * No standard value setter here so you need to cast to use correct one.
 *
 */
class FieldType
{
public:
  /// Returns this typename to string
  FXString typeName() const=0;
  
  /// Return the internal value to string
  const FXString& toString() const=0;

};

#endif // !__FIELD_TYPE_HPP__
