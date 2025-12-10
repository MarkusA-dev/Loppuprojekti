#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include "reservation.cpp"
using std::vector;

class reservationList {
public:
	// main storage vectors for the program
	vector<reservation> reslist;
	vector<room> rooms;

	// class constructor, only called if 
	reservationList() {
		if (!loadFromFile()) {
			// if storage files do not exist

			int roomCountUncertain = randGen(40, 300);
			if (roomCountUncertain % 2 != 0) {
				roomCount = roomCountUncertain - 1;
			}
			else
				roomCount = roomCountUncertain;

			reslist.reserve(roomCount);
			rooms.reserve(roomCount);

			for (int i = 0; i < roomCount; i++) {
				if (i < roomCount / 2)
					rooms.push_back(singleRoom());
				else
					rooms.push_back(twinRoom());
			}
		}
	}

	void addReservation(string n, int rId, int nights){
		int id = randGen(10000, 99999);
		reslist.push_back(reservation(id, n, &rooms.at(rId), nights, rId));
		rooms.at(rId).setReserved();
	}

	// Due to time constraints and the lack of this function being a strict requirement I have chosen to not implement it
	// however it is left here to show intent
	//void removeReservation(int id) {}
	
	
	int getReservation(int resId){
		for (reservation r : reslist) {
			if (r.resId == resId) {
				return r.roomId;
			}
		}
		return -1;
	}

	int getReservation(std::string name){
		for (reservation r : reslist) {
			if (r.name == name) {
				return r.roomId;
			}
		}
		return -1;
	}

	void printReservations() {
		for (reservation r : reslist) {
			r.print();
		}
	}

	bool isReserved(int index){
		return rooms.at(index).reserved;
	}

	// save rooms and reservations to separate files
	bool saveToFile(){
		const string roomFilename = "roominfo.txt";
		const string reservFilename = "reservinfo.txt";
		std::ofstream f(roomFilename);
		std::ofstream f2(reservFilename);
		if (!f.is_open() || !f2.is_open()) {
			std::cout << "failed create file " << roomFilename << std::endl;
			return false;
		}
		else {
			f << getRoomCount()<<"\n";
			for (room r : rooms) {
				f<<r.type<<" "<<r.reserved<<"\n";
			}
			for (reservation res : reslist) {
				f2  << res.resId << " "
					<< res.name << " "
					<< res.roomId << " "
					<< res.nightCount << " "
					<< res.discount<< " " 
					<< res.totalPrice << "\n";
			}
		}
		return true;
	}
	bool loadFromFile(){
		const string roomFilename = "roominfo.txt";
		const string reservFilename = "reservinfo.txt";
		std::ifstream f(roomFilename);
		std::ifstream f2(reservFilename);
		if (!f.is_open() || !f2.is_open()) {
			std::cout << "failed create file " << roomFilename << std::endl;
			return false;
		}
		else {
			int type = 0;
			bool reserved = false;
			room* temp = nullptr;
			reservation tempres;


			f >> roomCount;
			reslist.reserve(roomCount);
			rooms.reserve(roomCount);
			while (f>>type>>reserved) {
				if (type == 1)
					temp = new singleRoom;
				else
					temp = new twinRoom;
				
				if (temp != nullptr) {
					if (reserved) {
						temp->setReserved();
					}
					rooms.push_back(*temp);
				}
			}
			while (f2>>tempres.resId>>tempres.name
					 >>tempres.roomId>>tempres.nightCount
					 >>tempres.discount>>tempres.totalPrice) {
				tempres.roomP = &rooms.at(tempres.roomId);
				reslist.push_back(tempres);
			}
		}
		return true;
	}

	int getRoomCount() {
		return roomCount;
	}

private:
	int roomCount;
};