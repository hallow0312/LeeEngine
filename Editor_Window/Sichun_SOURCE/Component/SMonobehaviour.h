#pragma  once
#include"SComponent.h"

namespace  Sichun
{
	class Collider;
	class Monobehaviour :public  Component
	{
		using Base = Component;
	public:
		Monobehaviour();
		~Monobehaviour();
		void Initialize()override;
		void Update()override;
		void LateUpdate()override;
		void Render(HDC hdc)override;

		virtual void OnTriggerEnter(std::shared_ptr<Collider>other);
		virtual void OnTriggerStay(std::shared_ptr<Collider>other);
		virtual void OnTriggerExit(std::shared_ptr<Collider>other);
	private:
	};
}