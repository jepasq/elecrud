#ifndef __STARTUP_OPTIONS_HPP__
#define __STARTUP_OPTIONS_HPP__

/** \file StartupOptions.hpp
  * The eudcat tool options set at startup with command line arguments.
  *
  */

#include <list>
#include <string>
#include <stdexcept>

/** A logic error thrown when Icompatible Argument are detected
  *
  */
class IncompatibleArguments : public std::invalid_argument {
public:
  /** Constructor with optional what argument
    *
    * \param what Optional what argument as std string.
    *
    */
  IncompatibleArguments(const std::string& what = "") :
    std::invalid_argument(what) {}
};

/** A list of string */
typedef std::list<std::string> tStringList;

/** The options used to print eud content of a file
  *
  * Only used in eucat tool binary. Mainly a class (not a struct) to set
  * variable default values.
  *
  */
class StartupOptions
{
public:
  StartupOptions();
  bool check();

  void consume(tStringList&);

protected:
  bool contains(tStringList&, const std::string&, const std::string&) const;
  
public:
  bool printHelp; //!< Print Help/Usage and exit
  bool printAll;  //!< Should we print all extract values from .eud file
  bool printSet;  //!< On print setted values, not default values
};

#endif // !__STARTUP_OPTIONS_HPP__

