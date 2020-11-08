/* BME506 - 02: Lab 5
 * Author: Vivian Tan (500819934)
 * Due: November 8, 2020
 */
#ifndef PATIENT_H_
#define PATIENT_H_

#include <iostream>
#include <deque>
#include "Patient.h"
using namespace std;

class patQueue {
private:
    deque<Patient*> q; //define q 
public:
    patQueue(); ~patQueue();
    void size(); bool validate(int); void enroll(string, int, int, string); int examine(string, int, int); void display();
};
#endif /* PATIENT_H_ */
