/** \file MainWindow.hpp
  * Header file of the editor's main window.
  *
  */

#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include <fox-1.6/fx.h>
#include <string>

#include "ProjectFile.hpp"
#include "CollectionList.hpp"

#include "Elecrud.hpp"

// Forward declarations
class NewCollectionDialog;
// End of forward declarations

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

  /** Fox-toolkit messages IDs for our class
   *
   */
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

    ID_GPAB,   //!< The Generator panel Change Path button

    ID_PGEN,   //!< The project->Generate menu button
    ID_PRUN,   //!< The project->Run menu button

    ID_NCOL,   //!< New collection button
    ID_COLI,   //!< Collection list widget

    ID_LAST,   //!< Always last (and not used)
  };

  
  // Initialize
  virtual void create();
  virtual ~MainWindow();

  long onFileNew(FXObject*,FXSelector,void*);
  long onFileOpen(FXObject*,FXSelector,void*);
  long onFileSave(FXObject*,FXSelector,void*);
  long onFileSaveAs(FXObject*,FXSelector,void*);

  long onProjectGen(FXObject*,FXSelector,void*);
  long onProjectRun(FXObject*,FXSelector,void*);
  
  long onIconClicked(FXObject*,FXSelector,void*);
  long onProjectDetailsChanged(FXObject*,FXSelector,void*);
  long onProjectDescChanged(FXObject*,FXSelector,void*);

  long onGenPathClicked(FXObject*,FXSelector,void*);

  long onNewCollection(FXObject*,FXSelector,void*);
  long onCollSelectionChanged(FXObject*,FXSelector,void*);

  
  void addLogMessage(const FXString&);  
  void resetAllFields();

  void openProjectFile(const std::string&);
  
protected:
  MainWindow();
  
  void setRunnableProject(bool);
  void updateTitle(void);
  void setDirty(bool vDirty=true);

  bool preGenerationChecks(void);
  void copyUiToProjectfile(void);
  FXString getNewCollectionString(const NewCollectionDialog*) const;

  
private:
  FX::FXMenuBar*   mbFile;   //!< The File menubar 
  FX::FXMenuTitle* mtFile;   //!< The File menubar's title 

  FX::FXString     titlebase;//!< Window title got via constructor
  FX::FXString     filename; //!< The current project filename or an empty one.
  bool             dirty;    //!< Does the actual document need a save ?

  // Used to set them to disable if we can't generate project
  FXMenuCommand* mcGen;  //!< The Project>Generate menu command
  FXMenuCommand* mcRun;  //!< The Project>Run menu command
  FXMenuCommand* mcSave; //!< The File>Save menu command 
  
  FXSplitter* splitter;            //!< The parent of all panes
  FXVerticalFrame* projectPane;    //!< The project details panel
  FXHorizontalFrame* collectPane;  //!< The collections panel
  FXVerticalFrame* generatPane;    //!< The generator log panel
  FXVerticalFrame* logPane;        //!< The project log panel

  FXList* logger;             //!< The logger widget
  FXTextField* tfProjectName; //!< The widget for the project name edition
  FXTextField* tfProjectAuth; //!< The project author widget
  FXTextField* tfProjectVers; //!< The project version
  FXTextField* tfProjectLice; //!< The project license
  FXText*      ftDescription; //!< The description multiline input widget

  FXTextField* tfOutputName; //!< The output filename

  
  FXRecentFiles mrufiles; //!< Recent files list
  
  FXStatusBar* statusbar; //!< The main window's status bar used to print msgs
  FXCheckButton* cbCallNpm; //!< The call npm check box

  FXList* collectionsList; //!< The list containing current project's colls

  // Underlying/no UI datas
  ProjectFile    projectFile; //!< Used to load/save actual project
  CollectionList collections; //!< The project collections 
  
};

#endif // !__MAIN_WINDOW_HPP__
