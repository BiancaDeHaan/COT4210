#include "Header.h"

void TextAdventure::loadJames() {
    //This is a file dedicated to creating the character of Toby and adding him to the charactersList

    //Other names for Tobi
    vector<string> jamesAliases = { "james", "sinclair", "james sinclair", "james" };
    Character jamesSinclair(jamesAliases, "James Sinclair");

    //Default response
    jamesSinclair.setDefaultResponse("You’re going to have to repeat that for me, darling.  I didn’t catch a word of it.");
    jamesSinclair.setIntroduction("You're speaking to James Sinclair, remember the name.");
    jamesSinclair.setArrestResponse("Blackmail!  Intrigue!  Dialogue!  I’m not reading all that.  Maybe you should have!\n"
        "You got the wrong guy, dear!");
    //Adding all of the different variants of questions
    fstream newfile;
    vector<string> questionTokens;
    string answer = "";
    question_t question;

    newfile.open("james.txt", ios::in);
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
            jamesSinclair.addResponse(question);

            //this is for visually to separate tokens/answers in the file
            getline(newfile, fileInput); //should be a blank space, ignore

        }
        newfile.close(); //close the file object.
    }


    addCharacter(jamesSinclair);
}