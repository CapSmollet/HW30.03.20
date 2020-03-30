#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int del_cost = 20, sub_cost = 12, ins_cost = 15;

unsigned int Levenshtein_distance(const string& s1, string& s2)
{
	const size_t len1 = s1.size(), len2 = s2.size();
	vector<vector<int> > d(len1 + 1, vector<int>(len2 + 1));
	d[0][0] = 0;
	for (int i = 1; i <= len1; ++i)
        d[i][0] = d[i - 1][0] + del_cost;
	for (int i = 1; i <= len2; ++i)
        d[0][i] = d[0][i - 1] + ins_cost;
	for (int i = 1; i <= len1; ++i)
		for(int j = 1; j <= len2; ++j)
            d[i][j] = min((d[i - 1][j] + del_cost, d[i][j - 1] + ins_cost), d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : sub_cost)); //?: ternary operator (if ()? then 1 else 2)
	return d[len1][len2];
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << Levenshtein_distance(s1, s2);
    return 0;
}
