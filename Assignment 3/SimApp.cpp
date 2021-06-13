/*
 * SimulationApp.cpp
 *
 * Description: Event simulator
 * Author: Aditya Rajvanshi
 * Created: 26/02/2019
 *
 */
#include <iostream>
#include "Queue.h"
#include "PriorityQueue.h"
#include "Event.h"

using namespace std;

#include <sstream>
#include <iomanip>

int sum = 0;

void processArrival(Event& arrivalEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, int & currentTime, bool & tellerAvailable){
    cout << "Processing an arrival event at time:" << setw(5)<< right << currentTime << endl;	/*Creating white space of 5 and printing currentTime to the right of the space*/
    eventPriorityQueue.dequeue();
    int departureTime;
    if (bankLine.isEmpty() && tellerAvailable){
        departureTime = currentTime + arrivalEvent.getLen();
        Event departureEvent = Event(departureTime);
        eventPriorityQueue.enqueue(departureEvent);
        tellerAvailable = false;
    } else {
        bankLine.enqueue(arrivalEvent);
    }
}

void processDeparture(Event& departureEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, int & currentTime, bool & tellerAvailable){
    cout << "Processing a departure event at time:" << setw(4) << right << currentTime << endl;  /*Creating white space of 4 and printing currentTime to the right of the space*/
    eventPriorityQueue.dequeue();

    int departureTime;

    if (!bankLine.isEmpty()){

        try {
            Event customer = bankLine.peek();
            sum = sum + currentTime - customer.getTime();
            bankLine.dequeue();
            departureTime = currentTime + customer.getLen();
            Event newDepartureEvent = Event(departureTime);
            eventPriorityQueue.enqueue(newDepartureEvent);
        } catch (EmptyDataCollectionException& exception){
            cout << exception.what() << endl;
        }

    } else {
        tellerAvailable = true;
    }
}

int main(int argc, char* argv[]){

    cout << "Simulation Begins" << endl;
    int currentTime = 0;
    Queue<Event> bankLine = Queue<Event>();
    PriorityQueue<Event> eventPriorityQueue = PriorityQueue<Event>();

    bool tellerAvailable = true;

    double customerCount = 0.0;

    string aLine = "";
    int length = 0;
    int time = 0;
    Event streamEvent;

    while(getline(cin >> ws, aLine)) {   // while there is data to be inputted
        stringstream ss(aLine);
        ss >> time >> length;
        streamEvent =  Event();
        streamEvent.setLen(length);
        streamEvent.setTime(time);

        if (!eventPriorityQueue.enqueue(streamEvent)){
            return 1;
        }
    }
    customerCount = eventPriorityQueue.getElementCount();

    // Event Loop
    while (!eventPriorityQueue.isEmpty()) {
        try {
            Event newEvent = eventPriorityQueue.peek();
            currentTime = newEvent.getTime();

            if (newEvent.getType() == Event::ARRIVAL){
                processArrival(newEvent, eventPriorityQueue, bankLine, currentTime, tellerAvailable);
            } else {
                processDeparture(newEvent, eventPriorityQueue, bankLine, currentTime, tellerAvailable);
            }
        } catch (EmptyDataCollectionException & exception){
            cout << exception.what() << endl;
        }
    }

    // Print statistics
    cout << "Simulation Ends" << endl;
    cout << endl;
    cout << "Final Statistics: " << endl;
    cout << "    Total number of people processed:  " << customerCount << endl;
    cout << "    Average amount of time spent waiting: " << (float)sum/(float)customerCount << endl;
    return 0;
}
