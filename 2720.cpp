#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int Quarter = 25;
    int Dime = 10;
    int Nickel = 5;
    int Penny = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ncount;
    cin >> ncount;

    vector<int> n(ncount);
    for (int i = 0; i < n.size(); i++)
    {
        cin >> n[i];
    }

    for (int len : n)
    {
        int quarter = len / Quarter;
        len -= quarter * Quarter;
        int dime = len / Dime;
        len -= dime * Dime;
        int nickel = len / Nickel;
        len -= nickel * Nickel;
        int penny = len / Penny;

        cout << quarter << " " << dime << " " << nickel << " " << penny << "\n";
    }
}