#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

/**
 * @brief считывает вектор из одной строки
 * @param message сообщение перед вводом
 * @return введённый вектор
 */
std::vector<int> inputVector(const std::string& message);

/**
 * @brief вставляет -1 после каждого элемента вектора
 * @param v исходный вектор
 * @return изменённый вектор
 */
std::vector<int> insertMinusOne(std::vector<int> v);

/**
 * @brief выводит элементы вектора через пробел
 * @param v вектор для вывода
 */
void printVector(const std::vector<int>& v);

/**
 * @brief точка входа в программу
 * @return 0 при успешном завершении
 */
int main(void) {
    const std::vector<int> v = inputVector("Введите элементы вектора (в одну строку): ");
    std::cout << "До преобразований: ";
    printVector(v);

    const std::vector<int> result = insertMinusOne(v);
    std::cout << "После преобразований: ";
    printVector(result);

    return 0;
}

std::vector<int> inputVector(const std::string& message) {
    std::cout << message;
    std::string line = "";
    std::getline(std::cin, line);
    std::istringstream ss(line);
    return std::vector<int>(
        std::istream_iterator<int>(ss),
        std::istream_iterator<int>()
    );
}

std::vector<int> insertMinusOne(std::vector<int> v) {
    auto it = v.begin();
    while (it != v.end()) {
        ++it;
        it = v.insert(it, -1);
        ++it;
    }
    return v;
}

void printVector(const std::vector<int>& v) {
    std::copy(v.begin(), v.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}