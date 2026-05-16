#ifndef LEVELS_H
#define LEVELS_H

struct Fighter;

//caps level at level 10
const int maxLevel = 10;

//for determing how much exp is needed to level up.
int requiredExp(int level);

//add exp to the player, if max level is not reached
void addExp(Fighter& f, int expGained);

//increments base stats with each level up
void levelUp(Fighter& f);

#endif