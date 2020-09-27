#include "room.h"

using core::creatures::AbstractCreature;
using core::items::Item;
using core::dungeon::Room;
using core::dungeon::RoomEdge;

Room::Room()
{
}

Room::Room(int id): _id{id}{
    EdgesVector.assign(4,_roomEdge);
}

Room::~Room(){
    delete _roomEdge;
    for (int i = 0; i < (int)EdgesVector.size(); ++ i){
        delete EdgesVector[i];
    }
    delete _item;
    delete _abstractCreature;
}

std::string Room::description()
{
    return "a room\n";
}


int Room::id(){
    return _id;
}

Item *Room::item()
{
    return _item;
}

void Room::setItem(Item *newItem)
{
    _item = newItem;
}

AbstractCreature *Room::creature()
{
    return _abstractCreature;
}

void Room::setCreature(AbstractCreature *newCreature)
{
    _abstractCreature = newCreature;
}

void Room::setEdge(RoomEdge *edge, Direction direction){
    if(direction == Direction::North){
        if (!edge->isPassage()){
            if (edge->isEntrance()){
                edge->setChar('I');
            }
            else if (edge->isExit()) {
                edge->setChar('O');
            }
            else{
                edge->setChar('-');
            }
        }
        else {
            edge->setChar('^');
        }
        EdgesVector.at(0) = edge;
    }
    else if (direction == Direction::East) {

        if (!edge->isPassage()){
            if (edge->isEntrance()){
                edge->setChar('I');
            }
            else if (edge->isExit()) {
                edge->setChar('O');
            }
            else{
                edge->setChar('|');
            }
        }
        else {
            edge->setChar('>');
        }
        EdgesVector.at(1) = edge;
    }
    else if (direction == Direction::South) {
        if (!edge->isPassage()){
            if (edge->isEntrance()){
                edge->setChar('I');
            }
            else if (edge->isExit()) {
                edge->setChar('O');
            }
            else{
                edge->setChar('-');
            }
        }
        else {
            edge->setChar('v');
        }
        EdgesVector.at(2) = edge;

    }
    else {
        if (!edge->isPassage()){
            if (edge->isEntrance()){
                edge->setChar('I');
            }
            else if (edge->isExit()) {
                edge->setChar('O');
            }
            else{
                edge->setChar('|');
            }
        }
        else {
            edge->setChar('<');
        }
        EdgesVector.at(3) = edge;
    }
}

RoomEdge* Room::edgeAt(Direction direction){
    if(direction == Direction::North){
        return EdgesVector.at(0);
    }
    else if (direction == Direction::East) {
        return  EdgesVector.at(1);
    }
    else if (direction == Direction::South) {
        return EdgesVector.at(2);
    }
    else {
        return EdgesVector.at(3);
    }
}

std::string Room::edgeDescription(Room::Direction direction)
{
    return edgeAt(direction)->description();
}

std::string Room::creatureDescription()
{
    if(_abstractCreature == nullptr){
        return "There is no monster to fight\n";
    }
    else {
        return _abstractCreature->name();
    }
}

std::string Room::itemDescription()
{
    if(_item == nullptr){
        return "There is no Item to pick up\n";
    }
    else {
        return _item->name();
    }
}

std::vector<std::string> Room::display()
{
    std::string row;

    for (int i = 0; i < 5; ++i){
        if (i == 0) //create first row (1)
        {
            for (int j = 0; j < 11; ++j){
                if(j == 0 || j == 10)//the first and last charactor is '+'
                {
                    row.push_back('+');
                }
                else if (j == 5){
                    row.push_back(edgeAt(Room::Direction::North)->displayCharacter());
                }
                else {
                    row.push_back('-');
                }
            }
            roomMap.push_back(row);
            row = "";
        }
        else if (i == 4) //create last row (5)
        {
            for (int j = 0; j < 11; ++j){
                if(j == 0 || j == 10)//the first and last charactor is '+'
                {
                    row.push_back('+');
                }
                else if (j == 5){
                    row.push_back(edgeAt(Room::Direction::South)->displayCharacter());
                }
                else {
                    row.push_back('-');
                }
            }
            roomMap.push_back(row);
            row = "";
        }
        else if (i == 2) //create third row
        {
            for (int j = 0; j < 11; ++j){
                if(j == 0){
                    row.push_back(edgeAt(Room::Direction::West)->displayCharacter());
                }
                else if (j == 10) {
                    row.push_back(edgeAt(Room::Direction::East)->displayCharacter());
                }
                else if (j == 4) {
                    if (_abstractCreature != nullptr){
                        row.push_back(creature()->displayCharacter());
                    }
                    else {
                        row.push_back(' ');
                    }
                }
                else if (j == 5) {
                    if(_abstractCreature != nullptr && hasExit()){
                        row.push_back('*');
                    }
                    else {
                        row.push_back(' ');
                    }

                }
                else if (j == 6) {
                    if (_item != nullptr){
                        row.push_back(item()->displayCharacter());
                    }
                    else {
                        row.push_back(' ');
                    }
                }
                else {
                    row.push_back(' ');
                }
            }
            roomMap.push_back(row);
            row = "";
        }
        else // crreate 2 and 4 rows
        {
            for (int j = 0; j < 11; ++j){
                if(j == 0 || j == 10){
                    row.push_back('|');
                }
                else {
                    row.push_back(' ');
                }
            }
            roomMap.push_back(row);
            row = "";
        }
    }

    return roomMap;
}

int Room::doorwayCount()
{
    doorwayNumber = 0;
    if (edgeAt(Room::Direction::North)->isPassage()){
        doorwayNumber++;
    }
    if (edgeAt(Room::Direction::East)->isPassage()){
        doorwayNumber++;
    }
    if (edgeAt(Room::Direction::South)->isPassage()){
        doorwayNumber++;
    }
    if (edgeAt(Room::Direction::West)->isPassage()){
        doorwayNumber++;
    }

    return doorwayNumber;
}

bool Room::hasEntrance()
{
    if (edgeAt(Room::Direction::North)->isEntrance()){
        return true;
    }
    if (edgeAt(Room::Direction::East)->isEntrance()){
        return true;
    }
    if (edgeAt(Room::Direction::South)->isEntrance()){
        return true;
    }
    if (edgeAt(Room::Direction::West)->isEntrance()){
        return true;
    }
    return false;
}

bool Room::hasExit()
{
    if (edgeAt(Room::Direction::North)->isExit()){
        return true;
    }
    if (edgeAt(Room::Direction::East)->isExit()){
        return true;
    }
    if (edgeAt(Room::Direction::South)->isExit()){
        return true;
    }
    if (edgeAt(Room::Direction::West)->isExit()){
        return true;
    }
    return false;
}






