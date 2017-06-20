//
// projectile.cpp for projectile in /home/elyes/rendu/Projets/CPP/cpp_indie_studio/Dan2/src/
//
// Made by Elyes Ghalaza
// Login   <elyes.ghalaza@epitech.eu>
//
// Started on  Fri Jun 16 18:06:31 2017 Elyes Ghalaza
// Last update Sun Jun 18 23:33:32 2017 Arthur K
//

#include <collisionAtq.hpp>

Projectile::Projectile(irr::scene::IMetaTriangleSelector *metaSelector,
		       irr::scene::ISceneManager *sceneManager,
		       irr::scene::ISceneNode *player)
{
  irr::scene::ISceneNode *node = sceneManager->addMeshSceneNode(sceneManager->getMesh("obj/eclair.obj"));
  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  node->setMaterialTexture(0, sceneManager->getVideoDriver()->getTexture("obj/eclair.mtl"));
  node->setRotation(irr::core::vector3df(90, 0, 90));
  node->setScale(irr::core::vector3df(1.5, 1.5, 1.5));
  node->setID(ATQ);

  irr::scene::ITriangleSelector *selector = sceneManager->createTriangleSelectorFromBoundingBox(node);
  node->setTriangleSelector(selector);
  //node->setVisible(false);
  metaSelector->addTriangleSelector(selector);
  selector->drop();
  irr::scene::ISceneNodeAnimatorCollisionResponse *anim =
    sceneManager->createCollisionResponseAnimator(metaSelector, node,
						  irr::core::vector3df(2, 2, 2), irr::core::vector3df(0, 0, 0), irr::core::vector3df(0, 0, 0));
  MyCallBackProjectile *callback = new MyCallBackProjectile();
  callback->setProjectile(this);
  anim->setCollisionCallback(callback);
  node->addAnimator(anim);
  anim->drop();
  this->metaSelector = metaSelector;
  this->node = node;
  this->player = player;
}

irr::scene::ISceneNode *Projectile::getNode()
{
  return (this->node);
}

void	Projectile::setNode(irr::scene::ISceneNode *newNode)
{
  this->node = newNode;
}

void  Projectile::deleteProjectile()
{
  this->getNode()->removeAnimators();
  this->getMetaSelector()->removeTriangleSelector(this->getNode()->getTriangleSelector());
}
