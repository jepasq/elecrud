/** \file GeneratorV1.hpp
  * Header file of the actual, first version Generator.
  *
  */

#ifndef __GENERATOR_V1_HPP__
#define __GENERATOR_V1_HPP__

#include "Generator.hpp"

/** The v1 version of the Generator implementation
  *
  */
class GeneratorV1 : public Generator
{
public:
  
  virtual void generate();
  
};

#endif // !__GENERATOR_V1_HPP__
