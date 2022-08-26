#ifndef __ELECRUD_HPP__
#define __ELECRUD_HPP__

#include <fox-1.6/fx.h>

using namespace FX;

/** The main application object
  *
  */
class Elecrud : public FXApp {
  FXDECLARE(Elecrud)
public:
  Elecrud(const FXString&);
  virtual ~Elecrud();

  long onQuit(FXObject*,FXSelector,void*);
  
  enum{
    ID_CLOSEALL=FXApp::ID_LAST,  //!< Close all documents and exit
    ID_LAST                      //!< Last, unused event ID
    };
  
private:
  Elecrud(){}              //!< Forbidden default constructor
  Elecrud(const Elecrud&); //!< Forbidden copy constructor
  Elecrud& operator=(const Elecrud&); //!< Forbidden affectation operator

public:
  FXIcon* newicon;  //!< The File/New icon
  FXIcon* openicon; //!< The File/Open icon

  FXIcon* projecticon_big; //!< The Project pane icon
  FXIcon* collicon_big;    //!< The Collections icon
  FXIcon* logicon_big;     //!< The Log icon

};
#endif // !__ELECRUD_HPP__
