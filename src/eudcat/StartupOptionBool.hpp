#ifndef __STARTUP_OPTION_BOOL_HPP__
#define __STARTUP_OPTION_BOOL_HPP__


enum StartupOptionType
  {
    SOT_DEFAULT = 0,  //!< Default value programmatically set
    SOT_MANUAL        //!< Was manually set
  };

/** Defines a simple bool flag for StartupOptions
  *
  * It is defined to handle defference between default options and
  * manually set ones.
  *
  */
class StartupOptionBool
{
public:

  StartupOptionBool(bool v);
  void setValue(bool v);

  bool              getValue() const;
  StartupOptionType getType() const;
  
private:
  bool value;
  StartupOptionType type;
};

#endif // !__STARTUP_OPTION_BOOL_HPP__
