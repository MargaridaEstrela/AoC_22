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
    string rucksack;
    int priorities_sum = 0;

    while(std::getline(file, rucksack)) {

        int mid = rucksack.length()/2;

        string first_comp = rucksack.substr(0, mid);
        string second_comp = rucksack.substr(mid);

        char item;

        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < mid; j++) {
               if (first_comp[i] ==  second_comp[j]) {
                    item = first_comp[i];
                    continue;
                }
            }
            continue;
        }

        priorities_sum += get_priority(item);

    }

    std::cout << "Sum = " << priorities_sum << std::endl;

    return 0;
}
