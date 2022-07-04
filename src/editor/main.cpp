#include <string>
#include <iostream>

#include "MainWindow.hpp"

using namespace std;

// Forward declarations
int usage(void);
int error(const std::string&);
// End of forward declarations

/** Main entry of the editor binary
  *
  * \param argc Number of command line arguments including program name.
  * \param argv Command line arguments array as C null-terminated strings.
  *
  * /return The executable status code as a signed integer.
  *
  */
int
main(int argc, char** argv)
{

  if (argc<2)
    {
      // Make application
      FXApp application("elecrud","editor");
      
      application.init(argc,argv);
      
      MainWindow mw(&application, "elecrud editor v...");
      application.create();
      
      // Run the application
      return application.run();
    }
  else
    {
      using std::string;
      
      string s(argv[1]);
      if (s=="--help" || s=="-h" || s=="-?")
	{
	  return usage();
	}
      else
	{
	  return error(s);
	}
    }
}

int
usage(void)
{
  using std::cout;
  using std::endl;

  cout << "elecrud" << endl;
  cout << endl;
  cout << "A C++/electron based multi-user CRUD operator generator." << endl;
  cout << endl;
  cout << "-?|-h|--help    Show this help message and exit" << endl;
  return 0;
}

int
error(const std::string& option)
{
  using std::cout;
  using std::endl;

  cout << "Unrecognized option '" << option << "'" << endl;
  return 1;
}

 
