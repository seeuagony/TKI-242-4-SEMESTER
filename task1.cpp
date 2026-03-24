#include <iostream>
#include <iterator>
#include <algorithm>

double nextElement(double& current, double D, bool& first);

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
    bool first = true;
    std::generate_n(std::ostream_iterator<double>(std::cout, " "), N,
        [&current, &first, D]() {
            return nextElement(current, D, first);
        });
    std::cout << std::endl;
    return 0;
}

double nextElement(double& current, double D, bool& first) {
    if (first) { first = false; return current; }
    return current += D;
}
