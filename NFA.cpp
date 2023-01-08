#include<bits/stdc++.h>
using namespace std;
bool flag = false;
string state;

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
void Print_Transition(int x, char s[]) {
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
int isAccepted(char s[]) {
	int i = 0, len = strlen(s);
	while(!flag and i != len) {
		if(s[i] == '1' and s[i+1] == '1' and s[i+2] == '1') StateAllocation(i, s, len);
		else state[i] = 'a';
		i++;
	}
	Print_Transition(len, s);
	if(flag) return 1;
	else return 0;
}

int main() {
    int t = 10;
    while(t--) {
	cout << "Enter a string :";
	char str[100];
	gets(str);
	if (isAccepted(str))
		printf("ACCEPTED\n");
	else
		printf("NOT ACCEPTED\n");
    }
	return 0;
}