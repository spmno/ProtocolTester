#include <spdlog/spdlog.h>
#include <memory>

#ifndef _MXLOG_H_
#define _MXLOG_H_

class MXLog
{
public:
	static std::shared_ptr<spdlog::logger> mx_logger;
	static void Init();
};

#define MXLOG MXLog::mx_logger

#endif
