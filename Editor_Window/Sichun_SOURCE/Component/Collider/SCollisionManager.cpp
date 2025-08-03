#include"SCollisionManager.h"
#include"Scene/SScene.h"
#include"Scene/SSceneManager.h"
#include"GameObject/GameObject.h"
#include"Component/Collider/SCollider.h"
#include"Component/STransform.h"
#include"GameObject/GameObject.h"
namespace Sichun
{
	std::bitset<(UINT)LayerType::Max> CollisionManager::_collisionLayerMatrix[(UINT)LayerType::Max] = {};
	std::unordered_map<UINT64, bool>CollisionManager::_collisionMap = {};
	void CollisionManager::Initialize()
	{
	}
	void CollisionManager::Update()
	{
	
		for (UINT row = 0; row < (UINT)LayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)LayerType::Max; col++)
			{
				if (_collisionLayerMatrix[row][col] == true)
				{
					LayerCollision(SceneManager::GetActiveScene(), (LayerType)row, (LayerType)col);
				}
			}
		}
	}
	void CollisionManager::LateUpdate()
	{
	}
	void CollisionManager::Render(HDC hdc)
	{
	}
	void CollisionManager::LayerCollision(std::shared_ptr<Scene> scene, LayerType left, LayerType right)
	{
		const std::vector<std::shared_ptr<GameObject>>& lefts = scene->GetLayer(left)->GetGameObjects();
		const std::vector<std::shared_ptr<GameObject>>& rights = scene->GetLayer(right)->GetGameObjects();
		for (auto& left : lefts)
		{
			if (left->IsActive() == false)
				continue;
			std::shared_ptr<Collider> leftCol = left->GetComponent<Collider>();
			if (leftCol == nullptr)
				continue;
			for (auto& right : rights)
			{
				if (right->IsActive() == false)
					continue;
				std::shared_ptr<Collider> rightCol = right->GetComponent<Collider>();
				if (rightCol == nullptr)
					continue;
				if (left == right)continue;
				CheckColliderCollision(leftCol,rightCol);
			}
		}
	}
	void CollisionManager::CollisionLayerCheck(LayerType left, LayerType right, bool enable)
	{
		
		int row = 0;
		int col = 0;
		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}
		_collisionLayerMatrix[row][col] = enable;
	}

	void CollisionManager::CheckColliderCollision(std::shared_ptr<Collider> left, std::shared_ptr<Collider> right)
	{
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		auto iter = _collisionMap.find(id.ID);
		if (iter == _collisionMap.end())
		{
			_collisionMap.insert(std::make_pair(id.ID, false));
			iter = _collisionMap.find(id.ID);
		}
		if (Intersect(left, right))
		{
			if (iter->second == false)
			{
				left->OnTriggerEnter(right);
				right->OnTriggerEnter(left);
				iter->second = true;
			}
			else
			{
				left->OnTriggerStay(right);
				right->OnTriggerStay(left);
			}
		}
		else
		{
			if (iter->second == true)
			{
				left->OnTriggerExit(right);
				right->OnTriggerExit(left);
				iter->second = false;
			}
			
		}

	}
	bool CollisionManager::Intersect(std::shared_ptr<Collider> left, std::shared_ptr<Collider> right)
	{
		std::shared_ptr<Transform>leftTransform = left->GetOwner()->GetComponent<Transform>();
		std::shared_ptr<Transform>rightTransform = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTransform->GetWorldPosition() + left->GetOffset();
		Vector2 rightPos = rightTransform->GetWorldPosition() + right->GetOffset();

		//size 1,1경우 기본크기  100,100
		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		Enum::ColliderType leftType = left->GetColliderType();
		Enum::ColliderType rightType = right->GetColliderType();
		
		if (leftType == Enum::ColliderType::Rect && rightType == Enum::ColliderType::Rect)
		{
			if(RectCollision(leftSize, leftPos, rightSize, rightPos))
				return true;
		}
		if (leftType == Enum::ColliderType::Circle && rightType == Enum::ColliderType::Circle)
		{
			if(CircleCircleCollision(leftSize, leftPos, rightSize,  rightPos))
				return true;
		}
		if ((leftType == Enum::ColliderType::Rect && rightType == Enum::ColliderType::Circle)
			|| (leftType == Enum::ColliderType::Circle && rightType == Enum::ColliderType::Rect))
		{
			if (leftType == Enum::ColliderType::Rect)
			{
				if (RectCircleCollision(leftSize, leftPos, rightSize, rightPos))
					return true;
			}
			else
			{
				if (RectCircleCollision(rightSize, rightPos, leftSize, leftPos))
					return true;
			}

				
		}
		return false;
		
	}

	bool CollisionManager::RectCollision(Vector2 leftSize, Vector2 leftPos, Vector2 rightSize, Vector2 rightPos)
	{
		Vector2 leftCenter = leftPos + leftSize / 2.0f;
		Vector2 rightCenter = rightPos + rightSize / 2.0f;

		return fabs(leftCenter.x - rightCenter.x) < (leftSize.x / 2.0f + rightSize.x / 2.0f) &&
			fabs(leftCenter.y - rightCenter.y) < (leftSize.y / 2.0f + rightSize.y / 2.0f);
	}

	bool CollisionManager::CircleCircleCollision(Vector2 leftSize, Vector2 leftPos, Vector2 rightSize, Vector2 rightPos)
	{
		Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
		Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);
		float dist = (leftCirclePos - rightCirclePos).Length();
		if (dist <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
			return true;

		return false;
	}

	bool CollisionManager::RectCircleCollision(Vector2 rectSize, Vector2 rectPos, Vector2 circleSize, Vector2 circlePos)
	{
		Vector2 rectCenter = rectPos + rectSize / 2.0f;
		Vector2 circleCenter = circlePos + circleSize / 2.0f;

		float rectHalfWidth = rectSize.x / 2.0f;
		float rectHalfHeight = rectSize.y / 2.0f;
		float circleRadius = circleSize.x / 2.0f;

		float dx = fabs(circleCenter.x - rectCenter.x);
		float dy = fabs(circleCenter.y - rectCenter.y);

		if (dx > (rectHalfWidth + circleRadius) || dy > (rectHalfHeight + circleRadius))
			return false;

		if (dx <= rectHalfWidth || dy <= rectHalfHeight)
			return true;

		float cornerDistanceSq = (dx - rectHalfWidth) * (dx - rectHalfWidth) +
			(dy - rectHalfHeight) * (dy - rectHalfHeight);

		return cornerDistanceSq <= (circleRadius * circleRadius);
	}

	
		

}