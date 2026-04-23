#ifndef BATTLE-LOGIC_HPP
#define BATTLE-LOGIC_HPP
#include <random>
#include <string>

//MOVEKIND IS AN ENUM CLASS THAT DEFINES THE KIND OF MOVE, WHETHER IT BE AN ATTACK, HEAL OR DEFEND
enum class MoveKind {Attack, Heal, Defend};

//MOVE STRUCTURE DEFINES THE NAME OF THE MOVE, ITS KIND, POWER, ACCURACY AND CRIT CHANCE
struct Move {
	std::string name;
	MoveKind kind;
	int power;
	int critChance; // 0-100
};

//FIGHTER STRUCTURE DEFINES THE NAME, CLASSNAME, HP, ATK, DEF, SPD, A TEMPORARY DEFENSE BUFF, AND AN ARRAY OF MOVES
struct Fighter {
	std::string name;
	std::string className;

	int maxHP;
	int hp;
	int atk;
	int def;
	int spd;
    int defBuff;
	Move moves[3];

};

//RNG STRUCT FOR RANDOM NUMBER GENERATION
struct RNG {

	std::mt19937 gen;
	RNG() : gen(std::random_device{}()) {}

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

//FUNCTION TO COMPUTE THE DAMAGE OF AN ATTACK MOVE, TAKING INTO ACCOUNT THE ATTACKER'S ATK,
//THE DEFENDER'S DEF (INCLUDING BUFFS), THE MOVE'S POWER, AND WHETHER IT'S A CRITICAL HIT.
int computeDamage(const Fighter& attacker, const Fighter& defender, const Move& move, bool crit);

//FUNCTION TO APPLY A MOVE FROM ONE FIGHTER TO ANOTHER
void applyMove(Fighter* user, Fighter* target, Move* move, RNG& rng);

#endif