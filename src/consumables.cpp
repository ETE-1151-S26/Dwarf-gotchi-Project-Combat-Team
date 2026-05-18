// consumables.cpp
#include <iostream>
#include <string>

class Player {
private:
    int health;
    int strength;
    int speed;

public:
    Player(int hp, int str, int spd)
        : health(hp), strength(str), speed(spd) {}

    // Stat modifiers
    void heal(int amount) {
        health += amount;
        std::cout << "Recovered " << amount << " HP!\n";
    }

    void increaseStrength(int amount) {
        strength += amount;
        std::cout << "Strength increased by " << amount << "!\n";
    }

    void increaseSpeed(int amount) {
        speed += amount;
        std::cout << "Speed increased by " << amount << "!\n";
    }

    // Display current stats
    void showStats() const {
        std::cout << "\n=== PLAYER STATS ===\n";
        std::cout << "Health   : " << health << "\n";
        std::cout << "Strength : " << strength << "\n";
        std::cout << "Speed    : " << speed << "\n";
    }
};

// Base consumable class
class Consumable {
protected:
    std::string name;

public:
    Consumable(std::string n) : name(n) {}

    virtual void use(Player& player) = 0;

    virtual ~Consumable() {}
};

// Health Potion
class HealthPotion : public Consumable {
private:
    int healAmount;

public:
    HealthPotion(int amount)
        : Consumable("Health Potion"), healAmount(amount) {}

    void use(Player& player) override {
        std::cout << "\nUsing " << name << "...\n";
        player.heal(healAmount);
    }
};

// Strength Potion
class StrengthPotion : public Consumable {
private:
    int boostAmount;

public:
    StrengthPotion(int amount)
        : Consumable("Strength Potion"), boostAmount(amount) {}

    void use(Player& player) override {
        std::cout << "\nUsing " << name << "...\n";
        player.increaseStrength(boostAmount);
    }
};

// Speed Potion
class SpeedPotion : public Consumable {
private:
    int boostAmount;

public:
    SpeedPotion(int amount)
        : Consumable("Speed Potion"), boostAmount(amount) {}

    void use(Player& player) override {
        std::cout << "\nUsing " << name << "...\n";
        player.increaseSpeed(boostAmount);
    }
};

int main() {
    // Example player
    Player hero(100, 15, 10);

    // Potions
    HealthPotion hpPotion(30);
    StrengthPotion strPotion(5);
    SpeedPotion spdPotion(3);

    hero.showStats();

    // Use consumables
    hpPotion.use(hero);
    strPotion.use(hero);
    spdPotion.use(hero);

    hero.showStats();

    return 0;
}