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

  const std::string& getFilename(void) const;
  
private:
  std::string filename;
};

#endif // !__PROJECT_FILE_HPP__
