#pragma once
#include"Common/CommonInclude.h"
#include"SBoxCollider2D.h"
#include"SCircleCollider2D.h"
namespace Sichun
{
	class  Scene;
	using namespace Enum;
	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void LayerCollision(std::shared_ptr<Scene>scene, LayerType left , LayerType right);
		static void CollisionLayerCheck(LayerType left, LayerType right, bool enable);
		static void CheckColliderCollision(std::shared_ptr<Collider>left, std::shared_ptr<Collider>right);
	private:
		static std::bitset<(UINT)LayerType::Max>_collisionLayerMatrix[(UINT)LayerType::Max];
	};
}  