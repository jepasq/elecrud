#include "MainWindow.hpp"

// Message Map for the Scribble Window class
FXDEFMAP(MainWindow) MainWindowMap[]={
  //________Message_Type_____________________ID____________Message_Handler_______
  //  FXMAPFUNC(SEL_PAINT,             MainWindow::ID_CANVAS, MainWindow::onPaint),
  // FXMAPFUNC(SEL_LEFTBUTTONPRESS,   MainWindow::ID_CANVAS, MainWindow::onMouseDown),
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
MainWindow::MainWindow(FXApp* a, const FX::FXString& windowTitle):
FXMainWindow(a, windowTitle, NULL, NULL, DECOR_ALL, 0, 0, 640, 480)
{

}

MainWindow::~MainWindow()
{

}

void
MainWindow::create()
{
  // Create the windows
  FXMainWindow::create();
  // Make the main window appear
  show(PLACEMENT_SCREEN);
}

