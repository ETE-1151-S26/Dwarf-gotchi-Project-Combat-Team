#include "levels.h"
#include "major-stats.h"
#include <iostream>
#include <string>

int requiredExp(int level){
    if (level >= maxLevel){
    return 0;}
    return level * 100;
}

void levelUp(Fighter& f){
    f.level++;

    //Determines how stats increase for each class.
    //stat increase depends on chosesn class/ career
    if(f.className == "Engineering"){
        f.baseHP += 10;
        f.baseAtk += 2;
        f.baseDef =+ 4;
        f.baseIntel +=1;
        f.baseSpd += 1;
    }
    else if(f.className == "Natural Science"){
        f.baseHP += 5;
        f.baseAtk += 1;
        f.baseDef += 2;
        f.baseIntel += 3;
        f.baseSpd += 2;
    }

    f.maxHP = f.baseHP;
    f.intel = f.baseIntel;
    f.hp = f.maxHP;
    f.atk=f.baseAtk;
    f.def=f.baseDef;
    f.spd=f.baseSpd;
}

void addExp(Fighter& f, int expGained){
    if (f.level >= maxLevel) {
        std::cout<<f.name<<" is at max level. Prestige to continue leveling up.\n";
    }
    return; //No more exp if max level reached
