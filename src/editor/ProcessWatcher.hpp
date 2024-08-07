#ifndef __PROCESS_WATCHER_HPP__
#define __PROCESS_WATCHER_HPP__

/** \file ProcessWatcher.hpp
  * The header for the ProcessWatcher class.
  *
  */

#include <sys/types.h> // USES pid_t
#include <string>


/** A class used to watch a forked process
  *
  */
class ProcessWatcher
{
public:
  ProcessWatcher();
  
  int forkProcess(const char* command, const char* args=NULL);

protected:
  std::string forkMessage(int) const; 
  std::string execMessage(int) const; 
  
private:
  
  pid_t pid; //!< The process ID of the created fork (the child)
  
};

#endif // !__PROCESS_WATCHER_HPP__
