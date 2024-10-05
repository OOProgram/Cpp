#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
public:
    string player;

    Player() {}

    Player(string player) {
        this->player = player;
    }

    void setName(string player) {
        this->player = player;
    }

    string getName() {
        return player;
    }
};

class GamblingGame {
private:
    Player players[2];

public:
    GamblingGame() {
        string player1, player2;
        cout << "첫번째 선수 이름>>";
        cin >> player1;
        cout << "두번째 선수 이름>>";
        cin >> player2;

        players[0].setName(player1);
        players[1].setName(player2);
        cin.ignore();
    }

    void playGame() {
        srand(time(0));
        while (true) {
            if (takeTurn(players[0])) {
                cout << players[0].getName() << "님 승리!!" << endl;
                break;
            }
            if (takeTurn(players[1])) {
                cout << players[1].getName() << "님 승리!!" << endl;
                break;
            }
        }
    }

private:
    bool takeTurn(Player& player) {
        cout << player.getName() << ": <Enter>";
        cin.ignore();

        int num1 = rand() % 3;
        int num2 = rand() % 3;
        int num3 = rand() % 3;

        cout << "          " << num1 << "    " << num2 << "    " << num3 << "    ";

        if (num1 == num2 && num2 == num3) {
            return true;
        }
        else {
            cout << "아쉽군요!" << endl;
            return false;
        }
    }
};

int main() {
    GamblingGame game;
    game.playGame();

    return 0;
}
