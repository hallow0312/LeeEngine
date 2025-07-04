#pragma once
#include"CommonInclude.h"

namespace Sichun
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static float DeltaTime() { return DeltaTimeValue; }
	private:
		static LARGE_INTEGER CpuFrequency; //cpu frequency
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;

		
	};



}