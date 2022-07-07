#ifndef __ELECRUD_HPP__
#define __ELECRUD_HPP__

#include <fox-1.6/fx.h>

using namespace FX;

class Elecrud : public FXApp {
  FXDECLARE(Elecrud)
public:
  Elecrud(const FXString&);
  virtual ~Elecrud();

private:
  Elecrud(){}
  Elecrud(const Elecrud&);
  Elecrud& operator=(const Elecrud&);
  
  FXIcon* newicon;
  FXIcon* openicon;  
};
#endif // !__ELECRUD_HPP__
