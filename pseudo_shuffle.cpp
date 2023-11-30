#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>

int main() {
    std::ifstream questionsFile("vosrosi_base.txt"), answersFile("answers_base.txt"), timeFile("time_base.txt");
    std::ofstream newQuestionsFile("voprosi_new.txt"), newAnswersFile("otveti_new.txt"), newTimeFile("time_new.txt");

    std::vector<std::string> questions, answers, time;
    std::string line;
    std::vector<int> indices;

    while (getline(questionsFile, line)) {
        questions.push_back(line);
        indices.push_back(indices.size());
    }
    while (getline(answersFile, line)) {
        answers.push_back(line);
    }
    while (getline(timeFile, line)) {
        time.push_back(line);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);

    for (int i : indices) {
        newQuestionsFile << questions[i] << "\n";
        newAnswersFile << answers[i] << "\n";
        newTimeFile << time[i] << "\n";
    }

    return 0;
}
