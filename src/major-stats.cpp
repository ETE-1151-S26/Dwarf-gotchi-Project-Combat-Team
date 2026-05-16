#include <iostream>
#include <string>
#include <limits>
#include "major-stats.h"
#include "battle-logic.h"

//values not final in following classes, just placeholders for testing purposes. We can adjust as needed when we have a better idea of balance and how the moves work in practice. Also, the moves themselves are just placeholders and can be changed to fit the theme of each major better.

Fighter engineering() {
    
    Fighter f{};
    f.className = "Engineering";
    f.maxHP = 130; f.hp = 130;
    f.atk = 16; f.intel = 10; f.def = 12; f.spd = 8;
    f.defBuff= 0;

    //base stats, used for level and combat mode calculations
    f.baseAtk = 16; f.baseDef = 12; f.baseSpd = 8; f.baseIntel = 10; f.baseHP = 130;

    f.moves[0] = {"Physical Attack", MoveKind::Attack, 20,10};
    f.moves[1] = {"Magical Attack", MoveKind::MagAttack, 12, 5};
    f.moves[2] = {"Block", MoveKind::Defend, 6, 0};

    return f;
};

Fighter naturalScience(){
    Fighter f{};
    f.className = "Natural Science";
    f.maxHP = 110; f.hp = 110;
    f.atk = 12; f.intel = 14; f.def = 8; f.spd = 9;
    f.defBuff= 0;

    f.baseAtk = 12; f.baseDef = 8; f.baseSpd = 9;
    f.baseIntel = 14; f.baseHP = 110;

    f.moves[0] = {"Physical Attack", MoveKind::Attack, 16,10};
    f.moves[1] = {"Magical Attack", MoveKind::MagAttack, 18, 15};
    f.moves[2] = {"Block", MoveKind::Defend, 4, 0};

    return f;
};

Fighter education(){
    Fighter f{};
    f.className = "Education";
    f.maxHP = 100; f.hp = 100;
    f.atk = 10; f.intel = 16; f.def = 6; f.spd = 8;
    f.defBuff= 0;

    f.baseAtk = 10; f.baseDef = 6; f.baseSpd = 8;
    f.baseIntel = 16; f.baseHP = 100;
    f.moves[0] = {"Physical Attack", MoveKind::Attack, 14,10};
    f.moves[1] = {"Magical Attack", MoveKind::MagAttack, 20, 15};
    f.moves[2] = {"Block", MoveKind::Defend, 4, 0};

    return f;
};

Fighter computing_and_information(const std::string& playerName){
    Fighter f{};
    f.name = playerName;
    f.className = "Computing and Information";
    f.maxHP = 120; f.hp = 120;
    f.atk = 14; f.intel = 12; f.def = 10; f.spd = 7;
    f.defBuff= 0;

    f.baseAtk = 14; f.baseDef = 10; f.baseSpd = 7; f.baseIntel = 12; f.baseHP = 120;

    f.moves[0] = {"Physical Attack", MoveKind::Attack, 18,10};
    f.moves[1] = {"Magical Attack", MoveKind::Attack, 14, 10};
    f.moves[2] = {"Block", MoveKind::Defend, 6, 0};

    return f;
};
