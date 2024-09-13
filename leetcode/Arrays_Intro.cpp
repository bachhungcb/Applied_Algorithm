#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    // Create a 2D vector to store n arrays
    std::vector<std::vector<int>> arr(n);

    // Input the arrays
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        arr[i].resize(k);  // Resize the current vector to size k
        for (int j = 0; j < k; j++) {
            std::cin >> arr[i][j];  // Input elements of the ith array
        }
    }

    // Process each query
    for (int qIndex = 0; qIndex < q; qIndex++) {
        int i, j;
        std::cin >> i >> j;
        std::cout << arr[i][j] << std::endl;  // Output the required element
    }

    return 0;
}
