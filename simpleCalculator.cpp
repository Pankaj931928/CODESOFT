#include<iostream>
#include<math.h>
using namespace std;

// create Function to perform calculation process....
float SimpleCalculater(float num1,float num2,char operation){
switch(operation){
    case '+' : return num1+num2;
                break;
    case '-' : return num1-num2;
                break;
    case '*' : return num1*num2;
                break;
    case '/' : if(num2==0){
                cout << "Error: Division by zero is undefined!" ;// when denominator is zero...
                return NAN;
                      }
                      else{
                return num1/num2;
                break;  
                      }
    case '^' : return pow(num1,num2);   
                break;
    default : cout << "Erore !Invalid operation" ; 
              return NAN;
}

    

return 0;
}

int main(){
    float num1,num2;
    cout << "\t \t CALCUATOR" << endl;
     cout << "Welcome ! if You press Q to exit" << endl; 
    while(true){
    cout << "Enter First Element:";
    while(!(cin>>num1)){ // haddle if user sellect non-numerical input...
    cin.clear();
    cin.ignore(10000,'\n');
    cout << "invalid input.Enter First element:" << endl;
    }

    cout << "Enter seconnd Element:";
    while(!(cin>>num2)){// haddle if user sellect non-numerical input...
    cin.clear();
    cin.ignore(10000,'\n');
    cout << "invalid input.Enter second element:" << endl;
    }
    
    char operation;
    cout <<"Enter Arthimatic Operation Which you want(+,-,*,/,^):";
    cin >> operation;
      if(operation=='Q'){// if user want to exit...
          cout << "Thankyou for Coming!" << endl;
          break;
      }
      while(operation!='+' &&operation!='-' &&operation!='*'&&operation!='/'&&operation!='^'){// handle this situation when user sellect unncessary operation.. 
      cout << "invalid operation.Please Enter Arthimatic Operation Which you want(+,-,*,/,^):";
      cin >> operation;
      }
    cout << "result:" << "("<<num1 <<operation << num2<< ")" <<"="<< SimpleCalculater(num1,num2,operation) << endl;
    }
    return 0;
}
