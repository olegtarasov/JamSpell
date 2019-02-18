// TestUtil.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "jamspell_api.h"

int main()
{
	auto spell = CreateJamSpell();
	//TrainLangModel(spell, "C:\\Projects\\JamSpell\\test_data\\kapitanskaya_dochka.txt", "C:\\Projects\\JamSpell\\test_data\\alphabet_ru.txt", "C:\\Models\\model.bin");
	LoadModel(spell, "C:\\Models\\model.bin");

	std::wstring* words = new std::wstring[2]{ L"првет", L"медвед" };
	wchar_t** wPtr = new wchar_t*[2];
	wPtr[0] = const_cast<wchar_t*>(words[0].c_str());
	wPtr[1] = const_cast<wchar_t*>(words[1].c_str());
	wchar_t** buffers;

	int candidates = GetCandidates(spell, wPtr, 2, 0, &buffers);
}

