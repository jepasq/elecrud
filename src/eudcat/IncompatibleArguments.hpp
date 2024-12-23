#ifndef __INCOMPATIBLE_ARGUMENTS_HPP__
#define __INCOMPATIBLE_ARGUMENTS_HPP__

/** \file IncompatibleArguments.hpp
  * Header file for an exception fired when incompatible arguments are used.
  *
  */

#include <string>       // USES std::string

/** An invalid_argument exception thrown when icompatible Arguments are detected
 *
 *  The plural form is due to the fact than it needs at kleast two argument
 *  for them to to become invalid.
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


#endif // !__INCOMPATIBLE_ARGUMENTS_HPP__
