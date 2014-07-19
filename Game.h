#ifndef __GAME_H__
#define __GAME_H__

#include <vector>
#include <string>

class Player;
class Enemy;

class Game
{
    public:
        static Game *GetInstance();
        static void RemoveInstance();
        Player *GetPlayer();
        std::vector<Enemy *> &GetEnemies();
        void Play(std::string gameName, int difficulty);
        void Create(std::string gameName);
    
    protected:
        static void SetInstance(Game * game);
        Game();
        virtual ~Game();
        void Upgrade();
        
    private:
        virtual void InitLevel(int level, int difficulty, std::string fileName = "");
        void ResetLevel();
        virtual void PlayLevel();
        virtual bool GameEnd();
        static Game *instance;
        Player *player;
        std::vector <Enemy *>enemies;
        
};

#endif
