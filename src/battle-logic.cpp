#include <iostream>
#include "battle-logic.h"
#include "major-stats.h"

int computeDamage(const Fighter& attacker, const Fighter& defender, const Move& move, bool crit) {

//base = the move's power + the attacker's attack stat - the defender's defense stat (including buffs). Minimum base is 1.
//crit multiplies by 1.5 (rounded down)
    int effectiveDef = defender.def + defender.defBuff;

    int base = move.power + attacker.atk - effectiveDef;
    if (base < 1) base = 1;

    if (crit) {
        base = (base * 3) / 2; // 1.5x
        if (base < 1) base = 1;
    }

    return base;

}

void applyMove(Fighter* attacker, Fighter* defender, Move* move, RNG& rng, int difficultyLevel = 0, bool isPlayerDefender = false) {

//Pointers used intentionally so HP and buffs update the real fighters.
std::cout << attacker->name << " used " << move->name << "!\n";

//If the move is an attack, crit chance is checked, and damage is computed and applied to the enemy
//If the move is a heal, the player heals for the move's power, up to their max HP
//If the move is a defend, the player's defense buff increases by the move's power for the rest of the battle
switch (move->kind) {
        case MoveKind::Attack: {

            bool crit = rng.chance(move->critChance);
            int dmg = computeDamage(*attacker, *defender, *move, crit);
            defender->hp -= dmg;
            if (defender->hp < 0) defender->hp = 0;

            if (crit) std::cout << "Critical hit!\n";
            std::cout << defender->name << " took " << dmg << " damage.\n";
            break;

        }
        case MoveKind::Heal: {

            int heal = move->power;
            int before = attacker->hp;
            attacker->hp += heal;
            if (attacker->hp > attacker->maxHP) attacker->hp = attacker->maxHP;
            std::cout << attacker->name << " healed " << (attacker->hp - before) << " HP.\n";
            break;

        }
        case MoveKind::Defend: {

            attacker->defBuff += move->power;
            std::cout << attacker->name << "'s defense rose by " << move->power << "!\n";
            break;

        }
    }
}

Move* chooseEnemyMove(Fighter* enemy, RNG& rng) {

//Picks a random move for the enemy
    int pick = rng.rollInt(0, 2);
    return &enemy->moves[pick];
}

void printHPBar(const Fighter& f) {

//Simple bar of 20 blocks
//Temporary while we don't have a screen to display an actual bar
    const int barWidth = 20;
    int filled = (f.maxHP > 0) ? (f.hp * barWidth) / f.maxHP : 0;
    if (filled < 0) filled = 0;
    if (filled > barWidth) filled = barWidth;

    std::cout << f.name << " (" << f.className << ")\n";
    std::cout << "HP: " << f.hp << "/" << f.maxHP << "  [";
    for (int i = 0; i < barWidth; i++) std::cout << (i < filled ? '#' : '-');
    std::cout << "]\n";
    std::cout << "ATK: " << f.atk << "  DEF: " << f.def << "  SPD: " << f.spd
         << "  (DEF Buff: +" << f.defBuff << ")\n";

}

void showMoves(const Fighter& player) {

//Displays the player's moves with their stats, and prompts the player to choose one.
    std::cout << "\nChoose a move:\n";
    for (int i = 0; i < 4; i++) {
        const Move& m = player.moves[i];
        std::cout << "  " << (i + 1) << ") " << m.name;

        if (m.kind == MoveKind::Attack) {
            std::cout << "  [Attack | Power " << m.power << " | Crit " << m.critChance << "%]";
        } else if (m.kind == MoveKind::Heal) {
            std::cout << "  [Heal   | +" << m.power << " HP ";
        } else {
            std::cout << "  [Defend | +" << m.power << " DEF ";
        }
        std::cout << "\n";
    }

}

int promptChoiceInt(const std::string& prompt, int minVal, int maxVal) {

//Prompts the user to enter an integer between minVal and maxVal, and validates the input.
    while (true) {
        std::cout << prompt;
        int x;
        if (std::cin >> x && x >= minVal && x <= maxVal) {
            clearInputLine();
            return x;
        }
        clearInputLine();
        std::cout << "Invalid input. Choose " << minVal << " to " << maxVal << ".\n";
    }

}

void battle(Fighter* player, Fighter* enemy, RNG& rng, int difficultyLevel) {

    std::cout << "\n==============================\n";
    std::cout << "ENCOUNTER: " << enemy->name << " appears!\n";
    std::cout << "==============================\n";

    // Reset temporary buffs at battle start
    player->defBuff = 0;
    enemy->defBuff = 0;

    while (player->hp > 0 && enemy->hp > 0) {
        std::cout << "\n--- STATUS ---\n";
        printHPBar(*player);
        std::cout << "\n";
        printHPBar(*enemy);

        //Speed decides order each round (tie -> player first)
        bool playerFirst = (player->spd >= enemy->spd);

        //Shows moves and prompts player to choose one, or picks a random move for the enemy, depending on who goes first.
        if (playerFirst) {
            showMoves(*player);
            int choice = promptChoiceInt("Enter 1-3: ", 1, 3);
            Move* playerMove = &player->moves[choice - 1]; // pointer to chosen move
            applyMove(player, enemy, playerMove, rng, 0, false); // Player attacks, no dodge for enemy
            if (enemy->hp <= 0) break;

            Move* enemyMove = chooseEnemyMove(enemy, rng);
            applyMove(enemy, player, enemyMove, rng, difficultyLevel, true); // Enemy attacks, player can dodge via trivia
        } else {
            Move* enemyMove = chooseEnemyMove(enemy, rng);
            applyMove(enemy, player, enemyMove, rng, difficultyLevel, true); // Enemy attacks, player can dodge via trivia
            if (player->hp <= 0) break;

            showMoves(*player);
            int choice = promptChoiceInt("Enter 1-3: ", 1, 3);
            Move* playerMove = &player->moves[choice - 1];
            applyMove(player, enemy, playerMove, rng, 0, false); // Player attacks, no dodge for enemy
        }
    }

    //Displays the outcome of the battle. If the player's HP is 0 or less, they were defeated. Otherwise, the enemy was defeated.
    if (player->hp <= 0) {
        std::cout << "\n" << player->name << " was defeated...\n";
    } else {
        std::cout << "\n" << enemy->name << " was defeated!\n";
        int difficultyLevel = difficultyLevel + 1;
    }

}