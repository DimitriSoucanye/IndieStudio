#ifndef COLLISION_HPP
# define COLLISION_HPP

#include <player.h>

    typedef std::function<bool(Player *, irr::scene::ISceneNode *)> t_function;
    class MyCallbackPlayer : public irr::scene::ICollisionCallback
    {
    public:
      bool onCollision(const irr::scene::ISceneNodeAnimatorCollisionResponse &entity)
      {
        if (this->collision_map.size() == 0)
        {
           this->mapmaker(this->player, entity.getCollisionNode());
           std::cout << "stp j'en ai marre" << std::endl;
         }
        std::cout << entity.getTargetNode()->getID() << " collision with " << entity.getCollisionNode()->getID() << std::endl;
        std::cout << this->player->getHp() << std::endl;
        if (entity.getTargetNode() == entity.getCollisionNode())
          return (true);
        else
          return (collision_map[entity.getCollisionNode()->getID()](this->player, entity.getCollisionNode()));
        };
      void setPlayer(Player *ptr) {
        this->player = ptr;
      };
      Player *getPlayer() {
        return (this->player);
      };

      private:
        std::map<irr::s32, t_function> collision_map;
        void                              mapmaker(Player *, irr::scene::ISceneNode *);
        Player                            *player;
        bool playerCollision(Player *, irr::scene::ISceneNode*);
        bool mobCollision(Player *, irr::scene::ISceneNode *);
        bool atqCollision(Player *, irr::scene::ISceneNode *);
        bool potionCollision(Player *, irr::scene::ISceneNode *);
        bool doorCollision(Player *, irr::scene::ISceneNode *);
        bool keyCollision(Player *, irr::scene::ISceneNode *);
        bool spawnerCollision(Player *, irr::scene::ISceneNode *);
        bool wallCollision(Player *, irr::scene::ISceneNode *);
        bool floorCollision(Player *, irr::scene::ISceneNode *);
    };

#endif
