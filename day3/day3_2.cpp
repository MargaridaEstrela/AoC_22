#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using string = std::string;


int get_priority(char item) {

    char A = 'A';
    char a = 'a';

    if (isupper(item)) {
        return item - A + 27;
    } else {
        return item - a + 1;
    }

    return 0;
}


int main() {

    std::ifstream file("day3.txt");
    int priorities_sum = 0;
    string elves[3];

    while(!file.eof()) {

        for (int i = 0; i < 3; i++) {
            string rucksack;
            std::getline(file, rucksack);
            elves[i] = rucksack;
        }

        for (char c : elves[0]) {

            if ((elves[1].find(c) != string::npos) && (elves[2].find(c) != string::npos)) {
                priorities_sum += get_priority(c);
                break;
            }
        }
    }

    file.close();

    std::cout << "Sum = " << priorities_sum << std::endl;

    return 0;
}
