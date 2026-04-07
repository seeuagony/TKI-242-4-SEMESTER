#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>

/**
 * @brief считывает a, d, n из одной строки
 * @param a первый элемент прогрессии
 * @param d разность прогрессии
 * @param n количество элементов
 */
void input_params(double& a, double& d, int& n);

/**
 * @brief генерирует вектор с членами арифметической прогрессии
 * @param a первый элемент
 * @param d разность прогрессии
 * @param n количество элементов
 * @return вектор с n членами прогрессии
 */
std::vector<double> generate_progression(double a, double d, int n);

/**
 * @brief выводит элементы вектора через пробел
 * @param result вектор для вывода
 */
void print_result(const std::vector<double>& result);

/**
 * @brief точка входа в программу
 * @return 0 при успешном завершении
 */
int main(void) {
    double a = 0.0, d = 0.0;
    int n = 0;
    input_params(a, d, n);

    const std::vector<double> result = generate_progression(a, d, n);
    print_result(result);

    return 0;
}

void input_params(double& a, double& d, int& n) {
    std::cout << "Введите a, d, n: ";
    std::string line = "";
    std::getline(std::cin, line);
    std::istringstream ss(line);
    ss >> a >> d >> n;
}

std::vector<double> generate_progression(double a, double d, int n) {
    std::vector<double> result(n);
    std::generate_n(
        result.begin(),
        n,
        [a, d, i = 0]() mutable {
            return a + d * i++;
        }
    );
    return result;
}

void print_result(const std::vector<double>& result) {
    std::copy(
        result.begin(),
        result.end(),
        std::ostream_iterator<double>(std::cout, " ")
    );
    std::cout << std::endl;
}