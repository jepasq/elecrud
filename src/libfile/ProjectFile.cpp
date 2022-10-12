#include "ProjectFile.hpp"

#include <stdexcept>  // USES runtime_error
#include <FXFileStream.h>

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

/** Set the current filename (const char version)
  *
  * \param fn The new filename as a C string.
  *
  */
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
  if (filename.empty())
    throw std::runtime_error("Can't save project file with empty filename");
  else
    {
      FXString fna(filename.c_str());
      FXFileStream s;
      s.open(fna, FXStreamSave);
      s << FXString("test");
      s.close();
    }
}

