#pragma once
#include"..\\Sichun_SOURCE\Resource\SResources.h"
#include"..\\Sichun_SOURCE\Component\STexture.h"

namespace Sichun
{
	void LoadResources()
	{
		Resources::Load<Graphics::Texture>(L"Sichun", L"C:\\Users\\user\\Desktop\\2DGame\\LeeEngine\\Editor_Window\\Resources\\Sichun.png");
	}
}



