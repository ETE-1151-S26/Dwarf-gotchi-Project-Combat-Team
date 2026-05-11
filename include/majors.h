#ifndef MAJORS_H
#define MAJORS_H
#include <iostream>
#include <string>
#include <Arduino.h>

//REFER TO "major-stats.h" AND "major-stats.cpp" THIS IS AN OLD FILE. 

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
const MajorConfig ENGINEERING_STATS = {"Engineering", 20, 90, "spell name"};
const MajorConfig COMPUTING_AND_INFORMATION_STATS = {"Computing and Information", 25, 85, "spell name" };
const MajorConfig EDUCATION_STATS = {"Education", 25, 85, "spell name" };
const MajorConfig BUSINESS_STATS = {"Business", };
const MajorConfig NATURAL_SCIENCE_STATS = {"Natural Science", };
const MajorConfig MATH_STATS = {"Maethematics", };
const MajorConfig SOCIAL_SCIENCES_STATS = {"Social Science",};
const MajorConfig HUMANITITES_STATS = {"Humanities", };
const MajorConfig ARTS_STATS = {"Art", };
const MajorConfig ARCHITECTURE_STATS = {"Architecture and Design", };
const MajorConfig LAW_STATS = {"Law and Public Service", };
const MajorConfig AGRI_ENV_STATS = {"Agriculture and Environment", };
const MajorConfig COMMUNICATIONS_STATS = {"Communications", };
const MajorConfig INTERDISCIPLINARY_STATS = {"Interdisciplinary", };

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

class ComputingAndInformation : public Student {
    public:
        ComputingAndInformation() : Student(COMPUTING_AND_INFORMATION_STATS) {}
        void castSpell() override {}
};

#endif

