#include "battle-logic.h"
#include "combat-mode.h"
#include "major-stats.h"
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
int ModeManager::calculateAtk(int atk){
    if(currentMode == CombatMode::Explore){
        return (int)(atk * EXPLORE_ATK_DEBUFF);
    }
    return atk;
}
int ModeManager::calculateDef(int def){
    if(currentMode == CombatMode::Defense){
        return (int)(def * DEFENSIVE_DEF_BUFF);
    }
    return def;
}
int ModeManager::calculateSpd(int spd){
    if(currentMode == CombatMode::Offense){
        return (int)(spd * OFFENSIVE_SPD_BUFF);
    }
    return spd;
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

//POSSIBLE MODE SELECT? MENUES AND BUTTONS TEAM?
void selectCombatMode(Fighter& f){
    std::cout<<"\nCHOOSE A COMBAT READINESS STANCE\n";
    std::cout<<"1. Explore: -25% ATK\n";
    std::cout<<"2. Offense: +25% SPD\n";
    std::cout<<"3. Defense: +25% DEF\n";
    std::cout<<"Enter a number (1-3): ";
    int choice;
    std::cin>> choice;
    ModeManager modeSelect;
    switch(choice){
        case 1:
            modeSelect.applyMode(f, CombatMode::Explore);
            std::cout<<"You have chosen Explore mode.\n";
            break;
        case 2:
            modeSelect.applyMode(f, CombatMode::Offense);
            std::cout<<"You have chosen Offense mode.\n";
            break;
        case 3:
            modeSelect.applyMode(f, CombatMode::Defense);
            std::cout<<"You have chosen Defense mode.\n";
            break;
        default:
            std::cout<<"Invalid choice. Defaulting to Explore mode.\n";
            modeSelect.applyMode(f, CombatMode::Explore);
    }

};