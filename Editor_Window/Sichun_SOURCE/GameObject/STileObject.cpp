#include "STileObject.h"
#include"GameObject/GameObject.h"
#include"../Component/STransform.h"
\
namespace Sichun
{
	TileObject::TileObject()
	{	
	}
	TileObject::~TileObject()
	{
	}
	void TileObject::Initialize()
	{
		Super::Initialize();
	}
	void TileObject::Update()
	{
		Super::Update();
	}
	void TileObject::LateUpdate()
	{
		Super::LateUpdate();
	}
	void TileObject::Render(HDC hdc)
	{
		Super::Render(hdc);
	}
	void TileObject::SetPosition(Vector2 pos)
	{
		GetComponent<Transform>()->SetPosition(pos);
	}
}