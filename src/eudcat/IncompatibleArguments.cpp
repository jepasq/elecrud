/** \file IncompatibleArguments.cpp
  * Incomptatible arguments exception implementation file.
  *
  */

#include "IncompatibleArguments.hpp"

/** Constructor with optional what argument
  *
  * \param what Optional what argument as std string.
  *
  */
IncompatibleArguments::IncompatibleArguments(const std::string& what = ""):
  std::invalid_argument(what)
{

}
