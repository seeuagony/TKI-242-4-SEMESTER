#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<int> insertMinusOdin(std::vector<int> v) {
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

int main() {
    std::vector<int> v = {3, 7, 1, 9, 4};
    std::cout << "До преобразований:  ";
    printVector(v);
    auto result = insertMinusOdin(v);
    std::cout << "После преобразований  : ";
    printVector(result);

    return 0;
}