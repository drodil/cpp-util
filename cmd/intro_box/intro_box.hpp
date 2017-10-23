// intro_box.hpp
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
#ifndef INTRO_BOX_INTRO_BOX_HPP_
#define INTRO_BOX_INTRO_BOX_HPP_

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace drodil {
namespace cmd {
namespace intro_box {

class IntroBox {
public:

	// Constructor
	//
	// Construct new intro box with given content and optionally with custom
	// border character
	//
	// \param[in] content     std::string Content for intro box
	// \param[in] border_char char        Character to use for box rendering
	IntroBox(const std::string& content, const char& border_char = '*')
			noexcept :
			m_content(content), m_ver_border_char(border_char), m_hor_border_char(
					border_char), m_border_width(1), m_box_width(80), m_split_char(
			'\n'), m_padding(1) {
	}

	// Set character for vertical borders
	//
	// \param[in] border_char char Character
	//
	// \return void
	void set_vertical_border_char(const char& border_char) noexcept {
		m_ver_border_char = border_char;
	}

	// Set character for horizontal borders
	//
	// \param[in] border_char char Character
	//
	// \return void
	void set_horizontal_border_char(const char& border_char) noexcept {
		m_hor_border_char = border_char;
	}

	// Set character to be used when splitting content string to lines
	//
	// Default is newline character '\n'
	//
	// \param[in] split_char char Split character
	// \param[in] replace    bool Replace split characters in content with new split character
	//
	// \return void
	void set_split_char(const char& split_char, bool replace = false) noexcept {
		if (replace) {
			std::replace(m_content.begin(), m_content.end(), m_split_char,
					split_char);
		}
		m_split_char = split_char;
	}

	// Set padding of the box
	//
	// \param[in] padding unsigned short New padding to use
	//
	// \return void
	void set_padding(unsigned short padding) {
		if ((padding * 2) + (m_border_width * 2) > m_box_width) {
			throw std::invalid_argument(
					"Too large padding - no space for content");
		}
		m_padding = padding;
	}

	// Set content for this intro box
	//
	// \param[in] content string Content
	//
	// \return void
	void set_content(const std::string& content) noexcept {
		m_content = content;
	}

	// Set border width in characters
	//
	// \param[in] border_width unsigned short New border width
	//
	// \return void
	// \throws std::invalid_argument if border width is too large
	void set_border_width(unsigned short border_width) {
		if ((border_width * 2) + (m_padding * 2) > m_box_width) {
			throw std::invalid_argument(
					"Too large border width - no space for content");
		}
		m_border_width = border_width;
	}

	// Set box width in characters
	//
	// \param[in] border_width unsigned short New border width
	//
	// \return void
	// \throws std::invalid_argument if box width is too small
	void set_box_width(unsigned short box_width) {
		if (box_width < (m_border_width * 2) + (m_padding * 2)) {
			throw std::invalid_argument(
					"Too small box width - no space for content");
		}

		m_box_width = box_width;
	}

	// Return string presentation of the box
	//
	// \return std::string
	std::string to_string() const noexcept {
		std::string str;
		// Box upper border
		for(unsigned short i = 0; i < m_border_width; i++) {
			str += std::string(m_box_width, m_hor_border_char) + "\n";
		}

		// Upper padding
		for(unsigned short i = 0; i < m_padding; i++) {
			// Upper padding left boreder
			str += std::string(m_border_width, m_ver_border_char);
			str += std::string(m_box_width - 2*m_border_width, ' ');
			str += std::string(m_border_width, m_ver_border_char) + "\n";
		}

		// Loop content
		std::stringstream ss(m_content);
		std::string line;
		std::vector<std::string> lines;
		unsigned short max_line_length = m_box_width - ((m_border_width*2) + (m_padding*2));

		while(std::getline(ss, line, m_split_char)) {
			// Handle line breaks
			do {
				// Box left border
				str += std::string(m_border_width, m_ver_border_char);

				// Left padding
				str += std::string(m_padding, ' ');

				// todo: Word-break from space or other character
				std::string substr = line.substr(0, max_line_length);
				str += substr;
				line.erase(0, substr.length());

				unsigned short r_padding = m_box_width - substr.length() - m_padding - (m_border_width * 2);
				// Right padding
				str += std::string(r_padding, ' ');

				// Box right border
				str += std::string(m_border_width, m_ver_border_char) + "\n";
			}while(line.length() > 0);
		}

		// Bottom padding
		for(unsigned short i = 0; i < m_padding; i++) {
			// Bottom padding left border
			str += std::string(m_border_width, m_ver_border_char);
			str += std::string(m_box_width - 2*m_border_width, ' ');
			// Bottom padding right border
			str += std::string(m_border_width, m_ver_border_char) + "\n";
		}

		// Box bottom border
		for(unsigned short i = 0; i < m_border_width; i++) {
			str += std::string(m_box_width, m_hor_border_char) + "\n";
		}
		return str;
	}

	// Output box to output stream
	//
	// \param[in|out] os  std::ostream Target steram
	// \param[in]     box IntroBox     IntroBox to output
	//
	// \return std::ostream
	friend std::ostream& operator<<(std::ostream& os, const IntroBox& box) {
		os << box.to_string();
		return os;
	}

private:
	std::string m_content;
	char m_ver_border_char;
	char m_hor_border_char;
	char m_split_char;
	unsigned short m_border_width;
	unsigned short m_box_width;
	unsigned short m_padding;
};

} // namespace intro_box
} // namespace cmd
} // namespace drodil

#endif // INTRO_BOX_INTRO_BOX_HPP_
