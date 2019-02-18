// dllmain.cpp : Defines the entry point for the DLL application.
#include "jamspell_api.h"
#include <jamspell/spell_corrector.hpp>

using namespace NJamSpell;

JS_API(void*) CreateJamSpell()
{
	auto result = new TSpellCorrector();
	return result;
}

JS_API(void) LoadModel(void* hPtr, const char* path)
{
	auto spell = static_cast<TSpellCorrector*>(hPtr);
	spell->LoadLangModel(path);
}

JS_API(void) DestroyJamSpell(void* hPtr)
{
	delete static_cast<TSpellCorrector*>(hPtr);
}

JS_API(bool) TrainLangModel(void* hPtr, const char* textFile, const char* alphabetFile, const char* modelFile)
{
	auto spell = static_cast<TSpellCorrector*>(hPtr);
	return spell->TrainLangModel(textFile, alphabetFile, modelFile);
}

JS_API(int) GetCandidates(void* hPtr, wchar_t** words, int wordsCount, int position, wchar_t*** candidates)
{
	auto spell = static_cast<TSpellCorrector*>(hPtr);
	std::vector<std::wstring> sentense;

	for (int i = 0; i < wordsCount; ++i)
	{
		sentense.push_back(std::wstring(words[i]));
	}

	auto result = spell->GetCandidates(sentense, position);
	auto buffer = new wchar_t*[result.size()];
	for (int i = 0; i < result.size(); ++i)
	{
		auto len = result[i].length();
		buffer[i] = new wchar_t[len + 1];
		result[i].copy(buffer[i], len);
		buffer[i][len] = L'\0';
	}

	*(candidates) = buffer;

	return result.size();
}
