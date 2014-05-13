#include "Grenade.h"
#include "Character.h"
#include <iostream>
#include <cmath>

Grenade::Grenade(int xPos, int yPos, WeaponProperties weaponProperties, int direction):Weapon(xPos, yPos, weaponProperties),velocity(6),
    direction(direction),timer(40){}

void Grenade::Update()
{
    if (destroyThis)
    {
        delete this;
    }
    
    if (std::abs(xPos-xPosOrig) > GetProperties().GetRange()|| std::abs(yPos-yPosOrig) > GetProperties().GetRange())
    {
        delete this;
    }
    
    switch (direction)
    {
        case 0: // x+
            xPos += velocity;
            break;
        case 1: // x-
            xPos -= velocity;
            break;
        case 2: // y+ (this is actually down)
            yPos += velocity;
            break;
        case 3: // y- (this is actually up)
            yPos -= velocity;
            break;
        default:
            std::cerr << "Invalid grenade direction set\n";
    }
    #ifdef __MAP_H__
    if (Map::GetInstance().IsWall(xPos, yPos))
    {
        direction = (direction / 2) + 1 - (direction % 2); // switch direction 1-0 2-3
        velocity -= 2;
    }
    #endif
    
    timer--;
    if (timer == 0)
    {
        Detonate();
    }
}

void Grenade::Detonate()
{
    destroyThis = true;
}

void Grenade::Action( Character * character)
{
    if (character->Visit(*this))
    {
        destroyThis = true;
    }
}
