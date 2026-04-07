#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

/**
 * @brief функциональный объект для вывода элемента с количеством повторений
 */
struct PrintWithCount {
    const std::multiset<int>& m;
    explicit PrintWithCount(const std::multiset<int>& ms);
    void operator()(int val) const;
};

/**
 * @brief считывает вектор из потока ввода
 * @return введённый вектор
 */
std::vector<int> input_vector();

/**
 * @brief точка входа в программу
 * @return 0 при успешном завершении
 */
int main(void) {
    const std::vector<int> v = input_vector();

    const std::multiset<int> m(v.begin(), v.end());
    const std::set<int> s(v.begin(), v.end());

    std::for_each(s.begin(), s.end(), PrintWithCount(m));
    std::cout << '\n';

    return 0;
}

std::vector<int> input_vector() {
    std::cout << "Введите элементы вектора: ";
    return std::vector<int>(
        std::istream_iterator<int>(std::cin),
        std::istream_iterator<int>()
    );
}

PrintWithCount::PrintWithCount(const std::multiset<int>& ms) : m(ms) {}

void PrintWithCount::operator()(int val) const {
    std::cout << val << "(" << m.count(val) << ") ";
}