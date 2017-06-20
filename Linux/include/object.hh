#ifndef OBJECT_HH
# define OBJECT_HH

#include <irr/irrlicht.h>

class IEntity
{
public:
  virtual ~IEntity() = 0;
  virtual void CheckPlayer(irr::core::vector3df, Player *) = 0;

  virtual irr::IMeshSceneNode *getmesh() = 0;
};

class mobSpawner : public IEntity
{
public:
  mobSpawner(irr::video::IVideoDriver *, irr::scene::ISceneManager *, irr::scene::IMetaTriangleSelector *, irr::f64, irr::f64, irr::f64);
  ~mobSpawner();

  void CheckPlayer(irr::core::vector3df, Player *);
  irr::IMeshSceneNode *getMesh();

private:
  irr::scene::IMeshSceneNode *mesh;
};

class key : public IEntity
{
public:
  key(irr::video::IVideoDriver *, irr::scene::ISceneManager *, irr::scene::IMetaTriangleSelector *, irr::f64, irr::f64, irr::f64);
  ~key();

  void CheckPlayer(irr::core::vector3df, Player *);
  irr::IMeshSceneNode *getMesh();

private:
  irr::scene::IMeshSceneNode *mesh;
};

class door : public IEntity
{
public:
  door(irr::video::IVideoDriver *, irr::scene::ISceneManager *, irr::scene::IMetaTriangleSelector *, irr::f64, irr::f64, irr::f64);
  ~door();

  void CheckPlayer(irr::core::vector3df, Player *);
  irr::IMeshSceneNode *getMesh();

private:
  irr::scene::IMeshSceneNode *mesh;
};

class potion : public IEntity
{
public:
  potion(irr::video::IVideoDriver *, irr::scene::ISceneManager *, irr::scene::IMetaTriangleSelector *, irr::f64, irr::f64, irr::f64);
  ~potion();

  void CheckPlayer(irr::core::vector3df, Player *);
  irr::IMeshSceneNode *getMesh();

private:
  irr::scene::IMeshSceneNode *mesh;
};

class wall : public IEntity
{
public:
  wall(irr::video::IVideoDriver *, irr::scene::ISceneManager *, irr::scene::IMetaTriangleSelector *, irr::f64, irr::f64, irr::f64);
  ~wall();

  void CheckPlayer(irr::core::vector3df, Player *);
  irr::IMeshSceneNode *getMesh();

private:
  irr::scene::IMeshSceneNode *mesh:
};

#endif
