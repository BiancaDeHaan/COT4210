#include "Header.h"

void TextAdventure::loadEvelyn() {
    //This is a file dedicated to creating the character of Toby and adding him to the charactersList

    //Other names for Tobi
    vector<string> evelynAliases = { "garcia", "evelyn", "evelyn garcia", "Eve", "maid", "mrs. garcia", "the maid" };
    Character evelynGarcia(evelynAliases, "Evelyn Garcia");

    //Default response
    evelynGarcia.setDefaultResponse("Hang on, what’d you say ? I didn’t understand you.");
    evelynGarcia.setIntroduction("You've probably never heard of me, but I'm Evelyn Garcia. I am- was- a maid.");
    evelynGarcia.setArrestResponse("It must have been the maid, right?  It’s always the maid.  \n"
        "She was probably up to no good, you know how maids are.  Dastardly things.  She was quitting!\n"
        "Probably her guilty conscience from all the poisoning.\n\n"
        "Not even close!\n"
        "You got the wrong guy!");
    //Adding all of the different variants of questions
    fstream newfile;
    vector<string> questionTokens;
    string answer = "";
    question_t question;

    newfile.open("evelyn.txt", ios::in);
    if (newfile.is_open()) {
        string fileInput = "";
        while (getline(newfile, fileInput)) {

            //parse the line 
            string word = "";
            vector<string> questionTokens;
            for (auto x : fileInput)
            {
                if (x == ' ')
                {
                    questionTokens.push_back(word);
                    word = "";
                }
                else {
                    word = word + x;
                }
            }
            //Get the last word
            questionTokens.push_back(word);

            //next line is the answer
            getline(newfile, fileInput);
            answer = fileInput;

            question.tokens = questionTokens;
            question.answer = answer;
            evelynGarcia.addResponse(question);

            //this is for visually to separate tokens/answers in the file
            getline(newfile, fileInput); //should be a blank space, ignore

        }
        newfile.close(); //close the file object.
    }
    //only evelyn and tobi have added responses when the watch is discovered
    newfile.open("evelynwatch.txt", ios::in);
    if (newfile.is_open()) {
        string fileInput = "";
        while (getline(newfile, fileInput)) {

            //parse the line 
            string word = "";
            vector<string> questionTokens;
            for (auto x : fileInput)
            {
                if (x == ' ')
                {
                    questionTokens.push_back(word);
                    word = "";
                }
                else {
                    word = word + x;
                }
            }
            //Get the last word
            questionTokens.push_back(word);

            //next line is the answer
            getline(newfile, fileInput);
            answer = fileInput;

            question.tokens = questionTokens;
            question.answer = answer;
            evelynGarcia.addWatchResponse(question);

            //this is for visually to separate tokens/answers in the file
            getline(newfile, fileInput); //should be a blank space, ignore

        }
        newfile.close(); //close the file object.
    }

    addCharacter(evelynGarcia);
}