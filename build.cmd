call cmake -S . -B build -Wno-dev
call cmake --build build --target beman_senders --config Debug
call cmake --build build --target stdexec_senders --config Debug

:: call cmake -S . -B build_clang -T ClangCL -Wno-dev
:: call cmake --build build_clang --target beman_senders --config Debug
:: call cmake --build build_clang --target stdexec_senders --config Debug
