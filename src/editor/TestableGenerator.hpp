#ifndef __TESTABLE_GEENRATOR_HPP__
#define __TESTABLE_GEENRATOR_HPP__

#include <string>

using namespace std;

/// Used to instantiate and test the abstract Generator class
class TestableGenerator : public Generator {

public:
  void generate(){};

  bool _directoryExists(const std::string&d){ return directoryExists(d); } 
  void _createDirectory(const std::string&d){ createDirectory(d); } 
  void _removeDirectory(const std::string&d){ removeDirectory(d); } 
  string _replaceVars(const string& in){return replaceVars(in); } 

  bool _fileExists(const std::string&d){ return fileExists(d); } 
  bool _fileContains(const std::string&f, const std::string&txt){
    return fileContains(f, txt);
  } 
  void _copyFile(const std::string&from, const std::string&to){
    copyFile(from, to);
  }
  std::string _getFileContent(const std::string& filename){
    return getFileContent(filename);
  };
};

#endif // !__TESTABLE_GEENRATOR_HPP__
