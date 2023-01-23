#include <SFML/Graphics.hpp>
#include "settings.h"
#include "ball.h"
#include "bat.h"
#include "textobj.h"
#include "brick.h"
#include "bricksrow.h"
#include "functions1.h"



using namespace sf;
int main()
{
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE,
		Style::Titlebar | Style::Close
	);
	window.setFramerateLimit(60);

	Ball ball;
	ballInit(ball);
	Bat bat;
	batInit(bat);
	TextObj scoreText;
	textInit(scoreText, ball.score);
	Brickrow brickrow;
	brickRowInit(brickrow, 10, Vector2f{ 0.f,60.f }, BRICK_WIDTH);


	while (window.isOpen())
	{
		//1 îáðàáîòêà ñîáûòèé
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//îáíîâëåíèå èãðîâûõ îáúåêòîâ (ôóíêöèè update)
		ballUpdate(ball);
		batUpdate(bat);
		textUpdate(scoreText, ball.score);
		brickRowUpdate(brickrow);

		//ïðîâåðêà ñòîëêíîâåíèé
		ballCollidedWithBricks1(ball, brickrow);

		//îòðèñîâêà îáúåêòîâ è îáíîâëåíèå îêíà
		window.clear();
		ballDraw(window, ball);
		batDraw(window, bat);
		textDraw(window, scoreText);
		brickRowDraw(window, brickrow);
		window.display();
	}

	return 0;
}