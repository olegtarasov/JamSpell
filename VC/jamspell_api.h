#pragma once


#ifdef JAMSPELL_EXPORTS
#define JS_API(RetType) extern "C" __declspec(dllexport) RetType __stdcall
#else 
#define JS_API(RetType) extern "C" __declspec(dllimport) RetType __stdcall
#endif

JS_API(void*) CreateJamSpell();
JS_API(void) LoadModel(void* hPtr, const char* path);
JS_API(void) DestroyJamSpell(void* hPtr);

JS_API(bool) TrainLangModel(void* hPtr, const char* textFile, const char* alphabetFile, const char* modelFile);

JS_API(int) GetCandidates(void* hPtr, wchar_t** words, int wordsCount, int position, wchar_t*** candidates);
