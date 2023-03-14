#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; 
    cin >> s;
    ll x =  s.size();
    if(s.find('1') == -1) cout << "Not Accepted\n";
    else {
        cout << "Accepted\n";
        cout << "Derivations are : ";
        string S = "A1B";
        cout << S << " -> ";
        string ans;
        if(s[0] == '0') ans = "0A";
        else ans = "1B";
        int store = 0, f = 0;
        for(int i = 0; i < x; ++i) {
            if(s[i] == '1') {
                store = i + 1;
                if(i) ans.erase(ans.find('A'),1);
                cout << ans << " -> ";
                break;
            }
            else {
                if(i == 0) ans.replace(ans.find('A'), S.size(), S);
                else {
                    string first = ans.substr(0, ans.find('A'));
                    string second = ans.substr(ans.find('A') + 1, ans.size());
                    string ToBeReplaced = "0A";
                    ans = first + ToBeReplaced + second;
                }
                cout << ans << " -> ";
            }
        }
        string S2 = "0B", S3 = "1B";
        if(store < x) {
        for(int i = store; i < x; ++i) {
            if(s[i] == '0') {
                ans.replace(ans.find('B'), ans.size(), S2);
                cout << ans << " -> ";
            }
            else {
                ans.replace(ans.find('B'), ans.size(), S3);
                cout << ans << " -> ";
            }
        }
        }
        ans.erase(ans.find('B'),1);
        cout << ans << '\n';
    } 
    return 0;
}