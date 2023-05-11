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

  bool isDirty();
  void setDirty(bool);

  // Project pane-related editor fields
  void               setProjectName(const std::string&);
  const std::string& getProjectName(void) const;

  void               setProjectAuthor(const std::string&);
  const std::string& getProjectAuthor(void) const;

  
private:
  std::string filename; //!< The filename to this project file. Can be empty.
  bool dirty; // The underlying dirty flag (true if modifications must be saved)

  // Saved values/fields
  std::string projectName;
};

#endif // !__PROJECT_FILE_HPP__
