// Problem: https://www.hackerrank.com/challenges/minimum-distances/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/* 
    Map structure helps us reduce the search time.
    We only keep the element's last position
*/

int minimumDistances(vector<int> a) {
    int minimumDist = -1;
    std::map<int, int> dict;
    for (int i = 0; i < a.size(); i++) {
        if (dict.find(a[i]) != dict.end()) {
            if (minimumDist == -1) {
                minimumDist = i - dict[a[i]];
                continue;
            }
            if (i - dict[a[i]] < minimumDist)
                minimumDist = i - dict[a[i]];
        } else
          dict.insert(std::pair<int, int>(a[i], i));
    }
    return minimumDist;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = minimumDistances(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
