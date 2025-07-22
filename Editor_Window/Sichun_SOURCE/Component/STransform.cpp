#include "STransform.h"

namespace Sichun
{
	Transform::Transform():Base(Enum::ComponentType::Transform)
	{
		SetName(L"Transform");
		SetPosition(Vector2(0,0));
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
	
	void Transform::UpdateTransform()
	{
		if (HasParent())
		{
			_transform.World.Pos = GetParent()->GetWorldPosition() + GetLocalPos();
			_transform.World.Scale = GetParent()->GetWorldScale() * GetLocalScale();
			_transform.World.Rotation = GetParent()->GetWorldRotation() + GetLocalRotation();
		}
		else
		{
			_transform.World = _transform.Local;
		}

		for (auto& child : _children)
		{
			if (child)
				child->UpdateTransform();
		}
	}
	Vector2 Transform::GetWorldPosition()
	{
		if (HasParent())
			return _parent->GetWorldPosition() + GetLocalPos();
		else
			return GetLocalPos();
	}

	float Transform::GetWorldRotation()
	{
		if (HasParent())
			return _parent->GetWorldRotation() + GetLocalRotation();
		else
			return GetLocalRotation();
	}

	Vector2 Transform::GetWorldScale()
	{
		if (HasParent())
			return _parent->GetWorldScale() * GetLocalScale();
		else
			return GetLocalScale(); 
	}
	void Transform::SetParent(std::shared_ptr<Transform> parent)
	{
		_parent = parent;
		if (_parent)
		{
			_parent->AddChildren(shared_from_this());
		}
	}
	void Transform::AddChildren(std::shared_ptr<Transform> child)
	{
		if(child!=nullptr)
		_children.push_back(child);
	}
}