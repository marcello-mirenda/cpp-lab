#include <iostream>
#include <map>

using namespace std;

namespace fibApp
{
    // memoization
    long fib(const long n, map<long, long> &memo)
    {
        if (memo.contains(n))
            return memo[n];
        if (n <= 2)
            return 1;
        memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
        return memo[n];
    }

    int fibApp(int num)
    {
        map<long, long> memo;
        cout << fib(num, memo) << "\n";

        return EXIT_SUCCESS;
    }
} // namespace fibApp
