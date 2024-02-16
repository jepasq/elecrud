/** Defines a simple bool flag for StartupOptions
  *
  * It is defined to handle defference between default options and
  * manually set ones.
  *
  */
class StartupOptionBool
{
public:
  enum StartupOptionType
    {
      SOT_DEFAULT = 0,  //!< Default value programmatically set
      SOT_MANUAL        //!< Was manually set
    };

  
  StartupOptionBool(bool v):
    type(SOT_DEFAULT),
    value(v)
  {
    
  }

  void setValue(bool v)
  {
    type=SOT_MANUAL;
    value = v;
  }

private:
  bool value;
  StartupOptionType type;
};
