/** \file ProcessWatcher.cpp
  * Implementation file of the ProcessWatcher class.
  *
  */

#include "ProcessWatcher.hpp"

#include <cstdio>
//#include <cstdlib>
#include <unistd.h> // USES getpid(), getppid() and fork()

#include <sys/wait.h> // USES wait()

ProcessWatcher::ProcessWatcher():
  pid(-1)
{

}

// Return -1 in case of error
int
ProcessWatcher::fork_process(const char* command)
{
  using namespace std;
  int status;
  
  auto ret = fork();
  if (ret == -1)
    {
      perror("fork");
    }
  else if (pid == 0)
    {
      // On est dans le fils
      this->pid = getpid();
      if (execl(command, NULL) < 0) {
	printf("*** ERROR: exec failed\n");
	return -1;
      }
  }
  else
    {
      // On est dans le père
      //      this->pid =ret;
      while (wait(&status) != pid)       /* wait for completion  */
	;
    }
  return this->pid;
}
