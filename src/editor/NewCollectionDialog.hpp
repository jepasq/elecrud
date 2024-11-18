#ifndef __NEW_COLLECTION_DIALOG_HPP__
#define __NEW_COLLECTION_DIALOG_HPP__

#include <fox-1.6/fx.h>

/** Here is a fox toolkit, eventually modal, dialog used to enter new
 *  collection-related fields (name, description).
 *
 * Returned value are trimed to avoid unwanted space at the start or the end.
 *
 */
class NewCollectionDialog : public FXDialogBox
{
  FXDECLARE(NewCollectionDialog)
public:
  enum
    {
      ID_CANCEL=FXDialogBox::ID_LAST,  //!< The Cancel button
      ID_OK,                           //!< The OK button
      ID_COLNAM,                       //!< The collection name input field
      ID_COLDES,        //!< The collection description input field
      ID_LAST
    };
 
  NewCollectionDialog(FXWindow*);
  virtual ~NewCollectionDialog();

  long onCmdCancel(FXObject*,FXSelector,void*);
  long onCmdOk(FXObject*,FXSelector,void*);

  FXString getName(void) const;
  FXString getDescription(void) const;
  
protected:
  NewCollectionDialog(){}    // Needed by FXIMPLEMENT macro
  void construct();

private:
  FXTextField* tfName;        //!< The Name textfield
  FXText*      ftDescription; //!< The The description multiline text

};

#endif // !__NEW_COLLECTION_DIALOG_HPP__

