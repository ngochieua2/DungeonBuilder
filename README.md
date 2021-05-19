# DungeonBuilder

Dungeon builder is a C++ software and developed on Qt in order to create a map level in a Roguelike Dungeon game. 
Each dungeon level will comprise a set of rooms, connected by doors, with the possibility of a random monster and/or loot items (weapons or consumables such as potions). 
The items and monsters will display on some rooms, but they will not be completely game capable.
A text-based menu will allow the user to generate dungeon levels with a small set of parameters and display them to the console.

This project is created according to object-oriented design, some design pattern 
use some C++ features such as: class inheritance and polymorphism, dynamic memory allocation, and smart pointers

## Design Patterns:

* **Singleton:** use to make sure only one program (instance ) is created and run at a time
* **Builder:** use to build a level from smallest components like doors, walls, mosters, items to larger components like: a room and then a level with a collection of rooms
* **Prototype:**  use to clone some given monster, so it will optimize code

## Class Diagram:

![classDiagram](https://res.cloudinary.com/ngochieua2/image/upload/v1621400139/github/classDiagram_jhysnk.png)

## Features:

### Describing a Dungeon and its Components:

It will show information of a Dungeon level or a selected room after a Dungeon is created

For example:

Example Dungeon Level
* Size: 3 x 3
* Type: Dark Cave (Basic Dungeon)

OR

A chamber that glitters like a thousand stars in the torchlight. (Quartz Chamber)
* To the NORTH is the entrance to the dungeon level.
* To the SOUTH is an Open Doorway to another chamber.
* To the EAST is a Locked Door to another chamber.
* To the WEST is a One-Way Door from another chamber.
* There is a Goblin to fight.
* There is a Short Sword to pick up.

### Viewing a Dungeon Level

Each room MUST be displayed as an 11x5 square of characters using the '-' (hyphen) character for the North/South edges, and the character '|' (pipe) for the East/West edges, and the character '+' (plus) at the corners.

![Room](https://res.cloudinary.com/ngochieua2/image/upload/v1621419309/github/room_bqph8u.png)

Other components will have different shape, include in:
* Dungeon level Entrance/In: I (capital 'i')
* Dungeon level Exit/Out: O (capital 'o')
* Doorways passable in the appropriate direction (North, South, East, West, respectively): ^ (hat), v (lowercase 'v'), > (right-angle bracket), < (left-angle bracket)
* Locked Door: @ (at symbol)
* Blocked Doorway: X (capital 'x')
* Monster: M (capital 'm')
* "Boss" Monster (the monster in the room with the exit): M* (capital 'm' followed by asterisk)
* Loot item: L (capital 'l')
* Walls (all types): - (hyphen) or | (pipe) for North/South and East/West directions, respectively

### Generating a Dungeon Level Randomly:

Before creating a Dungeon randomly, user must enter some information like: name, type (basic or magical) and size (width and height)(must be in the range 1-4)

Some rule when generating randomly
* The entrance (In doorway) to the random dungeon level MUST be in one of the rooms of the first row.
* The exit (Out doorway) from the random dungeon level MUST be in one of the rooms of the last row.
* The entrance and the exit may be added to any edge (choose one at random) that cannot be connected to another room.
* Doorways MUST be added to each room randomly according to the following rules:
  * Each non-corner room MUST have at least two doorways (including the entrance and exit): this helps reduce the chances of degenerate dungeon levels that do not have a path from beginning to end.
  * Each corner room MUST have at least one doorway (excluding the entrance and exit): this prevents corner rooms from almost always being connected to both neighbouring rooms.
  * There is a 40% chance that an individual doorway is traversable, 30% chance that it is locked, and 30% chance that it is impassable.
* Rooms may contains Monsters and/or Items under the following conditions:
  * There is a 25% chance that a room will contain a Monster.
  * There is a 35% chance that a room will contain an Item: 65% chance that the Item is a Consumable and a 35% chance that it is a Weapon.
  * The room with the exit MUST ALWAYS contain a Monster (that is a 'boss') and an Item.
  * The room with the entrance MUST NOT have a Monster NOR an Item; except if the room also contains the exit.

## Component Description:

### Rooms, Walls, Doors 

Each room has 4 egdes in 4 directions: North, South, East, West. Each egde can be wall or door.
Depending Dungeon type (basic or magic), wall can be rock wall or magic wall. 
There are 4 types of doors: OpenDoorway, OneWayDoor, BlockedDoorway and LockedDoor

Each wall or door is a object, which store many information like isPassage(), connect(), displayCharacter()...

### Items & Creatures

#### Items

There are 2 types of items: Weapons and Consumables 

The following are the names of the weapons:
* Boomerang
* Short Sword
* Battle Axe
* Wizard's Staff
* Magic Wand

The consumable items include: 
* Health Potion
* Molotov Cocktail
* Smoke Bomb
* Resistance Potion

#### Creatures

There can be at most one monster per room and a monster never leaves the room in which it is created.

Depending Dungeon type (basic or magic), monster will be created differently

There are several monster types that may be chosen randomly to populate the dungeon level, their names are:
* Goblin
* Werewolf
* Evil Wizard
* Dragon

###  A Dungeon Level

It combines all components and create a complete Dungeon Level
