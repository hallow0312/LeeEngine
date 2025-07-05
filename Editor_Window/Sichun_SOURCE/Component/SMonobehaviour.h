#pragma  once
#include"SComponent.h"

namespace  Sichun
{
	class Monobehaviour :public  Component
	{
		using Base = Component;
	public:
		Monobehaviour();
		~Monobehaviour();
		virtual void Initialize()override;
		virtual void Update()override;
		virtual void LateUpdate()override;
		virtual void Render(HDC hdc)override;
	private:
	};
}