#include <iostream>
#include <vector>
#include <memory>
#include <map>

using namespace std;

namespace bestSumApp
{
    unique_ptr<vector<long>> &bestSum(long targetSum, const vector<long> &numbers, map<long, unique_ptr<vector<long>>> &memo)
    {
        if (memo.contains(targetSum)) return memo[targetSum];
        if (targetSum == 0)
        {
            memo[targetSum] = make_unique<vector<long>>();
            memo[targetSum].reset(new vector<long>(0));
            return memo[targetSum];
        }
        if (targetSum < 0)
        {
            memo[targetSum] = make_unique<vector<long>>();
            memo[targetSum].reset();
            return memo[targetSum];
        }
        vector<long>* shortestCombination = NULL;

        for (auto &&item : numbers)
        {
            const auto remainder = targetSum - item;
            const auto &remainderCombination = bestSum(remainder, numbers, memo);
            if (remainderCombination)
            {
                const auto combination = new vector<long>(*remainderCombination);
                combination->insert(combination->end(), item);
                if (!shortestCombination || combination->size() < shortestCombination->size())
                    shortestCombination = combination;
            }
        }
        memo[targetSum] = make_unique<vector<long>>();
        memo[targetSum].reset(shortestCombination);
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

    int bestSumApp()
    {
        auto memo = map<long, unique_ptr<vector<long>>>{};
        wcout << dumpVector(bestSum(7, vector<long>{5, 3, 4, 7}, memo)) << L"\n";

        memo = map<long, unique_ptr<vector<long>>>{};
        wcout << dumpVector(bestSum(8, vector<long>{2, 3, 5}, memo)) << L"\n";

        memo = map<long, unique_ptr<vector<long>>>{};
        wcout << dumpVector(bestSum(8, vector<long>{1, 4, 5}, memo)) << L"\n";

        memo = map<long, unique_ptr<vector<long>>>{};
        wcout << dumpVector(bestSum(100, vector<long>{1, 2, 5, 25}, memo)) << L"\n";

        return EXIT_SUCCESS;
    }
} // namespace bestSumApp
