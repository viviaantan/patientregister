#include "OTPRegister.h"
#include <climits>
using namespace std;

int main(){
    patQueue patRecQueue;
    string name; //name 
    int healthcard; //healthcard number
    int n = 0; //number of patients
    int cdil; //cervix dilation
    string num; int j;
    string condition;
    while (1){
    cout << "====================================" << endl;
    cout << "There are currently "<< n << " patient(s) in the list" << endl; 
    cout << "Please choose an option:" << endl;
    cout << "1. Register Patient" << endl;
    cout << "2. Examine Patient" << endl;
    cout << "3. Display Patients" << endl;
    cout << "4. Quit" << endl;
    cout << "Option: ";
    cin >> num;
    if ("1"==num){
        cout << "Enter Name: " ;
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        getline(cin, name, '\n');       
        cout << "Enter Health Card Number: " ;
        if (!(cin >> healthcard)){
            std::cin.ignore();
            std::cin.clear();
            cout << "Invalid health card number, please try again" << endl;  
        }
        else {
            bool val = patRecQueue.validate (healthcard);
            if (val == true){
             cout << "Health card number already registered" <<endl;
            }
            else {
            patRecQueue.enroll (name, healthcard, cdil, condition);
            n++; 
            }
        }
    }
    
    else if ("2" == num){
        cout <<"[Examine Patient] " <<endl; 
        cout << "Name: ";
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        getline(cin, name, '\n');
        cout << "Health Card Number: ";
        if (!(cin >> healthcard)){
            std::cin.ignore();
            std::cin.clear();
            cout << "Invalid health card number, please try again" << endl;  
        }
        else{
        int j = patRecQueue.examine(name, healthcard, cdil);
        cout <<j;
        if (j > 3){
            n--;
        }
    }
    }
    else if ("3" == num){ 
        patRecQueue.display();
        cout<<endl;
    }
    else if ("4" == num){
        cout << "Quitting Program..." << endl;
        return 0;
    }
    else{
        cout << "Invalid Option. Please try again."<<endl;
    }     
    }

    return 0;
   
}
