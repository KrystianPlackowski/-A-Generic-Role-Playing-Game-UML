#ifndef RACES_H
#define RACES_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Character.h"

using namespace std;




class Orc : public Character {								// typ postaci 1

public:
	
    virtual vector <string> getAdjectives() { vector<string>V; return V;}
    

    virtual void setName( string name_) { this->Name = name_;}
    virtual string getName() { return this->Name;}
    virtual string getRace() { return "orc";}
    

    virtual double getStrength() { return 100;}
    virtual double getInteligence() { return 50;}
    virtual double getDexterity() { return  10;}
    virtual double getBodyMass() { return  95;}
};


class Elf : public Character {								// typ postaci 2

public:
    
    virtual vector <string> getAdjectives() { vector<string>V; return V;}
        
        

    virtual void setName( string name_) { this->Name = name_;}
    virtual string getName() { return this->Name;}
    virtual string getRace() { return "elf";}
    

    virtual double getStrength() { return 50;}
    virtual double getInteligence() { return 20;}
    virtual double getDexterity() { return  50;}
    virtual double getBodyMass() { return  45;}
};

#endif
