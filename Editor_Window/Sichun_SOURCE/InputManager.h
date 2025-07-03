#pragma once
#include "CommonInclude.h"
#include <vector>
#include <string>

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

		static int GetAxis(AxisName axis);
		static int GetAxis(const string& axisName);

	private:
		static vector<Key> Keys;
		static void CreateKeys();
		static void CheckKeyInput();
	};
}
