#include "common.h"

std::string escapeJsonString(const std::string& input) {
	std::string output;
	output.reserve(input.size());

	for(size_t i = 0; i < input.size(); i++) {
		const unsigned char c = static_cast<unsigned char>(input[i]);
		switch(c) {
			case '"':
				output += "\\\"";
				break;
			case '\\':
				output += "\\\\";
				break;
			case '\b':
				output += "\\b";
				break;
			case '\f':
				output += "\\f";
				break;
			case '\n':
				output += "\\n";
				break;
			case '\r':
				output += "\\r";
				break;
			case '\t':
				output += "\\t";
				break;
			default:
				if(c < 0x20) {
					const char* hex = "0123456789abcdef";
					output += "\\u00";
					output += hex[(c >> 4) & 0x0F];
					output += hex[c & 0x0F];
				} else {
					output += static_cast<char>(c);
				}
				break;
		}
	}

	return output;
}