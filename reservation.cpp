#include <string>
#include "room.cpp"
#include "randgen.h"
#include <iostream>

using std::string;

class reservation {
public:
	int roomId;								// index of the room
	int resId;								// random unique number between 10000 and 99999. only used when searching for reservation
	string name;							// name of the reservee
	room* roomP;							// pointer to the specific room
	int nightCount;							// how many nights the reservation is for
	int discount;							// discount from final price of the stay
	int discountTable[3] = {0, 10, 20};		// possible discounts
	int totalPrice=0;						// total price of the reservation

	reservation(int id, string n, room* rp, int nights, int rId) : resId(id), name(n), roomP(rp), nightCount(nights), roomId(rId) {
		int index = randGen(0, 2);
		discount = discountTable[index];
		if (discount == 0)
			totalPrice = roomP->price * nightCount;
		else
			totalPrice = (roomP->price * nightCount) * (1.0 - float(discount) / 100.0);
	}

	void print() {
		std::cout << this->roomId << "\t" << this->resId << "\t" << this->name << "\t" << this->nightCount << "\t" << this->totalPrice << std::endl;
	}
};