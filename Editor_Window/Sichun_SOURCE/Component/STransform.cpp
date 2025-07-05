#include "STransform.h"

namespace Sichun
{
	Transform::Transform():Base(Enum::ComponentType::Transform)
	{
		SetName(L"Transform");
		SetPos(Vector2(0,0));
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
}