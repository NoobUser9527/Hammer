#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Hammer {
	class HAMMER_API Log
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

// Core Logºê
#define HM_CORE_TRACE(...)  ::Hammer::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HM_CORE_INFO(...)   ::Hammer::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HM_CORE_WARN(...)   ::Hammer::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HM_CORE_ERROR(...)  ::Hammer::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HM_CORE_FATAL(...)  ::Hammer::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log ºê
#define HM_TRACE(...)	    ::Hammer::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HM_INFO(...)	    ::Hammer::Log::GetClientLogger()->info(__VA_ARGS__)
#define HM_WARN(...)        ::Hammer::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HM_ERROR(...)       ::Hammer::Log::GetClientLogger()->error(__VA_ARGS__)
#define HM_FATAL(...)       ::Hammer::Log::GetClientLogger()->fatal(__VA_ARGS__)