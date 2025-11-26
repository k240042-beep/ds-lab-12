#include <iostream>
using namespace std;

int length(char s[]) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

void copystr(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void rabinKarp(char text[], char pattern[]) {
    int n = length(text);
    int m = length(pattern);

    int prime = 101;
    int d = 256;

    int patHash = 0;
    int txtHash = 0;
    int h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % prime;

    for (int i = 0; i < m; i++) {
        patHash = (d * patHash + pattern[i]) % prime;
        txtHash = (d * txtHash + text[i]) % prime;
    }

    cout << "[";
    bool first = true;

    char window[500];

    for (int i = 0; i <= n - m; i++) {

        if (patHash == txtHash) {
            bool match = true;

            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                if (!first) cout << ", ";
                cout << i;
                first = false;
            }
            else {
                cout << "\nFalse-positive collision at index " << i << endl;
            }
        }

        if (i < n - m) {
            txtHash = (d * (txtHash - text[i] * h) + text[i + 1 + m - 1]) % prime;
            if (txtHash < 0) txtHash += prime;
        }
    }

    cout << "]" << endl;
}

int main() {

    char text[300] =
        "Data structures and algorithms are fun. Algorithms make tasks easier.";

    char pattern[50] = "Algorithms";

    rabinKarp(text, pattern);

    return 0;
}
