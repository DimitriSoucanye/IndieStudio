#include <iostream>
#include <fstream>
#include <string>
#include <map>

class danteGen
{
private:
  int _x;
  int _y;
  int _countPlayer;
public:
  danteGen(int _x, int _y, int _countPlayer);
  virtual ~danteGen();
  std::string create_map();
  void add_player();
  std::map<int, int> map;
};
