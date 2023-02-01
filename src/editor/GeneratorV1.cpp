#include "GeneratorV1.hpp"


/** The generate metyhod reimplementation
  *
  */
void
GeneratorV1::generate()
{
  createDirectory(outputDir);
  copyFile("../src/app/index.html", outputDir+"/index.html");
}
