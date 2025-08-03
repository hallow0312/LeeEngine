#pragma once
#include"Common/CommonInclude.h"
#include"SBoxCollider2D.h"
#include"SCircleCollider2D.h"
namespace Sichun
{
	class  Scene;
	using namespace Enum;
	union CollisionID
	{
		struct
		{
			uint32 left;
			uint32 right;
		};
		uint64 ID;
	};
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
		static  bool  Intersect(std::shared_ptr<Collider>left, std::shared_ptr<Collider>right);
	
	private:
		static std::bitset<(UINT)LayerType::Max>_collisionLayerMatrix[(UINT)LayerType::Max];
		static std::unordered_map<uint64, bool>_collisionMap;

	private:
		static bool RectCollision(Vector2 leftSize,Vector2 leftPos,Vector2 rightSize, Vector2 rightPos);
		static bool CircleCircleCollision(Vector2 leftSize, Vector2 leftPos, Vector2 rightSize, Vector2 rightPos);
		static bool RectCircleCollision(Vector2 rectSize, Vector2 rectPos, Vector2 circleSize, Vector2 circlePos);
	};
}  