#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <sstream>

/**
 * @brief функциональный объект для вывода элемента с количеством повторений
 */
struct PrintWithCount {
    const std::multiset<int>& m;
    explicit PrintWithCount(const std::multiset<int>& ms);
    void operator()(int val) const;
};

/**
 * @brief считывает вектор из одной строки
 * @return введённый вектор
 */
std::vector<int> inputVector();

/**
 * @brief точка входа в программу
 * @return 0 при успешном завершении
 */
int main(void) {
    const std::vector<int> v = inputVector();
    const std::multiset<int> m(v.begin(), v.end());
    const std::set<int> s(v.begin(), v.end());
    std::for_each(s.begin(), s.end(), PrintWithCount(m));
    std::cout << '\n';
    return 0;
}

std::vector<int> inputVector() {
    std::cout << "Введите элементы вектора (в одну строку): ";
    std::string line = "";
    std::getline(std::cin, line);
    std::istringstream ss(line);
    return std::vector<int>(
        std::istream_iterator<int>(ss),
        std::istream_iterator<int>()
    );
}

PrintWithCount::PrintWithCount(const std::multiset<int>& ms) : m(ms) {}

void PrintWithCount::operator()(int val) const {
    std::cout << val << "(" << m.count(val) << ") ";
}