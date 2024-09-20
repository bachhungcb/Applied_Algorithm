#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        cin >> result[i];
    }

    // Sort the vector to use lower_bound correctly (assumption: vector should be sorted)
    sort(result.begin(), result.end());

    int q;
    cin >> q;
    int temp;

    for (int i = 0; i < q; i++) {
        cin >> temp;
        // Use lower_bound to get the position where temp would be inserted
        auto position = lower_bound(result.begin(), result.end(), temp);

        // If the element exists at that position, print "Yes" and its 1-based index
        if (position != result.end() && *position == temp) {
            cout << "Yes " << (position - result.begin() + 1) << endl;
        }
        // Otherwise, print "No" and the 1-based index where temp would be inserted
        else {
            cout << "No " << (position - result.begin() + 1) << endl;
        }
    }

    return 0;
}
