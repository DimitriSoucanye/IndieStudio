//
// main.cpp for main.cpp in /home/arthur.kleiber/cpp_indie_studio/Dan2
//
// Made by Arthur K
// Login   <arthur.kleiber>
//
// Started on  Sat Jun 17 17:10:57 2017 Arthur K
// Last update Sun Jun 18 22:56:15 2017 Arthur K
//

#include <indie_studio.hpp>
#include <map.hpp>
#include <collision.hpp>
#include <receiver.hpp>
#include <irrKlang.h>

std::map<irr::core::vector3df, t_projectile>	initProjo(irr::core::vector3df direction, const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime)
{
    std::map<irr::core::vector3df, t_projectile>	map;

    auto l1 = [] (irr::core::vector3df direction, const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime) {return goUp(direction, MOVEMENT_SPEED, frameDeltaTime);};
    map[irr::core::vector3df(0, 90, 0)] = l1;
    auto l2 = [] (irr::core::vector3df direction, const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime) {return goDown(direction, MOVEMENT_SPEED, frameDeltaTime);};
    map[irr::core::vector3df(0, 270, 0)] = l2;
    auto l3 = [] (irr::core::vector3df direction, const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime) {return goLeft(direction, MOVEMENT_SPEED, frameDeltaTime);};
    map[irr::core::vector3df(0, 0, 0)] = l3;
    auto l4 = [] (irr::core::vector3df direction, const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime) {return goRight(direction, MOVEMENT_SPEED, frameDeltaTime);};
    map[irr::core::vector3df(0, 180, 0)] = l4;
    return (map);
}

std::map<irr::EKEY_CODE, t_key>	mapMove(irr::EKEY_CODE code,
					irrklang::ISoundEngine* walk_sound,
					irr::core::vector3df nodePosition,
					const irr::f32 MOVEMENT_SPEED,
					const irr::f32 frameDeltaTime,
					irr::scene::IAnimatedMeshSceneNode *node)
{
    std::map<irr::EKEY_CODE, t_key>	map;

    auto m1 = [] (irrklang::ISoundEngine* walk_sound,
		  irr::core::vector3df nodePosition,
		  const irr::f32 MOVEMENT_SPEED,
		  const irr::f32 frameDeltaTime,
		  irr::scene::IAnimatedMeshSceneNode *node)
      {
	return keyZ(walk_sound, nodePosition, MOVEMENT_SPEED, frameDeltaTime, node);
      };
    map[irr::KEY_KEY_Z] = m1;
    auto m2 = [] (irrklang::ISoundEngine* walk_sound,
		  irr::core::vector3df nodePosition,
		  const irr::f32 MOVEMENT_SPEED,
		  const irr::f32 frameDeltaTime,
		  irr::scene::IAnimatedMeshSceneNode *node)
      {
	return keyS(walk_sound, nodePosition, MOVEMENT_SPEED, frameDeltaTime, node);
      };
    map[irr::KEY_KEY_S] = m2;
    auto m3 = [] (irrklang::ISoundEngine* walk_sound,
		  irr::core::vector3df nodePosition,
		  const irr::f32 MOVEMENT_SPEED,
		  const irr::f32 frameDeltaTime,
		  irr::scene::IAnimatedMeshSceneNode *node)
      {
      return keyQ(walk_sound, nodePosition, MOVEMENT_SPEED, frameDeltaTime, node);
    };
    map[irr::KEY_KEY_Q] = m3;
    auto m4 = [] (irrklang::ISoundEngine* walk_sound,
		  irr::core::vector3df nodePosition,
		  const irr::f32 MOVEMENT_SPEED,
		  const irr::f32 frameDeltaTime,
		  irr::scene::IAnimatedMeshSceneNode *node)
      {
	return keyD(walk_sound, nodePosition, MOVEMENT_SPEED, frameDeltaTime, node);
      };
    map[irr::KEY_KEY_D] = m4;
    return (map);
}

void				parse_map(irr::video::IVideoDriver *driver,
					  irr::scene::ISceneManager *sceneManager,
					  irr::scene::IMetaTriangleSelector *metaSelector)
{
  std::streampos		size;
  char				*memblock;
  int				idx = 0;
  irr::f64			x = 0.0f;
  irr::f64			z = 0.0f;

  std::ifstream			file ("map_created/map2.txt",
				      std::ios::in | std::ios::binary | std::ios::ate);
  if (file.is_open())
    {
      size = file.tellg();
      memblock = new char[size];
      file.seekg(0, std::ios::beg);
      file.read(memblock, size);
      file.close();
    }
  std::map<char, std::function<void(irr::video::IVideoDriver *driver,
				    irr::scene::ISceneManager *sceneManager,
				    irr::scene::IMetaTriangleSelector *metaSelector,
				    irr::f64 x, irr::f64 y, irr::f64 z)>> generationOrders;
  generationOrders = ptrmap(driver, sceneManager, metaSelector, x, 5.0f, z);
  while (idx++ < size)
    {
      if (memblock[idx] == 'Y')
	break;
      else if (memblock[idx] != 'Z')
	{
	  floorGenerator(driver, sceneManager, metaSelector, x, 0.0f, z);
	  generationOrders[memblock[idx]](driver, sceneManager, metaSelector, x, 5.0f, z);
	  x += 10.0f;
	}
      else
	{
	  x = 0.0f;
	  z -= 10.0f;
	}
    }
  delete[] memblock;
}

int				launch_game(irr::IrrlichtDevice *device,
                                            irr::video::IVideoDriver *driver,
                                            irr::scene::ISceneManager *sceneManager,
                                            MyEventReceiver & receiver,
					    irrklang::ISoundEngine *engine)
{
  engine->setSoundVolume(0.05);
  engine->play2D("media/ingame.mp3", true);
  irr::scene::IMetaTriangleSelector *metaSelector = sceneManager->createMetaTriangleSelector();
  device->getCursorControl()->setVisible (false);
  //begin_dante(50, 50, 50);
  parse_map(driver, sceneManager, metaSelector);
  irr::scene::ICameraSceneNode *camera = sceneManager->addCameraSceneNode(0, irr::core::vector3df(0, 0, 0), irr::core::vector3df(0, 0, 100), 1, 32);

  irr::scene::IAnimatedMeshSceneNode *node = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh("obj/pikachu-pokemon-go.obj"));
  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  node->setScale(irr::core::vector3df(0.25, 0.25, 0.25));
  node->setPosition(irr::core::vector3df(10, 23, -10));
  //node->setMaterialTexture(0, driver->getTexture("obj/sydney.bmp"));
  node->setMD2Animation(irr::scene::EMAT_STAND);    // joue l'animation STAND en boucle
  node->setID(PLAYER);
  Player *player = new Player(metaSelector, sceneManager, node);
  irr::scene::ITriangleSelector *selector = sceneManager->createTriangleSelectorFromBoundingBox(node);
  node->setTriangleSelector(selector);
  metaSelector->addTriangleSelector(selector);
  selector->drop();
  irr::scene::ISceneNodeAnimatorCollisionResponse* anim = sceneManager->createCollisionResponseAnimator(metaSelector, node,
													irr::core::vector3df(3, 3, 3), irr::core::vector3df(0, 0, 0), irr::core::vector3df(0, 0, 0));
  MyCallbackPlayer *callback = new MyCallbackPlayer();
  callback->setPlayer(player);
  anim->setCollisionCallback(callback);
  node->addAnimator(anim);
  anim->drop();

  irr::u32 then = device->getTimer()->getTime();
  const irr::f32 MOVEMENT_SPEED = 5.f;
  irr::core::vector3df nodePosition;
  irr::core::vector3df projPosition;
  irr::core::vector3df tmpProj;

  irrklang::ISoundEngine		*walk_sound = irrklang::createIrrKlangDevice();
  walk_sound->setSoundVolume(0.5);


  irr::video::ITexture			*grass_texture;
  grass_texture = driver->getTexture("media/lava.jpg");



  std::map<irr::core::vector3df, t_projectile>	ProjMap = initProjo(projPosition, MOVEMENT_SPEED, 0);
  std::map<irr::EKEY_CODE, t_key>	mapm = mapMove(receiver.findtouch(), walk_sound, nodePosition, MOVEMENT_SPEED, 0, node);
  while(device->run() && player->getHp() > 0 && player->getExit() == false)
    {
      const irr::u32 now = device->getTimer()->getTime();
      const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 100.f;
      then = now;
      nodePosition = node->getPosition();
      if ((receiver.findtouch() == irr::KEY_KEY_Z) || (receiver.findtouch() == irr::KEY_KEY_D) || (receiver.findtouch() == irr::KEY_KEY_Q) || (receiver.findtouch() == irr::KEY_KEY_S))
	nodePosition = mapm[receiver.findtouch()](walk_sound, nodePosition, MOVEMENT_SPEED, frameDeltaTime, node);

      if (receiver.IsKeyDown(irr::KEY_SPACE) || player->getFire() == true)
	{
	  if ((player->getFire()) == false)
	    {
	      player->attack();
	      player->setFire(true);
	      player->getProjectile()->getNode()->setPosition(node->getPosition());
		  tmpProj = player->getNode()->getRotation();
	    }
	  else
	    {
						projPosition = ProjMap[tmpProj](projPosition, MOVEMENT_SPEED, frameDeltaTime);
	      player->getProjectile()->getNode()->setPosition(projPosition);
	      if (player->getProjectile()->getNode()->isVisible() == false)
		{
		  player->setFire(false);
		  player->getProjectile()->deleteProjectile();
		}
	    }
	  projPosition = player->getProjectile()->getNode()->getPosition();
	}

      nodePosition.Y = 23;
      node->setPosition(nodePosition);
      camera->setTarget(node->getPosition());
      camera->setPosition(irr::core::vector3df(nodePosition.X, nodePosition.Y + 80.0f, nodePosition.Z - 30.0f));
      driver->beginScene(true, true, irr::video::SColor(0, 255, 255, 255));
      driver->draw2DImage(grass_texture, irr::core::position2d<irr::s32>(0, 0),
                          irr::core::rect<irr::s32>(0, 0, 1600, 900), NULL,
                          irr::video::SColor(255, 255, 255, 255), true);
      sceneManager->drawAll();
      print_pv(driver, player->getHp());
      driver->endScene();
    }
  if (player->getExit() == true)
    {
      engine->stopAllSounds();
      print_win(device, driver, sceneManager, receiver, engine);
    }
  if (player->getHp() <= 0)
    {
      engine->stopAllSounds();
      print_game_over(device, driver, sceneManager, receiver, engine);
    }
  if (engine && device)
    {
      engine->drop();
      device->drop();
    }
  return 0;
}

int				main(void)
{
  MyEventReceiver		receiver;
  irr::IrrlichtDevice		*device;
  irr::video::IVideoDriver	*driver;
  irr::scene::ISceneManager	*sceneManager;
  irrklang::ISoundEngine	*engine;

  device = irr::createDevice(irr::video::EDT_OPENGL,
                             irr::core::dimension2d<irr::u32>(1600, 900),
                             16, false, false, false, &receiver);
  driver = device->getVideoDriver();
  sceneManager = device->getSceneManager();
  device->setResizable(false);
  device->setWindowCaption(L"Pika Gauntlet v. 1.0");
  engine = irrklang::createIrrKlangDevice();
  if (!engine)
    fprintf(stderr, "Could not startup engine\n");
  print_menu(device, driver, sceneManager, receiver, engine);
  return 0;
}
