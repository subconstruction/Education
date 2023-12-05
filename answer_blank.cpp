#include <iostream>
#include <vector>
#include <string>

struct Question {
    std::string text;
    std::string answer;
};

class TestTaker {
public:
    void runTest() {
        askGroupAndName();
        administerTest();
        displayResult();
    }

private:
    int groupNumber;
    std::string studentName;
    int score = 0;
    const int totalQuestions = 10;
    std::vector<Question> questions = {
        {"Вопрос 1: ...", "Ответ 1"},
        {"Вопрос 2: ...", "Ответ 2"},
        {"Вопрос 3: ...", "Ответ 3"},
        {"Вопрос 4: ...", "Ответ 4"}
    };

    void askGroupAndName() {
        askGroupNumber();
        askStudentName();
    }

    void askGroupNumber() {
        std::cout << "Введите номер группы: ";
        std::cin >> groupNumber;
    }

    void askStudentName() {
        std::cout << "Введите ваше имя: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, studentName);
    }

    void administerTest() {
        for (const auto& q : questions) {
            std::cout << q.text << std::endl;
            std::string userAnswer = askForAnswer("Ваш ответ: ");
            
            if (userAnswer == q.answer) {
                score++;
            }
        }
    }

    std::string askForAnswer(const std::string& prompt) const {
        std::string userAnswer;
        std::cout << prompt;
        std::cin >> userAnswer;
        return userAnswer;
    }

    void displayResult() const {
        double percentage = static_cast<double>(score) / totalQuestions * 100;

        std::cout << "\nРезультат для студента " << studentName << " из группы " << groupNumber << ":\n";
        std::cout << "Баллы: " << score << " из " << totalQuestions << std::endl;
        std::cout << "Процент правильных ответов: " << percentage << "%" << std::endl;

        if (percentage >= 90) {
            std::cout << "Оценка: 5" << std::endl;
        } else if (percentage >= 75) {
            std::cout << "Оценка: 4" << std::endl;
        } else if (percentage >= 50) {
            std::cout << "Оценка: 3" << std::endl;
        } else {
            std::cout << "Оценка: 2" << std::endl;
        }
    }
};

int main() {
    TestTaker test;
    test.runTest();

    return 0;
}
