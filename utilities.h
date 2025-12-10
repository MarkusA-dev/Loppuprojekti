#ifndef UTILS_H
#define UTILS_H

int getNumber(int min, int max);
void setColor(int);
void resetColor();
bool validateName(string);
string getName();

// utility functions

void setColor(int color) { std::cout << "\033[" << color << "m"; }

void resetColor() { std::cout << "\033[0m"; }

// Specifically for getting multiple numbers and validating them
int getNumber(int min, int max) {
    int num = 0;
    while (!(std::cin >> num) || num > max || num < min) {
        std::cout << "\nplease enter valid digit: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return num;
}

// Handle name input
string getName() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string name = "";
    std::getline(std::cin, name);
    while (!validateName(name)) {
        std::cout << "\nPlease enter a valid name: ";
        std::cin.clear();
        std::getline(std::cin, name);
    }
    return name;
}

// Name validation to ensure non numeric and not empty name
bool validateName(string name) {
    if (name.length() == 0)
        return false;
    for (int i = 0; i < name.length(); i++)
        if (name[i] >= '0' && name[i] <= '9')
            return false;

    return true;
}

#endif