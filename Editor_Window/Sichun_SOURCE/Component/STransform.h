#pragma once
#include"SComponent.h"

namespace Sichun 
{
	using namespace math;
	
	class Transform : public Component, public std::enable_shared_from_this<Transform>
	{
		struct TransformData
		{
			Vector2 Pos = Vector2::Zero;
			Vector2 Scale = Vector2::One;
			float Rotation = 0;
		};
		struct PositionData
		{
			TransformData Local;
			TransformData World;
			PositionData()
			{
				Local = TransformData();  
				World = TransformData();
			}
		
		};
		using Base = Component;
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		
		void SetPosition(Vector2 pos)
		{
			_transform.Local.Pos = pos;
			UpdateTransform();
		}
		void SetScale(Vector2 scale)
		{
			_transform.Local.Scale = scale;
			UpdateTransform();
		}
		void SetRotation(float rotation)
		{
			_transform.Local.Rotation = rotation;
			UpdateTransform();
		}

		void UpdateTransform();
		
		float GetLocalRotation() 
		{
			return _transform.Local.Rotation; 
		}
		Vector2 GetLocalPos() { return  _transform.Local.Pos; }
		Vector2 GetLocalScale() { return _transform.Local.Scale; }
	
		Vector2 GetWorldPosition();
		float GetWorldRotation();
		Vector2 GetWorldScale();
		
		

#pragma region °èÃþ±¸Á¶
		void SetParent(std::shared_ptr<Transform>parent);
		
		std::shared_ptr<Transform>GetParent() { return _parent; }
		bool HasParent() { return _parent != nullptr; }

		void AddChildren(std::shared_ptr<Transform>child);
		const std::vector < std::shared_ptr<Transform >>& GetChildren() { return _children; }
#pragma endregion

	private:
		PositionData _transform;
		
		std::shared_ptr<Transform>_parent;
		std::vector <std::shared_ptr<Transform>>_children;
	private:

	
	};
}
