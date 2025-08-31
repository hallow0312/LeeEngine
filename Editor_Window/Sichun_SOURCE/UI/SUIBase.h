#pragma once
#include"../Common/SEntity.h"
namespace Sichun 
{
	using namespace  Enum;
	class UIBase: public  Entity
	{
	public:
		UIBase();
		~UIBase();

		void Active();
		void InActive();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void UIClear();

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInActive();
		virtual void OnTick();
		virtual void OnClear();

		UIType GetType() { return _type; }
		void SetFullScreen(bool screen) { _bFullScreen = screen; }
		bool IsFullScreen() { return  _bFullScreen; }
	private:
		UIType _type = UIType::None;
		bool _bFullScreen = false;
		bool _bEnabled = false;

	};

}
