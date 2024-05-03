#ifndef __PROCESS_WATCHER_HPP__
#define __PROCESS_WATCHER_HPP__

#include <sys/types.h> // USES pid_t

/** \file ProcessWatcher.hpp
  * The header for the ProcessWatcher class.
  *
  */

/** A class used to watch a forked process
  *
  */
class ProcessWatcher
{
public:
  ProcessWatcher();
  
  int fork_process(const char* command);

private:
  
  pid_t pid; // 
  
};

#endif // !__PROCESS_WATCHER_HPP__
