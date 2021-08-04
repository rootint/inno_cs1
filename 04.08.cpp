#include <iostream>
#include <vector>
#include <set>

int calculate_length(std::vector<std::vector<int>> adj_matrix, std::vector<int> path) {
    int current_city = path[0];
    int len = 0;
    for (int i = 1; i < path.size(); i++) {
        int next_city = path[i];
        len += adj_matrix[current_city][next_city];
        current_city = next_city;
    }
    return len;
}

bool all_unique(const std::vector<int>& path) {
    std::set<int> check_uniqueness(path.begin(), path.end());
    return check_uniqueness.size() == path.size();
}

int main(void) {
    int n;
    std::cout << "Enter a number of cities (4, 5, 6):";
    std::cin >> n;
    if (n != 4 && n != 5 && n != 6) {
        std::cout << "Wrong input!" << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i] = std::vector<int>(n);
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
            if (matrix[i][j] < 0) {
                std::cout << "Wrong input!" << std::endl;
                return 0;
            }
        }
    }

    int shortest_path = 9999999;
    
    for (int c1 = 1; c1 < n; c1++) {
        for (int c2 = 1; c2 < n; c2++) {
            for (int c3 = 1; c3 < n; c3++) {
                switch (n) {
                    case 4: {
                        std::vector<int> path = {0, c1, c2, c3};
                        if (all_unique(path)) {
                            path.push_back(0);
                            int path_len = calculate_length(matrix, path);
                            if (path_len < shortest_path) {
                                shortest_path = path_len;
                            }
                        }
                    }
                    break;

                    case 5: {
                        for (int c4 = 1; c4 < n; c4++) {
                            std::vector<int> path = {0, c1, c2, c3, c4};
                            if (all_unique(path)) {
                                path.push_back(0);
                                int path_len = calculate_length(matrix, path);
                                if (path_len < shortest_path) {
                                    shortest_path = path_len;
                                }
                            }
                        }
                    }
                    break;

                    case 6: {
                        for (int c4 = 1; c4 < n; c4++) {
                            for (int c5 = 1; c5 < n; c5++) {
                                std::vector<int> path = {0, c1, c2, c3, c4, c5};
                                if (all_unique(path)) {
                                    path.push_back(0);
                                    int path_len = calculate_length(matrix, path);
                                    if (path_len < shortest_path) {
                                        shortest_path = path_len;
                                    }
                                }
                            }
                        }
                    }
                    break;
                }   
            }   
        }
    }   
    std::cout << shortest_path << std::endl;
    return 0;
}