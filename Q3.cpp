#include <iostream>
using namespace std;

int length(char s[]) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

void buildBadChar(int badChar[], char pat[], int m) {
    for (int i = 0; i < 256; i++)
        badChar[i] = -1;

    for (int i = 0; i < m; i++)
        badChar[(int)pat[i]] = i;
}

void buildGoodSuffix(int goodSuffix[], int borderPos[], char pat[], int m) {
    int i = m, j = m + 1;

    borderPos[i] = j;

    while (i > 0) {
        while (j <= m && pat[i - 1] != pat[j - 1]) {
            if (goodSuffix[j] == 0)
                goodSuffix[j] = j - i;
            j = borderPos[j];
        }
        i--;
        j--;
        borderPos[i] = j;
    }

    j = borderPos[0];

    for (i = 0; i <= m; i++) {
        if (goodSuffix[i] == 0)
            goodSuffix[i] = j;
        if (i == j)
            j = borderPos[j];
    }
}

void boyerMoore(char text[], char pat[]) {
    int n = length(text);
    int m = length(pat);

    int badChar[256];
    buildBadChar(badChar, pat, m);

    int borderPos[500];
    int goodSuffix[500];
    for (int i = 0; i <= m; i++)
        goodSuffix[i] = 0;

    buildGoodSuffix(goodSuffix, borderPos, pat, m);

    cout << "[";

    bool first = true;
    int s = 0;

    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pat[j] == text[s + j])
            j--;

        if (j < 0) {
            if (!first) cout << ", ";
            cout << s;
            first = false;

            s += goodSuffix[0];
        } else {
            int bcShift = j - badChar[(int)text[s + j]];
            int gsShift = goodSuffix[j + 1];
            s += (bcShift > gsShift ? bcShift : gsShift);
        }
    }

    cout << "]" << endl;
}

int main() {
    char DNA[200] = "ACGTACGTGACG";
    char pattern[50] = "ACG";

    boyerMoore(DNA, pattern);

    return 0;
}
