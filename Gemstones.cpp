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
    bitset<26> common;
    common.set();

    for (const auto& rock : arr)
    {
        bitset<26> current;

        for (const char c : rock)
            current.set(c - 'a');

        common &= current;
    }

    return common.count();
}


inline int popcount(uint32_t n)
{
#if defined(_MSC_VER)
    return __popcnt(n);
#elif defined(__GNUC__) || defined(__clang__)
    return __builtin_popcount(n);
#else
    int count = 0;
    while (n)
    {
        n &= (n - 1);
        ++count;
    }
    return count;
#endif
}

int gemstones2(vector<string> arr)
{
    int common = (1 << 26) - 1;

    for (const auto& rock : arr)
    {
        int mask = 0;
        for (char c : rock)
            mask |= 1 << (c - 'a');

        common &= mask;
    }

    return popcount(common);
}


int gemstones3(vector<string> arr)
{
    int gems_count = 0;
    std::map<int, int> mp;

    for (const auto& rock : arr)
    {
        std::set<int> st;
        for (char c : rock)
        {
            st.insert(c - 'a');
        }

        for (int ch : st)
        {
            mp[ch]++;
        }
    }

    for (const auto& [ch, count] : mp)
    {
        if (count == arr.size())
        {
            gems_count++;
        }
    }

    return gems_count;
}


int gemstones4(std::vector<std::string> arr) {
    int gems_count = 0;
    std::map<int, int> mp;

    for (size_t i = 0; i < arr.size(); ++i) {
        std::set<int> st;
        for (size_t j = 0; j < arr[i].length(); ++j) {
            st.insert(arr[i][j] - 'a');
        }

        for (auto it = st.begin(); it != st.end(); ++it) {
            mp[*it]++;
        }
    }

    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second == arr.size()) {
            gems_count++;
        }
    }

    return gems_count;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);
    s.erase(
        s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );
    return s;
}

string rtrim(const string &str)
{
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end()
    );
    return s;
}
