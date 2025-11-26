#include <iostream>
using namespace std;

int length(char s[]) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

void computeLPS(char pattern[], int m, int lps[]) {
    int len = 0;
    lps[0] = 0;

    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPsearch(char text[], char pattern[]) {
    int n = length(text);
    int m = length(pattern);

    int lps[500];
    computeLPS(pattern, m, lps);

    cout << "LPS Array: [";
    for (int i = 0; i < m; i++) {
        cout << lps[i];
        if (i != m - 1) cout << ", ";
    }
    cout << "]" << endl;

    int i = 0;
    int j = 0;

    cout << "[";

    bool first = true;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            if (!first) cout << ", ";
            cout << (i - j);
            first = false;

            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    cout << "]" << endl;
}

int main() {
    char text[200] = "ababababc";
    char pattern[50] = "abab";

    KMPsearch(text, pattern);

    return 0;
}
