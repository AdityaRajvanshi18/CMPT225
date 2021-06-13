/*
 * Event.h
 *
 * Class Description: Models an arrival or departure event
 * Class Invariant:  Event type must be D(Departure) or A(Arrival).
 * Author: Aditya Rajvanshi
 * Created: 20/02/2019
 *
 */
#include <iostream>
#include "Event.h"

using namespace std;

// Description: Default constructor for event class
Event::Event(){
    this->type = ARRIVAL;
    this->time = 0;
    this->len = 0;
}

// Description: Parametrized constructor for departure event
Event::Event(int aTime){
    this->type = DEPARTURE;
    this->time = aTime;
    this->len = 0;
}

// Description: Parametrized constructor for event class
Event::Event(char aType, int aTime, int aLen){
    this->type = aType;
    this->time = aTime;
    this->len = aLen;
}

// Description: Returns type of event A/D
// Post-Condition: Event object is unchanged
char Event::getType() const {
    return this->type;
}

// Description: Returns time of event
// Post-Condition: Event object is unchanged
int Event::getTime() const {
    return this->time;
}

// Description: Returns length of event
// Post-Condition: Event object is unchanged
int Event::getLen() const {
    return this->len;
}

// Description: Sets type of event, A by default unless D is inputted
// Pre-Condition: Options are A or D chars
// Post-Condition: Type is A or D
void Event::setType(const char aType){
    if (aType != ARRIVAL && aType != DEPARTURE) {
        this->type = ARRIVAL;
    } else {
        this->type = aType;
    }
}

// Description: Sets time of event, or 0 if time is less than zero
// Pre-Condition: time is greater than 0
// Post-Condition: Type is given time or 0
void Event::setTime(const int aTime){
    if (aTime < 0) {
        this->time = 0;
    } else {
        this->time = aTime;
    }
}

// Description: Sets length of event, or 0 if length is less than zero
// Pre-Condition: length is greater than 0
// Post-Condition: length is given length or 0
void Event::setLen(const int aLen){
    if (aLen < 0) {
        this->len = 0;
    } else {
        this->len = aLen;
    }
}

// Description: return a bool based on time and type of event
bool Event::operator<(const Event & p){
    if (getTime() == p.getTime()){
        return getType() < p.getType();
    }
    return getTime() < p.getTime();

}

// Description: prints the event object
ostream &operator<<(ostream& os, const Event& event){
    os << event.getType() << ", " << event.getTime() << ", " << event.getLen() << endl;
    return os;
}
