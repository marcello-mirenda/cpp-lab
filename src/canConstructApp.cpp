#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

namespace canConstructApp
{
    const bool canConstruct(const wstring target, const vector<wstring> wordBank, map<wstring, bool> &memo)
    {
        if (memo.contains(target))
        {
            return memo[target];
        }
        if (target.size() == 0)
        {
            return true;
        }

        for (auto &&word : wordBank)
        {
            if (target.find(word) == 0)
            {
                const auto suffix = target.substr(word.size());
                if (canConstruct(suffix, wordBank, memo) == true)
                {
                    memo[target] = true;
                    return true;
                }
            }
        }

        memo[target] = false;
        return false;
    }

    int canConstructApp()
    {
        // auto memo = map<wstring, bool>{};
        // wcout << canConstruct(L"abcdef", vector<wstring>{L"ab", L"abc", L"cd", L"def", L"abcd"}, memo) << L"\n";

        // memo = map<wstring, bool>{};
        // wcout << canConstruct(L"skateboard", vector<wstring>{L"bo", L"rd", L"ate", L"t", L"ska", L"sk", L"boar"}, memo) << L"\n";

        // memo = map<wstring, bool>{};
        // wcout << canConstruct(L"enterapotentpot", vector<wstring>{L"a", L"p", L"ent", L"enter", L"ot", L"o", L"t"}, memo) << L"\n";

        auto memo = map<wstring, bool>{};
        wcout << canConstruct(
                     L"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                     vector<wstring>{
                         L"e", L"ee", L"eeeeeee", L"eee", L"eeee", L"eeeee", L"eeeeee"},
                     memo)
              << L"\n";

        return EXIT_SUCCESS;
    }

} // namespace canConstructApp