#include <chrono>
#include <iostream>
#include <iomanip>
#include "Account.hpp"
int main(void)
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	std::time_t time_now = std::chrono::system_clock::to_time_t(now);

	tm utc_tm = *localtime(&time_now);
	std::cout << std::setfill('0') << "[" << (utc_tm.tm_year + 1900)
			  << std::setw(2) << utc_tm.tm_mon
			  << std::setw(2) << utc_tm.tm_mday << "_"
			  << std::setw(2) << utc_tm.tm_hour
			  << std::setw(2) << utc_tm.tm_min
			  << std::setw(2) << utc_tm.tm_sec << "] ";


}