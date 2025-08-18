#pragma once

namespace  Sichun::Enum
{
	enum class ComponentType
	{
		Transform,
		Collider,
		RigidBody,
		TileMapRenderer,
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
		Tile,
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
	enum class ColliderType
	{
		Rect,
		Circle,
	};
}