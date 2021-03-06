#ifndef __GUN_H__
#define __GUN_H__

#include "AbstractGun.h"

class Gun : public AbstractGun
{
    private:
        
    public:
        Gun(int xPos, int yPos, WeaponProperties weaponProperties, int direction, Character * watcher);
        void Update();
        void Detonate();
        void Action(Character * character);
        void Draw(ALLEGRO_BITMAP *buffer, int midX, int midY);
};

#endif
