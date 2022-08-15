#include "MainWindow.hpp"

#include "Elecrud.hpp"

#include <iostream>
#include <sstream>

#include "icons.hpp"

using namespace std;

// Message Map for the Scribble Window class
FXDEFMAP(MainWindow) MainWindowMap[]={
  //________Message_Type_____________________ID____________Message_Handler_______
  //  FXMAPFUNC(SEL_PAINT,             MainWindow::ID_CANVAS, MainWindow::onPaint),
  // FXMAPFUNC(SEL_LEFTBUTTONPRESS,   MainWindow::ID_CANVAS, MainWindow::onMouseDown),
  FXMAPFUNC(SEL_COMMAND,MainWindow::ID_NEW,   MainWindow::onFileNew),
  FXMAPFUNC(SEL_COMMAND,MainWindow::ID_OPEN,  MainWindow::onFileOpen),
  FXMAPFUNC(SEL_COMMAND,MainWindow::ID_SAVE,  MainWindow::onFileSave),
  FXMAPFUNC(SEL_COMMAND,MainWindow::ID_SAVEAS,MainWindow::onFileSaveAs),

  FXMAPFUNC(SEL_COMMAND,MainWindow::ID_ICON,  MainWindow::onIconClicked),
};

// Macro for the ScribbleApp class hierarchy implementation
FXIMPLEMENT(MainWindow,FXMainWindow,MainWindowMap,ARRAYNUMBER(MainWindowMap))

/// Forbidden default constructor
MainWindow::MainWindow()
{
  
}
/** FXApp-based and titled constructor
  *
  * Thiw will create an editor MainWindow with hardcoded size.
  *
  * \param a           The current fxo toolkit application.
  * \param windowTitle The MainWindow's title.
  *
  */
MainWindow::MainWindow(Elecrud* app, const FX::FXString& windowTitle):
  FXMainWindow(app, windowTitle, NULL, NULL, DECOR_ALL, 0, 0, 640, 480),
  mbFile(nullptr),
  mtFile(nullptr),
  titlebase(windowTitle),
  filename(""),
  dirty(false),
  mcGen(nullptr),
  mcRun(nullptr)
{
  mbFile = new FX::FXMenuBar(this, LAYOUT_TOP|LAYOUT_LEFT|LAYOUT_FILL_X);
  auto filemenu=new FXMenuPane(this);
  mtFile = new FX::FXMenuTitle(mbFile, "&File", nullptr,filemenu);

  new FXMenuCommand(filemenu,tr("&New...\tCtl-N\tCreate new document."),
		    app->newicon,this,ID_NEW);
  new FXMenuCommand(filemenu,tr("&Open...\tCtl-O\tOpen document file."),
		    app->openicon,this,ID_OPEN);

  auto save = new FXMenuCommand(filemenu,tr("&Save\tCtrl-S\tOverride already saved file."),
				nullptr,this,ID_SAVE);
  save->disable();

  new FXMenuCommand(filemenu,tr("&Save as...\tCtrl-S\tSave in a new file."),
				nullptr,this,ID_SAVEAS);
  
  new FXMenuSeparator(filemenu);
  new FXMenuCommand(filemenu,tr("&Quit\tCtl-Q\tQuit program."),/*getApp()->quiticon*/nullptr,getApp(),Elecrud::ID_QUIT);



  auto mbProject=new FX::FXMenuBar(this, LAYOUT_TOP|LAYOUT_LEFT|LAYOUT_FILL_X);
  auto prjMenu=new FXMenuPane(this);
  auto mtFile = new FX::FXMenuTitle(mbFile, "&Project", nullptr,prjMenu);

  mcGen = new FXMenuCommand(prjMenu,
	       tr("&Generate...\tCtl-N\tGenerate the electron app."),
			    nullptr,this,ID_NEW);
  mcRun = new FXMenuCommand(prjMenu,
			    tr("&Run...\tCtl-O\tGenerate and run the app."),
			    nullptr,this,ID_OPEN);


  auto statusbar = new FXStatusBar(this,LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X|
				   STATUSBAR_WITH_DRAGCORNER|FRAME_RAISED);


  FXSplitter* splitter=new FXSplitter(this,LAYOUT_SIDE_TOP|LAYOUT_FILL_X|LAYOUT_FILL_Y|SPLITTER_TRACKING);
  
  auto ilMenu = new FXIconList (splitter, this, ID_ICON,
				ICONLIST_BIG_ICONS|FX::ICONLIST_SINGLESELECT );

  ilMenu->appendItem(new FXIconItem("Project", app->projecticon_big, nullptr));
  ilMenu->setWidth(120);
  
  
  new FXFrame(splitter,FRAME_RAISED|LAYOUT_CENTER_Y|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,0,0,4,4);
  
  setRunnableProject(false);
  updateTitle();
}

/** The main window destructor
  *
  */
MainWindow::~MainWindow()
{
  /*
  delete mbFile;
  delete mtFile;
  */
}

/** Create and set initial placement of the MainWindow
  *
  */
void
MainWindow::create()
{
  // Create the windows
  FXMainWindow::create();

  // Make the main window appear
  show(PLACEMENT_SCREEN);

}

/** New file menu command callback
  *
  */
long
MainWindow::onFileNew(FXObject*,FXSelector,void*)
{
  std::cout << "New file clicked!" << std::endl;
  return 1;
}

long
MainWindow::onFileOpen(FXObject*,FXSelector,void*)
{
  FXString filename = FXFileDialog::getOpenFilename(this, "Open a project...", "~");
  updateTitle();

  return 1;
}

long
MainWindow::onFileSave(FXObject*,FXSelector,void*)
{
  updateTitle();
  return 1;
}

long
MainWindow::onFileSaveAs(FXObject*,FXSelector,void*)
{
  return 1;
}

/** Set the generate/run menu enable/disable status
 *
 */
void
MainWindow::setRunnableProject(bool runnable)
{
  if (runnable)
    {
      mcGen->enable();
      mcRun->enable();
    }
  else
    {
      mcGen->disable();
      mcRun->disable();
    }
}

/** Update the window title with project save status
  *
  */
void
MainWindow::updateTitle(void)
{
  FXString title = "";
  if (filename.empty())
    title += "<Untitled>";
  else
    title += filename.text();

  if (dirty)
    title += "*";
    
  title += " - ";
  title += titlebase.text();
  this->setTitle(title);  
}

long
MainWindow::onIconClicked(FXObject*,FXSelector,void* idx)
{
  
  
  cout << "Icon clicked :  " << idx << endl;
  return 1;
}

