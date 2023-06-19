#include <iostream>

char GRADE_MAP[] = { 'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A' };

class Grade {
private:
    char letter;
    int percent;

public:
    void setGradeByPercent(int percent) {
        this->percent = percent;
        this->letter = GRADE_MAP[percent / 10];
    }

    void setGradeByLetter(char letter) {
        this->letter = letter;
        this->percent = 100 - (letter - 'A') * 10 - 5;
    }

    void printGrade() {
        std::cout << "Grade: " << percent << ": " << letter << std::endl;
    }
};



int main() {
    Grade g;
    int percent;

    std::cout << "Enter two grades separated by a space. Use a percentage for the first and letter for the second: ";
    std::cin >> percent;
    std::cin.ignore();

    g.setGradeByPercent(percent);
    g.printGrade();

    g.setGradeByLetter(std::cin.get());
    g.printGrade();

    return 0;
}
