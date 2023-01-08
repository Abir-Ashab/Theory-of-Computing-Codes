#include<bits/stdc++.h>
using namespace std;
bool flag = false;
string state;
set<string> d;
void StateAllocation(int i, char s[], int len) {
	flag = true;
	int k = 4;
	char j = 'b';
	state[i] = 'a';
	while(k--) {
		state[i + 1] = j;
		j++; i++;
	}
	j -= 2;
	while(i <= len) {
		state[i] = j;
		i++;
	}
}
void Print_Transition_of_nfa(int x, char s[]) {
	int i = 0;
	while(i < x){
		if(state[i] != state[i+1]) {
				cout << state[i] << "---" << s[i] << "--->" << state[i+1] << '\n';
				i++;
		} 
		else {
			cout << state[i] << "---" << s[i] << "--->" << state[i] << '\n';
			i++;
	    }
	}
}
void Print_Transition_of_dfa(int x, char s[]) {
	int i = 0;
    cout << "DFA transition table :\n";
    //cout << "states ->" << "  0     ->" << "1\n";
    string ss1 = "", ss2 = "a", ss3 = "a";
	while(i < x){
		if(state[i] != state[i+1]) {
            ss1 = ss1 + state[i];
			if(state[i+1] != 'd') {
            ss2 = ss1 + state[i+1];
            cout << ss1 << "----(0)--->  " << ss3 << '\n';
            cout << ss1 << "----(1)--->  " << ss2 << "\n";
            }
            else {
                ss2 = ss1 + state[i+1];
                cout << ss1 << "----(0)--->  " << ss3 << '\n';
                cout << ss1 << "----(1)--->  " << ss2 << "\n";
                ss3 = ss3 + state[i+1];
                ss1 = ss1 + state[i + 1];
            }
		} 
        i++;
	} int t = 2;
    while(t--) {
            cout << ss1 << "----(0)--->  " << ss3 << '\n';
            cout << ss1 << "----(1)--->  " << ss2 << "\n";
            ss1 = ss3;
            ss2 = ss3 + "b";
    }
    ss3 = ss2;
    ss1 = ss2;
    cout << ss1 << "----(0)--->  " << ss3 << '\n';
    cout << ss1 << "----(1)--->  " << "abcd\n" << "\n";
}
int isAccepted(char s[]) {
	int i = 0, len = strlen(s);
	while(!flag and i != len) {
		if(s[i] == '1' and s[i+1] == '1' and s[i+2] == '1') StateAllocation(i, s, len);
		else state[i] = 'a';
		i++;
	}
	Print_Transition_of_nfa(len, s);
	if(flag) return 1;
	else return 0;
}

int main() {
	cout << "Enter a string :";
	char str[100];
	gets(str);
    int len = strlen(str);
	if (isAccepted(str)) {
		printf("ACCEPTED\n");
        Print_Transition_of_dfa(len, str);
    }
	else
		printf("NOT ACCEPTED\n");
	return 0;
}