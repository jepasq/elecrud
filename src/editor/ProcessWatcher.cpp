/** \file ProcessWatcher.cpp
  * Implementation file of the ProcessWatcher class.
  *
  */

#include "ProcessWatcher.hpp"

#include <cstdio>     // USES perror
#include <stdexcept>  // USES runtime_error

//#include <cstdlib>
#include <unistd.h>   // USES getpid(), getppid() and fork()

#include <sys/wait.h> // USES wait()

ProcessWatcher::ProcessWatcher():
  pid(-1)
{

}

// Throw runtim_error in case of error
// wait() is from https://pubs.opengroup.org/onlinepubs/007904975/functions/waitpid.html
int
ProcessWatcher::fork_process(const char* command)
{
  using namespace std;
  int status;
  
  auto ret = fork();
  if (ret == -1)
    {
      perror("fork");
      throw runtime_error("ProcessWatcher::fork_process: fork() call failed");
    }
  else if (pid == 0)
    {
      // We're in the son. Partly from stackoverflow.com/q/15749071
      this->pid = getpid();
      //      if (execl(command, NULL) < 0)
      // command may be replaced with "/bin/ls", "ls", "-l"
      if (execl(command, NULL) < 0)
	{
	  throw runtime_error("ProcessWatcher::fork_process: execl() call failed");
	}
  }
  else
    {
      // On est dans le père
      //      this->pid =ret;
      while (wait( &status) != pid)  /* wait for completion  */
	;
    }
  return this->pid;
}
