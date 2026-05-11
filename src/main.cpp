#include <iostream>
#include <random>
#include <string>
#include "battle-logic.h"
#include "major-stats.h"

int main() {

    Fighter player{};
    Fighter enemies[1];
 
    player = engineering();
    player.name = "Player";
    enemies[0] = naturalScience();
    enemies[0].name = "Enemy";
    
    RNG rng;
    battleLoop(player, enemies, rng);

}