// https://renyili.org/post/std_chrono/时间介绍:三个概念---时钟（clock），持续时间(duration)，时间点(clock point)
// clock分为三种：system_clock, steady_clock, high_resolution_clock
//  1.system_clock: 系统时钟，表示系统的当前时间，通常与实际的日历时间相关联。
//  2.steady_clock: 稳定时钟，表示一个稳定的时间间流逝，不受系统时间调整的影响，适用于测量时间间隔。
//  3.high_resolution_clock: 高分辨率时钟，提供最高精度的时间测量
// 时间点（time_point）: 表示某个特定的时间点，通常与时钟相关联。
// 持续时间（duration）: 表示两个时间点之间的时间间隔，通常以秒、毫秒等为单位。

//*本文主要介绍时钟中的系统时钟 */
#include <chrono>
#include <iostream>
#include <ctime>
int main()
{
    // Create a time point representing the current time
    auto now = std::chrono::system_clock::now();

    // Convert to time_t for output
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    // Print the current time
    std::cout << "Current time point: " << now.count() << std::endl; // Current time point: 1751352465000000
    std::cout << "System time: " << now_time_t << std::endl;         // System time: 1751352465
    std::cout << "Current time: " << std::ctime(&now_time_t);        // Current time: Tue Jul  1 14:47:45 2025

    return 0;
}
