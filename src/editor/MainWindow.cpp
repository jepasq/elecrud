/** \file MainWindow.cpp
  * Implementation file of the editor's main window.
  *
  */

#include "MainWindow.hpp"

#include <iostream>
#include <sstream>

#include "Elecrud.hpp"
#include "icons.hpp"

#include "GeneratorV1.hpp"

#include <stdio.h>      /* printf */
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */

using namespace std;

/** The pattern for saved files extension */
#define EXT_PATTERN "*.eud"

/// Message Map for the MainWindow class
FXDEFMAP(MainWindow) MainWindowMap[]={
  //________Message_Type_____________________ID____________Message_Handler_______
  //  FXMAPFUNC(SEL_PAINT,             MainWindow::ID_CANVAS, MainWindow::onPaint),
  // FXMAPFUNC(SEL_LEFTBUTTONPRESS,   MainWindow::ID_CANVAS, MainWindow::onMouseDown),
  FXMAPFUNC(SEL_COMMAND,MainWindow::ID_NEW,   MainWindow::onFileNew),
  FXMAPFUNC(SEL_COMMAND,MainWindow::ID_OPEN,  MainWindow::onFileOpen),
  FXMAPFUNC(SEL_COMMAND,MainWindow::ID_SAVE,  MainWindow::onFileSave),
  FXMAPFUNC(SEL_COMMAND,MainWindow::ID_SAVEAS,MainWindow::onFileSaveAs),

  FXMAPFUNC(SEL_COMMAND,MainWindow::ID_PGEN,MainWindow::onProjectGen),
  FXMAPFUNC(SEL_COMMAND,MainWindow::ID_PRUN,MainWindow::onProjectRun),

  
  FXMAPFUNC(SEL_COMMAND,MainWindow::ID_ICON,  MainWindow::onIconClicked),
  FXMAPFUNC(SEL_COMMAND,MainWindow::ID_GPAB,  MainWindow::onGenPathClicked),

 FXMAPFUNC(SEL_CHANGED,MainWindow::ID_PRJD,MainWindow::onProjectDetailsChanged),
 // From https://rubydoc.info/gems/fxruby/Fox/FXText : Changed in any way.
 FXMAPFUNC(SEL_CHANGED,MainWindow::ID_DSCR,MainWindow::onProjectDescChanged),
 
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
  * \param app         The current fox toolkit application.
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
  mcRun(nullptr),
  ftDescription(nullptr),
  mrufiles(app)
{
  mbFile = new FX::FXMenuBar(this, LAYOUT_TOP|LAYOUT_LEFT|LAYOUT_FILL_X);
  auto filemenu=new FXMenuPane(this);
  mtFile = new FX::FXMenuTitle(mbFile, "&File", nullptr,filemenu);

  new FXMenuCommand(filemenu,tr("&New...\tCtl-N\tCreate new document."),
		    app->newicon,this,ID_NEW);
  new FXMenuCommand(filemenu,tr("&Open...\tCtl-O\tOpen document file."),
		    app->openicon,this,ID_OPEN);

 
  mcSave = new FXMenuCommand(filemenu,tr("&Save\tCtrl-S\tOverride already saved file."),
				nullptr,this,ID_SAVE);
  mcSave->disable();

  new FXMenuCommand(filemenu,tr("&Save as...\tCtrl-S\tSave in a new file."),
				nullptr,this,ID_SAVEAS);

  // Recent file menu; this automatically hides if there are no files
  //  new FXMenuSeparator(filemenu,&mrufiles,FXRecentFiles::ID_ANYFILES);
  new FXMenuCommand(filemenu,"&1",nullptr,&mrufiles,FXRecentFiles::ID_FILE_1);
  new FXMenuCommand(filemenu,"&2",nullptr,&mrufiles,FXRecentFiles::ID_FILE_2);
  new FXMenuCommand(filemenu,"&3",nullptr,&mrufiles,FXRecentFiles::ID_FILE_3);
  new FXMenuCommand(filemenu,"&4",nullptr,&mrufiles,FXRecentFiles::ID_FILE_4);
  new FXMenuCommand(filemenu,"&5",nullptr,&mrufiles,FXRecentFiles::ID_FILE_5);
  new FXMenuCommand(filemenu,"&6",nullptr,&mrufiles,FXRecentFiles::ID_FILE_6);
  new FXMenuCommand(filemenu,"&7",nullptr,&mrufiles,FXRecentFiles::ID_FILE_7);
  new FXMenuCommand(filemenu,"&8",nullptr,&mrufiles,FXRecentFiles::ID_FILE_8);
  new FXMenuCommand(filemenu,"&9",nullptr,&mrufiles,FXRecentFiles::ID_FILE_9);
  new FXMenuCommand(filemenu,"1&0",nullptr,&mrufiles,FXRecentFiles::ID_FILE_10);
  new FXMenuCommand(filemenu,tr("&Clear Recent Files"),nullptr,&mrufiles,FXRecentFiles::ID_CLEAR);
  //  new FXMenuSeparator(filemenu,&mrufiles,FXRecentFiles::ID_ANYFILES);

  new FXMenuSeparator(filemenu);
  new FXMenuCommand(filemenu,tr("&Quit\tCtl-Q\tQuit program."),/*getApp()->quiticon*/nullptr,getApp(),Elecrud::ID_QUIT);

  auto mbProject=new FX::FXMenuBar(this, LAYOUT_TOP|LAYOUT_LEFT|LAYOUT_FILL_X);
  auto prjMenu=new FXMenuPane(this);
  auto mtFile = new FX::FXMenuTitle(mbFile, "&Project", nullptr,prjMenu);

  mcGen = new FXMenuCommand(prjMenu,
	       tr("&Generate...\tCtl-N\tGenerate the electron app."),
			    nullptr,this,ID_PGEN);
  mcRun = new FXMenuCommand(prjMenu,
			    tr("&Run...\tCtl-O\tGenerate and run the app."),
			    nullptr,this,ID_PRUN);


  statusbar = new FXStatusBar(this,LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X|
			      STATUSBAR_WITH_DRAGCORNER|FRAME_RAISED);


  splitter=new FXSplitter(this,LAYOUT_SIDE_TOP|LAYOUT_FILL_X|LAYOUT_FILL_Y|SPLITTER_TRACKING);

  new FXFrame(splitter,FRAME_RAISED|LAYOUT_CENTER_Y|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,0,0,4,4);

  
  auto ilMenu = new FXIconList (splitter, this, ID_ICON,
				ICONLIST_BIG_ICONS|FX::ICONLIST_SINGLESELECT );

  ilMenu->appendItem(new FXIconItem("Project", app->projecticon_big, nullptr));
  ilMenu->appendItem(new FXIconItem("Collections", app->collicon_big, nullptr));
  ilMenu->appendItem(new FXIconItem("Generator", app->genicon_big, nullptr));
  ilMenu->appendItem(new FXIconItem("Log", app->logicon_big, nullptr));
  ilMenu->setWidth(120);
  
  // Project details pane
  //  projectPane = new FXFrame(splitter);
  auto lablength = 60;
  auto tflength = 35;
  projectPane = new FXVerticalFrame(splitter);
  new FXLabel(projectPane, "Project details");
  auto pph1 = new FXHorizontalFrame(projectPane);
  auto labPrjName=new FXLabel(pph1, "Name :", 0, LAYOUT_FIX_WIDTH );
  labPrjName->setWidth(lablength);
  tfProjectName = new FXTextField(pph1, tflength, this, ID_PRJD);
  
  auto pph2 = new FXHorizontalFrame(projectPane);
  auto labPrjAuth=new FXLabel(pph2, "Author :", 0, LAYOUT_FIX_WIDTH );
  labPrjAuth->setWidth(lablength);
  tfProjectAuth = new FXTextField(pph2, tflength, this, ID_PRJD);

  auto pph3 = new FXHorizontalFrame(projectPane);
  auto labPrjVers=new FXLabel(pph3, "Version :", 0, LAYOUT_FIX_WIDTH );
  labPrjVers->setWidth(lablength);
  tfProjectVers = new FXTextField(pph3, tflength, this, ID_PRJD);

  auto pph4 = new FXHorizontalFrame(projectPane);
  auto labPrjLice=new FXLabel(pph4, "License :", 0, LAYOUT_FIX_WIDTH );
  labPrjLice->setWidth(lablength);
  tfProjectLice = new FXTextField(pph4, tflength, this, ID_PRJD);

  new FXLabel(projectPane, "Multiline description and notes :");
  ftDescription = new FXText(projectPane, this, ID_DSCR,
			     LAYOUT_FILL_X|LAYOUT_FILL_Y);
  
  //  ftDescription->setText("Insert project description here.");
  
  // Collections edition pane
  collectPane  = new FXHorizontalFrame(splitter);
  new FXLabel(collectPane, "Collections details");

  // Generator details pane
  //  projectPane = new FXFrame(splitter);
  generatPane = new FXVerticalFrame(splitter);
  new FXLabel(generatPane, "Generator");
  auto pph10 = new FXHorizontalFrame(generatPane);
  auto labOutName=new FXLabel(pph10, "Output filename :", 0, LAYOUT_FIX_WIDTH );
  labOutName->setWidth(lablength+60);
  tfOutputName = new FXTextField(pph10, tflength, this, ID_PRJD);
  new FXButton(pph10, "...", nullptr, this, ID_GPAB);

  cbCallNpm = new FXCheckButton(generatPane,
		    "Call 'npm install' in generated dir (can be long)");
  
  // Logger pane
  logPane  = new FXVerticalFrame(splitter,
				 FRAME_THICK|LAYOUT_FILL_X|LAYOUT_FILL_Y);
  new FXLabel(logPane, "Logger");
  logger = new FXList(logPane, nullptr, 0,
		      FX::LIST_SINGLESELECT|LAYOUT_FILL_X|LAYOUT_FILL_Y);

  // Preselect project details
  onIconClicked(nullptr, 0, 0);
  ilMenu->selectItem(0);
  
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
  resetAllFields();
  filename = "";
  updateTitle();
  return 1;
}

/** The File/Open menu item callback.
  *
  * \param o Unused.
  * \param s Unused.
  * \param d Unused.
  *
  * \return Always returns 1.
  */
long
MainWindow::onFileOpen(FXObject* o,FXSelector s,void* d)
{
  filename = FXFileDialog::getOpenFilename(this, "Open a project...", "~",
					   EXT_PATTERN);

  // Dialog was cancelled
  if (filename.empty())
    return 1;

  openProjectFile(filename.text());
  
  return 1;
}

/** The File/Save menu item callback
  *
  * \param o   Unused.
  * \param sel Unused.
  * \param d   Unused.
  *
  * \return Always returns 1.
  */
long
MainWindow::onFileSave(FXObject* o,FXSelector sel,void* d)
{
  copyUiToProjectfile();
  projectFile.debug();
  projectFile.save();
  std::string s="Current project saved as '" + projectFile.getFilename() + "'";
  FXString fxs(s.c_str());
  statusbar->getStatusLine()->setNormalText(fxs);
  setDirty(false);
  updateTitle();
  return 1;
}

/** The File/Save as menu item callback
  *
  * \param o Unused.
  * \param s Unused.
  * \param d Unused.
  *
  * \return Always returns 1.
  */
long
MainWindow::onFileSaveAs(FXObject* o,FXSelector s,void* d)
{
  filename = FXFileDialog::getSaveFilename(this, "Save as project...", "~",
					   EXT_PATTERN);
  if (!filename.empty())
    {
      copyUiToProjectfile();
      projectFile.setFilename(filename);
      projectFile.save();
      
      updateTitle();
    }
  return 1;
}

/** Set the generate/run menu enable/disable status
 *
 */
void
MainWindow::setRunnableProject(bool runnable)
{
  //  if (runnable)
  // Now, we let tje Gen and Run button enabled but we will have a
  // pre-generation check
    {
      mcGen->enable();
      mcRun->enable();
    }
    /*  else
    {
      mcGen->disable();
      mcRun->disable();
    }
    */
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


/** An icon of the iconlist-based menu was clicked
  *
  * \param _o  Unused paramater.
  * \param _s  Unused paramater.
  * \param idx The index of clicked item. Used to change active panel.
  *
  * \return Always 1.
  *
  */
long
MainWindow::onIconClicked(FXObject* _o,FXSelector _s,void* idx)
{
  unsigned long i = (unsigned long)idx;
  
  if (i == 0)
    {
      projectPane->show();
      collectPane->hide();
      logPane->hide();
      generatPane->hide();
    }
  else if (i == 1)
    {
      projectPane->hide();
      collectPane->show();
      generatPane->hide();
      logPane->hide();
    }
  else if (i == 2)
    {
      projectPane->hide();
      collectPane->hide();
      generatPane->show();
      logPane->hide();
    }
  else
    {
      projectPane->hide();
      collectPane->hide();
      generatPane->hide();
      logPane->show();
      
    }
  splitter->layout();
  return 1;
}

/** Add a message in the log widget
  *
  * \param msg The message to be added.
  *
  */
void
MainWindow::addLogMessage(const FXString& msg)
{
  logger->appendItem(msg);
}

/** The content of the TextField widget used to modify the project name
  * has changed
  *
  * \param _o Unused parameter.
  * \param _s Unused parameter.
  * \param val The new content of the widget to be cast as a FXChar*.
  *
  * \return Always 1.
  *
  */
long
MainWindow::onProjectDetailsChanged(FXObject* _o,FXSelector _s,void* val)
{
  auto pn = (FXchar*)val;
  //  cout << "Project detail changed to '" << pn << "'" << endl;
  setDirty();
  return 1;
}

/** The content of the TextField widget used to modify the project name
  * has changed
  *
  * \param _o Unused.
  * \param _s Unused.
  * \param _d Unused.
  *
  */
long
MainWindow::onProjectDescChanged(FXObject* _o,FXSelector _s,void* _d)
{
  auto d = ftDescription->getText();
  cout << "Description changed to '" << d.text() << "'" << endl;
  setDirty();
  return 1;
}

/** Set the dirty flag to a new value (default to true) and update title
  *
  * It sets the internal ProjectFile object to the exact same value without
  * any check.
  *
  * \param vDirty The new dirty flag value.
  *
  */
void
MainWindow::setDirty(bool vDirty)
{
  dirty = vDirty;
  projectFile.setDirty(vDirty);
  updateTitle();
}

/** Empty the content of all fields
  *
  */
void
MainWindow::resetAllFields()
{
  // Project panel
  tfProjectName->setText("");
  tfProjectAuth->setText("");
  tfProjectVers->setText("");
  tfProjectLice->setText("");
  ftDescription->setText("");
  // Collections panel
  // Log panel
}

/** Launched when the Generator panel path change button is clicked
  *
  */
long
MainWindow::onGenPathClicked(FXObject*,FXSelector,void*)
{
  auto filename = FXFileDialog::getOpenDirectory(this,
						 "Select output directory...",
						 "generatorTest");

  std::cout << filename.text() << std::endl;
  
  
  tfOutputName->setText(filename);  
  return 1;
}

/** The run project callback
  *
  * \param _o Unused parameter.
  * \param _s Unused parameter.
  * \param _v Unused parameter.
  *
  * \return Always 1.
  *
  */
long
MainWindow::onProjectRun(FXObject* _o,FXSelector _s, void* _v)
{
  preGenerationChecks();
  std::cout << "ProRun clicked" << std::endl;

  // Switch to log pane
  onIconClicked(nullptr, 0, (void*)3); 

  GeneratorV1 gv1;
  addLogMessage("Generation started...");

  // Shoulod check for return value/file generation ?
  
  // Run previously generated project
  addLogMessage("Running generated project...");

  if (system(NULL)) puts ("Ok");
  else addLogMessage("Can't run system command!");

  std::string cmd = "cd "+ gv1.getOutputDir() +"&&npm start";
  
  auto i=system(cmd.c_str());
  printf ("The value returned was: %d.\n",i);
  
  return 1;
}

/** A check methods called just before generation/run
  *
  * \return Can generation start ?
  *
  */
bool
MainWindow::preGenerationChecks(void)
{
  bool check = true;
  std::string msg;
  
  if (tfProjectName->getText().empty())
  {
    msg = "Project name can't be null!";
    check = false;
    onIconClicked(nullptr, 0, (void*)0); 

  }

  if (tfOutputName->getText().empty())
  {
    msg = "Generator output isn't setup!";
    check =  false;
    onIconClicked(nullptr, 0, (void*)2); 

  }
  
  if (!check)
    FXMessageBox::warning(this, MBOX_OK, "Generator warning", "%s",
			  msg.c_str());
  
  return check;
}

/** The Project -> Generate callback.
  *
  * \param _o Unused sender information.
  * \param _s Unused selector.
  * \param _d Unused data.
  *
  */
long
MainWindow::onProjectGen(FXObject* _o,FXSelector _s,void* _d)
{
  if (!preGenerationChecks())
    {
      addLogMessage("Can't generate project. Fix previous errors first...");
      return 1;
    }

  // Switch to log pane
  onIconClicked(nullptr, 0, (void*)3); 

  GeneratorV1 gv1;
  addLogMessage("Generation started...");
  gv1.generate();
  addLogMessage("Generation finished...");

  
  return 1;
}

void
MainWindow::copyUiToProjectfile(void)
{
  projectFile.setProjectName(tfProjectName->getText().text());
  projectFile.setProjectAuthor(tfProjectAuth->getText().text());
  projectFile.setGeneratorFilename(tfOutputName->getText().text());

  projectFile.setGeneratorCallnpm(cbCallNpm->getCheck() == TRUE);
}

/** Open the given file
  *
  * \param filename The filename from open file dialog or command line argument.
  *
  */
void
MainWindow::openProjectFile(const std::string& filename)
{
  std::cout << "Opening '" << filename << "' ..." << std::endl;
  projectFile.setFilename(filename);
  projectFile.load();
  updateTitle();

  mcSave->enable();
  
  FXString pna(projectFile.getProjectName().c_str());
  tfProjectName->setText(pna);

  FXString pauth(projectFile.getProjectAuthor().c_str());
  tfProjectAuth->setText(pauth);
    
  FXString gfiln(projectFile.getGeneratorFilename().c_str());
  tfOutputName->setText(gfiln);

  cbCallNpm->setCheck(projectFile.getGeneratorCallnpm());

  this->filename = FXString(filename.c_str());
  
  updateTitle();
}

