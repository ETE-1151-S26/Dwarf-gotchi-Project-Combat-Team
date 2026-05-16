#ifndef COMBAT_MODE_H
#define COMBAT_MODE_H
#include <string>
#include <iostream>

struct Fighter;

//Defines the combat modes the player can be in
enum class CombatMode{
    Explore,
    Offense,
    Defense
};

//Defines what will actually change the stats of the player depending on the mode
class ModeManager{
    private:
        const float EXPLORE_ATK_DEBUFF = 0.75f; //-25% to atk for exploration player
        const float OFFENSIVE_SPD_BUFF = 1.25f; //+25% spd buff for offensive player
        const float DEFENSIVE_DEF_BUFF = 1.25f; //+25% def buff for defensive player

    public:
        //Modifies the 
        void applyMode(Fighter& f, CombatMode mode);
};  

void selectCombatMode(Fighter& f);

#endif