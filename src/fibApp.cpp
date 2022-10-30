#include <iostream>
#include <map>

using namespace std;

namespace fibApp
{
    // memoization
    long fib(long n, map<long, long> &memo)
    {
        if (memo.contains(n))
            return memo[n];
        if (n <= 2)
            return 1;

        memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
        return memo[n];
    }

    int fibApp()
    {
        map<long, long> memo;
        // cout << fib(6, memo) << "\n";
        // cout << fib(7, memo) << "\n";
        // cout << fib(8, memo) << "\n";
        cout << fib(50, memo) << "\n";
        return EXIT_SUCCESS;
    }
} // namespace fibApp
