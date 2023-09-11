#pragma once

class Game
{
public:
	Game();
	~Game();

	void Start();
	void Update(float frameTime);
	void Close();

	/// <summary>
	/// Amount of time passed since the previous frame in seconds
	/// </summary>
	float deltaTime;
};

