#pragma once
#include "Common/CommonInclude.h"


using std::vector;
using std::string;

namespace Sichun
{
	enum class KeyState
	{
		NONE,
		DOWN,
		PRESSED,
		UP,
	};

	enum class KeyCode
	{
		Q, W, E, R, T, Y,
		U, I, O, P, A, S,
		D, F, G, H, J, K,
		L, Z, X, C, V, B,
		N, M,

		LEFT, UP, RIGHT, DOWN,SPACE,
		LBUTTON,RBUTTON,MBUTTON,LEFTCTRL,RIGHTCTRL,
		End
	};

	enum class AxisName
	{
		HORIZONTAL,
		VERTICAL
	};

	class InputManager
	{
	public:
		struct Key
		{
			KeyCode _keyCode;
			KeyState _state;
			bool _isPressed;
		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(KeyCode code);
		static bool GetKeyUp(KeyCode code);
		static bool GetKey(KeyCode code);
		static math::Vector2 GetMousePosition() { return MousePosition; }
		static int GetAxis(AxisName axis);
		static int GetAxis(const string& axisName);

		static bool SaveKey();
		static void SettingKeyState();
		static void SetMousePositionByWindow();
		static void ClearKeys();
	private:
		static std::vector<Key> Keys;
		static math::Vector2 MousePosition;
		static void CreateKeys();
		static void CheckKeyInput();
	};
}
