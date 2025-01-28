#include "ProjectFile.hpp"

/** \file ProjectFile.cpp
  * The libfile's ProjectFile implementation.
  *
  */

#include <stdexcept>  // USES runtime_error
#include <FXFileStream.h>

#include <iostream> // MAY USE cout, endl

/** Check if the given file exists (Fox Toolkit version)
  *
  * \param filename The filename to be tested.
  *
  */
bool
file_exists(const FX::FXString& filename)
{
  // Can't hardly call the std::string version without a "call of overloaded"
  // "'***' is ambiguous error
  std::ifstream infile(filename.text());
  return infile.good();
}

/** Check if the given file exists (STL version)
  *
  * \param filename The filename to be tested.
  *
  */
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
  dirty(false),
  generatorCallnpm(false)
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
  * Here we use fox tooklit's FXFileStream to save current members values
  * to a new file called filename.
  *
  */
void
ProjectFile::save()
{
  if (filename.empty())
    throw std::runtime_error("Can't save project file with empty filename");
  else
    {
      using namespace std;
      
      FXString fna(filename.c_str());
      FXFileStream s;
      s.open(fna, FXStreamSave);
      s << stdToFx(projectName);
      s << stdToFx(projectAuthor);
      s << stdToFx(generatorFilename);
      s << (FXint)generatorCallnpm;  // Can't save a bool. Cast to int.
      s << stdToFx(description);

      // Collections
      s << colls.size();
      for (int ji = 0; ji < colls.size(); ++ji)
	colls.at(ji)->save(s);
      
      s.close();
      
      cout << "ProjectFile : saved as '" << filename.c_str() << "'" << endl;
    }
}

/** Load the project file from the file previously set with setFilename()
  *
  * Load the file named filename and set this instance's members.
  *
  */
void
ProjectFile::load()
{
  if (filename.empty())
    throw std::runtime_error("Can't load a project file with empty filename");
  else if (!file_exists(filename))
    {
      std::string s="Can't load project file '" + filename
	+ "'. It doesn't exist!";
      throw std::runtime_error(s.c_str());
    }
  else
    {
      std::cout << "Loading " << filename << std::endl;
    }


  FXString fna(filename.c_str()), pna, pau, gna, des;
  FXFileStream s;
  FXint iCallnpm;
  s.open(fna, FXStreamLoad);
  s >> pna;
  s >> pau;
  s >> gna;
  s >> iCallnpm;
  s >> des;


  FXint collnumber;
  s >> collnumber;
  for (int cni=0; cni < collnumber; ++cni)
    {
      auto cc = std::make_shared<Collection>("name");
      cc->load(s);
      colls.push_back(cc);
    }
  
  s.close();
  generatorCallnpm = (bool)iCallnpm;
  projectName       = pna.text();
  projectAuthor     = pau.text();
  
  generatorFilename = gna.text();
  description       = des.text();
}

/** Is this project file dirty ?
  *
  * Is there any modification waiting to be saved ?
  *
  * \return The dirty flag value as boolean.
  *
  */

bool
ProjectFile::isDirty()
{
  return this->dirty;
}


/** Manually changing the dirty flag value
  *
  * May issue an error in cerr if user try to set flag to false without
  * saving. Please use save() instead.
  *
  * \param d The new value
  *
  */
void
ProjectFile::setDirty(bool d)
{
  this->dirty = d;

  // May become a throw
  if (!d)
    std::cerr << "Warning : setting dirty flag to false without saving"
	      << std::endl;
}

/** Set the project name
  *
  * \param vpn The new value.
  *
  */
void
ProjectFile::setProjectName(const std::string& vpn)
{
  projectName = vpn;
}

/** Get the project name
  *
  * \return The name as std string.
  *
  */
const std::string&
ProjectFile::getProjectName(void) const
{
  return projectName;
}

/** Set the project author
  *
  * \param pa The new value.
  *
  */
void
ProjectFile::setProjectAuthor(const std::string& pa)
{
   projectAuthor = pa;
}

/** Get the project author
  *
  * \return The author as std string.
  *
  */
const std::string&
ProjectFile::getProjectAuthor(void) const
{
  return projectAuthor;
}

/** Set the generator filename
  *
  * \param gf The new value.
  *
  */
void
ProjectFile::setGeneratorFilename(const std::string& gf)
{
  generatorFilename = gf;
}

/** Get the generator filename
  *
  * \return The filename.
  *
  */
const std::string&
ProjectFile::getGeneratorFilename(void) const
{
  return generatorFilename;
}

/** Set the generatorCallnpm member field value
  *
  * \param b The bool value.
  *
  */
void
ProjectFile::setGeneratorCallnpm(bool b)
{
  generatorCallnpm = b;
}

/** Get the generatorCallnpm member field value
  *
  * \return The bool value.
  *
  */
bool
ProjectFile::getGeneratorCallnpm(void) const
{
  return generatorCallnpm;
}

/** Cast a standard library string to fox toolkit one
  *
  * @param s The string to be copied.
  *
  * @return The same string content as a FXString. 
  *
  */
FXString
ProjectFile::stdToFx(const std::string& s) const
{
  return FXString(s.c_str());
}

/** Print to console all project file fields
  *
  */
void
ProjectFile::debug(void) const
{
  using namespace std;
  cout << "Debugging ProjectFile :" << endl
       << "  name :" << projectName << endl
       << "  author :" << projectAuthor << endl
       << "  filename :" << generatorFilename << endl
       << "  callNpm :" << (generatorCallnpm ? "true" : "false") << endl;
}

/** Set the to-be-saved description field
  *
  * \param d The new description.
  *
  */
void
ProjectFile::setDescription(const std::string& d)
{
  description = d;
}

/** Returns the description
 *
 * \return The description fiels value.
 *
 */
const std::string&
ProjectFile::getDescription(void) const
{
  return description;
}

/** Returns a mutable Collection pointer
 *
 *  The lifetime of this pointer will be this instance's one.
 *
 *  @return A pointer to the current Collection list.
 *
 */
CollectionList*
ProjectFile::getCollections(void)
{
  return &colls;
}

