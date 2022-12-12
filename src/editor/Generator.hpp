#ifndef __GENERATOR_HPP__
#define __GENERATOR_HPP__

#include <map>
#include <string>

/** An abstract type used to provide common feature to all generators
  *
  * A generator will create the electron application based on editor-specified
  * values.
  *
  * It will generate the aplication in a user-defined output directory.
  *
  */
class Generator {
public:
  Generator();
  virtual ~Generator();

  /** Will finally generate the applicarion
    *
    * Must be reimplemented by subclasses to generate the final application
    * according to member variables. For example, use the outputDir member
    * as the final app. destination.
    *
    */
  virtual void generate(void)=0;

  const std::string& getOutputDir() const;
  void               setOutputDir(const std::string&);

  const std::map<std::string, std::string>& getVariables(void) const;
  void addVariable(const std::string&, const std::string&);
  
protected:
  bool directoryExists(const std::string&);
  void createDirectory(const std::string&);
  void removeDirectory(const std::string&);

  std::string replaceVars(const std::string&);
  
  
private:
  std::string outputDir; //!< The directory the output will be created in
  std::map<std::string, std::string> variables; //!< To-be-substitued vars
};

#endif // ! __GENERATOR_HPP__
