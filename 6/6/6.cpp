#include <iostream>
#include <fstream>

using namespace std;

bool prime(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i < n - 1; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }return true;

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
    for (int i = 2; i < n; ++i)
    {
        int a = n - i;
        if (prime(i) && prime(a))
        {
            output << i << " " << a;
            break;
        }
    }
}

