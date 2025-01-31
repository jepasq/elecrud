#include "FieldTypeFactory.hpp"

#include "FieldType.hpp"

#include "ftInt.hpp"
#include "ftString.hpp"

#include <stdexcept>


using namespace std;

/** Factory creator
 *
 * Also register default types.
 *
 */
FieldTypeFactory::FieldTypeFactory()
{  
  registerTypeInstance(new FieldTypeInt());
  registerTypeInstance(new FieldTypeString());
}

/** The factory destructor
 *
 * Needed to avoid "error-invalid-application-of-sizeof-to-an-incomplete-type"
 * error.
 *
 */
FieldTypeFactory::~FieldTypeFactory()
{

}

/** Register a new fieldType
  *
  * The field typename will be used as map key.
  *
  */
void
FieldTypeFactory::registerTypeInstance(FieldType* t)
{
  if (t->typeName().empty())
    throw invalid_argument("Can't register a new FieldType with empty name");
  
  types[t->typeName()] = std::unique_ptr<FieldType>(t);
}

/**
 * @brief Creates a new instance of FieldType based on the given type name.
 *
 * This function creates a new instance of FieldType. If the type name is
 * empty or not found in the types map, it throws an invalid_argument
 * exception.
 *
 * @param typen The name of the FieldType to create.
 * @return A pointer to the new FieldType instance.
 * @throws std::invalid_argument if the type name is empty or not found.
 *
 */
FieldType*
FieldTypeFactory::newInstance(const string& typen)
{
  if (typen.empty())
    throw invalid_argument("Can't instantiate FieldType with empty name");

  // Can't use a temporary pointer here to check for nullity because of the use
  // of unique_ptr
  if (types[typen] == nullptr)
    throw invalid_argument("Can't find type with name '" + typen + "'");
  
  return types[typen]->newInstance();
}

/** Return all keys in a new vector
 *
 * The internally registered types are stored in a string,type map. This
 * function is used to retrieve all string keys.
 *
 * @return A newly created vector.
 *
 */
std::vector<std::string>
FieldTypeFactory::getKeys() const
{
  std::vector<string> vkeys;
  vkeys.reserve(types.size());
  for(auto const& item: types)
    vkeys.push_back(item.first);

  return vkeys;
}
