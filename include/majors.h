#ifndef MAJORS_H
#define MAJORS_H
#include <iostream>
#include <string>
#include <Arduino.h>


struct MajorConfig{
    const char* name;
    int strength;
    int intelligence;
    const char* spellName;
   // const char* spellDesc;
};

//Theses are global variables/stats defined for each class to be used wherever needed in the code
//In order, it is Major Name, Strength, Intelligence, Spell Name, and Spell Desc
//Values are NOT FINAL
const MajorConfig CS_STATS = {"CompSci", 20, 90, "Showerless Odor"};
const MajorConfig ECE_STATS = {"ElectricalEngineering", 30, 80, "Kirchoff's Wrath" };

//==================================
//BASE CLASS to define majors off of
//==================================
class Student {
private:
    MajorConfig stats;
    int currentHealth;

public:
    Student(MajorConfig config)
        : stats(config), currentHealth(100) {}

    virtual ~Student() {}

    //each major will define this spell
    virtual void castSpell() = 0;

    //get functions to access stats
    std::string getMajorName() {return stats.name;}
    std::string getSpellName() {return stats.spellName;}
    int getStr() {return stats.strength;}
    int getIntel() {return stats.intelligence;}
    int getHealth() {return currentHealth;}
};

//==================================
//SPECFIFIC MAJOR CLASSES
//==================================

class CompSci : public Student {
    public:
        CompSci() : Student(CS_STATS) {}
        void castSpell() override {}
};
#endif
