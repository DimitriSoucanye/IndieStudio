#include <iostream>
#include <fstream>
#include <string>
#include <map>

class dante
{
private:
  int _argc;
  int _Xstart;
  int _Ystart;
  int _Xend;
  int _Yend;
  int _Xdir;
  int _Ydir;
  int _Xsearch;
  int _Ysearch;
  int _x_give;
  int _y_give;
  std::string _buf;
public:
  dante(const int _argc, int, int, int _Xsearch, int _Ysearch);
  virtual ~dante();

  int length_buffer();
  int getXend();
  int getYend();
  int profondeur();
  void start();


  std::map<int, int> map;
};
