#ifndef DECORATORS_H
#define DECORATORS_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Races.h"
#include "Character.h"

using namespace std;




class HalfWit : public Character {							// dekorator 1

public:

	Character *obj;
	
	HalfWit( Character *ptr): obj(ptr) {	// konstruktor


		this->bron = ptr->bron;				// daj bron half-witowi
		ptr->bron = NULL;					// zabierz bron characterowi
		
		this->zbroja = ptr->zbroja;			// daj zbroje half-witowi
		ptr->zbroja = NULL;					// zabierz zbroje characterowi
		
		this->rzecz = ptr->rzecz;			// daj rzeczy half-witowi
		ptr->rzecz.clear();					// zabierz rzeczy characterowi

	}
	
	
	
	virtual vector <string> getAdjectives() {		// funkcja zbierajaca przymiotniki
		
		vector<string>V = obj->getAdjectives();
		V.push_back("half-wit");
		return V;
	}


	virtual void setName( string name_) { obj->setName(name_);}
	virtual string getName() { return obj->getName();}
	virtual string getRace() { return obj->getRace();}
	


    virtual double getStrength() { return obj->getStrength();}
    virtual double getInteligence() { return obj->getInteligence() / 2;}
    virtual double getDexterity() { return obj->getDexterity();}
    virtual double getBodyMass() { return obj->getBodyMass();}
};




class Fatten: public Character {							// dekorator 2

public:

	Character *obj;
	
	Fatten( Character *ptr): obj(ptr) {		// konstruktor

		
		this->bron = ptr->bron;				// daj bron half-witowi
		ptr->bron = NULL;					// zabierz bron characterowi

		this->zbroja = ptr->zbroja;			// daj zbroje half-witowi
		ptr->zbroja = NULL;					// zabierz zbroje characterowi
		
		this->rzecz = ptr->rzecz;			// daj rzeczy half-witowi
		ptr->rzecz.clear();					// zabierz rzeczy characterowi
		
	}
	
	
	
	virtual vector <string> getAdjectives() {		// funkcja zbierajaca przymiotniki
		
		vector<string>V = obj->getAdjectives();
		V.push_back("overweight");
		return V;
	}
	
	

	virtual void setName( string name_) { obj->setName(name_);}
	virtual string getName() { return obj->getName();}
	virtual string getRace() { return obj->getRace();}
	


    virtual double getStrength() { return obj->getStrength();}
    virtual double getInteligence() { return obj->getInteligence();}
    virtual double getDexterity() { return obj->getDexterity();}
    virtual double getBodyMass() { return obj->getBodyMass() * 2;}
};




class TurboMixture : public Character {						// dekorator 3

public:

	Character *obj;
	
	TurboMixture( Character *ptr): obj(ptr) {	// konstruktor

		
		this->bron = ptr->bron;				// daj bron half-witowi
		ptr->bron = NULL;					// zabierz bron characterowi
		
		this->zbroja = ptr->zbroja;			// daj zbroje half-witowi
		ptr->zbroja = NULL;					// zabierz zbroje characterowi
		
		this->rzecz = ptr->rzecz;			// daj rzeczy half-witowi
		ptr->rzecz.clear();					// zabierz rzeczy characterowi
		
	}
	
	
	
	virtual vector <string> getAdjectives() {		// funkcja zbierajaca przymiotniki
		
		vector<string>V = obj->getAdjectives();
		V.push_back("drunk");
		return V;
	}
	
	

	virtual void setName( string name_) { obj->setName(name_);}
	virtual string getName() { return obj->getName();}
	virtual string getRace() { return obj->getRace();}
	


    virtual double getStrength() { return obj->getStrength();}
    virtual double getInteligence() { return obj->getInteligence();}
    virtual double getDexterity() { return obj->getDexterity() - 20;}
    virtual double getBodyMass() { return obj->getBodyMass();}
};

#endif
