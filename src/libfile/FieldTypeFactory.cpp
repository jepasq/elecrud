#include "FieldTypeFactory.hpp"

#include "FieldType.hpp"
#include "ftInt.hpp"

FieldTypeFactory::FieldTypeFactory()
{
  
  //types.emplace(std::make_pair("int", new FieldTypeInt()));
  registerTypeInstance(new FieldTypeInt());
}

void
FieldTypeFactory::registerTypeInstance(FieldType* t)
{
  types[t->typeName()] = std::unique_ptr<FieldType>(t);
}

