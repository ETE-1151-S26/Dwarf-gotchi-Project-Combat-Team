#include <iostream>
#include <random>
#include <string>
#include "battle-logic.h"
#include "major-stats.h"

int main() {

    Fighter player{};
    Fighter enemies[1];
 
    player = engineering();
    enemies[0] = compsci();
    
    RNG rng;
    battleLoop(player, enemies, rng);

}