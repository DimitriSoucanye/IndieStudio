//
// menu.cpp for menu.cpp in /home/arthur.kleiber/cpp_indie_studio/Dan2
// 
// Made by Arthur K
// Login   <arthur.kleiber>
// 
// Started on  Sat Jun 17 16:23:26 2017 Arthur K
// Last update Sun Jun 18 23:33:13 2017 Arthur K
//

#include <indie_studio.hpp>
#include <map.hpp>
#include <ctime>
#include <collision.hpp>
#include <receiver.hpp>
#include <irrKlang.h>

void				print_win(irr::IrrlichtDevice *device,
					  irr::video::IVideoDriver *driver,
					  irr::scene::ISceneManager *sceneManager,
					  MyEventReceiver & receiver,
					  irrklang::ISoundEngine *engine)
{
  irr::video::ITexture		*win_img;
  time_t			t0;

  win_img = driver->getTexture("media/win.jpg");
  sceneManager->clear();
  t0 = time(NULL);
  while (static_cast<unsigned>(time(NULL) - t0) < 7)
    {
      driver->beginScene(true, true,
			 irr::video::SColor(255, 255, 255, 255));
      driver->draw2DImage(win_img, irr::core::position2d<irr::s32>(0, 0),
			  irr::core::rect<irr::s32>(0, 0, 1600, 900), NULL,
			  irr::video::SColor(255, 255, 255, 255), true);
      sceneManager->drawAll();
      driver->endScene();
    }
  sceneManager->clear();
  print_menu(device, driver, sceneManager, receiver, engine);
}

void				print_game_over(irr::IrrlichtDevice *device,
						irr::video::IVideoDriver *driver,
						irr::scene::ISceneManager *sceneManager,
						MyEventReceiver & receiver,
						irrklang::ISoundEngine *engine)
{
  irrklang::ISoundEngine	*death_sound;
  irr::video::ITexture		*game_over_img;
  time_t			t0;

  death_sound = irrklang::createIrrKlangDevice();
  death_sound->setSoundVolume(1);
  death_sound->play2D("media/death.mp3", false);
  game_over_img = driver->getTexture("media/game_over.jpg");
  sceneManager->clear();
  t0 = time(NULL);
  while (static_cast<unsigned>(time(NULL) - t0) < 7)
    {
      driver->beginScene(true, true,
			 irr::video::SColor(255, 255, 255, 255));
      driver->draw2DImage(game_over_img, irr::core::position2d<irr::s32>(0, 0),
			  irr::core::rect<irr::s32>(0, 0, 1600, 900), NULL,
			  irr::video::SColor(255, 255, 255, 255), true);
      sceneManager->drawAll();
      driver->endScene();
    }
  sceneManager->clear();
  print_menu(device, driver, sceneManager, receiver, engine);
}

void			print_menu(irr::IrrlichtDevice *device,
				   irr::video::IVideoDriver *driver,
				   irr::scene::ISceneManager *sceneManager,
				   MyEventReceiver & receiver,
				   irrklang::ISoundEngine *engine)
{
  irr::video::ITexture		*menu_img;
  irr::gui::IGUIEnvironment	*gui;
  irr::gui::IGUIFont		*font;
  irr::gui::IGUIButton		*button_launch;
  irr::gui::IGUIButton		*button_exit;
  time_t			t0;

  device->getCursorControl()->setVisible(true);
  gui = device->getGUIEnvironment();
  font = gui->getFont("obj/fontlucida.png");
  button_launch = gui->addButton(irr::core::rect<irr::s32>(250, 600, 450, 650),
				 0, -1, L"LAUNCH GAME");
  button_exit = gui->addButton(irr::core::rect<irr::s32>(250, 670, 450, 720),
			       0, -1, L"EXIT");
  t0 = time(NULL);
  engine->play2D("media/menu.mp3", true);
  menu_img = driver->getTexture("media/les_killers_du_94.jpg");
  while (static_cast<unsigned>(time(NULL) - t0) < 4)
    {
      driver->beginScene(true, true,
			 irr::video::SColor(255,255,255,255));
      driver->draw2DImage(menu_img, irr::core::position2d<irr::s32>(0, 0),
			  irr::core::rect<irr::s32>(0,0,1600,900), 0,
			  irr::video::SColor(255, 255, 255, 255), true);
      sceneManager->drawAll();
      driver->endScene();
    }
  menu_img = driver->getTexture("media/menu.jpg");
  button_launch->setOverrideFont(font);
  button_exit->setOverrideFont(font);
  while (device->run())
    {
      driver->beginScene(true, true,
			 irr::video::SColor(255,255,255,255));
      driver->draw2DImage(menu_img, irr::core::position2d<irr::s32>(0, 0),
			  irr::core::rect<irr::s32>(0, 0, 1600, 900), 0,
			  irr::video::SColor(255, 255, 255, 255), true);
      sceneManager->drawAll();
      gui->drawAll();
      driver->endScene();
      if (button_launch->isPressed() == true)
	break ;
      else if (button_exit->isPressed() == true)
	{
	  engine->drop();
	  device->drop();
	  exit(0);
	}
    }
  gui->clear();
  launch_game(device, driver, sceneManager, receiver, engine);
}
