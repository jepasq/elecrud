#ifndef __NEW_FIELD_DIALOG_HPP__
#define __NEW_FIELD_DIALOG_HPP__

/** @file NewFieldDialog.hpp
 *  Field adding dialog header.
 *
 */

#include <fox-1.6/fx.h>

// Forward declarations
class Collection;
class FieldType;
// End of forward declarationd

/** Here is a fox toolkit-based, eventually modal, dialog used to add a new
 *  field to a collection
 *
 */
class NewFieldDialog : public FXDialogBox
{
  FXDECLARE(NewFieldDialog)
public:
  enum
    {
      ID_CANCEL=FXDialogBox::ID_LAST,  //!< The Cancel button
      ID_OK,                           //!< The OK button
      ID_COLNAM,                       //!< The collection name input field
      ID_COLDES,        //!< The collection description input field
      ID_LAST
    };
 
  NewFieldDialog(FXWindow*, Collection*);
  virtual ~NewFieldDialog();

  long onCmdCancel(FXObject*,FXSelector,void*);
  long onCmdOk(FXObject*,FXSelector,void*);

  const FXString& getName(void) const;
  const FXString& getDescription(void) const;

  static void checkCollection(Collection*);
  
protected:
  NewFieldDialog(){}    // Needed by FXIMPLEMENT macro
  void construct();

private:
  FXTextField* tfName;        //!< The Name textfield
  FXComboBox*  cbType;        //!< The type combobox
  FXText*      ftDescription; //!< The The description multiline text

  FXString name; //!< Temporary name returned by getter
  FXString desc; //!< Temporary description returned by getter

  FieldType*   type;  //!< The type of this field (from FieldTypeFactory)
};

#endif // !__NEW_FIELD_DIALOG_HPP__

