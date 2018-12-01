#include "Entities/Entities.h"
#include <stdio.h>
#include <iostream>

int main() {
	
	

	Character * orc = new Orc();
	
	cout << orc->getDescription() << endl;
	
	orc->wield(new Brick());
	
	cout << orc->getDescription() << endl;
	
	orc->carry(new Socks());
	
	cout << orc->getDescription() << endl;
	
	orc = new HalfWit(orc);
	
	cout << orc->getDescription() << endl;
	
	orc->setName("John");
	
	cout << orc->getDescription() << endl;
	
	orc->wear(new PlateArmor());
	
	cout << orc->getDescription() << endl;

	cout << orc->getJSON() << endl;

	return 0;
}
