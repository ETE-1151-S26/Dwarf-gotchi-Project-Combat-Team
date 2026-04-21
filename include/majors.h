#ifndef MAJORS_H
#define MAJORS_H
#include <iostream>
#include <string>
#include <Arduino.h>

//MR POWERS IS BASICALLY HANDLING ALL THIS, SO IGNORE THIS FILE FOR NOW

struct MajorConfig{
    const char* name;
    int strength;
    int intelligence;
    int dexterity;
    
    const char* spellName;
   // const char* spellDesc; <------ not sure if we have enough room on the screen for a spell description, but we can add later
};

//Theses are global variables/stats defined for each class to be used wherever needed in the code
//In order, stats are: {"Major Name", Strength, Intelligence, "Spell Name"};
//Values are NOT FINAL
const MajorConfig CS_STATS = {"CompSci", 20, 90, "Showerless Odor"};
const MajorConfig ECE_STATS = {"ElectricalEngineering", 30, 80, "Kirchoff's Wrath" };

//==================================
//BASE CLASS to define majors off of
//==================================
class Student {
private:
    MajorConfig stats;
    int playerHealth;

public:
    Student(MajorConfig config)
        : stats(config), playerHealth(100) {}

    virtual ~Student() {}

    //each major will define this spell
    virtual void castSpell() = 0;

    //get functions to access stats
    std::string getMajorName() {return stats.name;}
    std::string getSpellName() {return stats.spellName;}
    int getStr() {return stats.strength;}
    int getIntel() {return stats.intelligence;}
    int getHealth() {return playerHealth;}
};

//==================================
//SPECFIFIC MAJOR CLASSES inherited from base class Student
//==================================

class CompSci : public Student {
    public:
        CompSci() : Student(CS_STATS) {}
        void castSpell() override {}
};
#endif

