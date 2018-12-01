#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Entity.h"
#include "Items.h"

using namespace std;




class Character : public Entity {

public:
	
	 string Name;
	 
	 virtual string getName() = 0;

	 virtual void setName( string name_) = 0;




     virtual vector <string> getAdjectives() = 0;
     
     virtual string getRace() = 0;

     virtual double getStrength() = 0;

     virtual double getInteligence() = 0;

     virtual double getDexterity() = 0;

     virtual double getBodyMass() = 0;
     
     




     
     Weapon *bron;
     
     vector <Item*> rzecz;

     Armor *zbroja;
     
     
     
     void wear( Armor *ptr) { zbroja = ptr;}

     void wield( Weapon *ptr) { bron = ptr;}
     
     void carry( Item *ptr) { if( getSize()+ptr->getSize() < 10) rzecz.push_back(ptr);}
     // jesli suma rozmiarow itemow w sakwie razem z nowym itemem przekracza 10, to go nie podnos
     

     

     virtual double getSpeed() { 
		 
		 speed = this->getStrength() / this->getWeight();
		 
		 V = this->getAdjectives();		
		 
		 for( int i=0; i < V.size(); i++)		// jesli drunk, to odejmij 2 speedu
			if( V[i] == "drunk")
				speed -= 2;
			
		 return speed;
	 }

     virtual double getArmor() { return zbroja != NULL ? zbroja->getArmor() : 0;}

     virtual double getPower() { return bron != NULL ? bron->getPower() : 0;}
     
     
     
     
     
     
          
	 virtual double getSize() { 				// znajdz sume rozmiarow itemow w sakwie
		 
		totalSize = 0;
		 
		for( int i=0; i < rzecz.size(); i++)
			totalSize += rzecz[i]->getSize();
		
		//totalSize += zbroja->getSize();
		//totalSize += bron->getSize();
		
		return totalSize;
	}
	
	
	
	
	
	virtual double getWeight() { 				// znajdz ciezar itemow + mase ciala
		 
		totalWeight = this->getBodyMass();
		 
		for( int i=0; i < rzecz.size(); i++)
			totalWeight += rzecz[i]->getWeight();
		
		if( zbroja != NULL)
			totalWeight += zbroja->getWeight();
		if( bron != NULL)
			totalWeight += bron->getWeight();
		
		return totalWeight;
	}
	
     
     
     

     
    virtual string getDescription() { 
		 
		 
		V = this->getAdjectives();			// wektor przymiotnikow
				
		fullName = "";

		if( this->getName().size() > 0)		// jesli imie jest nadane badz nie
			fullName += getName() + " the ";
		else if( V.size() > 0 && V[0][0] != 'o')
			fullName += "a ";
		else if( V.size() == 0 || ( V.size() > 0 && V[0][0] == 'o'))
			fullName += "an ";
	
		
		for( int i=0; i < V.size(); i++) {	// wypisz przymiotniki
			
			fullName += V[i];
			if (i < V.size()-1)
				fullName += ", ";
			else
				fullName += " ";
		}
		
		
		fullName += getRace();
		
		if( bron != NULL)
			fullName += ", wielding " + bron->getDescription();
		
		if( zbroja != NULL)
			fullName += ", wearing " + zbroja->getDescription();
			
		if( rzecz.size() > 0)
			fullName += ", and carrying ";
				
		for( int i=0; i < rzecz.size(); i++) {	// wypisz przedmioty w sakwie
			
			fullName += rzecz[i]->getDescription();
			if (i < rzecz.size()-1)
				fullName += ", ";
		}
		
		
		return fullName;
	}
     
     
     
     
     	
     
	virtual string getJSON() {
		
				
		string result;

		
		result = "{\n";

		result += "\"type\": \"Character\",\n";
		
		if( this->getName().size() > 0)
			result += "\"name\": \"" + this->getName() + "\",\n";
			
		result += "\"race\": \"" + this->getRace() + "\",\n";
		
		
		V = this->getAdjectives();
		if( V.size() > 0) {						// wypisz przymiotniki
			
			result += "\"adjectives\": ";
			
			for( int i=0; i < V.size(); i++)
				result += "[ \"" + V[i] + "\" ], ";
			result += "\n";
			
		}
		
		
		
		if( bron != NULL) {
			
			result += "\"wield\":\n";
			result += bron->getJSON();
		}
		
		
		
		if( zbroja != NULL) {
			
			result += "\"wear\":\n";
			result += zbroja->getJSON();
		}
		
		
		
		
		if( rzecz.size() > 0) {
			
			result += "\"carry\": [\n";
				
			for( int i=0; i < rzecz.size(); i++) // wypisz przedmioty w sakwie
				result += rzecz[i]->getJSON();
	
		
			result.erase( result.end()-2);
			result += "]\n";
		}
		else
			result.erase( result.end()-2);
		
			
			
		return result + "}";
	}
	
	
    
    
     
	
	
	
private:

	vector <string> V;
    string fullName;
    double speed;
    double totalSize;
 	double totalWeight;
};





#endif
