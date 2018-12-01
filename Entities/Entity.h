#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;




class Entity {

public:


    virtual string getName() = 0;

    virtual string getDescription() = 0;
	
    virtual string getJSON() = 0;

    virtual double getWeight() = 0;
};

#endif
