/* BME506 - 02: Lab 5
 * Author: Vivian Tan (500819934)
 * Due: November 8, 2020
 */

#ifndef OTPREGISTER_H_
#define OTPREGISTER_H_

#include <iostream>
#include <deque>
using namespace std;

class Patient {
private:
    string name; // name
    int healthcard; // Health card number
    int cdil; //cervix dilation
    string condition; //condiiton (UNKNOWN, LABOUR, ADMIT)
public: 
    Patient (string, int, int, string); ~Patient();
    const string& getName(); const int getCard(); const int getDil(); string getCond();
};
#endif /* OTPREGISTER_H_ */
