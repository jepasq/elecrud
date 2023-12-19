/** \file Elecrud.cpp
  * The main editor application implementation file.
  *
  */

#include "Elecrud.hpp"

//#include <FXGIFIcon.h>

#include "icons.hpp"

/// The applicarion event Map
FXDEFMAP(Elecrud) ElecrudMap[]={
    FXMAPFUNC(SEL_SIGNAL,Elecrud::ID_QUIT,Elecrud::onQuit),
    /* FXMAPFUNC(SEL_SIGNAL,Adie::ID_CLOSEALL,Adie::onCmdCloseAll),
  FXMAPFUNC(SEL_COMMAND,Adie::ID_CLOSEALL,Adie::onCmdCloseAll),
  FXMAPFUNC(SEL_COMMAND,Adie::ID_SYNTAXPATHS,Adie::onCmdSyntaxPaths),
  FXMAPFUNC(SEL_UPDATE,Adie::ID_SYNTAXPATHS,Adie::onUpdSyntaxPaths),
  */
  };

FXIMPLEMENT(Elecrud,FXApp,ElecrudMap,ARRAYNUMBER(ElecrudMap))

/** The elecrud application named constructor
  *
  * \param name The fox application name.
  *
  */
Elecrud::Elecrud(const FXString& name):
  FXApp(name),
  newicon(nullptr),
  openicon(nullptr)
{
  // Make some icons; these are shared between all text windows
  /*  newicon=new FXGIFIcon(this,new_gif,0,IMAGE_ALPHAGUESS);
  openicon=new FXGIFIcon(this,open_gif);
  */

  newicon  = new FXGIFIcon(this, new_gif);
  openicon = new FXGIFIcon(this, open_gif);


  projecticon_big = new FXGIFIcon(this, project_big);
  collicon_big = new FXGIFIcon(this, coll_big);
  genicon_big = new FXGIFIcon(this, gen_big);
  logicon_big = new FXGIFIcon(this, log_big);
  }

/** Needed destructor overriding FXApp's one */
Elecrud::~Elecrud()
{

}

/** We asked to quit application certainly with File/Quit menu
  *
  */
long
Elecrud::onQuit(FXObject*,FXSelector,void*)
{
  return 0;
}
