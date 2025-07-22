#include "YinYang.h"
#include"Common/STime.h"
#include"Component/STransform.h"
#include"GameObject/GameObject.h"
namespace Sichun
{

	YinYang::YinYang()
	{
		_value = 0.0f;
	}
	YinYang::~YinYang()
	{
	}
	void YinYang::Initialize()
	{
	}
	void YinYang::Update()
	{
		_value += Time::DeltaTime();
		if (_value >= 3.0f)
		{
			_value = 0.0f;
			Vector2  pos = GetOwner()->GetComponent<Transform>()->GetWorldPosition();
			int a = 10;
		}
		Rotate();
	}
	void YinYang::LateUpdate()
	{
	}
	void YinYang::Render(HDC hdc)
	{
	}
	void YinYang::Move()
	{
	}
	void YinYang::Rotate()
	{

	}
}