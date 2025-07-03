#include "STime.h"

namespace Sichun
{
	
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float  Time::DeltaTimeValue = 0.0f;
 
	void Time::Initialize() 
	{
		//cpu 고유진동수
		QueryPerformanceFrequency(&CpuFrequency);
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);
		float differFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTimeValue = differFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;
		float fps = 1.0f / DeltaTimeValue;
		time += DeltaTimeValue;
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time: %f", fps);
		int len = wcsnlen_s(str, 50);
		TextOut(hdc, 0, 0, str, len);
	}


}