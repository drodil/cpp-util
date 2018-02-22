// binary_operators.hpp
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

#ifndef OPERATORS_BINARY_OPERATORS_HPP_
#define OPERATORS_BINARY_OPERATORS_HPP_

#include <iostream>

namespace drodil {
namespace general {
namespace binary_operators {

// BINARY OPERATORS FOR INT ENUMS
// Allows templating ~ operator for any enum class
template<class T> inline T operator~(T a) {
	return static_cast<T>(~static_cast<int>(a));
}

// Allows templating | operator for any enum class
template<class T> inline T operator|(T a, T b) {
	return static_cast<T>(static_cast<int>(a) | static_cast<int>(b));
}

// Allows templating & operator for any enum class
template<class T> inline T operator&(T a, T b) {
	return static_cast<T>(static_cast<int>(a) & static_cast<int>(b));
}

// Allows templating ^ operator for any enum class
template<class T> inline T operator^(T a, T b) {
	return static_cast<T>(static_cast<int>(a) ^ static_cast<int>(b));
}

// Allows templating |= operator for any enum class
template<class T> inline T& operator|=(T& a, T b) {
	return static_cast<T&>(static_cast<int&>(a) |= static_cast<int&>(b));
}

// Allows templating &= operator for any enum class
template<class T> inline T& operator&=(T& a, T b) {
	return static_cast<T&>(static_cast<int&>(a) &= static_cast<int&>(b));
}

// Allows templating ^= operator for any enum class
template<class T> inline T& operator^=(T& a, T b) {
	return static_cast<T&>(static_cast<int&>(a) ^= static_cast<int&>(a));
}

} // namespace binary_operators
} // namespace general
} // namespace drodil

#endif // OPERATORS_BINARY_OPERATORS_HPP_
