#include "Entities/Entities.h"
#include <iostream>

int main() {
  Character * orc = new Orc();
  std::cout << "I'm " << orc->getDescription() << ".\n";
  orc->wield(new Brick());
  std::cout << "I'm " << orc->getDescription() << ".\n";
  orc->carry(new Socks());
  std::cout << "I'm " << orc->getDescription() << ".\n";
  orc = new HalfWit(orc);
  std::cout << "I'm " << orc->getDescription() << ".\n";
  orc->setName("John");
  std::cout << "I'm " << orc->getDescription() << ".\n";
  orc->wear(new PlateArmor());
  std::cout << "I'm " << orc->getDescription() << ".\n";
  orc->carry(new Socks());
  std::cout << "I'm " << orc->getDescription() << ".\n";

  std::cout << "My weight is "      << orc->getWeight() << ".\n";
  std::cout << "My strength is "    << orc->getStrength() << ".\n";
  std::cout << "My inteligence is " << orc->getInteligence() << ".\n";
  std::cout << "My dexterity is "   << orc->getDexterity() << ".\n";
  std::cout << "My speed is "       << orc->getSpeed() << ".\n";
  std::cout << "My armor is "       << orc->getArmor() << ".\n";
  std::cout << "My power is "       << orc->getPower() << ".\n";
}
