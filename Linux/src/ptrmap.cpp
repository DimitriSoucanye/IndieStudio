//
// ptrmap.cpp for ptrmap.cpp in /home/arthur.kleiber/cpp_indie_studio/Linux
// 
// Made by Arthur K
// Login   <arthur.kleiber>
// 
// Started on  Sun Jun 18 23:25:35 2017 Arthur K
// Last update Sun Jun 18 23:33:45 2017 Arthur K
//

#include <indie_studio.hpp>
#include <collision.hpp>

void          wallGenerator(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *sceneManager,
			    irr::scene::IMetaTriangleSelector *metaSelector, irr::f64 x, irr::f64 y, irr::f64 z)
{
  irr::scene::IMeshSceneNode *cube = sceneManager->addMeshSceneNode(sceneManager->getMesh("obj/mur_briques.obj"));
  cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  cube->setMaterialTexture(0, driver->getTexture("obj/wall.jpg"));
  cube->setPosition(irr::core::vector3df(x, y, z));
  cube->setScale(irr::core::vector3df(5.0f, 15.0f, 5.0f));
  cube->setID(WALL);

  irr::scene::ITriangleSelector *selector = 0;
  selector = sceneManager->createTriangleSelectorFromBoundingBox(cube);
  cube->setTriangleSelector(selector);
  metaSelector->addTriangleSelector(selector);
  selector->drop();
}

void          floorGenerator(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *sceneManager,
			     irr::scene::IMetaTriangleSelector *metaSelector, irr::f64 x, irr::f64 y, irr::f64 z)
{
  irr::scene::IMeshSceneNode *cube = sceneManager->addMeshSceneNode(sceneManager->getMesh("obj/mur_briques.obj"));
  cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  cube->setMaterialTexture(0, driver->getTexture("obj/ground.jpg"));
  cube->setPosition(irr::core::vector3df(x, y, z));
  cube->setScale(irr::core::vector3df(5.0f, 5.0f, 5.0f));
  cube->setID(FLOOR);
}

void          playerGenerator(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *sceneManager,
			      irr::scene::IMetaTriangleSelector *metaSelector, irr::f64 x, irr::f64 y, irr::f64 z)
{
}

void          spawnerGenerator(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *sceneManager,
			       irr::scene::IMetaTriangleSelector *metaSelector, irr::f64 x, irr::f64 y, irr::f64 z)
{
  irr::scene::ISceneNode *cube = sceneManager->addMeshSceneNode(sceneManager->getMesh("obj/pokeball.obj"));
  cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  cube->setMaterialTexture(0, driver->getTexture("obj/pokeball.mtl"));
  cube->setPosition(irr::core::vector3df(x, y + 10, z));
  cube->setScale(irr::core::vector3df(0.4, 0.4, 0.4));
  cube->setID(SPAWNER);

  irr::scene::ITriangleSelector *selector = 0;
  selector = sceneManager->createTriangleSelectorFromBoundingBox(cube);
  cube->setTriangleSelector(selector);
  metaSelector->addTriangleSelector(selector);
  selector->drop();          }

void          doorGenerator(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *sceneManager,
			    irr::scene::IMetaTriangleSelector *metaSelector, irr::f64 x, irr::f64 y, irr::f64 z)
{
  irr::scene::IMeshSceneNode *cube = sceneManager->addMeshSceneNode(sceneManager->getMesh("obj/door.obj"));
  cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  cube->setMaterialTexture(0, driver->getTexture("obj/original.jpeg"));
  cube->setMaterialTexture(0, driver->getTexture("obj/wood-wallpaper-4.jpg"));
  cube->setMaterialTexture(0, driver->getTexture("obj/Castle-Wall-Textures-1.jpg"));
  cube->setPosition(irr::core::vector3df(x, y, z));
  cube->setScale(irr::core::vector3df(5.0f, 5.0f, 5.0f));
  cube->setID(DOOR);

  irr::scene::ITriangleSelector *selector = 0;
  selector = sceneManager->createTriangleSelectorFromBoundingBox(cube);
  cube->setTriangleSelector(selector);
  metaSelector->addTriangleSelector(selector);
  selector->drop();
}

void            keyGenerator(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *sceneManager,
			     irr::scene::IMetaTriangleSelector *metaSelector, irr::f64 x, irr::f64 y, irr::f64 z)
{
  irr::scene::IMeshSceneNode *cube = sceneManager->addMeshSceneNode(sceneManager->getMesh("obj/gold_key.3ds"));
  cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  cube->setMaterialTexture(0, driver->getTexture("obj/original.jpeg"));
  cube->setPosition(irr::core::vector3df(x - 2, y - 19, z));
  cube->setScale(irr::core::vector3df(15.0f, 15.0f, 15.0f));
  cube->setID(KEY);

  irr::scene::ITriangleSelector *selector = 0;
  selector = sceneManager->createTriangleSelectorFromBoundingBox(cube);
  cube->setTriangleSelector(selector);
  metaSelector->addTriangleSelector(selector);
  selector->drop();
}

void            potionGenerator(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *sceneManager,
				irr::scene::IMetaTriangleSelector *metaSelector, irr::f64 x, irr::f64 y, irr::f64 z)
{
  irr::scene::IMeshSceneNode *cube = sceneManager->addMeshSceneNode(sceneManager->getMesh("obj/potion.3ds"));
  cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  cube->setMaterialTexture(0, driver->getTexture("obj/potion.3ds"));
  cube->setPosition(irr::core::vector3df(x, y + 5, z));
  cube->setScale(irr::core::vector3df(3.0f, 3.0f, 3.0f));
  cube->setID(POTION);

  irr::scene::ITriangleSelector *selector = 0;
  selector = sceneManager->createTriangleSelectorFromBoundingBox(cube);
  cube->setTriangleSelector(selector);
  metaSelector->addTriangleSelector(selector);
  selector->drop();
}

void            exitGenerator(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *sceneManager,
			      irr::scene::IMetaTriangleSelector *metaSelector, irr::f64 x, irr::f64 y, irr::f64 z)
{
  irr::scene::IMeshSceneNode *cube = sceneManager->addMeshSceneNode(sceneManager->getMesh("obj/exit.obj"));
  cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  cube->setPosition(irr::core::vector3df(x, y + 15, z));
  cube->setRotation(irr::core::vector3df(0, 180, 0));
  cube->setScale(irr::core::vector3df(2, 2, 2));
  cube->setID(EXIT);

  irr::scene::ITriangleSelector *selector = 0;
  selector = sceneManager->createTriangleSelectorFromBoundingBox(cube);
  cube->setTriangleSelector(selector);
  metaSelector->addTriangleSelector(selector);
  selector->drop();
}

void            Simplereturn(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *sceneManager,
			     irr::scene::IMetaTriangleSelector *metaSelector, irr::f64 x, irr::f64 y, irr::f64 z)
{
  return;
}

std::map<char, param>		ptrmap(irr::video::IVideoDriver *driver,
				       irr::scene::ISceneManager *sceneManager,
				       irr::scene::IMetaTriangleSelector *metaSelector,
				       irr::f64 x, irr::f64 y, irr::f64 z)
{
  std::map<char, param>		ptrmap;

  auto l1 = [] (irr::video::IVideoDriver *driver,
		irr::scene::ISceneManager *sceneManager,
		irr::scene::IMetaTriangleSelector *metaSelector,
		irr::f64 x, irr::f64 y, irr::f64 z)
    {
      playerGenerator(driver, sceneManager, metaSelector, x, y, z);
    };
  ptrmap['P'] = l1;
  auto l2 = [] (irr::video::IVideoDriver *driver,
		irr::scene::ISceneManager *sceneManager,
		irr::scene::IMetaTriangleSelector *metaSelector,
		irr::f64 x, irr::f64 y, irr::f64 z)
    {
      wallGenerator(driver, sceneManager, metaSelector, x, y, z);
    };
  ptrmap['X'] = l2;
  auto l3 = [] (irr::video::IVideoDriver *driver,
		irr::scene::ISceneManager *sceneManager,
		irr::scene::IMetaTriangleSelector *metaSelector,
		irr::f64 x, irr::f64 y, irr::f64 z)
    {
      keyGenerator(driver, sceneManager, metaSelector, x, y, z);
    };
  ptrmap['K'] = l3;
  auto l4 = [] (irr::video::IVideoDriver *driver,
		irr::scene::ISceneManager *sceneManager,
		irr::scene::IMetaTriangleSelector *metaSelector,
		irr::f64 x, irr::f64 y, irr::f64 z)
    {
      spawnerGenerator(driver, sceneManager, metaSelector, x, y, z);
    };
  ptrmap['M'] = l4;
  auto l5 = [] (irr::video::IVideoDriver *driver,
		irr::scene::ISceneManager *sceneManager,
		irr::scene::IMetaTriangleSelector *metaSelector,
		irr::f64 x, irr::f64 y, irr::f64 z)
    {
      doorGenerator(driver, sceneManager, metaSelector, x, y, z);
    };
  ptrmap['D'] = l5;
  auto l6 = [] (irr::video::IVideoDriver *driver,
		irr::scene::ISceneManager *sceneManager,
		irr::scene::IMetaTriangleSelector *metaSelector,
		irr::f64 x, irr::f64 y, irr::f64 z)
    {
      potionGenerator(driver, sceneManager, metaSelector, x, y, z);
    };
  ptrmap['p'] = l6;
  auto l7 = [] (irr::video::IVideoDriver *driver,
		irr::scene::ISceneManager *sceneManager,
		irr::scene::IMetaTriangleSelector *metaSelector,
		irr::f64 x, irr::f64 y, irr::f64 z)
    {
      Simplereturn(driver, sceneManager, metaSelector, x, y, z);
    };
  ptrmap['*'] = l7;
  auto l8 = [] (irr::video::IVideoDriver *driver,
		irr::scene::ISceneManager *sceneManager,
		irr::scene::IMetaTriangleSelector *metaSelector,
		irr::f64 x, irr::f64 y, irr::f64 z)
    {
      exitGenerator(driver, sceneManager, metaSelector, x, y, z);
    };
  ptrmap['E'] = l8;
  return (ptrmap);
}
