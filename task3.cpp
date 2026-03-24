#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

struct PrintWithCount {
    const std::multiset<int>& m;
    explicit PrintWithCount(const std::multiset<int>& ms);
    void operator()(int val) const;
};

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    std::multiset<int> M(v.begin(), v.end());
    std::set<int> S(v.begin(), v.end());
    std::for_each(S.begin(), S.end(), PrintWithCount(M));
    std::cout << '\n';
    return 0;
}

PrintWithCount::PrintWithCount(const std::multiset<int>& ms) : m(ms) {}

void PrintWithCount::operator()(int val) const {
    std::cout << val << "(" << m.count(val) << ") ";
}
