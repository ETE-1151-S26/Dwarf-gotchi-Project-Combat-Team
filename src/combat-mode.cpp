#include "combat-mode.h"
#include <iostream>
#include <string>

ModeManager::ModeManager(){
    currentMode = CombatMode::Explore; //Explore will be the default mode
}

//function for setting the mode
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
}   
