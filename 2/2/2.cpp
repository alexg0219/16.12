#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input)
    {
        cout << "error";
        return 0;
    }

    string s, f, dop;
    input >> s >> f;
    int n = 100, count = 0, m;
    for (int i = 0; i <= 25; i++)
    {
        for (int j = 0; j < f.size(); j++)
        {
            if (f[j] + i > 90) dop += 64 + (f[j] + i) % 90;
            else dop += f[j] + i;
        }
        if (s.find(dop) != -1 || s == dop)
        {
            n = i;
            if (n == 100)
            {
                output << "IMPOSSIBLE";
            }
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] - n < 65) cout << char(90 - (64 - (s[i] - n)));
                else 
                    output << char(s[i] - n);
            }
        }
        dop = "";
    }

    input.close();
    output.close();
}