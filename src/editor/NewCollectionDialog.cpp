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

NewCollectionDialog::~NewCollectionDialog()
{
  delete tfName;
  delete ftDescription;
}


/** UI construction method
 *
 * Called from the constructor to build UI. It notably instanciates
 * @ref tfName and @ref ftDescription dynamically so these two pointers
 * need to be manually deleted in destructor.
 *
 */
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
  tfName = new FXTextField(pph1, 60, this, ID_COLNAM);
  
  new FXLabel(pane, "Multiline description and notes :");
  ftDescription = new FXText(pane, this, ID_COLDES,
			     FRAME_RAISED|FRAME_THICK|LAYOUT_FILL_X|LAYOUT_FILL_Y);
    
  resize(600, 400);
}

/** The dialog's Cancel button callback
 *
 * Stop the modal execution of this dialog with a `FALSE` status then hide it.
 *
 * @return Always return 1 to tell fox-toolkit the event has been consumed.
 *
 */
long
NewCollectionDialog::onCmdCancel(FXObject*,FXSelector,void*)
{
  getApp()->stopModal(this,FALSE); // From FXDialogBox sources
  hide();
  return 1;
}

/** The dialog's Ok button callback
 *
 * Stop the modal execution of this dialog with a `TRUE` status then hide it.
 *
 * @return Always return 1 to tell fox-toolkit the event has been consumed.
 *
 */
long
NewCollectionDialog::onCmdOk(FXObject*,FXSelector,void*)
{
  getApp()->stopModal(this,TRUE); // From FXDialogBox sources
  hide();
  return 1;
}

/** Get the trimmed version of the new collection name
 *
 *  @return The name as a FXString.
 *
 */  
FXString
NewCollectionDialog::getName(void) const
{
  return tfName->getText().trim();
}

/** Get the trimmed version of the new collection's description
 *
 *  @return The name as a FXString.
 *
 */  
FXString
NewCollectionDialog::getDescription(void) const
{
  return ftDescription->getText().trim();
}
