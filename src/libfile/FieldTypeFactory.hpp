#ifndef __FIELD_TYPE_FACTORY_HPP__
#define __FIELD_TYPE_FACTORY_HPP__

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <fox-1.6/fx.h>

// Forward declaration
class FieldType;
// Enf of forward declaration

/** A factory used to register new field types and create new instances
 *
 * The factory will internally use a name/type map to identify registered
 * types. You can then create a new FieldType instance with the newInstance
 * function, calling this function with a string parameter representing its
 * type.
 *
 */
class FieldTypeFactory
{
public:
  FieldTypeFactory();
  ~FieldTypeFactory();

  FieldType* newInstance(const std::string&);

  std::vector<std::string> getKeys() const;
  
protected:
  void registerTypeInstance(FieldType*);
  
private:
  // Based on https://stackoverflow.com/a/23516768
  /// I have issues usin FXString as key
  std::map<std::string, std::unique_ptr<FieldType>> types;  
};

#endif // !__FIELD_TYPE_FACTORY_HPP__

