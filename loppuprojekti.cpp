// Markus Alatyppö, ainakin 4 pistettä

#include <conio.h>
#include <iostream>
#include <string>
#include "reservationList.cpp"

using std::string;

void menu(reservationList*);
int getInt();
void book(reservationList*);
void resSearch(reservationList*);

void printRooms(reservationList*);
void setColor(int);
void resetColor();

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
        for (int i = 0; i < 4; i++) {
            std::cout << i + 1 << ". " << menuItems[i] << std::endl;
        }

        int c = getInt();
        if (c >= 1 && c <= 4) {
            switch (c) {
            case 1:
                book(resList);
                break;
            case 2:
                resSearch(resList);
                break;
            case 3:
                printRooms(resList);
                break;
            case 4:
                break;
            case 5:
                quit(resList);
                break;
            }
        }
    } while (true);
}

void book(reservationList* resList) {
    system("cls");

}

void resSearch(reservationList* resList) {
    system("cls");
    std::cout << "Reservation search, select which way to search" << std::endl;
    std::cout << "1. search by name" << std::endl;
    std::cout << "2. search by room" << std::endl;
    int selection =0;
    while (selection < 1 && selection >2) {
        selection = getInt();
    }
    switch(selection){
    case 1:
        resList->getReservation(getName());
        break;
    case 2:
        break;
    }
}

// Print all rooms with descriptive colors
void printRooms(reservationList* resList) {
    system("cls");
    int count = resList->getRoomCount();
    for (int i = 0; i < count; i++) {
        // if the room is free set the outputs background color green, if the room is not free set it to red instead
        if (resList->roomIsFree(i))
            setColor(101);
        else
            setColor(42);
        
        // the following if statements pad the text to avoid uneven rows
        if (i+1 < 10)
            std::cout << " ";
        if (i+1 < 100)
            std::cout << " ";

        std::cout << " " << i+1 << " ";
        if ((i+1) % 20 == 0)
            std::cout << std::endl;
        resetColor();
    }
}

// Save the room and reservation vectors to files
void quit(reservationList* resList) {
    
}

// utility functions

void setColor(int color) { std::cout << "\033[" << color << "m";}

void resetColor() { std::cout << "\033[0m"; }

string getName() {
    string name = "";
    std::getline(std::cin, name);
    while (!validateName(name)) {
        std::cout << "Please enter a valid name" << std::endl;
        std::cin.clear();
        std::getline(std::cin, name);
    }
    return name;
}

bool validateName(string name) {
    if (name.length() == 0)
        return false;
    for (int i = 0; i < name.length(); i++)
        if (name[i] >= '0' && name[i] <= '9')
            return false;

    return true;
}

int getInt() {
    int c = 0;
    c = _getch();
    if (std::isdigit(c)) {
        c -= '0';
    }
    return c;
}