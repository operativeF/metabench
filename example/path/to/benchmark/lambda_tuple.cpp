
template <typename ...T>
auto make_tuple(T ...t) {
    return [=](auto f) { return f(t...); };
}

int main() {
    auto tuple = make_tuple(<%= (1..n).to_a.join(', ') %>);
}
