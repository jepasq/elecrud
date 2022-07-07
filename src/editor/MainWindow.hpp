#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include <fox-1.6/fx.h>
#include <string>

/** The main editor window
  *
  */
class MainWindow : public FXMainWindow
{
  // Macro for class hierarchy declarations
  FXDECLARE(MainWindow)

public:
  // MainWindow's constructor
  MainWindow(FXApp* a, const FX::FXString& windowTitle);

  // Initialize
  virtual void create();
  virtual ~MainWindow();

protected:
  MainWindow();
  
private:  
  // Messages for our class
  enum{
    ID_CANVAS=FXMainWindow::ID_LAST,
    ID_CLEAR,

    ID_NEW,  // Creating a new project
    ID_OPEN,  // Open an existing project

    ID_LAST,

    };

  FX::FXMenuBar*   mbFile;   //!< The File menubar 
  FX::FXMenuTitle* mtFile;   //!< The File menubar's title 
};

#endif // !__MAIN_WINDOW_HPP__
