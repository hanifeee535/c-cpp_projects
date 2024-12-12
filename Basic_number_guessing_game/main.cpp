/*
    Authure: Soyabbir Abu Hanif
    Master's in Embedded  Systems
    Tampere University, Finland
    mdsoyabbir.abuhanif@tuni.fi
*/

#include <iostream>
using namespace std;

int main (){
    int num, random_num, tries = 0;
    cout<< "#################__Random_Number_Guessing_Game__#################" <<endl;
    random_num = (rand() %100+1);
    cout << "You have to guess a number between 1 to 100 "<<endl;

    do {
        cout << "Enter your number: " <<endl;
        cin >> num;
        tries ++;
        if (num> random_num)
        {
            cout <<"Your guess is too high"<<endl;
        }
        else if (num<random_num){
            cout << "Your guess is too low" <<endl;
        }
        else{
            cout << "Congratulations!! You guessed the right number!! " <<endl;
            cout << "Total attempt: " << tries << endl;
        }

    } while(num != random_num);
    cout<< "#################__Random_Number_Guessing_Game__#################" <<endl;
    return 0;
}
