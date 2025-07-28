#pragma once
#include"..//Sichun_SOURCE//Component/SMonobehaviour.h"
#include"..//Sichun_SOURCE//Component/STransform.h"
namespace Sichun
{
	class YinYang : public Monobehaviour
	{
	public:
		YinYang();
		~YinYang();

		void Initialize()override;
		void Update()override;
		void LateUpdate()override;
		void Render(HDC hdc)override;
		void Move();
		void Rotate();
		void Setting(std::shared_ptr<Transform>transform,Vector2 offset);
		
	private:
		std::shared_ptr<Transform>_playerTransform;
		std::shared_ptr<Transform>_transform;
		Vector2 _offset;
	};

}
