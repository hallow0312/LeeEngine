#pragma once
#include"../SComponent.h"


namespace Sichun
{
	using namespace Enum;
	class Collider :public Component
	{
		using Super = Component;
	public:
		Collider(ColliderType type);
		~Collider();

		uint32 GetID() { return _ID; }
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnTriggerEnter(std::shared_ptr<Collider>other);
		virtual void OnTriggerStay(std::shared_ptr<Collider>other);
		virtual void OnTriggerExit(std::shared_ptr<Collider>other);

		void  SetOffset(Vector2 offset) { _offset = offset; }
		Vector2 GetOffset() { return _offset; }
		void SetSize(Vector2 size) { _size = size;}
		Vector2 GetSize() { return _size; }

		ColliderType GetColliderType() { return _colliderType; }

	private:

		static uint32 _collisionID;
		uint32 _ID;
		Vector2 _offset;
		Vector2  _size;
		
		ColliderType _colliderType;

	private:
	
	};
}