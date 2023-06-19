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

        cout << "--- 開始猜數字遊戲 ---" << endl;
        cout << "請輸入數字範圍 (0~ ?): ";
        cin >> max;
        cout << endl;
        j = max;
        rightBound = max;

        do {
            cout << "你猜的是: ";
            cin >> guess;
            count++;
            if (guess > j) {
                cout << "小一點..." << endl;
            } else if (guess < i) {
                cout << "大一點..." << endl;
            } else {
                if (guess - i > j - guess) { // 左半邊剩比較多
                    j = guess - 1;
                    if (i < j) cout << "小一點!" << endl;
                } else { // 右半邊剩比較多
                    i = guess + 1;
                    if (i < j) cout << "大一點!" << endl;
                }
            }
        } while (i < j);

        cout << "你猜對了!" << endl;
        cout << endl << "總共猜了 " << count << " 次" << endl;
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
        cin.ignore(); // 忽略之前輸入的換行符號

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
