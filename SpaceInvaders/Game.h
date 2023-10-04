#pragma once

class Game
{
public:
	Game();
	~Game();

	void Start();
	void Update(double frameTime);
	void Close();

	/// <summary>
	/// Amount of time passed since the previous frame in seconds
	/// </summary>
	double deltaTime;
};

