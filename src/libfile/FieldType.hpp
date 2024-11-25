#ifndef __FIELD_TYPE_HPP__
#define __FIELD_TYPE_HPP__

#include <string>

#include <fox-1.6/fx.h>

/** An abstract type used as base of all Field types
 *
 * No standard value setter here so you need to cast to use correct one.
 *
 */
class FieldType
{
public:
  /// Returns this typename as string to be the first map argument in lower case
  virtual std::string typeName() const=0;
  
  /// Return the internal value to string
  virtual const FXString& toString() const=0;

};

#endif // !__FIELD_TYPE_HPP__
