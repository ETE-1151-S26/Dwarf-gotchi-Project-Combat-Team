#include <iostream>
#include <string>
#include <limits>
#include "major-stats.h"
#include "battle-logic.h"

Fighter compsci(const std::string& playerName) {

    Fighter f{};
    f.name = playerName;
    f.className = "Computer Science";
    f.maxHP = 120; f.hp = 120;
    f.atk = 14; f.intel = 12; f.def = 10; f.spd = 7;
    f.defBuff = 0;

    //the numbers at the end are attack power,
    //accuracy and critical hit chance values, for example
    //18,90,15 would be attack power 18 with 90 percent accuracy and 15 percent crit chance.
    f.moves[0] = {"Physical Attack", MoveKind::Attack, 18, 90, 15};
    f.moves[1] = {"Magical Attack", MoveKind::Attack, 14, 95, 10};
    f.moves[2] = {"Block", MoveKind::Defend, 6, 95, 0};

    return f;

}