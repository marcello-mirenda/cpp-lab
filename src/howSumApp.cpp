#include <iostream>
#include <vector>
#include <memory>
#include <map>

using namespace std;

namespace howSumApp
{
    unique_ptr<vector<long>> &howSum(long targetSum, const vector<long> &numbers, map<long, unique_ptr<vector<long>>> &memo)
    {
        if (targetSum < 0)
            targetSum = -1;
        if (memo.contains(targetSum))
            return memo[targetSum];
        if (targetSum == 0)
        {
            memo[targetSum] = unique_ptr<vector<long>>(new vector<long>(0));
            return memo[targetSum];
        }
        if (targetSum < 0)
        {
            memo[targetSum] = make_unique<vector<long>>();
            memo[targetSum].reset();
            return memo[targetSum];
        }

        for (auto &&item : numbers)
        {
            const auto remainder = targetSum - item;
            auto &remainderResult = howSum(remainder, numbers, memo);
            if (remainderResult != nullptr)
            {
                const auto newVec = new vector<long>(*remainderResult);
                newVec->insert(newVec->end(), item);
                memo[targetSum] = unique_ptr<vector<long>>(newVec);
                return memo[targetSum];
            }
        }

        memo[targetSum] = make_unique<vector<long>>();
        memo[targetSum].reset();
        return memo[targetSum];
    }

    wstring dumpVector(unique_ptr<vector<long>> &vec)
    {
        if (!vec)
        {
            return L"null";
        }
        wstring res = L"[";
        vector<long>::iterator i;
        for (i = vec->begin(); i != vec->end() - 1; ++i)
        {
            res.append(to_wstring(*i));
            res.append(L",");
        }
        res.append(to_wstring(*(i)));
        res.append(L"]");
        return res;
    }

    int howSumApp()
    {
        auto memo = map<long, unique_ptr<vector<long>>>{};
        wcout << dumpVector(howSum(7, vector<long>{2, 3}, memo)) << L"\n";

        memo = map<long, unique_ptr<vector<long>>>{};
        wcout << dumpVector(howSum(7, vector<long>{5, 3, 4, 7}, memo)) << L"\n";

        memo = map<long, unique_ptr<vector<long>>>{};
        wcout << dumpVector(howSum(7, vector<long>{2, 4}, memo)) << L"\n";

        memo = map<long, unique_ptr<vector<long>>>{};
        wcout << dumpVector(howSum(8, vector<long>{2, 3, 5}, memo)) << L"\n";

        memo = map<long, unique_ptr<vector<long>>>{};
        wcout << dumpVector(howSum(300, vector<long>{7, 14}, memo)) << L"\n";

        return EXIT_SUCCESS;
    }
} // namespace howSumApp
