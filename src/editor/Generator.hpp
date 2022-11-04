#ifndef __GENERATOR_HPP__
#define __GENERATOR_HPP__

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

  virtual void generate(void)=0;

  const std::string& getOutputDir() const;
  void               setOutputDir(const std::string&);
  
private:
  std::string outputDir;
  
};

#endif // ! __GENERATOR_HPP__
