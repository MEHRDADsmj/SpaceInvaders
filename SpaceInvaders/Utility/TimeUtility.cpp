#include "TimeUtility.h"
#include <chrono>

using namespace Utility;

long long TimeUtility::GetUnixNow() noexcept
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}