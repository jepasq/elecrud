/** \file src/eudcat/main.cpp
  * The main file of the eudcat CLI tool.
  *
  */
#include <iostream>

#include "config.h"

#include "libfile/ProjectFile.hpp"

#include <list>
#include <string>

#include "StartupOptions.hpp"

using namespace std;

/** Print an help message and exit with a 0 status code
  *
  */
void
usage()
{
  cout << "eudcat v" << PROJECT_NUMBER << endl
       << "This tool is part of the " << PROJECT_NAME << " project." << endl
       << endl
       << "Usage :" << endl
       << "  eudcat [options] <eudfile>" << endl
       << endl
       << "Options :" << endl
       << "  -h, --help  Print this message and exit." << endl
       << "  -a, --all   Print all values, even unsetted ones." << endl
       << "  -s, --set   Print only set values." << endl
       << endl;

  exit(EXIT_SUCCESS);
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

/** Print a key/value pair as needed in the printAll mode
  *
  * \param label The label
  * \param value The conditionnal print value
  *
  */
void
print_all(const std::string& label, const std::string& value)
{
  std::string v = "<unset>";

  if (!value.empty())
    v = value;
  
  std::cout << "  " << label << ":: " << v << endl;
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
  debugStdArgv(stdargv);

  StartupOptions startupOptions;
  tStringList sl(argv, argv + argc);
  startupOptions.consume(sl);
  
  if (startupOptions.printHelp.getValue())
    usage();
  
  ProjectFile pf;
  pf.setFilename(sl.front());
  pf.load();

  if (startupOptions.printSet.getValue())
    {
      print_if_not_empty("Project name",   pf.getProjectName());
      print_if_not_empty("Project author", pf.getProjectAuthor());
      print_if_not_empty("Generator filename", pf.getGeneratorFilename());
    }
  else // if (startupOptions.printAll)
    {
      print_all("Project name",   pf.getProjectName());
      print_all("Project author", pf.getProjectAuthor());
      print_all("Generator filename", pf.getGeneratorFilename());
      print_all("Call npm", pf.getGeneratorCallnpm()?"True":"False");
    }
  return 0;
}
