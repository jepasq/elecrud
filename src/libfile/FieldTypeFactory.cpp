#include "FieldTypeFactory.hpp"

#include "FieldType.hpp"
#include "ftInt.hpp"

FieldTypeFactory::FieldTypeFactory()
{
  
  //  types.emplace(std::make_pair("int", new FieldTypeInt()));
  registerTypeInstance(new FieldTypeInt());
}

// Needed to avoid "error-invalid-application-of-sizeof-to-an-incomplete-type"
// error
FieldTypeFactory::~FieldTypeFactory()
{

}


void
FieldTypeFactory::registerTypeInstance(FieldType* t)
{
  types[t->typeName()] = std::unique_ptr<FieldType>(t);
}

