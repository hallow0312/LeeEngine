#pragma once
#include"../Common/CommonInclude.h"
#include"SUIBase.h"
namespace Sichun 
{
	using namespace Enum;
	class UIManager
	{

	public:
		template <typename Func>
		static void ForEachUI(Func&& func)
		{
			std::stack<std::shared_ptr<UIBase>> uiBases = _uiBases;
			while (!uiBases.empty())
			{
				const auto& uiBase = uiBases.top();
				if (uiBase)
					func(uiBase);
				uiBases.pop();
			}
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void OnLoad(UIType type);
		static void OnComplete(std::shared_ptr<UIBase>addUI);
		static void OnFail();

		static void Push(UIType type);
		static void Pop(UIType type);

	private:
		static std::stack<std::shared_ptr<UIBase>>_uiBases;
		static std::queue<UIType>_requestUIQueue;
		static std::shared_ptr<UIBase> _activeUI;
		static std::unordered_map<UIType, std::shared_ptr<UIBase>>_UIs;
	};

}
