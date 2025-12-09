#include <string>
#include "room.cpp"
#include "randgen.h"

using std::string;

class reservation {
public:
	int resId;								// random unique number between 10000 and 99999. only used when searching for reservation
	string name;							// name of the reservee
	room* roomID;								// equal to the index of the room in the rooms array
	int nightCount;							// how many nights the reservation is for
	int discount;							// discount from final price of the stay
	int discountTable[3] = {0, 10, 20};
	int totalPrice=0;

	reservation(int id, string n, room* rId, int nights) : resId(id), name(n), roomID(rId), nightCount(nights) {
		int index = randGen(0, 2);
		discount = discountTable[index];
		if (discount == 0)
			totalPrice = roomID->price * nightCount;
		else
			totalPrice = (roomID->price * nightCount) * (1.0 - discount / 100.0);
	}
};