#include <iostream>
#include <string>
#include <fstream>

using string = std::string;

int main() {

    std::ifstream file("day1.txt");
    string line;
    int count;
    int top_calories[3] = {0};

    while(std::getline(file, line)) {

        if (line != "\n" && line != "\0") {
            count += stoi(line);
        } else {

            int min_value = top_calories[0];
            int min_index = 0;

            for (int i = 0; i < sizeof(top_calories)/sizeof(int); i++) {
                if (min_value > top_calories[i]) {
                    min_value = top_calories[i];
                    min_index = i;
                }
            }

            if (count > min_value) {
                top_calories[min_index] = count;
            }

            count = 0;
        }
    }

    int total_calories = 0;

    for (auto &value : top_calories) {
        total_calories += value;
    }

    std::cout << "Total Calories = " << total_calories << std::endl;

    return 0;
}
