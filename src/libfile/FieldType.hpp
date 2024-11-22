#include __FIELD_TYPE_HPP__
#define __FIELD_TYPE_HPP__

#include <fox-1.6/fx.h>

/** An abstract type used as base of all Field types
 *
 **/
class FieldType
{
public:
  const FXString& toString() const=0;

  
};

#endif // !__FIELD_TYPE_HPP__
