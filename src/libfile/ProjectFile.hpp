#ifndef __PROJECT_FILE_HPP__
#define __PROJECT_FILE_HPP__

#include <string>

/** The project file used to serialize a complete project
  *
  */
class ProjectFile
{
public:
  ProjectFile();

  void               setFilename(const std::string&);
  const std::string& getFilename(void) const;
  
private:
  std::string filename; //!< The filename to this project file. Can be empty.
};

#endif // !__PROJECT_FILE_HPP__
