#include <print>

#if __has_include(<beman/execution/execution.hpp>)
// warning C4459: declaration of 'sender' hides global declaration
#pragma warning(disable: 4459)
#include <beman/execution/execution.hpp>
namespace ex = beman::execution;
static const int once = ([]{ std::println("-- beman::execution"); }(), 1);
#elif __has_include(<stdexec/execution.hpp>)
#include <stdexec/execution.hpp>
namespace ex = stdexec;
static const int once = ([]{ std::println("-- stdexec"); }(), 1);
#endif

#if defined(NDEBUG)
#  undef NDEBUG
#endif
#include <cassert>

template<typename Receiver>
struct My_OperationState
{
    using operation_state_concept = ex::operation_state_t;
    
    void start() noexcept
    {
        ex::set_value(std::move(_receiver));
    }

    Receiver _receiver;
};

struct My_Sender
{
    using sender_concept = ex::sender_t;
    using completion_signatures = ex::completion_signatures<ex::set_value_t()>;

    template<typename Receiver
        , typename Receiver_ = std::remove_cvref_t<Receiver>>
    My_OperationState<Receiver_> connect(Receiver&& receiver)
    {
        return {std::forward<Receiver>(receiver)};
    }
};

int main()
{
    {
        std::optional<std::tuple<int>> x = ex::sync_wait(ex::just(1));
        assert(x.has_value());
        auto [v] = *x;
        std::println("ex::just(1) - got {}", v);
    }
    {
        std::optional<std::tuple<>> x = ex::sync_wait(My_Sender{});
        assert(x.has_value());
        std::println("My_Sender() - done");
    }
}

