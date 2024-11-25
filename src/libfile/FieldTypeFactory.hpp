#ifndef __FIELD_TYPE_FACTORY_HPP__
#define __FIELD_TYPE_FACTORY_HPP__

#include <map>
#include <string>

#include <fox-1.6/fx.h>

// Forward declaration
class FieldType;
// Enf of forward declaration

class FieldTypeFactory
{
public:
  FieldTypeFactory();

private:
  /// I have issues usin FXString as key
  std::map<std::string, FieldType*> types;
};

#endif // !__FIELD_TYPE_FACTORY_HPP__

