#include "Entities/Entities.h"
#include <iostream>

int main() {
  Entity * elf = new Elf();
  std::cout << elf.getDescription() << "\n";
  delete elf;

  Entity * halfwitOrc = new HalfWit(new Orc());
  std::cout << halfwitOrc.getDescription() << "\n";
  delete halfwitOrc;
  
  Entity * armoredOrc = new Orc();
  armoredOrc.wear(new PlateArmor());
  armoredOrc.wield(new Brick());
  armoderOrc.carry(new Axe());
  armoderOrc.carry(new TireBouchon());
  std::cout << armoredOrc.getDescription() << "\n";
  delete armoredOrc;

  Entity * heavyElf = new Elf();
  for (int i=0; i<30; i++) heavyElf.carry(new Brick());
  std::cout << heavyElf.getDescription() << "\n";
  delete heavyElf;
}
