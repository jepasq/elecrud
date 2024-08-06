#include "ProcessWatcher.hpp"

#include <iostream>

/** A simple ProcessWatcher example to show how to use it.
  *
  */
int
main(int argc, char** argv)
{
  using namespace std;

  const char* arg = "/usr/bin/ls -lh";
  if (argc >1)
    arg = argv[1];

  ProcessWatcher pw;
  cout << "Running ProcessWatch for '" << arg << "'" << endl;
  return pw.forkProcess(arg);
  
}
