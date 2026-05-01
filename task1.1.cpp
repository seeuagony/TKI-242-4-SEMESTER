#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>

/**
 * @brief считывает одно вещественное число
 * @param message сообщение перед вводом
 * @return введённое число
 */
double input_double(const std::string& message);

/**
 * @brief считывает одно целое число
 * @param message сообщение перед вводом
 * @return введённое число
 */
int input_int(const std::string& message);

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
 * @param v вектор для вывода
 */
void print_vector(const std::vector<double>& v);

/**
 * @brief точка входа в программу
 * @return 0 при успешном завершении
 */
int main(void) {
    const double a = input_double("Введите первый элемент прогрессии a: ");
    const double d = input_double("Введите разность прогрессии d: ");
    const int n = input_int("Введите количество элементов n: ");
    const std::vector<double> result = generate_progression(a, d, n);
    print_vector(result);
    return 0;
}

double input_double(const std::string& message) {
    std::cout << message;
    std::string line = "";
    std::getline(std::cin, line);
    std::istringstream ss(line);
    double value = 0.0;
    ss >> value;
    return value;
}

int input_int(const std::string& message) {
    std::cout << message;
    std::string line = "";
    std::getline(std::cin, line);
    std::istringstream ss(line);
    int value = 0;
    ss >> value;
    return value;
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

void print_vector(const std::vector<double>& v) {
    std::copy(v.begin(), v.end(),
              std::ostream_iterator<double>(std::cout, " "));
    std::cout << '\n';
}