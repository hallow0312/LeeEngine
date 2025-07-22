#pragma once
#include"..\\Sichun_SOURCE\Resource\SResources.h"
#include"..\\Sichun_SOURCE\Component\STexture.h"

namespace Sichun
{
	void LoadResources()
	{
		Resources::Load<Graphics::Texture>(L"Reimu", L"..\\Resources\\Reimu\\Idle\\ReimuSheet.png");
		Resources::Load<Graphics::Texture>(L"ReimuMove", L"..\\Resources\\Reimu\\Move\\ReimuMove.png");
		Resources::Load<Graphics::Texture>(L"YinYang", L"..\\Resources\\Reimu\\Item\\YinYang.png");
		Resources::Load<Graphics::Texture>(L"BackGround", L"..\\Resources\\BackGround\\BackGround.png");
	}
		
	
}



