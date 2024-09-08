 #include <iostream>
#include<string>
using namespace std; 
 
 int score_board(int Player1,int Player2){
  cout << " \t" << "Player 1" << "|" << " " << "Player 2" << endl;
  cout << " \t" <<"   "<<Player1 <<"    "<< "|" << "   " << Player2<<"" <<endl;
  cout << " \t" << "        " << "|" << " " << "        " << endl;
  

return 0;   
 }
 
void board(char arr[3][3]){
   // making tic-tac-toe board stacture....
    cout << " " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << " " << endl;
    cout << "----------" << endl;
    cout << " " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << " " << endl;
    cout << "----------" << endl;
    cout << " " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << " " << endl;
    
}
void PlayGame(char arr[3][3]){
  string Player_name1;
    string Player_name2;
    int Player_score1=0;
    int Player_score2=0;
    cout << "Player 1 : enter your name:";
    getline(cin,Player_name1);
    cout << "Player 2 : enter your name:";
    getline(cin,Player_name2);
    int turn=0;
    char player;
    int choice;
    while(true){
        board(arr);
        // turn=0 mean enter the key by Player1 otherwise enter the key by Player2 .....
        // if player 1 (in the case of starting match) want to change our turn than the sclect=0...
        if(turn%2==0){
             player='X';
               cout << "Player:" << Player_name1<<":"<< player << " Enter number(1-9)" << endl; 
        }
        else{
             player='O';
              cout << "Player:" << Player_name2<<":"<< player << " Enter number(1-9)" << endl; 
        }
        
        cin >> choice;
        // this indicate the address of number choice by player...
        //example if player choice 5 than The indicate arr[1][1] position....using this formula..
        int row=(choice-1)/3;
        int col=(choice-1)%3;
        // if player select a number(1-9) is not print 'X' and '0' than  print player sign who's selected the number.. 
        if(arr[row][col]!='X'&&arr[row][col]!='O'){
            arr[row][col]=player;
            turn++;
        }
        // Otherwise print invalid! and ask again choice your number.... 
        else{
            cout << "Invalid choice.Try Again" << endl;
        }
        // this condition indicate what's the situation player can Win...
        if((arr[0][0]==arr[0][1]&&arr[0][1]==arr[0][2])||
           (arr[1][0]==arr[1][1]&&arr[1][1]==arr[1][2])||
           (arr[2][0]==arr[2][1]&&arr[2][1]==arr[2][2])||
           (arr[0][0]==arr[1][0]&&arr[1][0]==arr[2][0])||
           (arr[0][1]==arr[1][1]&&arr[1][1]==arr[2][1])||
           (arr[0][2]==arr[1][2]&&arr[1][2]==arr[2][2])||
           (arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2])||
           (arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0])){
            board(arr);
            cout << "Player:" << player << " is WIN!" << endl;
            if(player=='X'){
            Player_score1++;
            }
            else{
            Player_score2++;
            }
            score_board(Player_score1,Player_score2);
            break;
        }
        // if Both player selecteed all choice number(1-9) than its mean Match is Draw... 
        if(turn==9){
            cout << "Match is Draw" << endl;
            score_board(Player_score1,Player_score2);
            break;
        }
    }
    
    
}
int main() {
    cout << "\t\t Tic-Tac-Toe" << endl;
    char arr[3][3]={'1','2','3','4','5','6','7','8','9'};
   PlayGame(arr);
   while(true){
      string PlayAgain;
    cout << "Would you Play again..?(yes/no)" << endl;
            cin >> PlayAgain;
            cin.ignore();
            // reset the game board paly again..
            if(PlayAgain=="Yes"||PlayAgain=="yes"){
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        arr[i][j]='1'+ i*3 +j;
                    }
                }
                PlayGame(arr);
            }
            else{
                break;
            }
  }

    return 0;
}
