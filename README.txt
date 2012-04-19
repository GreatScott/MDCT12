Written by Scott Novich (snovich@rice.edu / scott@glitch.fm)
--------------------------------

To use this for a non-Arduino application, just remove:

#include <avr/pgmspace.h> from mdct12.cpp
#include <Arduino.h> from mdct12.cpp
#include <Arduino.h> from mdct12.h

--------------------------------

This library should be placed under <your arduino installation>\libraries\

MDCT12: A pretty quick 12-point Modified Discrete Cosine Transform, built using an optimized algorithm
taken from "A New Efficient Method of Computing MDCT in MP3 Audio Coding" (Wu & Yang, 2012).

Relies on the libfixmath library: http://code.google.com/p/libfixmath/

USAGE: int* MDCT12(int* outframe, int* dataframe, bool spec);

outframe: an empty buffer (array). Should have 6 elements. Currently no check in place to ensure this.
dataframe: an incoming array of real data (such as audio). Should have 12 elements. Currently no check in place to ensure this.
spec: boolean. True will just take the absolute value of the input (the spectrogram). False will be the actual MDCT output.

MIT License (http://www.opensource.org/licenses/mit-license.php)

Copyright (c) <2012> <Scott Novich>
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
documentation files (the "Software"), to deal in the Software without restriction, including without limitation 
the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and 
to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED 
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
IN THE SOFTWARE.