#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace canSumApp
{
    bool canSum(const long targetSum, const vector<long> &numbers, map<long, bool> &memo)
    {
        if (targetSum == 0)
            return true;
        if (targetSum < 0)
            return false;
        if (memo.contains(targetSum))
            return memo[targetSum];

        for (auto &&item : numbers)
        {
            const long remainder = targetSum - item;
            if (canSum(remainder, numbers, memo) == true)
            {
                memo[targetSum] = true;
                return true;
            }
        }
        memo[targetSum] = false;
        return false;
    }

    int canSumApp()
    {
        auto memo = map<long, bool>{};
        cout << canSum(7, vector<long>{2, 3}, memo) << "\n";

        memo = map<long, bool>{};
        cout << canSum(7, vector<long>{5, 3, 4, 7}, memo) << "\n";

        memo = map<long, bool>{};
        cout << canSum(7, vector<long>{2, 4}, memo) << "\n";

        memo = map<long, bool>{};
        cout << canSum(8, vector<long>{2, 3, 5}, memo) << "\n";

        memo = map<long, bool>{};
        cout << canSum(300, vector<long>{7, 14}, memo) << "\n";
        return EXIT_SUCCESS;
    }
} // namespace canSumApp
