// argcv.hpp
//
// MIT License
//
// Copyright (c) 2017 Heikki Hellgren <heiccih@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#ifndef CMD_ARGCV_ARGCV_HPP_
#define CMD_ARGCV_ARGCV_HPP_

#include <vector>
#include <string>
#include <sstream>
#include <map>

namespace drodil {
namespace cmd {
namespace argcv {

// \class ArgCV
// Allows parsing command line arguments in the following formats:
//
// \code
// -key value
// -key
// --key value
// --key
// -key=value
// --key=value
// \endcode
class ArgCV {
public:

	// Initialize the parser with argc and argv
	//
	// \param[in] argc int    Number of arguments
	// \param[in] argv char** Pointer of char array of arguments
	ArgCV(int argc, char** argv)
			: m_tokens(argv + 1, argc + argv) {
		// Untough it's bad to do work in constructor, we do it anyways here
		// as it's such a simple thing :)
		parse();
	}

	// Initialize the parser with string vector
	//
	// \param[in] tokens std::vector<std::string> Arguments to parse
	ArgCV(std::vector<std::string> tokens)
			: m_tokens(tokens) {
		parse();
	}

	// Get all tokens from arguments
	//
	// \return std::vector<std::string>
	std::vector<std::string> get_tokens() const noexcept {
		return m_tokens;
	}

	// Get all arguments in std::map
	//
	// \return std::map<std::string, std::string>
	std::map<std::string, std::string> get_args() const noexcept {
		return m_args;
	}

	// Check if argument is set
	//
	// \param[in] key std::string Parameter key to check
	//
	// \return bool
	bool has_arg(const std::string& key) const noexcept {
		return m_args.count(key) == 1;
	}

	// Check if argument is set and it's value is non-zero length
	//
	// \param[in] key std::string Parameter key to check
	//
	// \return bool
	bool has_arg_with_value(const std::string& key) const noexcept {
		auto it = m_args.find(key);
		if (it == m_args.end()) {
			return false;
		}

		return !(it->second.empty());
	}

	// Returns value for given key
	//
	// If key is not set in arguments, returns empty string
	//
	// \param[in] key std::string Parameter key to get value for
	//
	// \return std::string
	std::string get_value(const std::string& key) const noexcept {
		auto it = m_args.find(key);
		if (it == m_args.end()) {
			return "";
		}
		return it->second;
	}

	// Get parameter value as user defined format
	//
	// \param[in] key std::string Parameter key to get value for
	//
	// \return T
	template<typename T>
	T get_value_as(const std::string& key) const noexcept {
		std::istringstream iss{get_value(key)};
		T result{};
		iss >> result;
		return result;
	}

private:
	// Parse parameters from tokens
	void parse() noexcept {
		for (auto it = m_tokens.begin(); it != m_tokens.end(); it++) {
			// Only support tokens that start with '-' char
			// TODO: Allow changing the config char
			if (it->substr(0, 1) != "-") {
				continue;
			}

			// Double '-', valid. Remove the start
			if (it->substr(0, 2) == "--") {
				it->erase(0, 2);
			} else {
				it->erase(0, 1);
			}

			// Handle params with format key=value
			std::size_t pos;
			if ((pos = it->find("=")) != std::string::npos) {
				m_args.insert(
						make_pair(it->substr(0, pos), it->substr(pos + 1)));
				continue;
			}

			// Check next token to be value
			auto next_it = std::next(it);
			if (next_it != m_tokens.end() && next_it->substr(0, 1) != "-") {
				m_args.insert(make_pair(*it, *next_it));
			} else {
				// No value, insert empty string as value
				m_args.insert(make_pair(*it, std::string("")));
			}
		}
	}

	// Raw tokens from constructor
	std::vector<std::string> m_tokens;

	// Parsed arguments
	std::map<std::string, std::string> m_args;
};

} // namespace argcv
} // namespace cmd
} // namespace drodil

#endif // CMD_ARGCV_ARGCV_HPP_
