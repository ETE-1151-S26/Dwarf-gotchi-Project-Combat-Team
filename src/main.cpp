#include <iostream>
#include <random>
#include <string>
#include "battle-logic.h"
#include "major-stats.h"

int main() {

    
//Creates player based on class selection
    Fighter player{};
    Fighter enemies[1];
 
    player = emset();
    enemies[0] = compsci();
    
    RNG rng;
    battleLoop(player, enemies, rng);

}