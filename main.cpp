#include <iostream>
#include <vector>
#include <cmath>
#include <string>

int main() {

    int size; // Number of test cases

    std::cin >> size;
    int numsInput [size];

    for (int i=0; i < size; i++) {
        std::cin >> numsInput[i];
//        std::cout << numsInput[i];
    }

    // Get the digit and it's place for each number
    int current_number;
//    int rounds [5] = {0,0,0,0,0};
    int round_number;
    int count_round_numbers;
    std::string output_string;

    for (int p=0; p<size; p++) {
        current_number = numsInput[p];
        count_round_numbers = 0;
        output_string = "";
        for (int l=0; l<5; l++) {
//            rounds[l] = (current_number % 10) * std::pow(10, i);
            round_number = (current_number % 10) * std::pow(10, l);
            current_number /= 10;
            if (round_number != 0) {
                count_round_numbers++;
                output_string += std::to_string(round_number) + " ";
            }
        }

        std::cout << count_round_numbers << "\n" << output_string << std::endl;
    }

    return 0;
}

//inline void
