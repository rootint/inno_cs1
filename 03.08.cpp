#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>

// std::vector<int> new_vec(vec.begin(), vec.begin() + n_elements);
// std::sort(array.begin(), array.end());

std::vector<int> bubble_sort(std::vector<int>& array) { // & saves time as it uses the same array
    int n = array.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j])
                std::swap(array[i], array[j]);
        }
    }
    return array;
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

    array = bubble_sort(array);

    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << std::endl;
    return 0;
}