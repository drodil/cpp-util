// example.cpp
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

#include "argcv.hpp"
#include <iostream>

using namespace drodil;

int main(int argc, char** argv) {
	if (argc <= 1) {
		std::cout << "Pass some parameters to see it work." << std::endl;
		return 0;
	}

	ArgCV parser(argc, argv);
	auto tokens = parser.get_tokens();
	std::cout << "Parsed tokens are:" << std::endl;
	for (const auto& token : tokens) {
		std::cout << "  " << token << std::endl;
	}

	auto args = parser.get_args();
	std::cout << "Parsed arguments are:" << std::endl;
	for (const auto& arg : args) {
		std::cout << "  " << arg.first << " => " << arg.second << std::endl;
	}

	return 1;
}

