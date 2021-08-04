#include <iostream>
#include <vector>
#include <set>

int main(void) {
    int n, num;
    std::cin >> n;
    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    std::set<int> v_set(array.begin(), array.end());

    std::cout << ((n == v_set.size()) ? "Unique" : "Not Unique") << std::endl;

    return 0;
}