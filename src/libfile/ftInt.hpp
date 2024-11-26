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
  virtual std::string typeName() const override;
  
  /// Return the internal value to string
  virtual const FXString& toString() const override;

  virtual FieldType* newInstance() const override;
  
private:

  int mValue;   // The internal value
};

#endif // !__FIELD_TYPE_INT_HPP__
