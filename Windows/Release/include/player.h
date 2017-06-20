#ifndef PLAYER_H
# define PLAYER_H

#include <indie_studio.hpp>
#include <collisionAtq.hpp>

class	Projectile;

class Player
{
 public:
  Player(irr::scene::IMetaTriangleSelector *metaSelector,
         irr::scene::ISceneManager *sceneManager,
         irr::scene::ISceneNode *node);
  ~Player() {};

  bool                   getKey();
  int                    getHp();
  bool					 getFire();
  Projectile			 *getProjectile();
  irr::scene::ISceneManager	*getSceneManager();
  irr::scene::ISceneNode	*getNode();
  irr::scene::IMetaTriangleSelector *getMetaSelector();

  void                   setKey(bool);
  void                   setHp(int);
  void					 setFire(bool);

  void					 attack();

 private:
  irr::scene::ISceneManager *sceneManager;
  bool key;
  int  hp;
  irr::scene::IMetaTriangleSelector *metaSelector;
  irr::scene::ISceneNode            *node;
  Projectile						*projectile;
  bool								isFiring;
};

#endif
