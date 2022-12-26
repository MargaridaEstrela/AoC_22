#include <iostream>
#include <string>
#include <fstream>

using string = std::string;

int main() {

    std::ifstream file("day1.txt");
    string line;
    int count, total_calories = 0;

    while(std::getline(file, line)) {

        if (line != "\n" && line != "\0") {
            count += stoi(line);
        } else {
            if (count > total_calories) {
                total_calories = count;
            }
            count = 0;
        }
    }
    std::cout << "Total Calories = " << total_calories << std::endl;

    return 0;
}
