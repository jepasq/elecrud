/** \file src/eudcat/main.cpp
  * The main file of the eudcat CLI tool.
  *
  */
#include <iostream>

#include "config.h"

#include "libfile/ProjectFile.hpp"

#include <list>
#include <string>

using namespace std;

/** The options used to print eud content of a file
  *
  * Only used in eucat tool binary.
  *
  */
struct tStartupOptions
{
  bool printAll;  //!< Shoyuld we print all extract values from .eud file
};

/** Print an help message and exit with a 0 status code
  *
  */
void
usage()
{
  cout << "eudcat v" << PROJECT_NUMBER << endl
       << "This tool is part of the " << PROJECT_NAME << " project." << endl;

  exit(0);
}

/** Print a key/value pair to std cout if value is not empty
  *
  * \param label The label
  * \param value The conditionnal print value
  *
  */
void
print_if_not_empty(const std::string& label, const std::string& value)
{
  if (!value.empty())
    std::cout << "  " << label << ":: " << value << endl;
  
}

/** Simply print argument to cout
  *
  * \param l the argument list
  *
  */
void
debugStdArgv(list<string>& l)
{
  cout << "Debugging ARGV :" << endl;
  for (auto i : l)
    cout << " - " << i << endl;
}

/** The main entry of the eudcat tool
  *
  *
  */
int
main(int argc, char** argv)
{
  // argv testing
  list<string> stdargv;
  for (int i=1; i<argc; ++i)
    stdargv.push_back(string(argv[i]));
  //  debugStdArgv(stdargv);

  tStartupOptions startupOptions;
  
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
