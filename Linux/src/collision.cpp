#include <collision.hpp>
#include <player.h>
#include <irrKlang.h>

bool      MyCallbackPlayer::playerCollision(Player *player, irr::scene::ISceneNode *node)
{
  return (true);
}

bool      MyCallbackPlayer::mobCollision(Player *player, irr::scene::ISceneNode *node)
{
  player->setHp(-10);
  node->drop();
  return (false);
}

bool       MyCallbackPlayer::atqCollision(Player *player, irr::scene::ISceneNode *node)
{
  return (true);
}

bool        MyCallbackPlayer::potionCollision(Player *player, irr::scene::ISceneNode *node)
{
  if (player->getHp() + 10 >= 100)
    player->setHp(100 - player->getHp());
  else
    player->setHp(10);
  player->getMetaSelector()->removeTriangleSelector(node->getTriangleSelector());
  node->remove();
  return (true);
}

bool        MyCallbackPlayer::doorCollision(Player *player, irr::scene::ISceneNode *node)
{
  if (player->getKey() == true)
    {
      irr::core::vector3df	tmp;
      irrklang::ISoundEngine	*door_sound;

      door_sound = irrklang::createIrrKlangDevice();
      door_sound->setSoundVolume(1);
      door_sound->play2D("media/door_open.mp3", false);
      player->setKey(false);
      node->getPosition();
      tmp.Y = -10;
      node->setPosition(tmp);
    }
  return (false);
}

bool        MyCallbackPlayer::keyCollision(Player *player, irr::scene::ISceneNode *node)
{
  irrklang::ISoundEngine	*key_sound;

  key_sound = irrklang::createIrrKlangDevice();
  key_sound->setSoundVolume(1);
  if (player->getKey() == true)
    return (false);
  key_sound->play2D("media/key_sound.mp3", false);
  player->setKey(true);
  player->getMetaSelector()->removeTriangleSelector(node->getTriangleSelector());
  node->remove();
  return (true);
}

bool        MyCallbackPlayer::spawnerCollision(Player *player, irr::scene::ISceneNode *node)
{
  player->setHp(-1);
  return (false);
}

bool        MyCallbackPlayer::wallCollision(Player *player, irr::scene::ISceneNode *node)
{
  return (false);
}

bool        MyCallbackPlayer::floorCollision(Player *player, irr::scene::ISceneNode *node)
{
  return (false);
}

bool        MyCallbackPlayer::exitCollision(Player *player, irr::scene::ISceneNode *node)
{
  player->getMetaSelector()->removeTriangleSelector(node->getTriangleSelector());
  node->remove();
  this->player->setExit(true);
  return (false);
}

void MyCallbackPlayer::mapmaker(Player* player, irr::scene::ISceneNode *node)
{
  auto map1 = [&] (Player *player, irr::scene::ISceneNode *node) {return MyCallbackPlayer::playerCollision(player, node);};
  this->collision_map[PLAYER] = map1;
  auto map2 = [&] (Player *player, irr::scene::ISceneNode *node) {return MyCallbackPlayer::mobCollision(player, node);};
  this->collision_map[MOB] = map2;
  auto map3 = [&] (Player *player, irr::scene::ISceneNode *node) {return MyCallbackPlayer::atqCollision(player, node);};
  this->collision_map[ATQ] = map3;
  auto map4 = [&] (Player *player, irr::scene::ISceneNode *node) {return MyCallbackPlayer::potionCollision(player, node);};
  this->collision_map[POTION] = map4;
  auto map5 = [&] (Player *player, irr::scene::ISceneNode *node) {return MyCallbackPlayer::doorCollision(player, node);};
  this->collision_map[DOOR] = map5;
  auto map6 = [&] (Player *player, irr::scene::ISceneNode *node) {return MyCallbackPlayer::keyCollision(player, node);};
  this->collision_map[KEY] = map6;
  auto map7 = [&] (Player *player, irr::scene::ISceneNode *node) {return MyCallbackPlayer::spawnerCollision(player, node);};
  this->collision_map[SPAWNER] = map7;
  auto map8 = [&] (Player *player, irr::scene::ISceneNode *node) {return MyCallbackPlayer::wallCollision(player, node);};
  this->collision_map[WALL] = map8;
  auto map9 = [&] (Player *player, irr::scene::ISceneNode *node) {return MyCallbackPlayer::floorCollision(player, node);};
  this->collision_map[FLOOR] = map9;
  auto map10 = [&] (Player *player, irr::scene::ISceneNode *node) {return MyCallbackPlayer::exitCollision(player, node);};
  this->collision_map[EXIT] = map10;
}
