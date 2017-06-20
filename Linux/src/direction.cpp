//
// direction.cpp for direction in /home/elyes/rendu/Projets/CPP/cpp_indie_studio/PROJET/Linux/src/
//
// Made by Elyes Ghalaza
// Login   <elyes.ghalaza@epitech.eu>
//
// Started on  Sun Jun 18 18:27:06 2017 Elyes Ghalaza
// Last update Sun Jun 18 22:04:50 2017 Elyes Ghalaza
//

#include <indie_studio.hpp>
#include <map.hpp>
#include <collision.hpp>

irr::core::vector3df	keyZ(irrklang::ISoundEngine* walk_sound, irr::core::vector3df nodePosition, const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime, irr::scene::IAnimatedMeshSceneNode *node)
{
    if (walk_sound->isCurrentlyPlaying("media/walk.mp3") == false)
      walk_sound->play2D("media/walk.mp3", false);
    nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
    node->setRotation(irr::core::vector3df(0, 180, 0));
    return (nodePosition);
}

irr::core::vector3df	keyS(irrklang::ISoundEngine* walk_sound, irr::core::vector3df nodePosition, const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime, irr::scene::IAnimatedMeshSceneNode *node)
{
    if (walk_sound->isCurrentlyPlaying("media/walk.mp3") == false)
      walk_sound->play2D("media/walk.mp3", false);
    nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
    node->setRotation(irr::core::vector3df(0, 0, 0));
    return (nodePosition);
}

irr::core::vector3df	keyQ(irrklang::ISoundEngine* walk_sound, irr::core::vector3df nodePosition, const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime, irr::scene::IAnimatedMeshSceneNode *node)
{
    if (walk_sound->isCurrentlyPlaying("media/walk.mp3") == false)
      walk_sound->play2D("media/walk.mp3", false);
    nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
    node->setRotation(irr::core::vector3df(0, 90, 0));
    return (nodePosition);
}

irr::core::vector3df	keyD(irrklang::ISoundEngine* walk_sound, irr::core::vector3df nodePosition, const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime, irr::scene::IAnimatedMeshSceneNode *node)
{
    if (walk_sound->isCurrentlyPlaying("media/walk.mp3") == false)
      walk_sound->play2D("media/walk.mp3", false);
    nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
    node->setRotation(irr::core::vector3df(0, 270, 0));
    return (nodePosition);
}

irr::core::vector3df	goRight(irr::core::vector3df projPosition, const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime)
{
    projPosition.Z += MOVEMENT_SPEED * frameDeltaTime * 2;
    return (projPosition);
}

irr::core::vector3df	goLeft(irr::core::vector3df projPosition, const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime)
{
    projPosition.Z -= MOVEMENT_SPEED * frameDeltaTime * 2;
    return (projPosition);
}

irr::core::vector3df	goUp(irr::core::vector3df projPosition, const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime)
{
    projPosition.X -= MOVEMENT_SPEED * frameDeltaTime * 2;
    return (projPosition);
}

irr::core::vector3df	goDown(irr::core::vector3df projPosition, const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime)
{
    projPosition.X += MOVEMENT_SPEED * frameDeltaTime * 2;
    return (projPosition);
}
