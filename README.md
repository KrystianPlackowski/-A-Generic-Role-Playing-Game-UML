# A Generic Role Playing Game (pun intended)

## Task
### English
Implement class structure described below on a diagram [UML diagram](https://en.wikipedia.org/wiki/Unified_Modeling_Language).
Add all files in the `Entities` directory separating classes into `.h` and `.cpp` files.
Include all relevant headers in the `Entities/Entities.h` file.

### Polski
Zaimplementuj strukturę klas przedstawioną na schemacie poniżej [UML diagram](https://pl.wikipedia.org/wiki/Unified_Modeling_Language).
Dodaj wszystkie pliki w katalogu `Entities`, dzieląc klasy na pliki `.h` i `.cpp`.
Załącz wszystkie potrzebne pliki nagłówkowe w `Entities/Entities.h`.

## Rulebook
![UML diagram](uml.png)

### Clarifications:
The weight of the character is the sum of its body mass and all equipment he carries.
Character can carry any number of items that fit in a sack of size `100`.
Character can wield only one weapon, and wear only one armor.
Character's speed is equal to it's strength divided by his total weight.

### Description:
The `getDescription` function should return a string that (as the name suggest) describe the item/character, and should include (for a character):
- Name (if present)
- Race
- Decorators
- Weapon (if any)
- Armor (if any)
- other Items (if any)

for instance:
`a half-wit orc, wielding a brick, wearing a plate armor, and carrying some socks and a severed hand`

### Usage:
```c++
Character elf = new Elf();
// I'm an elf.
elf.wield(new Axe());
// I'm an elf wielding an Axe.
elf.carry(new Brick());
// I'm an elf wielding an Axe and carrying a brick.
elf = new Fatten(elf);
// I'm an overweight elf wielding an Axe and carrying a brick.
elf.setName("John");
// I'm John the overweight elf wielding an Axe and carrying a brick.
elf.getSpeed();
// (50)/(2*45+3+1) = 0.53191489361
```

### JSON
The `getJSON` function should return a computer-readable data about the item/character in the [JSON format](https://en.wikipedia.org/wiki/JSON). For example (for the same character as above):
```json
{
	"type": "Character",
	"name": "",
	"race": "orc",
	"adjectives": [ "half-wit" ],
	"wield": {
		"type": "Weapon",
		"name": "brick",
		"power": 5,
		"weight": 1,
		"size": 0.5
	},
	"wears": {
		"type": "Armor",
		"name": "plate armor",
		"armor": 50,
		"weight": 20,
		"size": 3
	},
	"carries": [
		{
			"type": "Armor",
			"name": "socks",
			"armor": 2,
			"weight": 0.03,
			"size": 0.01
		},
		{
			"type": "Item",
			"name": "severed hand",
			"weight": 5,
			"size": 1
		}
	]
}
```
**The JSON string doesn't have to be formated the same way! But it have to be a valid JSON.**

## Requirements

Only files in the `Entities` directory will be considered as solution.

## Acknowledgments

Idea by [G. Gruszczynski](https://github.com/ggruszczynski). UML diagram done with [`yuml.me`](https://yuml.me/).