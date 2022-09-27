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
  * \param fn The new filename as a std string.
  *
  */
void
ProjectFile::setFilename(const std::string& fn)
{
  filename = fn;
}


/** Get the current filename of this project
  *
  * \return  The current filename.
  *
  */
const std::string&
ProjectFile::getFilename() const
{
  return filename;
}

/** Set the current filename from a FXString
  *
  * \param fn The new filename as a std string.
  *
  */
void
ProjectFile::setFilename(const FX::FXString& fn)
{
  std::string s(fn.text());
  filename = s;
}

void
ProjectFile::setFilename(const char* fn)
{
  std::string s(fn);
  filename = s;
}


/** Save the project file as a current set filename
  *
  */
void
ProjectFile::save()
{

}

