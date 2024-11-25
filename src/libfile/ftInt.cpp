#include "ftInt.hpp"

#include <FXString.h>

/// Returns this typename to string
FXString
FieldTypeInt::typeName() const
{
  return "integer";
}
  
/// Return the internal value to string
const FXString&
FieldTypeInt::toString() const
{
  // Second arg to FXString::value can be the base (default to 10)
  ///  return FX::FXString::value(mValue);
}
