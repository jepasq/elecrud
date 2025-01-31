#ifndef __FIELD_TYPE_STRING_HPP__
#define __FIELD_TYPE_STRING_HPP__

#include <fox-1.6/fx.h>

#include <string>

#include "FieldType.hpp"

/** A column type that handle a String type
 *
 */
class FieldTypeString : public FieldType
{
public:
  FieldTypeString();
  FieldTypeString(const FXString&);

  virtual ~FieldTypeString();

  
  void setValue(const FXString&);
  FXString  getValue();
    
  /// Returns this typename to string
  virtual std::string typeName() const override;
  
  /// Return the internal value to string
  virtual FXString toString() const override;

  virtual FieldType* newInstance() const override;
  
private:
  FXString mValue;   //!< The internal stored value
};

#endif // !__FIELD_TYPE_STRING_HPP__
