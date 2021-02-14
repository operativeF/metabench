#include <cstddef>
#include <type_traits>

template <typename T, typename U = typename std::remove_reference<T>::type>
struct decay {
    typedef typename std::remove_cv<U>::type type;
};

template <typename T, typename U>
struct decay<T, U[]> { typedef U* type; };
template <typename T, typename U, std::size_t N>
struct decay<T, U[N]> { typedef U* type; };

template <typename T, typename R, typename ...A>
struct decay<T, R(A...)> { typedef R(*type)(A...); };
template <typename T, typename R, typename ...A>
struct decay<T, R(A..., ...)> { typedef R(*type)(A..., ...); };

#if defined(METABENCH)

<%
iters = range(iterations)
%>
% for i in iters:
    struct T${i} { };
    typedef decay<T${i}>::type             foo1_${i};
    typedef decay<T${i}&>::type            foo2_${i};
    typedef decay<T${i}&&>::type           foo3_${i};
    typedef decay<T${i} const>::type       foo4_${i};
    typedef decay<T${i} volatile>::type    foo5_${i};
    typedef decay<T${i} [3]>::type         foo6_${i};
% endfor

#endif

int main() { }