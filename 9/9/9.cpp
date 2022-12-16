#include <iostream>
#include <vector>
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

    int n, a, s = 0;
    input >> n;
    bool b = 0;
    vector <int> arr(n);
    for (int i = 0; i < n; ++i)
        input >> arr[i];

    for (int i = 0; i < n; ++i) 
    {
        b = 0;
        for (int j = i + 1; j < n; ++j)
            if (arr[i] == arr[j]) {
                a = j;
                b = 1;
                break;
            }
        if (b)
            if (a - i > s)
                s = a - i;
    }
    output << s;

    input.close();
    output.close();
}
