#ifndef MAP_HPP
# define MAP_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <indie_studio.hpp>
#include <irr/irrlicht.h>

namespace mapGenerator
{
  void                              generateMap(irr::video::IVideoDriver*, irr::scene::ISceneManager*, irr::scene::IMetaTriangleSelector*);
  void                              create_cube(irr::video::IVideoDriver*, irr::scene::ISceneManager*, irr::scene::IMetaTriangleSelector*, irr::f64, irr::f64, irr::f64);
  void                              create_cube_wall(irr::video::IVideoDriver*, irr::scene::ISceneManager*, irr::scene::IMetaTriangleSelector*, irr::f64, irr::f64, irr::f64);
};

#endif
