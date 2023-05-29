#include <iostream>

#include "config.h"

using namespace std;

int
main(int argc, char** argv)
{
  cout << "eudcat v" << PROJECT_NUMBER << endl
       << "This tool is part of the " << PROJECT_NAME << " project." << endl;

  return 0;
}
