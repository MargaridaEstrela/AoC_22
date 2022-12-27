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

int get_end(char play) {
    if (play == 'X') {
        return LOST;
    } else if (play == 'Y') {
        return DRAW;
    } else if (play == 'Z') {
        return WIN;
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
        char end_play, opponent_play;

        play >> opponent_play;
        play >> end_play;

        int end, opponent_score = 0;

        end = get_end(end_play);
        opponent_score = get_opponent_score(opponent_play);

        score += end;

        if (end == DRAW) {

            score += opponent_score;

        } else if (end == WIN) {
            if (opponent_score == ROCK) {
                score += PAPER; 
            } else if (opponent_score == PAPER) {
                score += SCISSORS;
            } else {
                score += ROCK;
            }
        } else {
            if (opponent_score == ROCK) {
                score += SCISSORS; 
            } else if (opponent_score == PAPER) {
                score += ROCK;
            } else {
                score += PAPER;
            }
        }
    }

    std::cout << "Total score = " << score << std::endl;

    return 0;
}
