#include <iostream>
#include <set>
#include <fstream>

using namespace std;

int check(int a, int q)
{
    int b = 0, c = a;
    while (c)
    {
        b = b * q + c % q;
        c /= q;
    }
    if (a == b)
        return q;
    else
        return 0;
}

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
    set <int> k;
    k.clear();

    for (int i = 2; i < 37; i++)
        k.insert(check(n, i));
    
    if (k.size() == 1)
        output << "none";

    if (k.size() == 2)
    {
        output << "unique" << endl;
        for (auto i : k)
        {
            if (i != 0)
                output << i << " ";
        }
    }

    if (k.size() != 1 && k.size() != 2)
    {
        output << "multiple" << endl;
        for (auto i : k)
        {
            if (i != 0)
                output << i << " ";
        }
    }

    input.close();
    output.close();
}