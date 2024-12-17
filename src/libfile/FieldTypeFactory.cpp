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
  types[t->typeName()] = std::unique_ptr<FieldType>(t);
}

FieldType*
FieldTypeFactory::newInstance(const string& typen)
{
  // Can't use a temporary pointer here to check for nullity because of the use
  // of unique_ptr
  if (types[typen] == nullptr)
    throw invalid_argument("Can't find type with name " + typen);
  
  return types[typen]->newInstance();
}

std::vector<std::string>
FieldTypeFactory::getKeys() const
{
  std::vector<string> vkeys;
  vkeys.reserve(types.size());
  for(auto const& item: types)
    vkeys.push_back(item.first);

  return vkeys;
}
