#include <fstream>
#include <vector>
#include <iostream>
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

	void addReservation(string n, room* rId, int nights, int roomSize){
		int id = randGen(10000, 99999);

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

	bool roomIsFree(int index){
		return rooms.at(index).reserved;
	}

	// save rooms and reservations to separate files
	bool saveToFile(){
		string roomFilename = "roominfo.txt";
		std::ofstream f(roomFilename);
		if (!f.is_open()) {
			std::cout << "failed create file " << roomFilename << std::endl;
			return false;
		}
		else {
			for (int i = 0; i < roomCount; i++) {
				if (rooms.at(i).reserved == true) {
					//logic for saving reservation data
				}
				
			}
		}
		return true;
	}
	bool loadFromFile(){
		return false;
	}

	int getRoomCount() {
		return roomCount;
	}

private:
	int roomCount;
};