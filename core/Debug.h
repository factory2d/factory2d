#ifndef __FACTORY2D_DEBUG
#define __FACTORY2D_DEBUG

#include <string>
#include <iostream>

#define TYPE_CONSOLE 1
#define TYPE_WARNING 2
#define TYPE_ERROR 3

#define COLOR_CONSOLE "\033[39m"
#define COLOR_WARNING "\033[33m"
#define COLOR_ERROR "\033[31m"

/*
enum DebugTypes {
	CONSOLE = 0,
	WARNING,
	ERROR
};
*/
#define LOG(message, ...) Debug::Write(__FUNCTION__, __LINE__, message, COLOR_CONSOLE)
#define WARNING(message, ...) Debug::Write(__FUNCTION__, __LINE__,  message, COLOR_WARNING)
#define ERROR(message, ...) Debug::Write(__FUNCTION__, __LINE__, message, COLOR_ERROR)

namespace F2D
{
	class Debug {
	public:
		static const bool enabled = true;
		static const bool output = true;

		static void Write(std::string file, unsigned int line, std::string string, std::string color);
	};
}

#endif