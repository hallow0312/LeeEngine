#include "SAnimation.h"
#include"../Common/STime.h"
namespace Sichun {
	Animation::Animation():Base(Enum::ResourceType::Animation)
		, _texture(nullptr)
		,_sprites{}
		,_index(-1)
		,_time(0.0f)
		,_isComplete(false)
	{
		
	}

	
	Animation::~Animation()
	{
	}
	void Animation::Update()
	{
		if (_isComplete)return;
		_time += Time::DeltaTime();

		if (_sprites[_index].Duration <= _time)
		{
			if (_index < _sprites.size()-1)
			{
				_index++;
			}
			else
			{
				_isComplete = true;
			}
		}
	}
	void Animation::CreateAnimation(const std::wstring& name, std::shared_ptr<Sichun::Graphics::Texture> spriteSheet, Vector2 leftTop, Vector2 size, UINT spriteLength, float duration)
	{
	}
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::Reset()
	{
		_time = 0.0f;
		_index = 0;
		_isComplete = false;
	}
}