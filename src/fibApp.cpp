#include <iostream>
#include <map>

using namespace std;

namespace fibApp
{
    // memoization
    float fib(const float n, map<float, float> &memo)
    {
        if (memo.contains(n))
            return memo[n];
        if (n <= 2)
            return 1;
        memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
        return memo[n];
    }

    int fibApp(float num)
    {
        map<float, float> memo;
        cout << std::fixed << fib(num, memo) << "\n";

        return EXIT_SUCCESS;
    }
} // namespace fibApp
