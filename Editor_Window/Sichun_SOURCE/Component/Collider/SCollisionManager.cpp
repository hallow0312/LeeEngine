#include"SCollisionManager.h"
#include"Scene/SScene.h"
#include"Scene/SSceneManager.h"
#include"GameObject/GameObject.h"
#include"Component/Collider/SCollider.h"
namespace Sichun
{
	std::bitset<(UINT)LayerType::Max> CollisionManager::_collisionLayerMatrix[(UINT)LayerType::Max] = {};

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
				if (right->GetComponent<Collider>() == nullptr)
					continue;
				if (left == right)continue;
				CheckColliderCollision(leftCol,rightCol);
			}
		}
	}
	void CollisionManager::CollisionLayerCheck(LayerType left, LayerType right, bool enable)
	{
		// しししし
		//	 ししし
		//	   しし
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
		//TODO : 中宜端滴 稽送 
	}
}