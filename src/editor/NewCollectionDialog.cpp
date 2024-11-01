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

  auto pane = new FXVerticalFrame(this);
  auto pph1 = new FXHorizontalFrame(pane);
  auto labPrjName=new FXLabel(pph1, "Collection name :", 0, LAYOUT_FIX_WIDTH );
  labPrjName->setWidth(120);
  auto tfCollName = new FXTextField(pph1, 60, this, ID_COLNAM);
  
  new FXLabel(pane, "Multiline description and notes :");
  auto ftDescription = new FXText(pane, this, ID_COLDES,
			     LAYOUT_FILL_X|LAYOUT_FILL_Y);
  
  
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

