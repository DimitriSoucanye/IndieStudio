//
// hud.cpp for hud.cpp in /home/arthur.kleiber/cpp_indie_studio/Dan2
// 
// Made by Arthur K
// Login   <arthur.kleiber>
// 
// Started on  Sat Jun 17 19:38:18 2017 Arthur K
// Last update Sun Jun 18 19:16:31 2017 Arthur K
//

#include <irr/irrlicht.h>
#include "indie_studio.hpp"

void			print_pv(irr::video::IVideoDriver *driver,
				 int const & pv)
{
  driver->draw2DRectangle(irr::video::SColor(255, 0, 0, 0),
			  irr::core::rect<irr::s32>(15, 15, 325, 45));
  driver->draw2DRectangle(irr::video::SColor(255, 255, 0, 0),
			  irr::core::rect<irr::s32>(20, 20, 320, 40));
  driver->draw2DRectangle(irr::video::SColor(255, 0, 255, 0),
			  irr::core::rect<irr::s32>(20, 20, pv * 3 + 20, 40));
}
