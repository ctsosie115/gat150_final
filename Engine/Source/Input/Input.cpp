#include "..//../Source/Input/Input.h"

#include <SDL.h>

bool Input::Initialize()
{
	int numKeys;
	const uint8_t* keyboardState = SDL_GetKeyboardState(&numKeys);

	m_keyboardState.resize(numKeys);

	//copy keyboardstate into out keyboard state
	std::copy(keyboardState, keyboardState + numKeys, m_keyboardState.begin());

	m_prevKeyboardState = m_keyboardState;

	return true;
}

void Input::Shutdown()
{
	//
}

void Input::Update()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	//keyboard
	m_prevKeyboardState = m_keyboardState;
	const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
	std::copy(keyboardState, keyboardState + m_keyboardState.size(), m_keyboardState.begin());

	//mouse input
	int x, y;

	uint32_t buttonState = SDL_GetMouseState(&x, &y); // the code will change based on what it is clicked

	m_mouse_position.x = (float)x;
	m_mouse_position.y = (float)y;

	prevMouseButtonState = mouseButtonState;

	//Button state
	// 000 <-button state
	// 001 <-button mask
	// 000 <- False
	// 001 <- True
	mouseButtonState[0] = buttonState & SDL_BUTTON_LMASK;
	//000 <-button state
	//010 <-button mask
	mouseButtonState[1] = buttonState & SDL_BUTTON_MMASK;
	//000 <- button state
	//100 <- button mask
	mouseButtonState[2] = buttonState & SDL_BUTTON_RMASK;
}
