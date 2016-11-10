#include "MXLog.h"

std::shared_ptr<spdlog::logger> MXLog::mx_logger;

void MXLog::Init() {
	mx_logger = spdlog::stdout_logger_mt("mxlog");
}
