#ifndef MAJOR_STATS_H
#define MAJOR_STATS_H
#include <string>
#include "combat-mode.h"

//MOVEKIND IS AN ENUM CLASS THAT DEFINES THE KIND OF MOVE, WHETHER IT BE AN ATTACK, MAGICAL ATTACK OR DEFEND
enum class MoveKind {Attack, MagAttack, Defend};

//MOVE STRUCTURE DEFINES THE NAME OF THE MOVE, ITS KIND, PHYSICAL POWER, MAGICAL POWER, AND CRIT CHANCE
struct Move {
	std::string name;
	MoveKind kind;
	int power;
    int magpower;
	int critChance; //0-100
};

//FIGHTER STRUCTURE DEFINES THE NAME, CLASSNAME, HP, ATK, INTEL, DEF, SPD, A TEMPORARY DEFENSE BUFF, AND AN ARRAY OF MOVES
struct Fighter {
	std::string name;
	std::string className;

	int maxHP;
	int hp;
	int atk; //str value
	int intel; //magic attack
	int def; //block
	int spd;
    int defBuff;
	//base stats. These are used for calculations involving level and combat mode buffs
	int baseAtk;
	int baseDef;
	int baseSpd;
	int baseIntel;
	int baseHP;
	Move moves[3]; //each fighter has three moves: block, attack, magic attack
	ModeManager mode; //

};

Fighter engineering();

Fighter naturalScience();

Fighter education();

#endif