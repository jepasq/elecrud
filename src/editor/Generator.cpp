#include "Generator.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>    // POSIX-only solution

#include <iostream>
#include <fstream>     // USES fstream
#include <cstring>     // USES strcmp

#include <regex>

/** Default constructor
  *
  * Mainly set outputDir  default value.
  *
  */
Generator::Generator():
  outputDir()
{
  
}

/// Destructor
Generator::~Generator()
{
  
}

/** Get the current outputDir value
  *
  * \return The outputDir value as a string.
  *
  */
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

/** Check if the given directory exists
  *
  * \param dir The dir name as a std string.
  *
  * \return true If we can access the existing directory.
  *
  */
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

/** Create the given directory
  *
  * \param dir The directory name.
  *
  */
void
Generator::createDirectory(const std::string& dir)
{
  int r = mkdir(dir.c_str(), 0700);
  if (r != 0)
    std::cout << "Cannot create directory '" << dir <<"'." << std::endl;
  // see https://www.man7.org/linux/man-pages/man2/mkdir.2.html#RETURN_VALUE
  // for more
}

/** Remove the given directory
  *
  * \param The directory name.
  *
  */
void
Generator::removeDirectory(const std::string& dir)
{
  int r = rmdir(dir.c_str());
  if (r != 0)
    std::cout << "Something wen wrong." << std::endl;
  
}

/** Get the variables map
  *
  * \return A reference to the local variables map.
  *
  */
const std::map<std::string, std::string>&
Generator::getVariables(void) const
{
  return variables;
}

/** Insert the given key and value to the variables map
  *
  * \param key   The text to be replaced.
  * \param value The value to replace the key with.
  *
  */
void
Generator::addVariable(const std::string& key, const std::string& value)
{
  variables.insert({key, value});
}

/** Return a text wher we replaced all variale jey by its value
 *
 * \param in The input string.
 *
 * \return The modified string.
 *
 */
std::string
Generator::replaceVars(const std::string& in)
{

  std::string out = in;

  for (auto var : variables)
    out = std::regex_replace(out, std::regex(var.first), var.second);

  return out;
  
}

/** Does the given file exist ?
  *
  * \param file The filename to be checked.
  *
  * \return true if the file exists accordibng to stat().
  *
  */
bool
Generator::fileExists(const std::string& file)
{
  struct stat info;
  auto pathname = file.c_str();
  
  return (stat( pathname, &info ) == 0);
}

/** Does the file contain the given txt
 *
 * Performs a case sensitive search. For unit test purpose.
 *
 * \param filename The file to be checked
 * \param txt      The text to be searched for.
 *
 * \return true is the text was found. false if not or if the file can't be
 *         opened.
 *
 */
bool
Generator::fileContains(const std::string& filename, const std::string& txt)
{
  if (!fileExists(filename))
    return false;
  
  // see https://stackoverflow.com/a/13482546
  auto wordToFind = txt.c_str();
  std::string aWord;

  std::fstream file;
  file.open(filename, std::ios::in);
  
  while (file.good())
    {
      file >> aWord;
      //      std::cout << "Got '" << aWord << "'" << std::endl;
      //      if (file.good() && strcmp(aWord, wordToFind) == 0) {
      if (aWord.find(txt) != std::string::npos)
	{
	  //found word
	  file.close();
	  return true;
	}
    }
  file.close();
  return false;
}

