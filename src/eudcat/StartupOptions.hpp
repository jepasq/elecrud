#ifndef __STARTUP_OPTIONS_HPP__
#define __STARTUP_OPTIONS_HPP__

/** \file StartupOptions.hpp
  *
  *
  *

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
  
public:
  bool printAll; //!< Should we print all extract values from .eud file
  bool printSet; //!< On print setted values, not default values
};

#endif // !__STARTUP_OPTIONS_HPP__

