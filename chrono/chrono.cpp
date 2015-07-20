#include <cstdint>
#include <chrono>
#include <iostream>
#include <thread>

int main( int argc, char ** argv )
{
    using namespace std::literals::chrono_literals;

    const std::chrono::duration<int64_t, std::micro> ctSleepTime = 2s;
    std::cout << "===============" << '\n'
              << "Chrono examples" << '\n'
              << "===============" << '\n'
              << "Sleeping for 2 seconds" << '\n'
              << std::endl;

    // Other clocks are: steady clock (monotonic)
    //                   high_resolution_clock
    std::chrono::time_point< std::chrono::system_clock> l_start, l_end;

    l_start = std::chrono::system_clock::now();

    std::this_thread::sleep_for( ctSleepTime );

    l_end = std::chrono::system_clock::now();

    std::chrono::duration<double, std::milli> l_durationMs = l_end - l_start;
    std::chrono::duration<double, std::micro> l_durationUs = l_end - l_start;
    std::chrono::duration<double, std::nano> l_durationNs = l_end - l_start;

    std::cout << "Duration in milliseconds: " << l_durationMs.count() << '\n'
              << "Duration in microseconds: " << l_durationUs.count() << '\n'
              << "Duration in nanoseconds: " << l_durationNs.count() << '\n';

    std::cout << "For system_clock: " << '\n'
              << "0 duration: " << std::chrono::system_clock::duration::zero().count() << '\n'
              << "min duration: " << std::chrono::system_clock::duration::min().count() << '\n'
              << "max duration: " << std::chrono::system_clock::duration::max().count() << '\n'
              ; 
    
    std::cout << "For steady_clock: " << '\n'
              << "0 duration: " << std::chrono::steady_clock::duration::zero().count() << '\n'
              << "min duration: " << std::chrono::steady_clock::duration::min().count() << '\n'
              << "max duration: " << std::chrono::steady_clock::duration::max().count() << '\n'
              ; 
    
    std::cout << "For high_resolution_clock: " << '\n'
              << "0 duration: " << std::chrono::high_resolution_clock::duration::zero().count() << '\n'
              << "min duration: " << std::chrono::high_resolution_clock::duration::min().count() << '\n'
              << "max duration: " << std::chrono::high_resolution_clock::duration::max().count() << '\n'
              ; 
    
    return 0;
}
