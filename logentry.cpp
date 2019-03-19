/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"

Date::Date(const String s) : Date() {
	day = s.substr(1, 2);
	month = s.substr(4, 6);
	year = s.substr(8, 11).toInt();
}

LogEntry::LogEntry(String s) : LogEntry() {
	std::vector<String> vec = s.split(' ');
	if (vec.size() == 10) {
		host = vec[0];
		date = vec[3].substr(0, 11);
		time = Time(vec[3].substr(13, 20));
		request = vec[5] + ' ' + vec[6] + ' ' + vec[7];
		status = vec[8];
		const int NUM_BYTES = vec[9].toInt();
		number_of_bytes = NUM_BYTES > 0 ? NUM_BYTES : 0; // Make sure number of bytes is at least 0
	}
}

Time::Time(const String s) : Time() {
	hour = (s.substr(0, 1)).toInt();
	minute = (s.substr(3, 4)).toInt();
	second = (s.substr(6, 7)).toInt();
}

std::ostream& operator<<(std::ostream &out, const LogEntry &log) {
	const int HOUR = log.time.getHour(), MINUTE = log.time.getMinute(),
		SECOND = log.time.getSecond();

	const bool HOUR_PLACEHOLDER = HOUR < 10 ? true : false;
	const bool MINUTE_PLACEHOLDER = MINUTE < 10 ? true : false;
	const bool SECOND_PLACEHOLDER = SECOND < 10 ? true : false;
	
	out << "IP: " << log.host << " | ";
	out << "Date: " << log.date.getDay() << "/";
	out << log.date.getMonth() << "/";
	out << log.date.getYear() << " ";
	out << "Time: ";

	if (HOUR_PLACEHOLDER)
		out << 0;
	out << log.time.getHour() << ":";
	if (MINUTE_PLACEHOLDER)
		out << 0;
	out << log.time.getMinute() << ":";
	if (SECOND_PLACEHOLDER)
		out << 0;
	out << log.time.getSecond() << " | ";

	out << "Request: " << log.request << " | ";
	out << "Status: " << log.status << " | ";
	out << "Byte size: " << log.number_of_bytes;
	return out;
}

std::vector<LogEntry> parse(std::istream &in) {
	std::vector<LogEntry> vec;

	char c;
	in.get(c);
	int numFields;

	// Add lines to vector until end of file
	do {
		numFields = 1;
		String logLine;

		// Make sure first character of line is not new line
		bool push = true;
		if (c == '\n') {
			push = false;
			in.get(c);
		}

		if (push) {
			// Read until end of line
			do {
				if (c == ' ')
					++numFields;
				logLine += c;
				in.get(c);
			} while (c != '\n' && !in.eof());

			// Push string onto vector
			if (numFields == 10)
				vec.push_back(logLine);
			else {
				vec.push_back(LogEntry());
			}
			// Reset numFields
			numFields = 0;
		}
		else
			push = true; // reset push
	} while (!in.eof());

	return vec;
}

void output_all(std::ostream& out, const std::vector<LogEntry> &logs) {
	const int NUM_LOGS = logs.size();

	for (int i = 0; i < NUM_LOGS; ++i)
		out << logs[i] << std::endl;
}

void by_host(std::ostream& out, const std::vector<LogEntry> &logs) {
	const int NUM_LOGS = logs.size();

	for (int i = 0; i < NUM_LOGS; ++i)
		out << logs[i].getHost() << std::endl;
}

int byte_count(const std::vector<LogEntry> &logs) {
	const int LOGS_NUM = logs.size();
	int numberOfBytes = 0;

	for (int i = 0; i < LOGS_NUM; ++i)
		numberOfBytes += logs[i].getBytes();

	return numberOfBytes;
}
