#include "NewCollectionDialog.hpp"

// Map
FXDEFMAP(NewCollectionDialog) NewCollectionDialogMap[]={
  FXMAPFUNC(SEL_COMMAND,NewCollectionDialog::ID_OK,NewCollectionDialog::onCmdOk),
  FXMAPFUNC(SEL_COMMAND,NewCollectionDialog::ID_CANCEL,NewCollectionDialog::onCmdCancel),
};

// Object implementation
FXIMPLEMENT(NewCollectionDialog, FXDialogBox, NewCollectionDialogMap,
	    ARRAYNUMBER(NewCollectionDialogMap))

NewCollectionDialog::NewCollectionDialog(FXWindow *owner):
  FXDialogBox(owner, "New Collection")
{
  construct();
}

void
NewCollectionDialog::construct()
{
  auto buttons=new FXHorizontalFrame(this,LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH|PACK_UNIFORM_HEIGHT,0,0,0,0,0,0,0,0);
  auto okBtn=new FXButton(buttons, "&Ok", NULL, this, ID_OK,
			  BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|LAYOUT_CENTER_Y|LAYOUT_RIGHT);
  auto cancelBtn=new FXButton(buttons, "&Canel", NULL, this, ID_CANCEL,
			      FRAME_RAISED|FRAME_THICK|LAYOUT_FILL_Y|LAYOUT_RIGHT);
  new FXHorizontalSeparator(this,SEPARATOR_GROOVE|LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X);
 
  resize(600, 400);
}

long
NewCollectionDialog::onCmdCancel(FXObject*,FXSelector,void*)
{
  getApp()->stopModal(this,FALSE); // From FXDialogBox sources
  hide();
  return 1;
}

long
NewCollectionDialog::onCmdOk(FXObject*,FXSelector,void*)
{
  getApp()->stopModal(this,TRUE); // From FXDialogBox sources
  hide();
  return 1;
}

