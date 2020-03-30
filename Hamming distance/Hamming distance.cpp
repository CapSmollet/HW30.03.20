#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int hamming_distance(string x, string y)
{
    int dist = 0;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] != y[i])
            dist++;
    }
    return dist;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << hamming_distance(s1, s2);
    return 0;
}
