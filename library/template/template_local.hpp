#ifndef TEMPLATE_LOCAL_HPP
#define TEMPLATE_LOCAL_HPP

#include "template.hpp"

#define impl_show1(a) { std::clog << #a << " = " << a << endl; }
#define impl_show2(a, ...) { std::clog << #a << " = " << a << ", "; impl_show1(__VA_ARGS__); }
#define impl_show3(a, ...) { std::clog << #a << " = " << a << ", "; impl_show2(__VA_ARGS__); }
#define impl_show4(a, ...) { std::clog << #a << " = " << a << ", "; impl_show3(__VA_ARGS__); }
#define impl_show5(a, ...) { std::clog << #a << " = " << a << ", "; impl_show4(__VA_ARGS__); }
#define impl_show6(a, ...) { std::clog << #a << " = " << a << ", "; impl_show5(__VA_ARGS__); }
#define show(...) { std::clog << "\033[33m"; \
                    impl_overload6(__VA_ARGS__, impl_show6, impl_show5, impl_show4, impl_show3, impl_show2, impl_show1)(__VA_ARGS__) \
                    std::clog << "\033[0m" << std::flush; }

template<class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    bool first = true;
    for (const auto& e : v) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "]";
    return os;
}

#endif // TEMPLATE_LOCAL_HPP
