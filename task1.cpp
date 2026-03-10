#include <iostream>
#include <iterator>
#include <algorithm>

int main() {
    double A, D;
    int N;

    std::cout << "Введите первый элемент A: ";
    std::cin >> A;
    std::cout << "Введите разность D: ";
    std::cin >> D;
    std::cout << "Введите количество членов N: ";
    std::cin >> N;

    std::cout << "Арифметическая прогрессия: ";
    double current = A;
    std::generate_n(std::ostream_iterator<double>(std::cout, " "), N,
        [&current, D, first = true]() mutable {
            if (first) { first = false; return current; }
            return current += D;
        });
    std::cout << std::endl;

    return 0;
}