#ifndef BATTLE_LOGIC_H
#define BATTLE_LOGIC_H
#include <random>
#include <string>
#include <chrono>
#include "major-stats.h"

//RNG STRUCT FOR RANDOM NUMBER GENERATION
struct RNG {

	std::mt19937 gen;
	RNG() : gen(std::chrono::system_clock::now().time_since_epoch().count()) {}  //Fixed seed for testing

	int rollInt(int lo, int hi) {
		std::uniform_int_distribution<int> dist(lo, hi);
		return dist(gen);
	}

	bool chance(int percent) { // percent 0..100
		if (percent <= 0) return false;
		if (percent >= 100) return true;
		return rollInt(1, 100) <= percent;
	}

};

//FUNCTION DISPLAYS THE BATTLE BETWEEN THE PLAYER AND AN ENEMY
void battle(Fighter* player, Fighter* enemy);

//FUNCTION ALLOWS THE PLAYER TO FIGHT A SERIES OF ENEMIES, IF NEEDED
int battleLoop(Fighter& player, Fighter enemies[1], RNG& rng);

//FUNCTION TO PROMPT THE USER TO CHOOSE A MOVE, WITH VALIDATION.
int promptChoiceInt(const std::string& prompt, int minVal, int maxVal);

//DISPLAYS THE HP BAR AND STATS OF A FIGHTER IN A USER-FRIENDLY WAY.
void printHPBar(const Fighter& f);

//SHOWS THE PLAYER'S MOVES WITH THEIR STATS, AND PROMPTS THE PLAYER TO CHOOSE ONE.
void showMoves(const Fighter& player);

//FUNCTION TO CLEAR THE INPUT BUFFER AFTER READING AN INT, TO AVOID LEFTOVER INPUT CAUSING ISSUES.
void clearInputLine();

//FUNCTION TO PICK A RANDOM MOVE FOR THE ENEMY.
Move* chooseEnemyMove(Fighter* enemy, RNG& rng);

//FUNCTION TO COMPUTE THE DAMAGE OF A PHYSICAL ATTACK MOVE, TAKING INTO ACCOUNT THE ATTACKER'S ATK,
//THE DEFENDER'S DEF (INCLUDING BUFFS), THE MOVE'S POWER, AND WHETHER IT'S A CRITICAL HIT.
int computephysDamage(const Fighter& attacker, const Fighter& defender, const Move& move, bool crit);

//FUNCTION TO COMPUTE THE DAMAGE OF A MAGIC ATTACK MOVE, TAKING INTO ACCOUNT THE ATTACKER'S INTELLIGENCE,
//THE DEFENDER'S MAGIC DEFENSE (INCLUDING BUFFS), THE MOVE'S POWER, AND WHETHER IT'S A CRITICAL HIT.
int computemagDamage(const Fighter& attacker, const Fighter& defender, const Move& move, bool crit);

//FUNCTION TO APPLY A MOVE FROM ONE FIGHTER TO ANOTHER
void applyMove(Fighter* user, Fighter* target, Move* move, RNG& rng);

#endif