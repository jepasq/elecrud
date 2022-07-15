#include "ProjectFile.hpp"


ProjectFile::ProjectFile():
  filename()
{

}

const std::string&
ProjectFile::getFilename() const
{
  return filename;
}
