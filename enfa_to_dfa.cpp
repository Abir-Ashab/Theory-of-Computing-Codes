#include <bits/stdc++.h>
using namespace std;

vector<char> cha;

int Search(char val)
{
    int i, ind = -1;
    for (i = 0; i < cha.size(); i++)
    {
        if (cha[i] == val)
        {
            ind = i;
            break;
        }
    }
    return ind;
}

vector<string> epsilon;

void eclos(char c, set<char> &tmp)
{
    int p = Search(c);
    string s = epsilon[p];
    for (auto val : s)
    {
        if (val != 'N' && val != c && tmp.find(val) == tmp.end())
        {
            tmp.insert(val);
            eclos(val, tmp);
        }
    }
}

int main()
{
    int n;
    cout << "How many states are there? \n";
    cin >> n;
    cout << "Please enter the states:\n";
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        cha.push_back(c);
    }
    cout << "Enter the epsilon of the states: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "epsilon(" << cha[i] << ")=?\n";
        string s;
        cin >> s;

        epsilon.push_back(s);
    }

    vector<set<char>> eclosure;

    for (auto val : cha)
    {
        set<char> tmp;
        tmp.insert(val);
        eclos(val, tmp);
        eclosure.push_back(tmp);
    }

    cout << "E-closure of states: \n";
    for (int i = 0; i < eclosure.size(); i++)
    {
        cout << cha[i] << " : ";
        for (auto v : eclosure[i])
        {
            cout << v;
        }
        cout << "\n";
    }

    getchar();
    char nfa[n][2][10];
    for (int i = 0; i < n; i++)
    {
        cout << "(" << cha[i] << ",0)=?\n";
        cin >> nfa[i][0];
        cout << "(" << cha[i] << ",1)=?\n";
        cin >> nfa[i][1];
    }

    printf("Printing the transition table:\n");
    printf("# 0 1\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c ", cha[i]);
        for (int j = 0; j < 2; j++)
        {
            if (nfa[i][j][0] == '\0')
                printf("N ");
            else
                printf("%s ", nfa[i][j]);
        }
        printf("\n");
    }

    // enfa to dfa:
    printf("The transition function of dfa:\n");
    vector<set<char>> states;
    set<char> curr_state;
    states.push_back(eclosure[0]);

    for (int i = 0; i < states.size(); i++)
    {
        curr_state = states[i];
        set<char> s0, s1;
        for (auto ch : curr_state)
        {
            for (int k = 0; nfa[Search(ch)][0][k]; k++)
            {
                if (nfa[Search(ch)][0][k] == 'N')
                    continue;

                s0.insert(nfa[Search(ch)][0][k]);
                for (auto ch : eclosure[Search(nfa[Search(ch)][0][k])])
                {
                    s0.insert(ch);
                }
            }
            for (int k = 0; nfa[Search(ch)][1][k]; k++)
            {
                if (nfa[Search(ch)][1][k] == 'N')
                    continue;

                s1.insert(nfa[Search(ch)][1][k]);
                for (auto ch : eclosure[Search(nfa[Search(ch)][1][k])])
                {
                    s1.insert(ch);
                }
            }
        }
        // printing the states:
        cout << "(";
        for (auto c : curr_state)
        {
            cout << c;
        }
        cout << ",0)-->";
        for (auto c : s0)
        {
            cout << c;
        }
        cout << "\n";
        cout << "(";
        for (auto c : curr_state)
        {
            cout << c;
        }
        cout << ",1)-->";
        for (auto c : s1)
        {
            cout << c;
        }
        cout << "\n";

        // checking the states are present or not and push the state if not present
        bool present = false;
        for (auto val : states)
        {
            if (s0 == val)
            {
                // printf("dfdfdfg\n");
                present = true;
            }
        }
        if (!present)
            states.push_back(s0);
        present = false;
        for (auto val : states)
        {
            if (s1 == val)
                present = true;
        }
        if (!present)
            states.push_back(s1);
    }
}
