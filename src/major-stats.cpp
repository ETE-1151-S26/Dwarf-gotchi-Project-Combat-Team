#include <iostream>
#include <string>
#include <limits>
#include "major-stats.h"
#include "battle-logic.h"

Fighter compsci() {

    Fighter f{};
    f.className = "Computer Science";
    f.maxHP = 120; f.hp = 120;
    f.atk = 14; f.intel = 12; f.def = 12; f.spd = 7;
    f.defBuff = 0;

    //the numbers at the end are attack power,
    //accuracy and critical hit chance values, for example
    //18,15 would be attack power 18 with 15 percent crit chance.
    f.moves[0] = {"Physical Attack", MoveKind::Attack, 18, 15};
    f.moves[1] = {"Magical Attack", MoveKind::Attack, 14, 10};
    f.moves[2] = {"Block", MoveKind::Defend, 6, 0};

    return f;

}

Fighter emset() {

    Fighter f{};
    f.className = "Electomechanical Systems Engineering Technology";
    f.maxHP = 105; f.hp = 105;
    f.atk = 16; f.intel = 10; f.def = 10; f.spd = 8;
    f.defBuff = 0;

    //the numbers at the end are attack power,
    //accuracy and critical hit chance values, for example
    //18,15 would be attack power 18 with 15 percent crit chance.
    f.moves[0] = {"Physical Attack", MoveKind::Attack, 18, 15};
    f.moves[1] = {"Magical Attack", MoveKind::Attack, 14, 10};
    f.moves[2] = {"Block", MoveKind::Defend, 6, 0};

    return f;

}