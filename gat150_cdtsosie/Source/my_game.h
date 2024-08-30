#pragma once
#include "Game.h"

class Font;
class Text;

class MyGame
{
public:
	enum class eState
	{
		Title,
		StartGame,
		StartLevel,
		Game,
		PlayerDead,
		GameOver
	};

public:
	MyGame(Engine* engine);
	MyGame() = default;

	bool Initialize();
	void Shutdown();
	void Update(float dt, float time);
	void Draw(Renderer& renderer);

	void OnPlayerDeath();

private:
	eState m_state{ eState::Title };
	float m_spawnTimer{ 0 };
	float m_spawnTime{ 0 };
	float m_stateTimer{ 3 };

	Font* m_font{ nullptr };
	Font* m_fontLarge{ nullptr };

	//blink variable
	float m_blinkTimer{ 0 };
	float m_pickupTimer{ 0 };
	float m_pickup2Timer{ 0 };
	int GetScore() const { return m_score; }
	void AddPoints(int points) { m_score += points; }

	int GetLives() const { return m_lives; }
	void SetLives(int lives) { m_lives = lives; }

	friend Scene;
	friend Engine;
protected:
	int m_score = 0;
	int m_lives = 0;

	Engine* m_engine{ nullptr };
	Scene* m_scene{ nullptr };
};


