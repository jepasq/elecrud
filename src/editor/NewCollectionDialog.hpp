#ifndef __NEW_COLLECTION_DIALOG_HPP__
#define __NEW_COLLECTION_DIALOG_HPP__

#include <fox-1.6/fx.h>

class NewCollectionDialog : public FXDialogBox
{
public:
  enum
    {
      ID_CANCEL=FXDialogBox::ID_LAST,
      ID_OK,
      ID_LAST
    };
 
  NewCollectionDialog(FXWindow*);

  long onCmdCancel(FXObject*,FXSelector,void*);
  long onCmdOk(FXObject*,FXSelector,void*);
  
};

#endif // !__NEW_COLLECTION_DIALOG_HPP__

