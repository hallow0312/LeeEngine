#include "InputManager.h"
#include <Windows.h>

namespace Sichun
{
	vector<InputManager::Key> InputManager::_keys = {};

	static const int VKMap[] =
	{
		'Q','W','E','R','T','Y',
		'U','I','O','P','A','S',
		'D','F','G','H','J','K',
		'L','Z','X','C','V','B',
		'N','M',
		VK_LEFT, VK_UP, VK_RIGHT, VK_DOWN
	};

	void InputManager::Initialize()
	{
		for (size_t i = 0; i < static_cast<size_t>(KeyCode::End); i++)
		{
			Key key = {};
			key._isPressed = false;
			key._state = KeyState::NONE;
			key._keyCode = static_cast<KeyCode>(i);
			_keys.push_back(key);
		}
	}

	void InputManager::Update()
	{
		CheckKeyInput();
	}

	void InputManager::CheckKeyInput()
	{
		for (size_t i = 0; i < static_cast<size_t>(KeyCode::End); i++)
		{
			bool isPressed = GetAsyncKeyState(VKMap[i]) & 0x8000;

			if (isPressed)
			{
				if (_keys[i]._isPressed)
				{
					_keys[i]._state = KeyState::PRESSED;
				}
				else
				{
					_keys[i]._state = KeyState::DOWN;
					_keys[i]._isPressed = true;
				}
			}
			else
			{
				if (_keys[i]._isPressed)
				{
					_keys[i]._state = KeyState::UP;
					_keys[i]._isPressed = false;
				}
				else
				{
					_keys[i]._state = KeyState::NONE;
				}
			}
		}
	}

	bool InputManager::GetKeyDown(KeyCode code)
	{
		return _keys[static_cast<size_t>(code)]._state == KeyState::DOWN;
	}

	bool InputManager::GetKeyUp(KeyCode code)
	{
		return _keys[static_cast<size_t>(code)]._state == KeyState::UP;
	}

	bool InputManager::GetKey(KeyCode code)
	{
		return _keys[static_cast<size_t>(code)]._state == KeyState::PRESSED;
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
}
