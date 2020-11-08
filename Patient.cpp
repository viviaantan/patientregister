/* BME506 - 02: Lab 5
 * Author: Vivian Tan (500819934)
 * Due: November 8, 2020
 */
// Queue of patients
#include "Patient.h"
using namespace std;

Patient::Patient (string name, int healthcard, int cdil, string condition) {
    this-> name = name; //define name as part of patient struct
    this-> healthcard = healthcard; //define healthcard as part of patient struct
    this -> cdil = cdil;
    this-> condition = condition;
}

Patient::~Patient(){
}

const string& Patient::getName(){ //function prototype
    return name;
}

const int Patient::getCard() { //function prototype
    return healthcard;
}

string Patient::getCond() { //function prototype
    return condition;
}

const int Patient::getDil() { //function prototype
    return cdil; 
}
