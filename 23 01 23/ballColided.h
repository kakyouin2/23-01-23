#pragma once
#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include "brick.h"
#include "brick_row.h"

struckt Brickrow


sf::Vector2f midLeft{
  ball.shape.getPosition().x,
  ball.shape.getPosition().y + BALL_RADIUS
};
sf::Vector2f midTop{
 ball.shape.getPosition().x + BALL_RADIUS,
 ball.shape.getPosition().y
};
sf::Vector2f midBottom{
 ball.shape.getPosition().x + BALL_RADIUS,
 ball.shape.getPosition().y + 2 * BALL_RADIUS
};
sf::Vector2f midRight{
 ball.shape.getPosition().x + 2 * BALL_RADIUS,
 ball.shape.getPosition().y + BALL_RADIUS
}; 
for (int i = 0; i < brick) {
	if(pointInRect(brickrow.brickArr[i]))
		ball.speedY = - ball.speedY
}