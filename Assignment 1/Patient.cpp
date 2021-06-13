/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: Aditya Rajvanshi - 301349754
 * Date: 20/01/2019
 */


// You can add #include statements if you wish.
#include <iostream>
#include <locale>
#include <string>
#include "Patient.h"

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() {
	setCareCard ("0000000000");
	setName ("To be entered");
	setAddress ("To be entered");
	setPhone ("To be entered");
	setEmail ("To be entered");

}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard){
	setName ("To be entered");
	setAddress ("To be entered");
	setPhone ("To be entered");
	setEmail ("To be entered");
	if (aCareCard.length() == 10)
		setCareCard (aCareCard);	
	else
		setCareCard ("0000000000");
}

// Getters and setters 
	// Description: Returns patient's name.	
	string Patient::getName() const{
		return Name;
}
	// Description: Returns patient's address.
	string Patient::getAddress() const{
		return Address;
}
	// Description: Returns patient's phone.
	string Patient::getPhone() const{
		return Phone;
}
	// Description: Returns patient's email.
	string Patient::getEmail() const{
		return Email;
}	
	// Description: Returns patient's care card.
	string Patient::getCareCard() const{
		return CareCard;
}
	// Description: Sets the patient's name.
	void Patient::setName(const string aName){
		Name = aName;
		return;
}
	// Description: Sets the patient's address.
	void Patient::setAddress(const string anAddress){
		Address = anAddress;
		return;
}
	// Description: Sets the patient's phone.
	void Patient::setPhone(const string aPhone){
		Phone = aPhone;
		return;
}
	// Description: Sets the patient's email.
	void Patient::setEmail(const string anEmail){
		Email = anEmail;
		return;
}
	// Description: Sets the patient's care card.
	void Patient::setCareCard(const string aCareCard){
		CareCard = aCareCard;
		return;
}
// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {
	// Compare both Patient objects
	return this->CareCard == rhs.getCareCard();
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->CareCard > rhs.getCareCard();
	
} // end of operator >


// Description: Prints the content of "this".
ostream& operator<<(ostream & os, const Patient & p) {
	os << p.getCareCard() << " - Patient: " << p.getName() << ", " <<  p.getAddress() << ", " << p.getPhone() << ", " << p.getEmail() << "\n";
	return os;

} // end of operator<<



// end of Patient.cpp
