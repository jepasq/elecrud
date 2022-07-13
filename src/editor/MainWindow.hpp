#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include <fox-1.6/fx.h>
#include <string>

/** The main editor window
  *
  * If current \c filename is an empty string, 
  *
  */
class MainWindow : public FXMainWindow
{
  // Macro for class hierarchy declarations
  FXDECLARE(MainWindow)

public:
  // MainWindow's constructor
  MainWindow(FXApp* a, const FX::FXString& windowTitle);

  // Messages for our class
  enum{
    ID_CANVAS=FXMainWindow::ID_LAST,
    ID_CLEAR,

    ID_NEW,  // Creating a new project
    ID_OPEN,  // Open an existing project
    ID_SAVE,
    ID_SAVEAS,
    
    
    ID_LAST,
    };

  
  // Initialize
  virtual void create();
  virtual ~MainWindow();

  long onFileNew(FXObject*,FXSelector,void*);
  long onFileOpen(FXObject*,FXSelector,void*);
  long onFileSave(FXObject*,FXSelector,void*);
  long onFileSaveAs(FXObject*,FXSelector,void*);
  
protected:
  MainWindow();

private:
  FX::FXMenuBar*   mbFile;   //!< The File menubar 
  FX::FXMenuTitle* mtFile;   //!< The File menubar's title 

  FX::FXString     filename; //!< The current prohject filename or an empty one.
  bool             dirty;    //!< Does the actual document need a save ?
};

#endif // !__MAIN_WINDOW_HPP__
