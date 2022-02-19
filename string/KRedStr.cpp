// Reduce the string by removing K consecutive identical characters
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string remove_k_char(int k, string s)
{
    if (k == 1)
        return "";

    string output = "";

    stack<pair<char, int> > stk;

    for (int i = 0; i < s.length(); i++) {
        if (stk.empty() == true) {
            stk.push(make_pair(s[i], 1));
        }
        else {
            if (s[i] == (stk.top()).first) {
                stk.push({ s[i], stk.top().second + 1 });
                if (stk.top().second == k) {
                    int x = k;
                    while (x) {
                        stk.pop();
                        x--;
                    }
                }
            }
            else {
                stk.push(make_pair(s[i], 1));
            }
        }
    }

    while (!stk.empty()) {
        output += stk.top().first;
        stk.pop();
    }
    reverse(output.begin(), output.end());
    return output;
}

int main()
{

	string s = "aaabccddcde";
	int k = 2;
	cout << remove_k_char(k, s) << "\n";

	return 0;
}

