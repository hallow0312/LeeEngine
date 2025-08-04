#include "SToolScene.h"
#include"../GameObject/SObject.h"
#include"../GameObject/STileObject.h"
namespace Sichun
{
	ToolScene::ToolScene()
	{
	}
	ToolScene::~ToolScene()
	{
	}
	void ToolScene::Initialize()
	{
		Super::Initialize();
		Object::Instantiate<TileObject>(Enum::LayerType::Tile);
	}
	void ToolScene::Update()
	{
		Super::Update();
	}
	void ToolScene::LateUpdate()
	{
		Super::LateUpdate();
	}
	void ToolScene::Render(HDC hdc)
	{
		Super::Render(hdc);
	}
}