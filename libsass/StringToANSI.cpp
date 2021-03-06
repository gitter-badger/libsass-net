//Copyright (C) 2013 by TBAPI-0KA
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of
//this software and associated documentation files (the "Software"), to deal in
//the Software without restriction, including without limitation the rights to
//use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
//of the Software, and to permit persons to whom the Software is furnished to do
//so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

#using <System.dll>
#include <string>
#include "StringToANSI.hpp"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace LibSassNet
{
	char* MarshalString(String^ s)
    {
        if (!s) {
            return nullptr;
        }

        char* original_str = (char*)(Marshal::StringToCoTaskMemAnsi(s)).ToPointer();
        char* target_str = (char*)malloc(strlen(original_str) + 1);
        strcpy(target_str, original_str);

        FreeString(original_str);

        return target_str;
	}

	void FreeString(const char* p)
	{
        if (p) Marshal::FreeCoTaskMem(IntPtr((void *) p));
	}

	const char* MarshalConstString(String^ s)
	{
        return (const char*) ((Marshal::StringToCoTaskMemAnsi(s)).ToPointer());
	}

	void FreeConstString(const char* p)
	{
        if (p) Marshal::FreeCoTaskMem(IntPtr((void *) p));
	}
}