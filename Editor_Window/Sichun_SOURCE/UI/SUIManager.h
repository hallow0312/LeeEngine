#pragma once
#include"../Common/CommonInclude.h"
#include"SUIBase.h"
namespace Sichun 
{
	class UIManager
	{

	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static std::stack<std::shared_ptr<UIBase>>_uiBases;
		static std::queue<Enum::UIType>_requestUIQueue;
	};

}
