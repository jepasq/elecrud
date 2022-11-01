#include "Generator.hpp"

Generator::Generator():
  outputDir()
{
  
}

Generator::~Generator()
{
  
}

const std::string&
Generator::getOutputDir() const
{
  return outputDir;
}
