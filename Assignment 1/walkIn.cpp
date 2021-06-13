/*
 * walkIn.cpp
 * 
 *
 * Author: Aditya Rajvanshi - 301349754
 * Date: 20/01/2019
 */

#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h"

using namespace std;

//Features: Add, Remove, Edit, Search, Print.
//Add a new patient to the system.
void Add(List& patients){
	string num ="";
	cout << "To add a new patient, please enter a 10-digit care card number below:\n";
	cin >> num;
	cout << "\n";
	
	Patient newpatient = Patient(num);
	bool verify = patients.insert(newpatient);
	if (verify == false){
		cout << "Failed to add new patient! Attempt to search if the patient is already in the system or if care card was entered correctly.\n";
		cout << "----------------\n";
	}
	else{
		cout << "The patient has been added.\n";
		operator<<(cout, newpatient);
		cout << "----------------\n";
	}
}

//Remove a patient from the system.
void Remove(List& patients){
	string num;
	cout << "To remove an existing patient, please enter the 10-digit care card number of the patient.\n";
	cin >> num;
	
	Patient rem = Patient(num);
	bool verify = patients.remove(rem);
	if (verify == false){
		cout << "Failed to remove patient! Attempt to search if patient is still in the system.\n";
		cout << "----------------\n";
	}
	else{
		cout << "The patient has been removed.\n";
		operator<<(cout, rem);
		cout << "----------------\n";
	}
}
//Edit a patient's information.
void Edit(List& patients){
	string num;
	cout << "To edit a existing patient's information, please enter the 10-digit care card number.\n";
	cin >> num;

	Patient toFind = Patient(num);
	Patient * patient = patients.search(toFind);
	if (patient == NULL){
		cout << "The patient was not found. Check if the 10-digit care card was entered correctly or attempt to search if the patient is still in the system.\n";
		cout << "----------------\n";

	}
	else{
		bool compEditing = false;
		while (not compEditing) {
			char editAspect = 0;
			string aspect;
			
			cout << "What would you like to edit?\n";
			cout << "To edit name, enter: n\n";
			cout << "To edit address, enter: a\n";
			cout << "To edit phone number, enter: p\n";
			cout << "To edit email, enter: e\n";
			cout << "To end editing, enter: x\n";
			cout << "\n";
			cin >> editAspect;

			cin.ignore();
			switch (tolower(editAspect)){
				case 'n':
					cout << "Enter a name\n";
					getline(cin, aspect);
					patient->setName(aspect);
					cout << "Name set to: " << aspect << "\n";
					cout << "\n";
					break;

				case 'a':
					cout << "Enter an address\n";
					getline(cin, aspect);
					patient->setAddress(aspect);
					cout << "Address set to: " << aspect << "\n";
					cout << "\n";
					break;
				case 'p':
					cout << "Enter a phone number\n";
					getline(cin, aspect);
					patient->setPhone(aspect);
					cout << "Phone number set to: " << aspect << "\n";
					cout << "\n";
					break;
				case 'e':
					cout << "Enter an email\n";
					getline(cin, aspect);
					patient->setEmail(aspect);
					cout << "Email set to: " << aspect << "\n";
					cout << "\n";
					break;				
				case 'x':
					cout << "Editing complete, returning to main menu. \n";
					cout << "----------------\n";
					compEditing = true;
					break;
				
				default:
					cout << "Sorry, that is not one of the options, try again.\n";
					cout << "\n";
			}
		}
	}
}

void Search(List& patients){
	string num;
	cout << "To find an existing patient, please enter the 10-digit care card.\n";
	cin >> num;
	
	Patient find = Patient(num);
	Patient * patient = patients.search(find);
	if (patient == NULL){
		cout << "The patient was not found. Please check that the care card number was entered correctly.\n";
		cout << "----------------\n";	
	}
	else{
		cout << "The patient is in the system.\n";
		operator<<(cout, find);
		cout << "----------------\n";	
	}
}

void Print(List patients){
	if(patients.getElementCount() == 0){
		cout << "Sorry, there are no patients in the database right now.\n";
		cout << "----------------\n";
	}
	else{
		cout << "These are the patients in the database:\n";
		patients.fullprint();
		cout << "----------------\n";
	}
}

int main(){
	List patients = List();
	bool exit = false;
	char input = 0; 
	cout << "--- System Loaded ---\n";
	cout << "Welcome to the Walk-in Clinic Patient Servicing System.\n";
	while(not exit){
		cout << "\n";
	
		cout << "To add a patient to the system, enter: a\n";
		cout << "To remove a patient from the system, enter: r\n";
		cout << "To edit a patient's information, enter: e\n";
		cout << "To search for a patient in the system enter: s\n";
		cout << "To print all the patients in the system enter: p\n";
		cin >> input;
		cout << "----------------\n";

		switch(tolower(input)){
			case 'a': Add(patients); break;
			case 'r': Remove(patients); break;
			case 'e': Edit(patients); break;
			case 's': Search(patients); break;			
			case 'p': Print(patients); break;
			case 'x': cout << "Exiting\n"; exit = true; break;
			default: cout << "Not sure what you mean, try again\n";
		}
	}
	
		return 0;
}








