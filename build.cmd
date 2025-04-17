call cmake -S . -B build -Wno-dev
call cmake --build build --target beman_senders --config Debug
call cmake --build build --target stdexec_senders --config Debug
