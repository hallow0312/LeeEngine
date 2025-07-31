#pragma once

namespace  Sichun::Enum
{
	enum class ComponentType
	{
		Transform,
		Collider,
		SpriteRenderer,
		Animator,
		Camera,
		Script,
		End
	};
	enum
	{
		FIXED_COMPONENT_COUNT = static_cast<uint8>(ComponentType::End) - 1
	};

	enum class LayerType
	{
		None,
		BackGround,
		Object,
		AI,
		Bullet,
		Player,
		Particle,
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