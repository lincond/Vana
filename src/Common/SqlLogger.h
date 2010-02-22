/*
Copyright (C) 2008-2010 Vana Development Team

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#pragma once

#include "Logger.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class SqlLogger : public Logger {
public:
	SqlLogger(const string &format, const string &timeFormat, int16_t serverType, size_t bufferSize = 10);
	~SqlLogger();

	void log(LogTypes::LogTypes type, const string &identifier, const string &message);
	void flush();
private:
	size_t m_bufferSize;
	vector<LogMessage> m_buffer;
};