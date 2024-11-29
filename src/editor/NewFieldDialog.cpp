#include "NewFieldDialog.hpp"

#include "FieldType.hpp"
#include "FieldTypeFactory.hpp"
#include "Collection.hpp"

#include <stdexcept>

#include <sstream>

// Map
FXDEFMAP(NewFieldDialog) NewFieldDialogMap[]={
  FXMAPFUNC(SEL_COMMAND,NewFieldDialog::ID_OK,NewFieldDialog::onCmdOk),
  FXMAPFUNC(SEL_COMMAND,NewFieldDialog::ID_CANCEL,NewFieldDialog::onCmdCancel),
};

// Object implementation
FXIMPLEMENT(NewFieldDialog, FXDialogBox, NewFieldDialogMap,
	    ARRAYNUMBER(NewFieldDialogMap))

/** @param coll The parent Collection. Shouldn't be nullptr.
 *
 * @exception std::invalid_argument If the parent collection is invalid.
 *
 */

NewFieldDialog::NewFieldDialog(FXWindow *owner, Collection* parent):
  FXDialogBox(owner, "New Field")
{
  name = "aze";
  desc = "zer";
  
  checkCollection(parent);

  // New title
  std::ostringstream oss;
  auto n = parent->getName().text();
  oss << "New Field for collection '" << n << "'";
  setTitle(oss.str().c_str());

  construct();
}

NewFieldDialog::~NewFieldDialog()
{
  delete tfName;
  delete ftDescription;
}

// Declared static to be easily unit tested 
void
NewFieldDialog::checkCollection(Collection* parent)
{
  if (parent  == nullptr)
    throw std::invalid_argument("The parent Collection shouldn't be a nullptr");
}


/** UI construction method
 *
 * Called from the constructor to build UI. It notably instanciates
 * @ref tfName and @ref ftDescription dynamically so these two pointers
 * need to be manually deleted in destructor.
 *
 */
void
NewFieldDialog::construct()
{
  auto buttons=new FXHorizontalFrame(this,LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH|PACK_UNIFORM_HEIGHT,0,0,0,0,0,0,0,0);
  auto okBtn=new FXButton(buttons, "&Ok", NULL, this, ID_OK,
			  BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|LAYOUT_CENTER_Y|LAYOUT_RIGHT);
  auto cancelBtn=new FXButton(buttons, "&Canel", NULL, this, ID_CANCEL,
			      FRAME_RAISED|FRAME_THICK|LAYOUT_FILL_Y|LAYOUT_RIGHT);
  new FXHorizontalSeparator(this,SEPARATOR_GROOVE|LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X);

  auto pane = new FXVerticalFrame(this);
  auto pph1 = new FXHorizontalFrame(pane);
  auto labPrjName=new FXLabel(pph1, "Field name :", 0, LAYOUT_FIX_WIDTH );
  labPrjName->setWidth(120);
  tfName = new FXTextField(pph1, 60, this, ID_COLNAM);

  // Type
  auto pph2 = new FXHorizontalFrame(pane);
  new FXLabel(pph2, "Field type :", 0, LAYOUT_FIX_WIDTH);
  cbType = new FXComboBox(pph2, 60, this, ID_COLNAM /* Must be changed */);

  // Feed types
  FieldTypeFactory ftf;
  for (auto const& i : ftf.getKeys())
    cbType->appendItem(FXString(i.c_str()));
  
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
NewFieldDialog::onCmdCancel(FXObject*,FXSelector,void*)
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
NewFieldDialog::onCmdOk(FXObject*,FXSelector,void*)
{
  // Setting temporary values here to avoid a segfault.
  name = tfName->getText().trim();
  desc = ftDescription->getText().trim();
  
  getApp()->stopModal(this,TRUE); // From FXDialogBox sources
  hide();
  return 1;
}

/** Get the trimmed version of the new collection name
 *
 *  @return The name as a FXString.
 *
 */  
const FXString&
NewFieldDialog::getName(void) const
{
  return name;
}

/** Get the trimmed version of the new collection's description
 *
 *  @return The name as a FXString.
 *
 */  
const FXString&
NewFieldDialog::getDescription(void) const
{
  return desc;
}
