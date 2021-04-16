#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <istream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

//This represents being asked a question
//Given the tokens that would trigger the response and the answer
typedef struct question {
    vector<string> tokens;
    string answer;
} question_t;

//Class of a character
//Plan to make one per person, so 4 total objects/instances
class Character {
private:
    vector<string> aliases; //contains all the different names they can be called, maybe first, last, first + last
    string introduction;
    vector< question_t> responses;
    string defaultResponse;
    string name;
    bool isQuestion(question_t question, vector<string> tokens);
    string arrestResponse;


public:
    void setIntroduction(string introduction) { this->introduction = introduction; }
    string getIntroduction() { return introduction; }
    void setArrestResponse(string response) { arrestResponse = response; }
    string getArrestResponse() { return arrestResponse; }
    Character() {}
    Character(vector<string> aliases, string name) {
        this->aliases = aliases;
        this->name = name;
    }
    string askQuestion(vector<string> question);
    void addResponse(question_t question) { responses.push_back(question); }
    void setDefaultResponse(string str) { defaultResponse = str; }
    vector<string> getAliases() { return aliases; }
    string getName() {
        return name;
    }

};

class Item {
public:
    string getName() { return name; }
    string getDescription() { return description; }
    bool getToAdd() { return add; }
    Item(string name, string description, bool toAdd) {
        this->name = name;
        this->description = description;
        this->add = toAdd;
    }
private:
    string name;
    string description;
    bool add;

};

//Class of the text adventure
//handles transitions from character to character 
//overarching class
class TextAdventure {
private:
    vector<Character> charactersInGame;
    vector<Item> itemsInGame;
    vector<Item> itemsDiscovered;
public:
    void addDiscoveredItem(Item item) {
        itemsDiscovered.push_back(item);
    }
    void loadToby();
    void loadEvelyn();
    void loadJames();
    void loadAlex();
    void loadItems();
    void addCharacter(Character character) { charactersInGame.push_back(character); }
    Item* findItem(string name);
    Character* findCharacter(string name);
    TextAdventure() {}
    vector<Item> getDiscoveredItems() {
        return itemsDiscovered;
    }
};
