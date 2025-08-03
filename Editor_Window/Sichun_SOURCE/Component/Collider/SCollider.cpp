#include"SCollider.h"
#include"Component/SMonobehaviour.h"
#include"GameObject/GameObject.h"
namespace Sichun
{
	uint32 Collider::_collisionID = 1;
	Collider::Collider(ColliderType type):
		Super(Enum::ComponentType::Collider)
		,_ID(_collisionID++)
		,_size(Vector2::One)
		,_colliderType(type)
	{
	}
	Collider::~Collider()
	{
	}
	void Collider::Initialize()
	{
	}
	void Collider::Update()
	{
	}
	void Collider::LateUpdate()
	{
	}
	void Collider::Render(HDC hdc)
	{
	}
	void Collider::OnTriggerEnter(std::shared_ptr<Collider> other)
	{
		std::shared_ptr<Monobehaviour>script = GetOwner()->GetComponent<Monobehaviour>();
		if(script) 
		script->OnTriggerEnter(other);
	}
	void Collider::OnTriggerStay(std::shared_ptr<Collider> other)
	{
		std::shared_ptr<Monobehaviour>script = GetOwner()->GetComponent<Monobehaviour>();
		if (script)
		script->OnTriggerStay(other);
	}
	void Collider::OnTriggerExit(std::shared_ptr<Collider> other)
	{
		std::shared_ptr<Monobehaviour>script = GetOwner()->GetComponent<Monobehaviour>();
		if (script)
		script->OnTriggerExit(other);
	}
	
	
}