#include <iostream>

using namespace std;

int main()
{
    string questions [] = { "1. Who invented facebook?",
                            "2. Which year facebook was invented?",
                            "3.What is the mother company of facebook?",
                            "4.Where is the headquarter of facebook?"
                            };
    string options [][4] = {
                            { "A. Mark Zuckerberg", "B. Barak Obama", "C. Elon Mask", "D. Donald Trump" },
                            {"A. 1997", "B. 1999", "C. 2004", "D.2003"},
                            {"A. Meta", "B. Google", "C.Spacex", "D. Yaho"},
                            {"A. USA", "B. France", "C. England", "D.India"}
                            };
    char answerKeys[] = {'A', 'C', 'A', 'A'};

    //size calculation of arrays:
    int questionSize = sizeof (questions)/sizeof (string);
    int option_row_size = sizeof(options)/sizeof (options[0]);

    char user_answer;
    int score = 0;

    for (int i = 0; i<questionSize; i++){
        cout << "################################"<<endl;
        cout<< questions[i]<<endl;
        cout << "################################"<<endl;
        for (int j = 0; j<option_row_size; j++){
            cout << options[i][j] <<endl;
            }
        cin>>user_answer;
        user_answer = toupper(user_answer);
        if (user_answer == answerKeys[i]){
            cout<< "Correct answer"<<endl;
            score += 1;
        }
        else {
            cout<< "correct answer is " <<answerKeys[i] <<endl;
        }
    }
    cout << "Your score is: " <<score <<endl;
    return 0;
}
