#include "InputManager.h"
#include"../S_Application.h"
#include <Windows.h>

extern Sichun::Application _application;
namespace Sichun
{
	std::vector<InputManager::Key> InputManager::Keys = {};
	math::Vector2 InputManager::MousePosition = math::Vector2::One;
	static const int VKMap[] =
	{
		'Q','W','E','R','T','Y',
		'U','I','O','P','A','S',
		'D','F','G','H','J','K',
		'L','Z','X','C','V','B',
		'N','M',
		VK_LEFT, VK_UP, VK_RIGHT, VK_DOWN,VK_SPACE,
		VK_LBUTTON,VK_RBUTTON,VK_MBUTTON
	};

	void InputManager::Initialize()
	{
		CreateKeys();
	}

	void InputManager::Update()
	{
		CheckKeyInput();
	}

	void InputManager::CreateKeys()
	{
		for (size_t i = 0; i < static_cast<size_t>(KeyCode::End); i++)
		{
			Key key = {};
			key._isPressed = false;
			key._state = KeyState::NONE;
			key._keyCode = static_cast<KeyCode>(i);
			Keys.push_back(key);
		}
	}

	void InputManager::CheckKeyInput()
	{
		if (!GetFocus())
		{
			ClearKeys();
		}
		else 
		{
			
			SettingKeyState();
			SetMousePositionByWindow();
		}
	}

#pragma region InputKey
	bool InputManager::GetKeyDown(KeyCode code)
	{
		return Keys[static_cast<size_t>(code)]._state == KeyState::DOWN;
	}

	bool InputManager::GetKeyUp(KeyCode code)
	{
		return Keys[static_cast<size_t>(code)]._state == KeyState::UP;
	}

	bool InputManager::GetKey(KeyCode code)
	{
		return Keys[static_cast<size_t>(code)]._state == KeyState::PRESSED;
	}

	void InputManager::SettingKeyState()
	{
		for (size_t i = 0; i < static_cast<size_t>(KeyCode::End); i++)
		{
			bool isPressed = GetAsyncKeyState(VKMap[i]) & 0x8000;

			if (isPressed)
			{
				if (Keys[i]._isPressed)
				{
					Keys[i]._state = KeyState::PRESSED;
				}
				else
				{
					Keys[i]._state = KeyState::DOWN;
					Keys[i]._isPressed = true;
				}
			}
			else
			{
				if (Keys[i]._isPressed)
				{
					Keys[i]._state = KeyState::UP;
					Keys[i]._isPressed = false;
				}
				else
				{
					Keys[i]._state = KeyState::NONE;
				}
			}
		}
	}

	int InputManager::GetAxis(AxisName axis)
	{
		switch (axis)
		{
		case AxisName::HORIZONTAL:
		{
			bool right = GetKey(KeyCode::D) || GetKey(KeyCode::RIGHT);
			bool left = GetKey(KeyCode::A) || GetKey(KeyCode::LEFT);
			if (right && !left) return 1;
			if (left && !right) return -1;
			return 0;
		}
		case AxisName::VERTICAL:
		{
			bool up = GetKey(KeyCode::W) || GetKey(KeyCode::UP);
			bool down = GetKey(KeyCode::S) || GetKey(KeyCode::DOWN);
			if (up && !down) return -1;
			if (down && !up) return 1;
			return 0;
		}
		default:
			return 0;
		}
	}

	int InputManager::GetAxis(const string& axisName)
	{
		if (axisName == "Horizontal")
			return GetAxis(AxisName::HORIZONTAL);
		else if (axisName == "Vertical")
			return GetAxis(AxisName::VERTICAL);
		else
			return 0;
	}
	void InputManager::SetMousePositionByWindow()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(_application.GetHwnd(),&mousePos);

		MousePosition.x = mousePos.x;
		MousePosition.y = mousePos.y;
	}
	void InputManager::ClearKeys()
	{
		for (Key& key : Keys)
		{
			if (key._state == KeyState::DOWN || key._state == KeyState::PRESSED)
				key._state = KeyState::UP;
			else if (key._state == KeyState::UP)
				key._state = KeyState::NONE;

			key._isPressed = false;
		}
	}
#pragma endregion

	
}
