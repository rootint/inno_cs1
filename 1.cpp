#include <iostream>
#include <vector>

float avg(std::vector<int> array) {
    int n = array.size();
    int sum = 0;
    for (int element : array) {
        sum += element;
    }
    return (float) sum / n;
}

int main(void) {
    int n;
    std::cin >> n;
    std::vector<int> array(n); //pre-allocating memory makes things faster
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    return 0;
}