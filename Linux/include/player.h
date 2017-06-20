/*
** player.h for player.h in /home/arthur.kleiber/cpp_indie_studio/Dan2
**
** Made by Arthur K
** Login   <arthur.kleiber>
**
** Started on  Sat Jun 17 19:37:54 2017 Arthur K
** Last update Sat Jun 17 19:37:55 2017 Arthur K
*/

#ifndef PLAYER_H
# define PLAYER_H

# include <indie_studio.hpp>
# include <collisionAtq.hpp>

class					Projectile;

class					Player
{
 public:
  Player(irr::scene::IMetaTriangleSelector *metaSelector,
         irr::scene::ISceneManager *sceneManager,
         irr::scene::ISceneNode *node);
  ~Player() {};

  bool          getExit();
  bool					getKey();
  int					getHp();
  bool					getFire();
  Projectile				*getProjectile();
  irr::scene::ISceneManager		*getSceneManager();
  irr::scene::ISceneNode		*getNode();
  irr::scene::IMetaTriangleSelector	*getMetaSelector();

  void          setExit(bool);
  void					setKey(bool);
  void					setHp(int);
  void					setFire(bool);

  void					 attack();

 private:
  irr::scene::ISceneManager		*sceneManager;
  bool					key;
  int					hp;
  irr::scene::IMetaTriangleSelector	*metaSelector;
  irr::scene::ISceneNode		*node;
  Projectile				*projectile;
  bool					isFiring;
  bool          exit;
};

#endif /* !PLAYER_H_ */
