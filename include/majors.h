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

    const char* spellName;
   // const char* spellDesc; <------ not sure if we have enough room on the screen for a spell description, but we can add later
};

//Theses are global variables/stats defined for each class to be used wherever needed in the code
//In order, stats are: {"Major Name", Strength, Intelligence, "Spell Name"};
//Values are NOT FINAL
const MajorConfig ENGINEERING_STATS = {"Engineering", 20, 90, "Showerless Odor"};
const MajorConfig COMPUTING_AND_INFORMATION_STATS = {"Computing and Information", 25, 85, "Curriculum Chaos" };
const MajorConfig EDUCATION_STATS = {"Education", 25, 85, "Curriculum Chaos" };
const MajorConfig BUSINESS_STATS = {};
const MajorConfig NATURAL_SCIENCE_STATS = {};
const MajorConfig MATH_STATS = {};
const MajorConfig SOCIAL_SCIENCES_STATS = {};
const MajorConfig HUMANITITES_STATS = {};
const MajorConfig ARTS_STATS = {};
const MajorConfig ARCHITECTURE_STATS = {};
const MajorConfig LAW_STATS = {};
const MajorConfig AGRI_ENV_STATS = {};
const MajorConfig COMMUNICATIONS_STATS = {};
const MajorConfig INTERDISCIPLINARY_STATS = {};
const

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

