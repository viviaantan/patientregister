/* BME506 - 02: Lab 5
 * Author: Vivian Tan (500819934)
 * Due: November 8, 2020
 */

#include "OTPRegister.h"
#include <climits>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;
using std::setw;

patQueue::patQueue(){
}

patQueue::~patQueue(){
    int qSize = q.size();
    for (int i=0; i < qSize; ++i){
        delete q[i];
        q[i] = 0;
    }
}

void patQueue::size(){
    cout << q.size();
}
bool patQueue::validate(int healthcard){ 
    for (int i = 0; i < q.size() ; ++i){ //loops through all patients within queue
        if (q[i] -> getCard() == healthcard){ //validating patient record
            break;
            return true;
        }
    }
}
void patQueue::enroll(string name, int healthcard, int cdil, string condition){ //Register Patients
    cdil = 0;
    condition = "UNKNOWN";
        Patient * p = new Patient(name, healthcard, cdil, condition);
        q.push_back(p); //push to bottom of list - first registered first listed
        cout<< "... [Registering]" << endl;
}

int patQueue::examine(string name, int healthcard, int dil){ //Examine Cervix Dilation
    if (q.empty()) return 0; //if queue is empty, return nothing
    int n; 
    for (int i = 0; i < q.size() ; ++i){ //loops through all patients within queue
        Patient * p = q[i];
        if (p -> getName() == name && p -> getCard() == healthcard){ //validating patient record
            n++;
            cout << endl << "Enter Cervix Dilation: ";
            cin >> dil;
            if (dil > 3){  //Admit if cervix dilation is greater than 3 mm (4 mm +) 
                cout << "...[Admitting]" <<endl;
                cout << p->getName() << " " << p->getCard() << " " << dil << " ADMIT" << endl;
                delete p; p = 0; 
                q.pop_back();
            }
            else if (dil < 4){ //Keep if cervix dilation is less than 4 mm (3 mm -)
                cout << "... [Going back to queue]"<<endl;
                string condition = "LABOUR";
                q.push_back(p);//push record back to queue
                q.pop_back(); 
                q[i] = new Patient(name, healthcard, dil, condition);
                break;
            }   
        }
    }
    if (n = 0){
            cout << "Patient not registered" <<endl;
        }
    return dil;
}

void patQueue::display(){ //display patient records
    cout<<"[Display Patients]"<<endl;
    int qSize = q.size();
    for (int i=0; i<qSize; ++i) {
        if (q[i] !=0){
        cout << setw(10) << q[i] -> getName() << setw(3)<<" "<<setw(3)<< q[i] -> getCard() << setw(3)
                <<" " << q[i] -> getDil() << setw(3) << " " << setw(7) << q[i] -> getCond() << endl;
        }
    }
}
