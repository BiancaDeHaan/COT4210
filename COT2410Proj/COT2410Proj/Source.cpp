#include "Header.h"

const string introduction = "(There was a party at Fairsley manor last night.  \nThe owner of a large pharmaceutical company, Ben Fairsley, was found dead this morning by his wife.  \nHe’d been poisoned."
"Investigators at the scene found that based on the type of poison used, \nthe time of the poisoning could only have been last night, during the party.\n "
"Mrs. Fairsley was called into work last night at the start of the party to perform emergency surgery.\nShe was in the operating room all night, with cameras on herand fellow doctors surrounding her at all hours to confirm her alibi.\n"
"The manor itself, normally seen in pristine condition, is in shambles.\nEverything from"
" the party was left exactly where it was when everyone leftand the host went to sleep.\n"
"Your job is to figure out who, among the suspects in this room, committed this crime.\n"
"Good luck!\n";
const string description = "There are four suspects in the room; Evelyn Garcia, Tobi Park, Alex Hughes, and James Sinclair. \n";
const string instructions = "\nUse question words to begin talking to the suspects, for example, ask Alex. \n"
"Afterwards, when talking to a suspect, you can ask them questions, such as where they were at the time of the murder.\n"
"You can also inspect items around the room.\n";
vector<string> questionWords = { "talk to", "talk", "ask", "question", "interrogate" };
vector<string> examineWords = { "examine", "look at", "look", "inspect" };
vector<string> accuseWords = { "accuse", "arrest" };


//Implemented methods

//checks to see if this question is in their questions, if not default response is returned
string Character::askQuestion(vector<string> question) {
    //loops through all responses
    for (int i = 0; i < responses.size(); i++) {
        //iterates through all the responses/questions
        if (isQuestion(responses[i], question)) {
            string response = responses[i].answer;
            return response;
        }
    }

    return defaultResponse;
}

//helper function
bool Character::isQuestion(question_t question, vector<string> tokens) {
    vector<string> questionTokens = question.tokens;
    //logic: tokens has to contain all questionTokens
    for (int n = 0; n < questionTokens.size(); n++) {
        bool flag = false;

        //iterate through tokens/ input string
        for (int i = 0; i < tokens.size(); i++) {
            //if found, return true for this round
            if (tokens[i].compare(questionTokens[n]) == 0)
                flag = true;
        }
        //if not found, return default response
        if (!flag) {
            return false;
        }
    }
    return true;
}

Character* TextAdventure::findCharacter(string name) {
    //Given a string for a name, return who is being talked to, or null if no one is found
    for (int i = 0; i < charactersInGame.size(); i++) {
        vector<string> aliases = charactersInGame[i].getAliases();
        //loops through the aliases for each character, if it matches, return that character
        for (int n = 0; n < aliases.size(); n++) {
            if (name.compare(aliases[n]) == 0)
                return &charactersInGame[i];
        }
    }
    return nullptr;
}


//Function to turn a string into tokens
vector<string> tokenizeString(string str) {
    string word = "";
    vector<string> vec;
    for (auto x : str)
    {
        if (x == ' ')
        {
            vec.push_back(word);
            word = "";
        }
        else {
            //make word lower case for easier machine reading
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            word = word + x;
        }
    }
    //Get the last word
    vec.push_back(word);
    return vec;
}

//check if a string has a substring
bool contains(string str, string keyword) {
    if (str.find(keyword) != std::string::npos) {
        return true;
    }
    else {
        return false;
    }
}

//check if a vector of strings contains a string
bool contains(vector<string> tokens, string token) {
    transform(token.begin(), token.end(), token.begin(), ::tolower);
    for (int i = 0; i < tokens.size(); i++) {
        //change everything to lower case temporarily, 
        //this is so that the user's input will validate even if it's like some weird capitalization errors
        transform(tokens[i].begin(), tokens[i].end(), tokens[i].begin(), ::tolower);
        if (tokens[i].compare(token) == 0) {
            //found a match, return true
            return true;
        }
    }
    //end loop has ended without finding a match, return false
    return false;
}

bool talkTo(vector<string> tokens) {
    //Is the statement/user input going into "talking to x" instance
    for (int i = 0; i < questionWords.size(); i++) {
        if (contains(tokens, questionWords[i]))
            return true;
    }
    //NOTE: does not account for "talk to" command but sort of does, registers as "talk"
    return false;
}

bool examine(vector<string> tokens) {
    //logic for determining if the command was to examine an item
    for (int i = 0; i < questionWords.size(); i++) {
        if (contains(tokens, questionWords[i]))
            return true;
    }
    return false;
}


bool accuse(vector<string> tokens) {
    //logic for determining if the command was to accuse someone
    for (int i = 0; i < questionWords.size(); i++) {
        if (contains(tokens, accuseWords[i]))
            return true;
    }
    return false;
}

int main() {
    cout << introduction << endl;
    cout << description << endl;



    Character alexHuges;
    Character jamesSinclair;
    Character evelynGarcia;

    TextAdventure textAdventure = TextAdventure();
    textAdventure.loadToby();
    textAdventure.loadAlex();
    textAdventure.loadEvelyn();
    textAdventure.loadJames();

    //TODO
    //Add examine items
    //Add accuse functionality
    //Add more exit/return/go back commands other than exit
    //Input loop
    string userInput = "";
    while (userInput.compare("exit") != 0) {
        cout << instructions << endl;
        getline(cin, userInput);

        vector<string> userTokens = tokenizeString(userInput);

        //"talk to x"
        if (talkTo(userTokens)) {

            //find out who they are talking to, and allows them to talk to that character
            //command should be in format "talk to x" or "ask x", so x, character name, should be 2nd/3rd? assumption being made
            Character* ch;
            if (userTokens.size() > 1)
                ch = textAdventure.findCharacter(userTokens[1]);
            else
                ch = nullptr;

            Character* ch2;
            if (userTokens.size() > 2)
                ch2 = textAdventure.findCharacter(userTokens[2]);
            else
                ch2 = nullptr;

            Character talkingTo;
            //Check to see if anyone viable was found
            if (ch == nullptr && ch2 == nullptr) {
                //did not find a valid person to talk to
                cout << "Who are you trying to talk to? I didn't get that clearly enough, inspector." << endl;
                continue; //break out of this loop
            }
            else {
                //additional logic
                if (ch != nullptr) {
                    cout << "temp";
                    talkingTo = *ch;
                }
                else {
                    talkingTo = *ch2;
                }
            }

            string secondUserInput = "";
            cout << endl << talkingTo.getIntroduction() << endl;

            while (secondUserInput.compare("exit") != 0) {
                cout << "You are currently talking to " << talkingTo.getName() << endl;
                cout << "You can ask them a question, or type exit to leave this conversation" << endl << endl;

                getline(cin, secondUserInput);

                if (secondUserInput.compare("exit") == 0)
                    break;

                //remmove ?
                secondUserInput.erase(remove(secondUserInput.begin(), secondUserInput.end(), '?'), secondUserInput.end());


                vector<string> secondUserTokens = tokenizeString(secondUserInput);
                cout << talkingTo.askQuestion(secondUserTokens) << endl;

                cout << endl;

            }

        }
        else if (examine(userTokens)) {
            cout << "You are inspecting something" << endl;
        }
        else if (accuse(userTokens)) {
            Character* suspect;
            if(userTokens.size() >= 1)
                suspect = textAdventure.findCharacter(userTokens[1]);
            if (suspect == nullptr) {
                cout << "Who are you trying to accuse? I didn't catch that, inspector." << endl;
                continue;
            }

            cout << suspect->getArrestResponse() << endl;
            break;


        }
        else {
            cout << "Inspector, what are you trying to do?" << endl;
            cout << "Maybe it would be helpful to format what you are trying to do, such as \"talk to x\" or \"examine x\"." << endl << endl;
        }


        //accuse 



    }

    //TODO, add "are you sure you want to exit without accusing/failure test

}