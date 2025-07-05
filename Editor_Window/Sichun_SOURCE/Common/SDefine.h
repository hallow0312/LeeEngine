#pragma once

namespace  Sichun::Enum
{
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
		//Mesh
		//Shader
		AudioClip,
		Prefab,
	};
}