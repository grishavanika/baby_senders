#include <print>

#if __has_include(<beman/execution/execution.hpp>)
// warning C4459: declaration of 'sender' hides global declaration
#pragma warning(disable: 4459)
#include <beman/execution/execution.hpp>
namespace ex = beman::execution;
#elif __has_include(<stdexec/execution.hpp>)
#include <stdexec/execution.hpp>
namespace ex = stdexec;
#endif

#if defined(NDEBUG)
#  undef NDEBUG
#endif
#include <cassert>

int main()
{
    std::optional<std::tuple<int>> x = ex::sync_wait(ex::just(1));
    assert(x.has_value());
    auto [v] = *x;
    std::println("ex::just(1) - got {}", v);
}
