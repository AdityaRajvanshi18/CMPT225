/*
 * Event.h
 *
 * Class Description: Models an arrival or departure event
 * Class Invariant:  Event type must be D(Departure) or A(Arrival).
 * Author: Aditya Rajvanshi
 * Created: 20/02/2019
 *
 */
#pragma once
#include <string>

using namespace std;

class Event {

private:

    char type; // D/A
    int time;
    int len;

public:

    // Constants
    const static char ARRIVAL = 'A';
    const static char DEPARTURE = 'D';

    // Description: Default constructor for event class
    Event();

    // Description: Parametrized constructor for departure event
    Event(int aTime);

    // Description: Parametrized constructor for event class
    Event(char aType, int aTime, int aLen);

    // Getters and Setters

    // Description: Returns type of event A/D
    // Post-Condition: Event object is unchanged
    char getType() const;

    // Description: Returns time of event
    // Post-Condition: Event object is unchanged
    int getTime() const;

    // Description: Returns length of event
    // Post-Condition: Event object is unchanged
    int getLen() const;

    // Description: Sets type of event, A by default unless D is inputted
    // Pre-Condition: Options are A or D chars
    // Post-Condition: Type is A or D
    void setType(const char aType);

    // Description: Sets time of event, or 0 if time is less than zero
    // Pre-Condition: time is greater than 0
    // Post-Condition: Type is given time or 0
    void setTime(const int aTime);

    // Description: Sets length of event, or 0 if length is less than zero
    // Pre-Condition: length is greater than 0
    // Post-Condition: length is given length or 0
    void setLen(const int aLen);

    // Operators

    // Description: return a bool based on time and type of event
    bool operator<(const Event & p);

    // Description: prints the event object
    friend ostream &operator<<(ostream& os, const Event& event);
};
