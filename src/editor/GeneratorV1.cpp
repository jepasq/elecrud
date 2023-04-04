#include "GeneratorV1.hpp"


/** The generate metyhod reimplementation
  *
  */
void
GeneratorV1::generate()
{
  createDirectory(outputDir);
  copyFile("../src/app/index.html", outputDir+"/index.html");
  copyFile("../src/app/package.json", outputDir+"/package.json");

  createDirectory(outputDir + "/src");
  copyFile("../src/app/src/main.js", outputDir+"/src/main.js");
  copyFile("../src/app/src/preload.js", outputDir+"/src/preload.js");
  copyFile("../src/app/src/renderer.js", outputDir+"/src/renderer.js");

}
