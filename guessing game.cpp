#include <iostream>

using namespace std;

class GuessGame {
public:
    virtual void go() = 0; // play game
    virtual void welcome(string text) = 0; // print the welcome message
    virtual void exitGame(string text) = 0; // print the ending message
    virtual ~GuessGame() = default;
};

class ConsoleGame : public GuessGame {
public:
    void go() {
        int i = 0, j = 0, max = 0;
        int guess = 0;
        int count = 0;
        int leftBound = 0;
        int rightBound = 0;

        cout << "--- �}�l�q�Ʀr�C�� ---" << endl;
        cout << "�п�J�Ʀr�d�� (0~ ?): ";
        cin >> max;
        cout << endl;
        j = max;
        rightBound = max;

        do {
            cout << "�A�q���O: ";
            cin >> guess;
            count++;
            if (guess > j) {
                cout << "�p�@�I..." << endl;
            } else if (guess < i) {
                cout << "�j�@�I..." << endl;
            } else {
                if (guess - i > j - guess) { // ���b��Ѥ���h
                    j = guess - 1;
                    if (i < j) cout << "�p�@�I!" << endl;
                } else { // �k�b��Ѥ���h
                    i = guess + 1;
                    if (i < j) cout << "�j�@�I!" << endl;
                }
            }
        } while (i < j);

        cout << "�A�q��F!" << endl;
        cout << endl << "�`�@�q�F " << count << " ��" << endl;
    }

    void welcome(string text) {
        cout << "welcome" << endl;
    }

    void exitGame(string text) {
        cout << "GG" << endl;
    }
};

int main() {
    string welcome_msg, exit_msg;

    string playAgain = "Y";
    while (playAgain == "Y" || playAgain == "y") {
        cout << "You want to play (Y/N): ";
        cin >> playAgain;
        cin.ignore(); // �������e��J������Ÿ�

        if (playAgain == "Y" || playAgain == "y") {
            GuessGame *game = new ConsoleGame();
            game->welcome(welcome_msg);
            game->go();
            game->exitGame(exit_msg);
            delete game;
        }
    }
    return 0;
}
