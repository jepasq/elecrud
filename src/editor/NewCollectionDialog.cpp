#include "NewCollectionDialog.hpp"

// Map
/*
FXDEFMAP(NewCollectionDialog) NewCollectionDialogMap[]={
  FXMAPFUNC(SEL_COMMAND,NewCollectionDialog::ID_OK,NewCollectionDialog::onCmdOk),
  FXMAPFUNC(SEL_COMMAND,NewCollectionDialog::ID_CANCEL,NewCollectionDialog::onCmdCancel),
};
*/

NewCollectionDialog::NewCollectionDialog(FXWindow *owner):
  FXDialogBox(owner, "New Collection")
{
  new FXHorizontalSeparator(this,SEPARATOR_GROOVE|LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X);
  auto buttons=new FXHorizontalFrame(this,LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH|PACK_UNIFORM_HEIGHT,0,0,0,0,0,0,0,0);
  auto cancelBtn=new FXButton(buttons, "&Canel", NULL, this, ID_CANCEL,
			      LAYOUT_FILL_Y|LAYOUT_RIGHT);
  auto okBtn=new FXButton(buttons, "&Ok", NULL, this, ID_OK,
			  BUTTON_DEFAULT|LAYOUT_CENTER_Y|LAYOUT_RIGHT);
 
  resize(600, 400);
}

long
NewCollectionDialog::onCmdCancel(FXObject*,FXSelector,void*)
{
  return 1;
}

long
NewCollectionDialog::onCmdOk(FXObject*,FXSelector,void*)
{
  return 1;
}

