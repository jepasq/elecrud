#ifndef __FIELD_TYPE_INT_HPP__
#define __FIELD_TYPE_INT_HPP__

#include <fox-1.6/fx.h>

#include <string>

#include "FieldType.hpp"

/** A column type that handle Integer type
 *
 */
class FieldTypeInt : public FieldType
{
public:
  /// Returns this typename to string
  std::string typeName() const;
  
  /// Return the internal value to string
  const FXString& toString() const;
private:

  int mValue;   // The internal value
};

#endif // !__FIELD_TYPE_INT_HPP__
