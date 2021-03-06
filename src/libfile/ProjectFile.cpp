#include "ProjectFile.hpp"

/** The default constructor
  *
  * This sets the project filename to an empty string.
  *
  */
ProjectFile::ProjectFile():
  filename()
{

}

/** Set the current filename
  *
  * \param fn The new filename.
  *
  */
void
ProjectFile::setFilename(const std::string& fn)
{
  filename = fn;
}


/** Get the current filename of this project
  *
  */
const std::string&
ProjectFile::getFilename() const
{
  return filename;
}
