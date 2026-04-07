#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

/**
 * @brief функция для ввода вещественного числа пользователем
 * @param message сообщение перед вводом
 * @return введённое значение
 */
double input_double(const std::string& message);

/**
 * @brief функция для ввода целого числа пользователем
 * @param message сообщение перед вводом
 * @return введённое значение
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
 * @param result вектор для вывода
 */
void print_result(const std::vector<double>& result);

/**
 * @brief точка входа в программу
 * @return 0 при успешном завершении
 */
int main(void) {
    const double a = input_double("Введите a: ");
    const double d = input_double("Введите d: ");
    const int n = input_int("Введите n: ");

    const std::vector<double> result = generate_progression(a, d, n);
    print_result(result);

    return 0;
}

double input_double(const std::string& message) {
    std::cout << message;
    double value = 0.0;
    std::cin >> value;
    return value;
}

int input_int(const std::string& message) {
    std::cout << message;
    int value = 0;
    std::cin >> value;
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

void print_result(const std::vector<double>& result) {
    std::copy(
        result.begin(),
        result.end(),
        std::ostream_iterator<double>(std::cout, " ")
    );
    std::cout << std::endl;
}