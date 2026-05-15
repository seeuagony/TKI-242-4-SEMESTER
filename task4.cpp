#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
struct point {
    int x, y;
    std::string s;
    /**
     * @brief Сравнивает два объекта point.
     * @param other Объект для сравнения с текущим.
     * @return true, если текущий объект больше other; false иначе.
     */
    bool operator>(const point& other) const {
        if (x != other.x) return x > other.x;
        return y > other.y;
    }
    /**
     * @brief Умножает координаты точки на число.
     * @param k Множитель.
     * @return Новый объект point с координатами k*x, k*y и той же строкой s.
     */
    point mult(int k) const {
        return point{k * x, k * y, s};
    }
};
/**
 * @brief Считывает объект point из входного потока.
 * @param is Входной поток.
 * @param p Объект point, в который записываются данные.
 * @return Ссылка на входной поток.
 */
std::istream& operator>>(std::istream& is, point& p) {
    return is >> p.x >> p.y >> p.s;
}
/**
 * @brief Записывает объект point в выходной поток.
 * @param os Выходной поток.
 * @param p Объект point, данные которого записываются.
 * @return Ссылка на выходной поток.
 */
std::ostream& operator<<(std::ostream& os, const point& p) {
    return os << p.x << ' ' << p.y << ' ' << p.s;
}
/**
 * @brief Складывает две точки покомпонентно.
 * @param a Левый операнд (от него берётся строка s).
 * @param b Правый операнд.
 * @return Точка с координатами a.x+b.x, a.y+b.y и строкой a.s.
 */
point operator+(const point& a, const point& b) {
    return point{a.x + b.x, a.y + b.y, a.s};
}
int main() {
    const int K = 3;
    const std::string name1 = "name1.txt";
    const std::string name2 = "name2.txt";
    std::ifstream file1(name1);
    std::vector<point> V1(
        (std::istream_iterator<point>(file1)),
        std::istream_iterator<point>()
    );
    file1.close();
    std::ifstream file2(name2);
    std::vector<point> V2(
        (std::istream_iterator<point>(file2)),
        std::istream_iterator<point>()
    );
    file2.close();
    using namespace std::placeholders;
    std::transform(V1.begin(), V1.end(), V2.begin(), V1.begin(),
        std::bind(std::plus<point>(),
                  std::bind(&point::mult, _1, K),
                  _2)
    );
    std::copy(
        V1.begin(), V1.end(),
        std::ostream_iterator<point>(std::cout, "\n")
    );
    return 0;
}