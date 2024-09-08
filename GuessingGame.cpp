// Online C++ compiler to run C++ program online
#include <iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
// this is the operation of gussing game....
void GuessOperation(){
     srand(time(0));
    int RandumNumber=rand()%100+1;// its help the select random number for gussing...
    int guess;
    while(true){
        cout << "Gusse the NUmber under(1-100)->" ;
        cin >> guess;
        if(cin.fail()){
             cout << "Invailed!try Again:" << endl;// is user enter non-numerical value..than handle...
            cin.clear();
            cin.ignore();
            continue;
        }
        if(guess > RandumNumber){// if user selcect high value..
            cout << "guess to high.Try again" << endl;
        }
         else if(guess < RandumNumber){//if user select low value..
            cout << "guess to low.Try again" << endl;
        }
         else{//if user select correct value...
            cout << "Congratulation!you are Correct Gussing" << endl;
            break;
        }
    }
    
}
int main() {
    cout << "\t\t <-----Let's Play a Guessing Game---->" << endl;
    cout << endl;
      GuessOperation();
    while(true){
   string PlayAgain;
    cout << endl;
    cout << "IF YOU WANT PLAY AGAIN...?(YES/NO)" << endl;// if user want paly again...
    cin >> PlayAgain;
    
    if(PlayAgain=="yes"||PlayAgain=="YES"){
        GuessOperation();
    }
    else{
        cout << "Thank You! " << endl;
        break;
    }
    }
    return 0;
}