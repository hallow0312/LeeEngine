#pragma once

namespace  Sichun::Enum
{
	enum class ComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		End
	};

	enum class LayerType
	{
		None,
		BackGround,
		Object,
		AI,
		Player,
		UI,
		Max=16,
	};

	enum class ResourceType
	{
		Texture,
		Animation,
		//Mesh
		//Shader
		AudioClip,
		Prefab,
	};
}