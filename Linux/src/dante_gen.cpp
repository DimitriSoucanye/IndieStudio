#include <ctime>
#include "dante_gen.hpp"

danteGen::danteGen(int x, int y, int player)
{
  this->_x = x;
  this->_y = y;
  this->_countPlayer = player;
}

danteGen::~danteGen() { }

static char		verify(int tmp1, int tmp2, int _x, int _y)
{
  if (tmp1 == _x - 1 && tmp2 == _y - 1)
    return ('D');
  else if (((rand() % 4) + 1) == 1)
    return ('X');
  else
    return ('*');
}

std::string danteGen::create_map()
{
  std::fstream fichier;
  int tmp1;
  int tmp2;
  int count_key;
  int count_monster;
  int player;

  player = 0;
  fichier.open("map_created/map.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
  tmp1 = 0;
  count_key = 0;
  count_monster = 0;
  tmp2 = 0;
  srand(static_cast<unsigned int>(time(NULL)));
  while (tmp1 != _x)
    {
      while (tmp2 != _y)
        {
          if (player < this->_countPlayer)
	    {
	      fichier << "P";
	      player += 1;
	    }
	  else if (((rand() % 8) + 1) == 1 && count_key == 0 && tmp1 >= ((rand() % _x)))
	    {
	      fichier << "K";
	      count_key += 1;
	    }
	  else if (((rand() % 8) + 1) == 1 && count_monster < 4 && tmp1 >= (this->_x / 4) * count_monster)
	    {
	      map[tmp1] = tmp2;
	      fichier << "M";
	      count_monster += 1;
	    }
	  else
	    fichier << verify(tmp1, tmp2, _x, _y);
	  tmp2++;
        }
      tmp2 = 0;
      tmp1++;
      if (tmp1 != _x)
	fichier << std::endl;
    }
  fichier.close();
  return ("");
}
