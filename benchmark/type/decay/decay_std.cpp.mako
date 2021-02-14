#include <type_traits>
using std::decay;

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
