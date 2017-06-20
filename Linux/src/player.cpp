#include <player.h>

Player::Player(irr::scene::IMetaTriangleSelector *metaSelector,
	       irr::scene::ISceneManager *sceneManager,
	       irr::scene::ISceneNode *node)
{
  this->metaSelector = metaSelector;
  this->hp = 100;
  this->key = false;
  this->sceneManager = sceneManager;
  this->node = node;
  this->isFiring = false;
  this->exit = false;
}

irr::scene::ISceneManager	*Player::getSceneManager()
{
  return (this->sceneManager);
}

bool      Player::getExit()
{
  return (this->exit);
}

bool      Player::getKey()
{
  return (this->key);
}

int       Player::getHp()
{
  return (this->hp);
}

bool	Player::getFire()
{
  return (this->isFiring);
}

irr::scene::ISceneNode	*Player::getNode()
{
  return (this->node);
}

Projectile	*Player::getProjectile()
{
  return (this->projectile);
}

void      Player::setExit(bool b)
{
  this->exit = b;
}

void      Player::setKey(bool set)
{
  this->key = set;
}

void      Player::setHp(int damage)
{
  this->hp += damage;
}

void	Player::setFire(bool shoot)
{
  this->isFiring = shoot;
}

irr::scene::IMetaTriangleSelector *Player::getMetaSelector()
{
  return(this->metaSelector);
}

void	Player::attack()
{
  Projectile *proj = new Projectile(getMetaSelector(), getSceneManager(), getNode());
  this->projectile = proj;
}
