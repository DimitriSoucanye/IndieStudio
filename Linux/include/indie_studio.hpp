//
// indie_studio.hpp for indie_studio in /home/arthur.kleiber/cpp_indie_studio/Dan2
//
// Made by Arthur K
// Login   <arthur.kleiber>
//
// Started on  Sat Jun 17 19:33:40 2017 Arthur K
// Last update Sun Jun 18 22:35:41 2017 Arthur K
//

#ifndef INDIE_STUDIO_HPP
# define INDIE_STUDIO_HPP

# include <irr/irrlicht.h>
# include <irrKlang.h>
# include <receiver.hpp>
# include <string>
# include <iostream>
# include <functional>
# include <fstream>
# include <map>

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
    EXIT,
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
void			print_win(irr::IrrlichtDevice *,
				  irr::video::IVideoDriver *,
				  irr::scene::ISceneManager *,
				  MyEventReceiver &,
				  irrklang::ISoundEngine *); 
void			print_pv(irr::video::IVideoDriver *, int const &);
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

typedef std::function<irr::core::vector3df(irrklang::ISoundEngine*, irr::core::vector3df, const irr::f32, const irr::f32, irr::scene::IAnimatedMeshSceneNode *)> t_key;

std::map<irr::EKEY_CODE, t_key> mapMove(irr::EKEY_CODE, irrklang::ISoundEngine*, irr::core::vector3df, const irr::f32, const irr::f32, irr::scene::IAnimatedMeshSceneNode *);
irr::core::vector3df	keyZ(irrklang::ISoundEngine*, irr::core::vector3df, const irr::f32, const irr::f32, irr::scene::IAnimatedMeshSceneNode *);
irr::core::vector3df	keyS(irrklang::ISoundEngine*, irr::core::vector3df, const irr::f32, const irr::f32, irr::scene::IAnimatedMeshSceneNode *);
irr::core::vector3df	keyQ(irrklang::ISoundEngine*, irr::core::vector3df, const irr::f32, const irr::f32, irr::scene::IAnimatedMeshSceneNode *);
irr::core::vector3df	keyD(irrklang::ISoundEngine*, irr::core::vector3df, const irr::f32, const irr::f32, irr::scene::IAnimatedMeshSceneNode *);

typedef std::function<irr::core::vector3df(irr::core::vector3df, const irr::f32, const irr::f32)> t_projectile;

std::map<irr::core::vector3df, t_projectile> initProjo(irr::core::vector3df, const irr::f32, const irr::f32);
irr::core::vector3df	goRight(irr::core::vector3df, const irr::f32, const irr::f32);
irr::core::vector3df	goLeft(irr::core::vector3df, const irr::f32, const irr::f32);
irr::core::vector3df	goUp(irr::core::vector3df, const irr::f32, const irr::f32);
irr::core::vector3df	goDown(irr::core::vector3df, const irr::f32, const irr::f32);

#endif /* !INDIE_STUDIO_HPP */
