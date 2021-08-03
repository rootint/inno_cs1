#include <iostream>
#include <cmath>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::string f = "wtf";
    std::cout << f << std::endl;
    do {
        std::cout << "Enter the number: ";
        std::cin >> n;  
    } while (n < 0);
    std::cout << ((is_prime(n)) ? "Prime" : "Not Prime") << std::endl;
    return 0;
}