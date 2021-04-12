#include "Header.h"

void TextAdventure::loadAlex() {
    //This is a file dedicated to creating the character of Toby and adding him to the charactersList

    //Other names for Tobi
    vector<string> alexAliases = { "alex", "hughes", "alex hughes" };
    Character alexHughes(alexAliases, "Alex Hughes");

    //Default response
    alexHughes.setDefaultResponse("I’m sorry?  You’re gonna have to speak up, friend.  I didn’t understand what you said there.");
    alexHughes.setIntroduction("Hello, inspector.  A pleasure to meet you, I am Alex Hughes, an old friend of the owner of this manor.  And you are?");
    alexHughes.setArrestResponse("Surely, it the neighbor driven mad by jealousy?\n"
        "Tired of playing second fiddle all his life, he poisoned Ben’s cake and made sure he ate it by initiating a competition on purpose!\n\n"
        "Incorrect!This man is a gentle giantand wouldn’t hurt a fly, how dare you!\n"
        "You got the wrong guy!\n");
    //Adding all of the different variants of questions
    fstream newfile;
    vector<string> questionTokens;
    string answer = "";
    question_t question;

    newfile.open("alex.txt", ios::in);
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
            alexHughes.addResponse(question);

            //this is for visually to separate tokens/answers in the file
            getline(newfile, fileInput); //should be a blank space, ignore

        }
        newfile.close(); //close the file object.
    }


    addCharacter(alexHughes);
}