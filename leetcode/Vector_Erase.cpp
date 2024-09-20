#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<long long int> result(n);
    for (int i = 0; i < n; i++)
    {
        cin >> result[i];
    }

    int x;
    cin >> x;
    result.erase(result.begin() + x - 1);

    int start, end;
    cin >> start >> end;
    result.erase(result.begin() + start - 1, result.begin() + end - 1);

    cout << result.size() << endl;
    for (long long int num : result)
    {
        cout << num << " ";
    }
    return 0;
}
