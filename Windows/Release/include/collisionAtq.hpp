//
// collisionAtq.hpp for collision in /home/elyes/rendu/Projets/CPP/cpp_indie_studio/Dan2/include/
//
// Made by Elyes Ghalaza
// Login   <elyes.ghalaza@epitech.eu>
//
// Started on  Fri Jun 16 17:05:21 2017 Elyes Ghalaza
// Last update Sat Jun 17 01:59:58 2017 Elyes Ghalaza
//

#ifndef COLLISIONATQ_HPP_
# define COLLISIONATQ_HPP_

#include <indie_studio.hpp>

class Projectile
{
public:
    Projectile(irr::scene::IMetaTriangleSelector *metaSelector,
               irr::scene::ISceneManager *sceneManager,
               irr::scene::ISceneNode *player);
    ~Projectile();

  irr::scene::ISceneNode *getNode();
  void                   setNode(irr::scene::ISceneNode *newNode);

  void					launchProjectile()
  {
      node->setVisible(true);
  };


  irr::scene::IMetaTriangleSelector	*getMetaSelector()
  {
      return (this->metaSelector);
  };

private:
  irr::scene::ISceneNode *node;
  irr::scene::ISceneNode *player;
  irr::scene::IMetaTriangleSelector *metaSelector;
};

typedef std::function<bool(Projectile *, irr::scene::ISceneNode *)> t_proj;

class	MyCallBackProjectile : public irr::scene::ICollisionCallback
{
public:
bool	onCollision(const irr::scene::ISceneNodeAnimatorCollisionResponse &entity)
{
        if (this->projectile_map.size() == 0)
        {
            std::cout << "creation map projectile" << std::endl;
            this->mapmaker(this->projectile, entity.getCollisionNode());
        }
        if (entity.getTargetNode() == entity.getCollisionNode())
            return (true);
        else
            return (projectile_map[entity.getCollisionNode()->getID()](this->projectile, entity.getCollisionNode()));
};

void	setProjectile(Projectile *ptr)
{
        this->projectile = ptr;
};

Projectile	*getProjectile()
{
    return (this->projectile);
};

private:
    std::map<irr::s32, t_proj> projectile_map;
    void	mapmaker(Projectile *, irr::scene::ISceneNode *);
    Projectile	*projectile;

    bool	playerCollision(Projectile *, irr::scene::ISceneNode *);
    bool	mobCollision(Projectile *, irr::scene::ISceneNode *);
    bool	atqCollision(Projectile *, irr::scene::ISceneNode *);
    bool	potionCollision(Projectile *, irr::scene::ISceneNode *);
    bool	doorCollision(Projectile *, irr::scene::ISceneNode *);
    bool	keyCollision(Projectile *, irr::scene::ISceneNode *);
    bool	spawnerCollision(Projectile *, irr::scene::ISceneNode *);
    bool	wallCollision(Projectile *, irr::scene::ISceneNode *);
    bool	floorCollision(Projectile *, irr::scene::ISceneNode *);
};

#endif
