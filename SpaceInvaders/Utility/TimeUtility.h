#pragma once

namespace Utility
{

static class TimeUtility
{
public:
	/// <summary>
	/// Calculates Unix time in miliseconds
	/// </summary>
	/// <returns>Unix time in miliseconds</returns>
	static long long GetUnixNow() noexcept;
};

}