#include <print>

// warning C4459: declaration of 'sender' hides global declaration
#pragma warning(disable: 4459)
#include <beman/execution/execution.hpp>

#if defined(NDEBUG)
#  undef NDEBUG
#endif
#include <cassert>

namespace ex = beman::execution;

int main()
{
    std::optional<std::tuple<int>> x = ex::sync_wait(ex::just(1));
    assert(x.has_value());
    auto [v] = *x;
    std::println("ex::just(1) - got {}", v);
}
