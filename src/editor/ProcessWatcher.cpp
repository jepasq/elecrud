/** \file ProcessWatcher.cpp
  * Implementation file of the ProcessWatcher class.
  *
  */

#include "ProcessWatcher.hpp"

#include <cstdio>     // USES perror
#include <stdexcept>  // USES runtime_error
#include <sstream>    // USES ostringstream

//#include <cstdlib>
#include <unistd.h>   // USES getpid(), getppid() and fork()

#include <sys/wait.h> // USES wait()


/** Watcher constructor
  *
  * By default with a negative PID member value.
  *
  */
ProcessWatcher::ProcessWatcher():
  pid(-1)
{

}

/** For the geven process
  *
  * wait() is from
  * https://pubs.opengroup.org/onlinepubs/007904975/functions/waitpid.html
  *
  * @throws runtime_error if we can't use fork().
  *
  * @param command The executable to be called without possible parameters.
  * @param args    All parameters in one string.
  *
  * @return The forked process PID.
  * 
  */
int
ProcessWatcher::fork_process(const char* command, const char* args)
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
      //      perror("fork");
      ostringstream oss;
      oss << "ProcessWatcher::fork_process: fork('" << command
	  << "') call failed : " << forkMessage(ret);
      throw runtime_error(oss.str().c_str());
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
      if (execl(command, args) < 0)
	{
	  ostringstream oss;
	  // Error according to https://linux.die.net/man/2/execve ones
	  oss << "ProcessWatcher::fork_process('" << command
	      << "'): execl() failed "
	      << "with error '" << execMessage(errno) << "'";
	  throw runtime_error(oss.str());
	}
  }
  else
    {
      this->pid = ret;
      // We're the parent process
      //      while (wait( &status) != pid)  /* wait for completion  */
	;
	
    }
  return this->pid;
}

/** Return a textual error message from an errno value
  *
  * From https://linux.die.net/man/2/execve
  *
  * \param e The errno value.
  *
  * \return The text message as a std string.
  *
  */
std::string
ProcessWatcher::execMessage(int e) const
{
  std::string ret;

  switch (e)
    {
    case E2BIG:
      ret = "The total number of bytes in the environment (envp) and argument list (argv) is too large.";
      break;
    case EACCES:
      ret ="The file or a script interpreter is not a regular file. Execute permission is denied for the file or a script or ELF interpreter. The file system is mounted noexec.";
      break;
      
    case EFAULT:
      ret ="filename points outside your accessible address space.";
      break;

    case EINVAL:
      ret ="An ELF executable had more than one PT_INTERP segment (i.e., tried to name more than one interpreter).";
      break;
      
    case EIO:
      ret ="An I/O error occurred.";
      break;
      
    case EISDIR:
      ret ="An ELF interpreter was a directory.";
      break;
      
    case ELIBBAD:
      ret ="n ELF interpreter was not in a recognized format.";
      break;
      
    case ELOOP:
      ret ="oo many symbolic links were encountered in resolving filename or the name of a script or ELF interpreter.";
      break;
      
    case EMFILE:
      ret ="The process has the maximum number of files open.";
      break;
      
    case ENAMETOOLONG:
      ret ="ilename is too long.";
	break;
 
    case ENFILE:
	ret ="he system limit on the total number of open files has been reached.";
	break;
	
    case ENOENT:
	ret ="The file filename or a script or ELF interpreter does not exist, or a shared library needed for file or interpreter cannot be found.";
	break;
	
    case ENOEXEC:
	ret ="The executable is not in a recognized format, is for the wrong architecture, or has some other format error that means it cannot be executed.";
	break;
	
    case ENOMEM:
	ret ="Insufficient kernel memory was available.";
	break;
	
    case ENOTDIR:
	ret =" component of the path prefix of filename or a script or ELF interpreter is not a directory.";
	break;
	
    case EPERM:
	ret ="The file system is mounted nosuid, the user is not the superuser, and the file has the set-user-ID or set-group-ID bit set. The process is being traced, the user is not the superuser and the file has the set-user-ID or set-group-ID bit set.";
	break;
	
    case ETXTBSY:
	ret ="Executable was open for writing by one or more processes.";
	break;
	
    default:
      ret="Undefined error";
    }

  return ret;
}

/** Return a textual error message from a failing fork() call
  *
  * From https://linux.die.net/man/2/fork
  *
  * \param val The errno value.
  *
  * \return The text message as a std string.
  *
  */
std::string
ProcessWatcher::forkMessage(int val) const
{
  std::string ret;

  switch (val)
    {
    case EAGAIN:
      ret = "It was not possible to create a new process because the caller's RLIMIT_NPROC resource limit was encountered. To exceed this limit, the process must have either the CAP_SYS_ADMIN or the CAP_SYS_RESOURCE capability.";
      break;
  case ENOMEM:
    ret = "fork() failed to allocate the necessary kernel structures because memory is tight.";
      break;
  case ENOSYS:
    ret = "fork() is not supported on this platform (for example, hardware without a Memory-Management Unit).";
      break;
      
    default:
      ret="Undefined error";
    }

  return ret;
}


