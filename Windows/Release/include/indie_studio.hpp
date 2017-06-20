#ifndef INDIE_STUDIO_HPP
# define INDIE_STUDIO_HPP

#include <irr/irrlicht.h>
#include <irrKlang.h>
#include <receiver.hpp>
#include <string>
#include <iostream>
#include <functional>
#include <fstream>
#include <map>

enum			collisionID
  {
    PLAYER,
    MOB,
    ATQ,
    POTION,
    DOOR,
    KEY,
    SPAWNER,
    WALL,
    FLOOR,
  };

typedef			std::function<void(irr::video::IVideoDriver *,
				   irr::scene::ISceneManager *,
				   irr::scene::IMetaTriangleSelector *,
				   irr::f64, irr::f64, irr::f64)>param;

int			begin_dante(int, int, int);
int			launch_game(irr::IrrlichtDevice *,
				    irr::video::IVideoDriver *,
				    irr::scene::ISceneManager *,
				    MyEventReceiver &,
				    irrklang::ISoundEngine *);
void			print_menu(irr::IrrlichtDevice *, irr::video::IVideoDriver *,
				   irr::scene::ISceneManager *, MyEventReceiver &,
				   irrklang::ISoundEngine *);
void			print_game_over(irr::IrrlichtDevice *,
					irr::video::IVideoDriver *,
					irr::scene::ISceneManager *,
					MyEventReceiver &,
					irrklang::ISoundEngine *);
void			floorGenerator(irr::video::IVideoDriver *, irr::scene::ISceneManager *,
			       irr::scene::IMetaTriangleSelector *, irr::f64, irr::f64, irr::f64);
std::map<char, param>	ptrmap(irr::video::IVideoDriver *,
			       irr::scene::ISceneManager *,
			       irr::scene::IMetaTriangleSelector *,
			       irr::f64, irr::f64, irr::f64);

#endif /* !INDIE_STUDIO_HPP */
