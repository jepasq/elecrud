#ifndef __PROCESS_WATCHER_HPP__
#define __PROCESS_WATCHER_HPP__

/** \file ProcessWatcher.hpp
  * The header for the ProcessWatcher class.
  *
  */

#include <sys/types.h> // USES pid_t

/** A class used to watch a forked process
  *
  */
class ProcessWatcher
{
public:
  ProcessWatcher();
  
  int fork_process(const char* command);

private:
  
  pid_t pid; // The process ID of the created fork (the child)
  
};

#endif // !__PROCESS_WATCHER_HPP__
