#include <bits/stdc++.h>
using namespace std;
char DFA[100][100];

int findDFA(char str, int stateNumber) {
    for (int i = 0; i < stateNumber; i++) {
        if (DFA[i][0] == str) {
            return i;
        }
    }
    return -1;
}

int main() {
    int stateNumber; cin >> stateNumber;
    int NonFinal; cin >> NonFinal;
    string NF; cin >> NF;
    int Final; cin >> Final;
    string F; cin >> F;
    // DFA transition table
    for (int i = 0; i < stateNumber; i++) cin >> DFA[i][0] >> DFA[i][1] >> DFA[i][2];

    int table[stateNumber][stateNumber];
    for (int i = 0; i < stateNumber; i++) {
        for (int j = 0; j < stateNumber; j++) {
            if (i > j)
                table[i][j] = 0;

            else
                table[i][j] = -1;
        }
    }
    // Final-Non final checking operation
    map<string, int> m;
    char c = 'A';
    for (int i = 0; i < stateNumber; i++, c++) {
        char d = 'A';
        for (int j = 0; j < stateNumber; j++, d++) {
            if (table[i][j] == 0) {
                if (((NF.find(c) != -1) and (F.find(d) != -1)) || ((NF.find(d) != -1) and (F.find(c) != -1))) {
                    table[i][j] = 1;
                    char ch1 = c;
                    char ch2 = d;
                    string str = string(1, ch1) + string(1, ch2);
                    m[str] = 1;
                }
            }
        }
    }
    char c1 = 'A';
    for (int i = 0; i < stateNumber; i++, c1++) {
        char d = 'A';
        for (int j = 0; j < stateNumber; j++, d++) {
            if (table[i][j] == 0) {
                int index1 = findDFA(c1, stateNumber);
                int index2 = findDFA(d, stateNumber);
                char ch3 = DFA[index1][1];
                char ch4 = DFA[index2][1];
                string str = string(1, ch3) + string(1, ch4);
                cout << "for 0 --> " << c1 << " and " << d << " goes to " << str[0] << " and " << str[1] << '\n';
                auto it = m.find(str);
                if (it != m.end()) {
                    table[i][j] = 1;
                    m[str] = 1;
                }
                char ch5 = DFA[index1][2];
                char ch6 = DFA[index2][2];
                string str1 = string(1, ch5) + string(1, ch6);
                cout << "for 1 --> " << c1 << " and " << d << " goes to " << str1[0] << " and " << str1[1] << '\n';
                auto it1 = m.find(str1);
                if (it1 != m.end()) {
                    table[i][j] = 1;
                    m[str1] = 1;
                }
            }
        }
    }

    for (int i = 0; i < stateNumber; i++) {
        for (int j = 0; j < stateNumber; j++) {
            cout << table[i][j] << "  ";
        }
        cout << '\n';
    }
    cout << "final equivalent states : \n"; 
    char c2 = 'A';
    for (int i = 0; i < stateNumber; i++, c2++) {
        char d2 = 'A';
        for (int j = 0; j < stateNumber; j++, d2++) {
            if(!table[i][j]) cout << c2  << " is equivalent of " << d2 << '\n';
        }
    }
}