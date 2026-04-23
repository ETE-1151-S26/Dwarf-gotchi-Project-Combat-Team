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
    //18,15 would be attack power 18 with 15 percent crit chance.
    f.moves[0] = {"Physical Attack", MoveKind::Attack, 18, 15};
    f.moves[1] = {"Magical Attack", MoveKind::Attack, 14, 10};
    f.moves[2] = {"Block", MoveKind::Defend, 6, 0};

    return f;

};

//values not final in following classes, just placeholders for testing purposes. We can adjust as needed when we have a better idea of balance and how the moves work in practice. Also, the moves themselves are just placeholders and can be changed to fit the theme of each major better.

Fighter engineering(const std::string& playerName) {
    
    Fighter f{};
    f.name = playerName;
    f.className = "Engineering";
    f.maxHP = 130; f.hp = 130;
    f.atk = 16; f.intel = 10; f.def = 12; f.spd = 8;
    f.defBuff= 0;

    f.moves[0] = {"Physical Attack", MoveKind::Attack, 20,10};
    f.moves[1] = {"Magical Attack", MoveKind::Attack, 12, 5};
    f.moves[2] = {"Block", MoveKind::Defend, 6, 0};

    return f;
};

Fighter naturalScience(const std::string& playerName){
    Fighter f{};
    f.name = playerName;
    f.className = "Natural Science";
    f.maxHP = 110; f.hp = 110;
    f.atk = 12; f.intel = 14; f.def = 8; f.spd = 9;
    f.defBuff= 0;

    f.moves[0] = {"Physical Attack", MoveKind::Attack, 16,10};
    f.moves[1] = {"Magical Attack", MoveKind::Attack, 18, 15};
    f.moves[2] = {"Block", MoveKind::Defend, 4, 0};

    return f;
};

Fighter education(const std::string& playerName){
    Fighter f{};
    f.name = playerName;
    f.className = "Education";
    f.maxHP = 100; f.hp = 100;
    f.atk = 10; f.intel = 16; f.def = 6; f.spd = 8;
    f.defBuff= 0;

    f.moves[0] = {"Physical Attack", MoveKind::Attack, 14,10};
    f.moves[1] = {"Magical Attack", MoveKind::Attack, 20, 15};
    f.moves[2] = {"Block", MoveKind::Defend, 4, 0};

    return f;

}