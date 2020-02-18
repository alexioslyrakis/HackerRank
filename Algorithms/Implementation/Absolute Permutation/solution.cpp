/*
  Problem: https://www.hackerrank.com/challenges/absolute-permutation/problem
  Time Complexity: O(n)
  Space Complexity: O(n) // that is the vector we'd like to return from our function
  
*/


/*
    - If (k == 0) then we just have as a permutation the normal sequence from 1 to n
    - Else if (n % (2 * k)) != 0) the problem does not have a solution. It can be
                                    proved by contradiction
    - Else first push k numbers equal to i + k and each time (i % k == 0) change k = -k
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the absolutePermutation function below.
vector<int> absolutePermutation(int n, int k) {
    int pos = 1, currentNumber = k + 1, remainingNumbers = n;
    vector<int> permutation;
    int temp = k;

    if (k == 0) {
        for (int i = 1; i <= n; i++) {
            permutation.push_back(i);
        }
    }else if ((n % (2 * k)) == 0) {
        for (int i = 1; i <= n; i++) {
            permutation.push_back(i + temp);
            if (i % k == 0) {
                temp *= -1;
            }
        }
    } else {
        return vector<int> {-1};
    }
    return permutation;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);

        vector<int> result = absolutePermutation(n, k);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
