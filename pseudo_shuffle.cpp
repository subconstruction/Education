#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

int main() {
    std::string line;
    std::vector<std::string> answers;
    std::ifstream file("otveti_base.txt");

    while (getline(file, line)) {
        answers.push_back(line);
    }
    file.close();

    int num_questions = answers.size();

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(answers.begin(), answers.end(), std::default_random_engine(seed));

    for (int i = 0; i < num_questions; ) {
        if (answers[i] == line) {
            std::shuffle(answers.begin(), answers.end(), std::default_random_engine(seed));
            i = 0;
        } else {
            i++;
        }
    }

    std::ofstream outfile("otveti_new.txt");

    for (const auto& answer : answers) {
        outfile << answer << "\n";
    }
    outfile.close();

    std::cout << "Количество вопросов: " << num_questions << std::endl;

    return 0;
}
