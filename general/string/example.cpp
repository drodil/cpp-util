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

#include "string_utils.hpp"
#include <iostream>

using namespace drodil::general::string;

int main() {
    std::string splitted = "Hello World From Oulu Finland";
    std::cout << "Splitting string: " << splitted << std::endl;
    int i = 0;
    for (auto split : drodil::general::string::split(splitted, " ")) {
        std::cout << i << ": " << split << std::endl;
        i++;
    }

    std::string l = "   To trim   ";
    std::cout << "l_trim for '" << l << "' -> ";
    std::cout << "'" << l_trim(l) << "'" << std::endl;

    std::string lminus = "-----To trim---";
    std::cout << "l_trim for '" << lminus << "' -> ";
    std::cout << "'" << l_trim(lminus, "-") << "'" << std::endl;

    std::string r = "   To trim   ";
    std::cout << "r_trim for '" << r << "' -> ";
    std::cout << "'" << r_trim(r) << "'" << std::endl;

    std::string rminus = "-----To trim---";
    std::cout << "r_trim for '" << rminus << "' -> ";
    std::cout << "'" << r_trim(rminus, "-") << "'" << std::endl;

    std::string lr = "   To trim   ";
    std::cout << "trim for '" << lr << "' -> ";
    std::cout << "'" << trim(lr) << "'" << std::endl;

    std::string lrminus = "-----To trim---";
    std::cout << "trim for '" << lrminus << "' -> ";
    std::cout << "'" << trim(lrminus, "-") << "'" << std::endl;

    std::cout << "Random string of 5 characters: " << random_string(5) << std::endl;
    std::cout << "Random string of 50 characters: " << random_string(50) << std::endl;

    std::vector<std::string> elems{"elem1", "elem2", "elem3"};
    std::cout << "Imploded: " << drodil::general::string::implode(elems, "#") << std::endl;
}
