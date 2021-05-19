# DungeonBuilder

Dungeon builder is a C++ software and developed on Qt in order to create a map level in a Roguelike Dungeon game. 
Each dungeon level will comprise a set of rooms, connected by doors, with the possibility of a random monster and/or loot items (weapons or consumables such as potions). 
The items and monsters will display on some rooms, but they will not be completely game capable.
A text-based menu will allow the user to generate dungeon levels with a small set of parameters and display them to the console.

This project is created according to object-oriented design, some design pattern 
use some C++ features such as: class inheritance and polymorphism, dynamic memory allocation, and smart pointers

## Design Patterns:

* ***Singleton:*** use to make sure only one program (instance ) is created and run at a time
* ***Builder:*** use to build a level from smallest components like doors, walls, mosters, items to larger components like: a room and then a level with a collection of rooms
* ***Prototype:***  use to clone some given monster, so it will optimize code

