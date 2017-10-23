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

#include "binary_operators.hpp"
#include <iostream>
#include <bitset>

using namespace drodil::general::binary_operators;

enum class TestEnum {
    None = 0,
    First = 1 << 1,
    Second = 1 << 2,
    Third = 1 << 3
};

int main() {
    std::bitset<8> firstComplement(static_cast<int>(~TestEnum::First));
    std::cout << "First ones complement: " << firstComplement << std::endl;

    std::bitset<8> firstAndSecond(static_cast<int>(TestEnum::First | TestEnum::Second));
    std::cout << "First | Second: " << firstAndSecond << std::endl;
    
	return 1;
}
