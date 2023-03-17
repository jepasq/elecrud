#ifndef __PROJECT_FILE_HPP__
#define __PROJECT_FILE_HPP__

#include <string>
#include <fstream>
#include <fox-1.6/fx.h>

// From https://stackoverflow.com/a/19841704
bool file_exists(const FX::FXString& filename);
bool file_exists(const std::string& filename);

/** The project file used to serialize a complete project
  *
  */
class ProjectFile
{
public:
  ProjectFile();

  void               setFilename(const std::string&);
  void               setFilename(const FX::FXString&);
  void               setFilename(const char*);

  const std::string& getFilename(void) const;

  void save();
  void load();
  
private:
  std::string filename; //!< The filename to this project file. Can be empty.
};

#endif // !__PROJECT_FILE_HPP__
