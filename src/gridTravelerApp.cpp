#include <iostream>
#include <map>

using namespace std;

namespace gridTravelerApp
{
    long gridTraveler(const long m, const long n, map<wstring,long>& memo)
    {
        const wstring key = to_wstring(m) + L"," + to_wstring(n);
        if (memo.contains(key)) return memo[key];
        if (m == 1 && n == 1)
            return 1;
        if (m == 0 || n == 0)
            return 0;
        memo[key] = gridTraveler(m - 1, n, memo) + gridTraveler(m, n - 1, memo);
        return memo[key];
    }

    int gridTravelerApp()
    {
        map<wstring,long> memo;
        cout << gridTraveler(1, 1, memo) << "\n";
        cout << gridTraveler(2, 3, memo) << "\n";
        cout << gridTraveler(3, 2, memo) << "\n";
        cout << gridTraveler(3, 3, memo) << "\n";
        cout << gridTraveler(18, 18, memo) << "\n";
        return EXIT_SUCCESS;
    }
} // namespace gridTraveverlApp
