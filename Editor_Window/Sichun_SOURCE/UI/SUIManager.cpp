#include "SUIManager.h"


namespace Sichun
{
	std::stack<std::shared_ptr<UIBase>>UIManager::_uiBases = {};
	std::unordered_map<UIType, std::shared_ptr<UIBase>>UIManager::_UIs = {};
	std::queue<UIType>UIManager::_requestUIQueue = {};
	std::shared_ptr<UIBase> UIManager::_activeUI = nullptr;
	
	void UIManager::Initialize()
	{
	}

	void UIManager::Update()
	{
		ForEachUI([](const std::shared_ptr<UIBase>& uiBase) {uiBase->Update();});
	

		while (!_requestUIQueue.empty())
		{
			UIType requestUI = _requestUIQueue.front();
			_requestUIQueue.pop();
			OnLoad(requestUI);
		}
	}
	void UIManager::LateUpdate()
	{
		ForEachUI([](const std::shared_ptr<UIBase>& uiBase) {uiBase->LateUpdate(); });
	}
			
	void UIManager::Render(HDC hdc)
	{
		std::stack<std::shared_ptr<UIBase>> uiBases = _uiBases;
		while (!uiBases.empty())
		{
			const auto& uiBase = uiBases.top();
			if (uiBase)
				Render(hdc);
			uiBases.pop();
		}
	}
			

	void UIManager::OnLoad(UIType type)
	{
		std::unordered_map<UIType, std::shared_ptr<UIBase>>::iterator  iter =
			_UIs.find(type);
		if (iter == _UIs.end())
		{
			OnFail();
			return;
		}
		OnComplete(iter->second);
	}
	void UIManager::OnComplete(std::shared_ptr<UIBase>addUI)
	{
		if (addUI == nullptr)return;
		addUI->Initialize();
		addUI->Active();
		addUI->Update();

		if (addUI->IsFullScreen())
		{
			std::stack<std::shared_ptr<UIBase>> uiBases = _uiBases;

			while (!uiBases.empty())
			{
				const auto& uiBase = uiBases.top();
				uiBases.pop();
				if (uiBase)
					uiBase->InActive();
			}
			_uiBases.push(addUI);
			_activeUI = nullptr;
		}
	}
	void UIManager::OnFail()
	{
		_activeUI = nullptr;
	}
	void UIManager::Push(UIType type)
	{
		_requestUIQueue.push(type);
	}
	void UIManager::Pop(UIType type)
	{
		if (_uiBases.size() <= 0)return;
		std::shared_ptr<UIBase>uiBase = nullptr;
		while (_uiBases.size() > 0)
		{
			uiBase = _uiBases.top();
			_uiBases.pop();

		}
	}
}