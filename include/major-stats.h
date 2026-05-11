#ifndef MAJOR_STATS_H
#define MAJOR_STATS_H
#include <string>

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
	int atk;
	int intel;
	int def;
	int spd;
    int defBuff;
	Move moves[3];

};

Fighter engineering();

Fighter naturalScience();

Fighter education();

#endif