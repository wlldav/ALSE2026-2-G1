#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

class Spreadsheet {
private:
    unordered_map<string, int> grid;

    int resolve(const string& token) {
        if (token.empty()) return 0;
        if (isdigit(token[0])) {
            return stoi(token);
        }
        return grid.count(token) ? grid[token] : 0;
    }

public:
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) {
        grid[cell] = value;
    }

    void resetCell(string cell) {
        grid.erase(cell);
    }

    int getValue(string formula) {
        if (formula.empty() || formula[0] != '=') {
            return resolve(formula);
        }

        string expr = formula.substr(1);
        size_t plusPos = expr.find('+');

        string part1 = expr.substr(0, plusPos);
        string part2 = expr.substr(plusPos + 1);

        return resolve(part1) + resolve(part2);
    }
};

int main() {
    Spreadsheet sheet(10);

    sheet.setCell("A1", 5);
    sheet.setCell("B1", 10);

    cout << "Valor A1: " << sheet.getValue("A1") << endl;
    cout << "Valor B1: " << sheet.getValue("B1") << endl;
    cout << "Suma =A1+B1: " << sheet.getValue("=A1+B1") << endl;
    cout << "Suma =A1+20: " << sheet.getValue("=A1+20") << endl;

    sheet.resetCell("A1");
    cout << "Valor A1 tras reset: " << sheet.getValue("A1") << endl;

    return 0;
}
