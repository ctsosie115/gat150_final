#pragma once

#include "..//../Source/Renderer/Vector2.h"

#include <vector>
#include <array>

class Input
{
public:
	Input() = default;
	~Input() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	bool GetKeyDown(uint8_t key) { return m_keyboardState[key]; }
	bool GetPreviousKeyDown(uint8_t key) { return m_prevKeyboardState[key]; }

	Vector2 GetMousePosition() const { return m_mouse_position; }

	bool GetMouseButtonDown(uint8_t button) { return mouseButtonState[button]; }
	bool GetPreviousMouseButtonDown(uint8_t button) { return prevMouseButtonState[button]; }

private:
	std::vector<uint8_t> m_keyboardState;
	std::vector<uint8_t> m_prevKeyboardState;

	Vector2 m_mouse_position{ 0, 0 };
	std::array<uint8_t, 3> mouseButtonState{ 0,0,0 };
	std::array<uint8_t, 3> prevMouseButtonState{ 0,0,0 };
};