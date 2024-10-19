#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h> 

using namespace std;

const int num_rows = 5;
const int num_cols = 5;
const int num_mines = rand() % 2 + 3;

vector<pair<int, int>> generateMineCoordinates();

string generateFieldString() {
    vector<vector<char>> field(num_rows, vector<char>(num_cols, '='));
    vector<pair<int, int>> minesCoordinates = generateMineCoordinates();

    for (auto& mineCoordinate : minesCoordinates) {
        field[mineCoordinate.first][mineCoordinate.second] = 'X';
    }

    string fieldString = "";
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            fieldString += field[row][col];
        }
        fieldString += '\n';
    }

    return fieldString;
}

vector<pair<int, int>> generateMineCoordinates() {
    vector<pair<int, int>> coordinates;
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            coordinates.push_back({row, col});
        }
    }

    vector<pair<int, int>> minesCoordinates;
    srand(time(nullptr));
    for (int i = 0; i < num_mines; i++) {
        int randomIndex = rand() % coordinates.size();
        minesCoordinates.push_back(coordinates[randomIndex]);
        coordinates.erase(coordinates.begin() + randomIndex);
    }

    return minesCoordinates;
}

int main() {
    while (true) {
        string fieldString = generateFieldString();
        system("cls");
        cout << "Press any key to generate" << endl;
        cout << fieldString << endl;
        _getch();
    }

    return 0;
}

//Brincando um pouco com c++