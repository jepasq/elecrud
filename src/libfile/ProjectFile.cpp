#include "ProjectFile.hpp"

#include <stdexcept>  // USES runtime_error
#include <FXFileStream.h>

#include <iostream> // MAY USE cout, endl

bool
file_exists(const FX::FXString& filename)
{
  // Can't hardly call the std::string version without a "call of overloaded"
  // "'***' is ambiguous error
  std::ifstream infile(filename.text());
  return infile.good();
}

bool
file_exists(const std::string& filename)
{
  std::ifstream infile(filename);
  return infile.good();
}


/** The default constructor
  *
  * This sets the project filename to an empty string.
  *
  */
ProjectFile::ProjectFile():
  filename(),
  dirty(false)
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
      s << FXString(projectName.c_str());
      s << FXString(projectAuthor.c_str());
      s << FXString(generatorFilename.c_str());
      s.close();
    }
}

/** Load the project file from the file previously set with setFilename()
  *
  */
void
ProjectFile::load()
{
  if (filename.empty())
    throw std::runtime_error("Can't load a project file with empty filename");
  else if (!file_exists(filename))
    throw std::runtime_error("Can't load a project file that doesn't exist");
  else
    {
      std::cout << "Loading " << filename << std::endl;
    }


  FXString fna(filename.c_str()), pna, pau, gna;
  FXFileStream s;
  s.open(fna, FXStreamLoad);
  s >> pna;
  s >> pau;
  s >> gna;
  s.close();

  projectName       = pna.text();
  projectAuthor     = pau.text();
  
  generatorFilename = gna.text();
}

bool
ProjectFile::isDirty()
{
  return this->dirty;
}

void
ProjectFile::setDirty(bool d)
{
  this->dirty = d;

  // May become a throw
  if (!d)
    std::cerr << "Warning : setting dirty flag to false without saving"
	      << std::endl;
}


void
ProjectFile::setProjectName(const std::string& vpn)
{
  projectName = vpn;
}

const std::string&
ProjectFile::getProjectName(void) const
{
  return projectName;
}

void
ProjectFile::setProjectAuthor(const std::string& pa)
{
   projectAuthor = pa;
}

const std::string&
ProjectFile::getProjectAuthor(void) const
{
  return projectAuthor;
}

void
ProjectFile::setGeneratorFilename(const std::string& gf)
{
  generatorFilename = gf;
}

const std::string&
ProjectFile::getGeneratorFilename(void) const
{
  return generatorFilename;
}

