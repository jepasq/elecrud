#ifndef __PROJECT_FILE_HPP__
#define __PROJECT_FILE_HPP__

#include <string>
#include <fox-1.6/fx.h>

/** The project file used to serialize a complete project
  *
  */
class ProjectFile
{
public:
  ProjectFile();

  void               setFilename(const std::string&);
  void               setFilename(const FX::FXString&);

  const std::string& getFilename(void) const;
  
private:
  std::string filename; //!< The filename to this project file. Can be empty.
};

#endif // !__PROJECT_FILE_HPP__
