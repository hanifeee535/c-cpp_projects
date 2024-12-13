/*
    Author: Soyabbir Abu Hanif
    Master's in Embedded  Systems
    Tampere University, Finland
    mdsoyabbir.abuhanif@tuni.fi
*/

#include <iostream>
#include <random>
using namespace std;

int main (){
    int num, random_num, tries = 0;
    //generating the random number:
    random_device rd; // Generate a random seed from the system
    default_random_engine gen (rd());  // Initialize the random engine with the seed
    uniform_int_distribution <int> distr(1,100); // Define a uniform distribution in the range [1, 100]
    random_num = distr (gen); // Generate a random number within the specified range

    cout<< "#################__Random_Number_Guessing_Game__#################" <<endl;    
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
