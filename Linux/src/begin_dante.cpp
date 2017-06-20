//
// begin_dante.cpp for begin_dante.cpp in /home/arthur.kleiber/cpp_indie_studio/Linux
// 
// Made by Arthur K
// Login   <arthur.kleiber>
// 
// Started on  Sun Jun 18 23:32:31 2017 Arthur K
// Last update Sun Jun 18 23:32:32 2017 Arthur K
//

#include "dante.hpp"
#include "dante_gen.hpp"

dante::dante(int argc, int x_give, int y_give, int Xsearch, int Ysearch) {
  this->_argc = argc;
  this->_x_give = x_give;
  this->_y_give = y_give;
  this->_Xsearch = Xsearch;
  this->_Ysearch = Ysearch;
  this->_Xstart = 0;
  this->_Ystart = 0;
  this->_Xend = 0;
  this->_Yend = 0;
  this->_Xdir = 0;
  this->_Ydir = 0;
}

dante::~dante() { }

int dante::length_buffer()
{
  std::string buf;
  std::ifstream fd;
  int size;

  size = 0;
  fd.open ("map_created/map.txt", std::ifstream::in);
  char c = fd.get();
  while (fd.good())
    {
      this->_buf += c;
      size += 1;
      c = fd.get();
    }
  fd.close();
  return (size);
}

int dante::getXend()
{
  int idx;

  idx = 0;
  while (this->_buf[idx] != 10)
    idx += 1;
  return idx;
}

int dante::getYend()
{
  int idx;
  int count;

  count = 0;
  idx = 0;
  while(this->_buf[idx] != 0)
    {
      if (this->_buf[idx] == 10)
	count += 1;
      idx += 1;
    }
  return count + 1;
}

void dante::start()
{
  this->_Xend = this->getXend();
  this->_Yend = this->getYend();
}

int begin_dante(int argc, int arg, int arg2)
{
  dante dante(argc, arg, arg2, 5, 5);
  danteGen gen(50, 50, 4);

  if (dante.length_buffer() == 1)
    return (0);
  dante.map = gen.map;
  gen.create_map();
  dante.start();
  return (0);
}
