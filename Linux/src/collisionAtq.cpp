//
// collisionAtq.cpp for collision in /home/elyes/rendu/Projets/CPP/cpp_indie_studio/Dan2/src/
//
// Made by Elyes Ghalaza
// Login   <elyes.ghalaza@epitech.eu>
//
// Started on  Fri Jun 16 17:28:42 2017 Elyes Ghalaza
// Last update Sun Jun 18 23:32:42 2017 Arthur K
//

#include <collision.hpp>
#include <collisionAtq.hpp>

bool      MyCallBackProjectile::playerCollision(Projectile *projectile, irr::scene::ISceneNode *node)
{
  return (true);
}

bool      MyCallBackProjectile::mobCollision(Projectile *projectile, irr::scene::ISceneNode *node)
{
  projectile->getMetaSelector()->removeTriangleSelector(node->getTriangleSelector());
  node->remove();
  projectile->getNode()->setVisible(false);
  return (false);
}

bool       MyCallBackProjectile::atqCollision(Projectile *projectile, irr::scene::ISceneNode *node)
{
  return (true);
}

bool        MyCallBackProjectile::potionCollision(Projectile *projectile, irr::scene::ISceneNode *node)
{
  return (true);
}

bool        MyCallBackProjectile::doorCollision(Projectile *projectile, irr::scene::ISceneNode *node)
{
  projectile->getNode()->setVisible(false);
  return (false);
}

bool        MyCallBackProjectile::keyCollision(Projectile *projectile, irr::scene::ISceneNode *node)
{
  return (true);
}

bool        MyCallBackProjectile::spawnerCollision(Projectile *projectile, irr::scene::ISceneNode *node)
{
  projectile->getMetaSelector()->removeTriangleSelector(node->getTriangleSelector());
  node->remove();
  projectile->getNode()->setVisible(false);
  return (false);
}

bool        MyCallBackProjectile::wallCollision(Projectile *projectile, irr::scene::ISceneNode *node)
{
  projectile->getNode()->setVisible(false);
  return (false);
}

bool        MyCallBackProjectile::floorCollision(Projectile *projectile, irr::scene::ISceneNode *node)
{
  projectile->getNode()->setVisible(false);
  return (false);
}

bool        MyCallBackProjectile::exitCollision(Projectile *projectile, irr::scene::ISceneNode *node)
{
  projectile->getNode()->setVisible(false);
  return (false);
}

void MyCallBackProjectile::mapmaker(Projectile *projectile, irr::scene::ISceneNode *node)
{
  auto map1 = [&] (Projectile *projectile, irr::scene::ISceneNode *node) {return MyCallBackProjectile::playerCollision(projectile, node);};
  this->projectile_map[PLAYER] = map1;
  auto map2 = [&] (Projectile *projectile, irr::scene::ISceneNode *node) {return MyCallBackProjectile::mobCollision(projectile, node);};
  this->projectile_map[MOB] = map2;
  auto map3 = [&] (Projectile *projectile, irr::scene::ISceneNode *node) {return MyCallBackProjectile::atqCollision(projectile, node);};
  this->projectile_map[ATQ] = map3;
  auto map4 = [&] (Projectile *projectile, irr::scene::ISceneNode *node) {return MyCallBackProjectile::potionCollision(projectile, node);};
  this->projectile_map[POTION] = map4;
  auto map5 = [&] (Projectile *projectile, irr::scene::ISceneNode *node) {return MyCallBackProjectile::doorCollision(projectile, node);};
  this->projectile_map[DOOR] = map5;
  auto map6 = [&] (Projectile *projectile, irr::scene::ISceneNode *node) {return MyCallBackProjectile::keyCollision(projectile, node);};
  this->projectile_map[KEY] = map6;
  auto map7 = [&] (Projectile *projectile, irr::scene::ISceneNode *node) {return MyCallBackProjectile::spawnerCollision(projectile, node);};
  this->projectile_map[SPAWNER] = map7;
  auto map8 = [&] (Projectile *projectile, irr::scene::ISceneNode *node) {return MyCallBackProjectile::wallCollision(projectile, node);};
  this->projectile_map[WALL] = map8;
  auto map9 = [&] (Projectile *projectile, irr::scene::ISceneNode *node) {return MyCallBackProjectile::floorCollision(projectile, node);};
  this->projectile_map[FLOOR] = map9;
  auto map10 = [&] (Projectile *projectile, irr::scene::ISceneNode *node) {return MyCallBackProjectile::exitCollision(projectile, node);};
  this->projectile_map[EXIT] = map10;
}
