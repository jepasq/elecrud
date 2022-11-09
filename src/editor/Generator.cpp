#include "Generator.hpp"

#include <sys/types.h>
#include <sys/stat.h>

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

bool
Generator::directoryExists(const std::string& dir)
{
  // From https://stackoverflow.com/a/18101042
  struct stat info;

  auto pathname = dir.c_str();
  
  if( stat( pathname, &info ) != 0 )
    printf( "cannot access %s\n", pathname );
  else if( info.st_mode & S_IFDIR )
    {
      printf( "%s is a directory\n", pathname );
      return true;
    }
  else
    printf( "%s is no directory\n", pathname );

  return false;
}

void
Generator::createDirectory(const std::string&)
{

}

void
Generator::removeDirectory(const std::string&)
{

}
