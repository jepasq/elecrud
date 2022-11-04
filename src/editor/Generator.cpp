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

/** Change the current outputDir member to new one
  *
  * \param nod The new output dir set without any check.
  *
  */
void
Generator::setOutputDir(const std::string& nod)
{
  this->outputDir = nod;
}
