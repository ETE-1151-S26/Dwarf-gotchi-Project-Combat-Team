#include "combat-mode.h"
#include <iostream>
#include <string>

/*ModeManager::ModeManager() : currentMode(CombatMode::Explore) {} //Explore will be the default mode
void ModeManager::setMode(CombatMode mode){
    currentMode = mode;
}
CombatMode ModeManager::getMode(){
    return currentMode;
}
std::string ModeManager::getModeName(){
    switch(currentMode){
        case CombatMode::Explore: return "Explore";
        case CombatMode::Offense: return "Offensive";
        case CombatMode::Defense: return "Defensive";
    }
}
int ModeManager::calculateAtk(int baseAtk){
    if(currentMode == CombatMode::Explore){
        return (int)(baseAtk * EXPLORE_ATK_DEBUFF);
    }
    return baseAtk;
}
int ModeManager::calculateDef(int baseDef){
    if(currentMode == CombatMode::Defense){
        return (int)(baseDef * DEFENSIVE_DEF_BUFF);
    }
    return baseDef;
}
int ModeManager::calculateSpd(int baseSpd){
    if(currentMode == CombatMode::Offense){
        return (int)(baseSpd * OFFENSIVE_SPD_BUFF);
    }
    return baseSpd;
}  */
void ModeManager::applyMode(Fighter& f, CombatMode mode){
    //Before claculations, stats are set to base levels
    f.atk = f.baseAtk;
    f.def = f.baseDef;
    f.spd = f.baseSpd;

    //buffs/debuffs applied based on combat mode
    switch(mode){
        case CombatMode::Explore:
            f.atk = int(f.baseAtk * EXPLORE_ATK_DEBUFF);
            break;
        case CombatMode::Offense:
            f.spd = int(f.baseSpd * OFFENSIVE_SPD_BUFF);
            break;
        case CombatMode::Defense:
            f.def = int(f.baseDef * DEFENSIVE_DEF_BUFF);
            break;
    }
}

//possible way to select mode?
ModeManager modeSelect;
    Fighter player = engineering();
    modeSelect.applyMode(player, CombatMode::Defense);