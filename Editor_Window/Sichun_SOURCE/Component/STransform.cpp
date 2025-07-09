#include "STransform.h"

namespace Sichun
{
	Transform::Transform():Base(Enum::ComponentType::Transform),_scale(Vector2::One),_rotation(0.0f)
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