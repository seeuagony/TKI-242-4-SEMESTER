#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <vector>

double nextElement(std::vector<double>& state, double d);

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