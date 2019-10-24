#pragma once
#include "public.h"

using namespace std;

template<typename T, typename... Types>
void estimateFuncTime(T firstArg, Types... args)
{
        clock_t start,end;
	start = clock();
	firstArg(args...);
	end = clock();
	cout << "used time: " << (float)(end - start)*1000/CLOCKS_PER_SEC << "ms" << endl;
}

template<typename T, typename... Types>
void estimateFuncTimeLoop(int times, T firstArg, Types... args)
{
        clock_t start,end;
        start = clock();
	assert(times >= 1);
	for (int i = 0; i < times; ++i)
	{
		firstArg(args...);
	}
        end = clock();
        cout << "used time: " << (float)(end - start)*1000/CLOCKS_PER_SEC << "ms" << endl;
}

