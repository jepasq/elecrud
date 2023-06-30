/** \file src/euddcat/main.cpp
  * The main file of the eudcat CLI tool.
  *
  */
#include <iostream>

#include "config.h"

#include "libfile/ProjectFile.hpp"

using namespace std;

void
usage()
{
  cout << "eudcat v" << PROJECT_NUMBER << endl
       << "This tool is part of the " << PROJECT_NAME << " project." << endl;

  exit(0);
}

void
print_if_not_empty(std::string label, std::string value)
{
  if (!value.empty())
    std::cout << "  " << label << ":: " << value << endl;
  
}


/** The main entry of the eudcat tool
  *
  *
  */
int
main(int argc, char** argv)
{
  if (argc != 2)
    usage();
  
  ProjectFile pf;
  pf.setFilename(argv[1]);
  pf.load();

  print_if_not_empty("Project name",   pf.getProjectName());
  print_if_not_empty("Project author", pf.getProjectAuthor());

  print_if_not_empty("Generator filename", pf.getGeneratorFilename());
  
  return 0;
}
