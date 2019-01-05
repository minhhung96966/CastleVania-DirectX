#pragma once
#include <fstream>
#include <Windows.h>

using namespace std;

extern void ignoreLineIfstream(ifstream& fs, int lineCount);

extern wstring stringToWstring(string& s);

