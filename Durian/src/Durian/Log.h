#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Durian {

	class DURIAN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
			
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define DR_CORE_TRACE(...)  ::Durian::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DR_CORE_ERROR(...)  ::Durian::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DR_CORE_WARN(...)   ::Durian::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DR_CORE_INFO(...)   ::Durian::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DR_CORE_FATAL(...)  ::Durian::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define DR_TRACE(...)  ::Durian::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DR_ERROR(...)  ::Durian::Log::GetClientLogger()->error(__VA_ARGS__)
#define DR_WARN(...)   ::Durian::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DR_INFO(...)   ::Durian::Log::GetClientLogger()->info(__VA_ARGS__)
#define DR_FATAL(...)  ::Durian::Log::GetClientLogger()->fatal(__VA_ARGS__)
