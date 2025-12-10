// Markus Alatyppö, ainakin 4 pistettä

#include <conio.h>
#include <iostream>
#include "reservationList.cpp"
#include "utilities.h"
#include <thread>
#include <chrono>

#define RED 101
#define GREEN 42

using std::chrono::milliseconds;
using std::this_thread::sleep_for;

void menu(reservationList*);
void book(reservationList*);
void reservationSearch(reservationList*);
void printRooms(reservationList*);
void quit(reservationList*);


int main()
{
    reservationList resList;
    menu(&resList);
}


// Drawing and handling menu inputs,
void menu(reservationList* resList) {
    string menuItems[5] = {
        "Book a room",
        "Search for reservation",
        "Show all rooms",
        "Show all reservations",
        "Quit"
    };
    bool cnt = true;

    do {
        system("cls");

        std::cout << "Hotel booking and management" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << i + 1 << ". " << menuItems[i] << std::endl;
        }

        int c = getNumber(1, 5);
        switch (c) {
        case 1:
            book(resList);
            break;
        case 2:
            reservationSearch(resList);
            break;
        case 3:
            printRooms(resList);
            break;
        case 4:
            system("cls");
            std::cout << "reservations" << std::endl;
            resList->printReservations();
            std::cin.get();
            std::cin.ignore();
            break;
        case 5:
            quit(resList);
            break;
        }

    } while (true);
}

// create a new reservation
void book(reservationList* resList) {
    system("cls");
    std::cout << "Reserver name: ";
    string name = getName();

    std::cout << "\nRoom size (1 or 2) persons: ";
    int roomSize = getNumber(1, 2);

    std::cout << "Select room number: ";
    int roomNum = getNumber(0, resList->getRoomCount());

    std::cout << "\nHow many nights is the reservation for (max 356): ";
    int nights = getNumber(1, 365);
    resList->addReservation(name, roomNum, nights);
}

void reservationSearch(reservationList* resList) {
    int reservIndex=-1;
    system("cls");
    std::cout << "Reservation search, select which way to search" << std::endl;
    std::cout << "1. search by name" << std::endl;
    std::cout << "2. search by room" << std::endl;
    int selection = 0;
    selection = getNumber(1, 2);

    switch(selection){
    case 1:
        system("cls");
        std::cout << "Give name to search for: ";
        reservIndex = resList->getReservation(getName());
        break;
    case 2:
        system("cls");
        std::cout << "Give reservation id to search for: ";
        reservIndex = resList->getReservation(getNumber(10000, 99999));
        break;
    }
    if (reservIndex < 0) {
        std::cout << "Failed to find a reservation with the given information. please try again" << std::endl;
        sleep_for(milliseconds(1500));
        return;
    }
    resList->reslist.at(reservIndex).print();
    std::cin.get();
    std::cin.ignore();
}

// Print all rooms with descriptive colors
void printRooms(reservationList* resList) {
    system("cls");
    int count = resList->getRoomCount();

    
    std::cout << "Free:\t\t";
    setColor(GREEN);
    std::cout << "  " << std::endl;

    resetColor();
    std::cout << "Reserved:\t";
    setColor(RED);
    std::cout << "  \n" << std::endl;
    resetColor();

    for (int i = 0; i < count; i++) {
        // if the room is free set the outputs background color green, if the room is not free set it to red instead
        if (resList->isReserved(i)) {
            setColor(RED);
        }
        else {
            setColor(GREEN);
        }
        // the following if statements pad the text to avoid uneven rows
        if (i < 10)
            std::cout << " ";
        if (i < 100)
            std::cout << " ";

        std::cout << " " << i << " ";
        if ((i+1) % 20 == 0)
            std::cout << std::endl;
        resetColor();
    }
    std::cout << "\npress enter to return";
    std::cin.get();
    std::cin.ignore();
}

// Save the room and reservation vectors to files
void quit(reservationList* resList) {
    exit(0);
}

