#pragma once
#include"GameObject.h"
namespace Sichun
{
	class TileObject:public GameObject
	{
		using Super = GameObject;
			
	public:
		TileObject();
		~TileObject();

		 void Initialize() override;
		 void Update() override;
		 void LateUpdate()  override;
		 void Render(HDC hdc) override;

	private:

	};
}

