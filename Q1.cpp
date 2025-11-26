#include <iostream>
using namespace std;

int length(char s[]) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

void bruteForceSearch(char text[], char pattern[]) {
    int n = length(text);
    int m = length(pattern);

    int comparisons = 0;

    cout << "[";

    bool first = true;
    for (int i = 0; i <= n - m; i++) {

        bool match = true;
        for (int j = 0; j < m; j++) {
            comparisons++;
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
    }

    cout << "]" << endl;
    cout << "Total Comparisons: " << comparisons << endl;
}

int main() {
    char text[200] = "the quick brown fox jumps over the lazy dog";
    char pattern[50] = "the";

    bruteForceSearch(text, pattern);

    return 0;
}
