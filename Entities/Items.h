#ifndef ITEMS_H
#define ITEMS_H

#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;




class Item  {
	
public:
	
	virtual string getDescription() { return this->getDescription();}
	virtual double getSize() { return this->getSize();}
	virtual double getWeight() { return this->getWeight();}
	
	
	
	virtual string getJSON() = 0;
	virtual string getName() = 0;

};

class Weapon : public Item {

public:

	virtual double getPower() { return this->getPower();}
	
	
};

class Armor : public Item {
	
public:
	
	virtual double getArmor() { return this->getArmor();}
	
};




class SeveredHand : public Item {
	
public:
	
	virtual string getDescription() { return "a severed hand";}
	virtual string getName() { return "severed hand";}
	virtual double getWeight() { return 5;}
	virtual double getSize() { return 1;}
	
	
	virtual string getJSON() {
		
		string result;
		
		result = "\t\"type\": \"Item\",\n";
		result += "\t\"name\": \"severed hand\",\n";
		result += "\t\"weight\": 5,\n";
		result += "\t\"size\": 1\n";
			
		return "{\n" + result + "},\n";
	}
	
};



class Brick : public Weapon {
	
public:
	
	virtual string getDescription() { return "a brick";}
	virtual string getName() { return "brick";}
	virtual double getPower() { return 5;}
	virtual double getWeight() { return 1;}
	virtual double getSize() { return 0.5;}
	
	
	virtual string getJSON() {
		
		string result;
		
		result = "\t\"type\": \"Weapon\",\n";
		result += "\t\"name\": \"brick\",\n";
		result += "\t\"power\": 5,\n";
	    result += "\t\"weight\": 1,\n";
		result += "\t\"size\": 0.5\n";
			
		return "{\n" + result + "},\n";
	}
};

class TireBouchon : public Weapon {
	
public:
	
	virtual string getDescription() { return "a tire bouchon";}
	virtual string getName() { return "tire bouchon";}
	virtual double getPower() { return 10;}
	virtual double getWeight() { return 0.05;}
	virtual double getSize() { return 0.1;}
	
	
	virtual string getJSON() {
		
		string result;
		
		result += "\t\"type\": \"Weapon\",\n";
		result += "\t\"name\": \"tire bouchon,\n";
		result += "\t\"power\": 10,\n";
	    result += "\t\"weight\": 0.05,\n";
		result += "\t\"size\": 0.1\n";
			
		return "{\n" + result + "},\n";
	}
};

class Axe : public Weapon {
	
public:
	
	virtual string getDescription() { return "an axe";}
	virtual string getName() { return "axe";}
	virtual double getPower() { return 30;}
	virtual double getWeight() { return 3;}
	virtual double getSize() { return 1;}
	
	
	virtual string getJSON() {
		
		string result;
		
		result = "\t\"type\": \"Weapon\",\n";
		result += "\t\"name\": \"axe\",\n";
		result += "\t\"power\": 30,\n";
	    result += "\t\"weight\": 3,\n";
		result += "\t\"size\": 1\n";
			
		return "{\n" + result + "},\n";
	}
};



class Socks : public Armor {
	
public:
	
	virtual string getDescription() { return "some socks";}
	virtual string getName() { return "socks";}
	virtual double getArmor() { return 2;}
	virtual double getWeight() { return 0.03;}
	virtual double getSize() { return 0.01;}
	
	
	virtual string getJSON() {
		
		string result;
		
		result = "\t\"type\": \"Armor\",\n";
		result += "\t\"name\": \"socks\",\n";
		result += "\t\"armor\": 2,\n";
	    result += "\t\"weight\": 0.03,\n";
		result += "\t\"size\": 0.01\n";
			
		return "{\n" + result + "},\n";
	}
};

class PlateArmor : public Armor {
	
public:
	
	virtual string getDescription() { return "a plate armor";}
	virtual string getName() { return "plate armor";}
	virtual double getArmor() { return 50;}
	virtual double getWeight() { return 20;}
	virtual double getSize() { return 3;}
	
	
	virtual string getJSON() {
		
		string result;
		
		result = "\t\"type\": \"Armor\",\n";
		result += "\t\"name\": \"plate armor\",\n";
		result += "\t\"armor\": 50,\n";
	    result += "\t\"weight\": 20,\n";
		result += "\t\"size\": 3\n";
			
		return "{\n" + result + "},\n";
	}
};

#endif
