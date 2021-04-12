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
    string name;
    string description;
private:
};

//Class of the text adventure
//handles transitions from character to character 
//overarching class
class TextAdventure {
private:
    vector<Character> charactersInGame;
public:
    void loadToby();
    void loadEvelyn();
    void loadJames();
    void loadAlex();
    void addCharacter(Character character) { charactersInGame.push_back(character); }
    Character* findCharacter(string name);
    TextAdventure() {}
};

class Item {

};