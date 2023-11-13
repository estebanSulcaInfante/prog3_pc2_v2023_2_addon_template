#include <iostream>
#include <iomanip>
#include "find_max_product.h"
int main() {
    // Caso de uso #1
    std::vector<int> v {-1000, -1, 2, 3, 4, 150, -900, 100};
    auto result = find_max_product(v);
    std::cout << result << std::endl; // Salida esperada: 900000

    // Caso de uso #2
    std::deque<double> d {1500, -1, 2, 3, 4, -100, 10, -900, 100};
    auto result2 = find_max_product(d);
    std::cout << std::fixed << std::setprecision(2) << result2 << std::endl; // Salida esperada: 150000
}