#include "YinYang.h"
#include"Common/STime.h"
#include"Component/STransform.h"
#include"GameObject/GameObject.h"
namespace Sichun
{

	YinYang::YinYang():_offset(Vector2::Zero)
	{
		
	}
	YinYang::~YinYang()
	{
	}
	void YinYang::Initialize()
	{
	}
	void YinYang::Update()
	{
		if (!_playerTransform)return;
		Move();
	}
	void YinYang::LateUpdate()
	{
	}
	void YinYang::Render(HDC hdc)
	{
	}
	void YinYang::Move()
	{
		Vector2  movePos = _playerTransform->GetWorldPosition() + _offset;
		_transform->SetPosition(movePos);
	}
	void YinYang::Rotate()
	{

	}
	void YinYang::Setting(std::shared_ptr<Transform> transform,Vector2 offset)
	{
		_playerTransform = transform;
		_offset = offset;
		_transform = GetOwner()->GetComponent<Transform>();
	}
}