#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include <fox-1.6/fx.h>
#include <string>

#include "libfile/ProjectFile.hpp"

#include "Elecrud.hpp"

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
  MainWindow(Elecrud* a, const FX::FXString& windowTitle);

  // Messages for our class
  enum{
    ID_CANVAS=FXMainWindow::ID_LAST,
    ID_CLEAR,

    ID_NEW,    //!< Creating a new project
    ID_OPEN,   //!< Open an existing project
    ID_SAVE,   //!< The file/save menu item
    ID_SAVEAS, //!< The file/save as menu item
    
    ID_ICON,   //!< An icon from isonlist has been clicked
    ID_PRJD,   //!< The name textfield has been modified
    ID_DSCR,   //!< The project description widget
    
    ID_LAST,   //!< Always last (and not used)
    };

  
  // Initialize
  virtual void create();
  virtual ~MainWindow();

  long onFileNew(FXObject*,FXSelector,void*);
  long onFileOpen(FXObject*,FXSelector,void*);
  long onFileSave(FXObject*,FXSelector,void*);
  long onFileSaveAs(FXObject*,FXSelector,void*);

  long onIconClicked(FXObject*,FXSelector,void*);
  long onProjectDetailsChanged(FXObject*,FXSelector,void*);
  long onProjectDescChanged(FXObject*,FXSelector,void*);

  void addLogMessage(const FXString&);  
  
protected:
  MainWindow();

  void setRunnableProject(bool);
  void updateTitle(void);
  
private:
  FX::FXMenuBar*   mbFile;   //!< The File menubar 
  FX::FXMenuTitle* mtFile;   //!< The File menubar's title 

  FX::FXString     titlebase;//!< Window title got via constructor
  FX::FXString     filename; //!< The current project filename or an empty one.
  bool             dirty;    //!< Does the actual document need a save ?

  // Used to set them to disable if we can't generate project
  FXMenuCommand* mcGen; //!< Then Project>Generate menu command
  FXMenuCommand* mcRun; //!< Then Project>Run menu command
  
  ProjectFile      projectFile; //!< Used to load/save actual project

  FXSplitter* splitter;            //!< The parent of all panes
  FXVerticalFrame* projectPane;    //!< The project details panel
  FXHorizontalFrame* collectPane;  //!< The collections panel
  FXVerticalFrame* logPane;        //!< The project log panel

  FXList* logger;             //!< The logger widget
  FXTextField* tfProjectName; //!< The widget for the project name edition
  FXTextField* tfProjectAuth; //!< The project author widget
  FXTextField* tfProjectVers; //!< The project version
  FXTextField* tfProjectLice; //!< The project version
  FXText*      ftDescription; //!< The description multiline input widget
};

#endif // !__MAIN_WINDOW_HPP__
