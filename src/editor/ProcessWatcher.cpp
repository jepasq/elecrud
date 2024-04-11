/** \file ProcessWatcher.cpp
  * Implementation file of the ProcessWatcher class.
  *
  */

#include "ProcessWatcher.hpp"

#include <cstdio>
#include <cstdlib>
#include <unistd.h>

ProcessWatcher::ProcessWatcher():
  pid(-1)
{

}

int
ProcessWatcher::fork(const char* command)
{
  this->pid = fork(command);
  if (pid == -1) {
    // Il y a une erreur
    perror("fork");
  } else if (pid == 0) {
    // On est dans le fils
    printf("Mon PID est %i et celui de mon père est %i\n", getpid(),getppid());
  } else {
    // On est dans le père
    printf("Mon PID est %i et celui de mon fils est %i\n", getpid(), pid);
  }
}
