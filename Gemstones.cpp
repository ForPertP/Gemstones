#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gemstones' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY arr as parameter.
 */

int gemstones(vector<string> arr)
{
    int gems_count = 0;
    std::map<int, int> mp;

    for (const auto& rock : arr)
    {
        std::set<int> st;

        for (size_t i = 0; i < rock.size(); ++i)
        {
            st.insert(rock[i] - 'a');
        }

        for (auto itr = st.cbegin(); itr != st.cend(); ++itr)
        {
            mp[*itr]++;
        }
    }

    for (auto itr = mp.cbegin(); itr != mp.cend(); ++itr)
    {
        if (itr->second == arr.size())
        {
            gems_count++;
        }
    }

    return gems_count;
}
