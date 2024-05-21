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
  int status; // The wait status paramater

  // https://man7.org/linux/man-pages/man2/fork.2.html
  //
  // On success, the PID of the child process is returned in the
  // parent, and 0 is returned in the child.  On failure, -1 is
  // returned in the parent, no child process is created, and errno is
  // set to indicate the error.
  auto ret = fork();
  if (ret == -1)
    {
      perror("fork");
      throw runtime_error("ProcessWatcher::fork_process: fork() call failed");
    }
  else if (ret == 0)
    {
      // We're in the son. Partly from stackoverflow.com/q/15749071
      this->pid = getpid();
      //      if (execl(command, NULL) < 0)
      // command may be replaced with "/bin/ls", "ls", "-l"
      // https://linux.die.net/man/3/execl
      //
      // only return if an error has occurred. The return value is -1,
      // and errno is set to indicate the error.
      if (execl(command, NULL) < 0)
	{
	  char str[120];
	  // Error according to https://linux.die.net/man/2/execve ones
	  sprintf(str, "ProcessWatcher::fork_process(): execl() failed "
		   "with error '%d'", errno);
	  throw runtime_error(str);
	}
  }
  else
    {
      this->pid = ret;
      // We're the parent process
      while (wait( &status) != pid)  /* wait for completion  */
	;
    }
  return this->pid;
}
