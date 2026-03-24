#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

double nextElement(std::vector<double>& state, double d);

int main() {
    double a = 0.0, d = 0.0;
    int n = 0;
    std::cout << "Введите первый элемент A: ";
    std::cin >> a;
    std::cout << "Введите разность D: ";
    std::cin >> d;
    std::cout << "Введите количество членов N: ";
    std::cin >> n;
    std::cout << "Арифметическая прогрессия: ";
    std::vector<double> state = {a, 1.0};
    std::generate_n(std::ostream_iterator<double>(std::cout, " "), n,
        [&state, d]() {
            return nextElement(state, d);
        });
    std::cout << std::endl;
    return 0;
}

double nextElement(std::vector<double>& state, double d) {
    if (state[1] == 1.0) { state[1] = 0.0; return state[0]; }
    return state[0] += d;
}
