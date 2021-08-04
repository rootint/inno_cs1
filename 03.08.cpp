#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>

// std::vector<int> new_vec(vec.begin(), vec.begin() + n_elements);
// std::sort(array.begin(), array.end());

std::vector<int> merge(std::vector<int> left, std::vector<int> right) {
    std::vector<int> merged;
    int idxl, idxr;
    idxl = idxr = 0;
    while (idxl < left.size() && idxr < right.size()) {
        if (left[idxl] < right[idxr]) {
            merged.push_back(left[idxl]);
            idxl++;
        } else {
            merged.push_back(right[idxr]);
            idxr++;
        }
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    int n;
    std::cout << "Sort an array in ascending order:" << std::endl;
    do {
        std::cout << "Enter the correct number of elements (more than 0): ";
        std::cin >> n;  
    } while (n < 0);
    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    // ?
    merge_sort(array, 0, array.size() - 1);

    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << std::endl;
    return 0;
}