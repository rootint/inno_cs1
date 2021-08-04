#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>

// std::vector<int> new_vec(vec.begin(), vec.begin() + n_elements); // copying the vector
// std::sort(array.begin(), array.end());

// MERGE SORT

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

    while (idxl < left.size()) {
        merged.push_back(left[idxl]);
        idxl++;
    }

    while (idxr < right.size()) {
        merged.push_back(right[idxr]);
        idxr++;
    }
    return merged;
}

std::vector<int> merge_sort(std::vector<int> array) {
    if (array.size() <= 1) {
        return array;
    }
    int mid = array.size() / 2;
    std::vector<int> left(array.begin(), array.begin() + mid);
    std::vector<int> right(array.begin() + mid, array.end());
    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
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
    // std::vector<int> a = merge()
    array = merge_sort(array);

    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << std::endl;
    return 0;
}