/** \file src/euddcat/main.cpp
  * The main file of the eudcat CLI tool.
  *
  */
#include <iostream>

#include "config.h"

using namespace std;

void
usage()
{
  cout << "eudcat v" << PROJECT_NUMBER << endl
       << "This tool is part of the " << PROJECT_NAME << " project." << endl;
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
  else
    cout << "filename is " << argv[1] << endl;
  return 0;
}
