#include <iostream>
#include <string>
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

    int n;
    input >> n;
    string s = "2";

    for (int i = 1; i < n; i++) 
    {
        string r = "";
        int temp = 0;
        for (int i = s.size() - 1; i >= 0; i--) 
        {
            int t = (int(s[i]) - 48) * 2 + temp;
            temp = 0;
            if (t >= 10)
                temp = 1;
            r.insert(0, 1, char(t % 10 + 48));
        }
        if (temp)
            r.insert(0, 1, char(temp + 48));
        s = r;
    }

    output << s;

    input.close();
    output.close();
}
