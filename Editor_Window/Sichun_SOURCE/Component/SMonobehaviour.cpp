#include "SMonobehaviour.h"

namespace Sichun
{
	Monobehaviour::Monobehaviour():Base(Enum::ComponentType::Script)
	{
	}
	Monobehaviour::~Monobehaviour()
	{
	}
	void Monobehaviour::Initialize()
	{
	}
	void Monobehaviour::Update()
	{
	}
	void Monobehaviour::LateUpdate()
	{
	}
	void Monobehaviour::Render(HDC hdc)
	{
	}
	void Monobehaviour::OnTriggerEnter(std::shared_ptr<Collider>other)
	{

	}
	void Monobehaviour::OnTriggerStay(std::shared_ptr<Collider>other)
	{

	}
	void Monobehaviour::OnTriggerExit(std::shared_ptr<Collider>other)
	{

	}
}