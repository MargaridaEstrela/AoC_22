#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using string = std::string;

enum Scores {
    ROCK = 1,
    PAPER = 2,   
    SCISSORS = 3,
    LOST = 0,
    DRAW = 3,
    WIN = 6
};


int get_opponent_score(char play) {
    if (play == 'A') {
        return ROCK;
    } else if (play == 'B') {
        return PAPER;
    } else if (play == 'C') {
        return SCISSORS;
    } else {
        return 0;
    }
}

int get_my_score(char play) {
    if (play == 'X') {
        return ROCK;
    } else if (play == 'Y') {
        return PAPER;
    } else if (play == 'Z') {
        return SCISSORS;
    } else {
        return 0;
    }
}


int main() {

    std::ifstream file("day2.txt");
    string line;
    int score = 0;

    while(std::getline(file, line)) {
        std::stringstream play(line);
        char my_play, opponent_play;

        play >> opponent_play;
        play >> my_play;

        int my_score, opponent_score = 0;
        my_score = get_my_score(my_play);
        opponent_score = get_opponent_score(opponent_play);

        score += my_score;

        if (my_score == opponent_score) {

            score += DRAW;

        } else if ((my_score == ROCK && opponent_score == SCISSORS) || 
            (my_score == PAPER && opponent_score == ROCK) || 
            (my_score == SCISSORS && opponent_score == PAPER)) {

            score += WIN;
        } 
        else {
            score += LOST;
        }
    }

    std::cout << "Total score = " << score << std::endl;

    return 0;
}
