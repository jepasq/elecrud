#ifndef __NEW_COLLECTION_DIALOG_HPP__
#define __NEW_COLLECTION_DIALOG_HPP__

/** @file NewCollectionDialog.hpp
 *  Collection adding dialog header.
 *
 */

#include <fox-1.6/fx.h>

/** Here is a fox toolkit, eventually modal, dialog used to enter new
 *  collection-related fields (name, description).
 *
 *  Returned values are trimed to avoid unwanted space at the start or the end.
 *  These values are also stored in temporary variables on Ok button callback
 *  to avoid segfault when accessing UI widgets after hide() call.
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

  const FXString& getName(void) const;
  const FXString& getDescription(void) const;
  
protected:
  NewCollectionDialog(){}    // Needed by FXIMPLEMENT macro
  void construct();

private:
  FXTextField* tfName;        //!< The Name textfield
  FXText*      ftDescription; //!< The The description multiline text

  FXString name; //!< Temporary name returned by getter
  FXString desc; //!< Temporary description returned by getter
};

#endif // !__NEW_COLLECTION_DIALOG_HPP__

