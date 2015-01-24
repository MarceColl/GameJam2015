#include "Player.h"

Player::Player(sf::RenderWindow *wndw) : texture(Resources::player), spriteCount(sf::Vector2i(4, 3)) {
    window = wndw;
    sprite.setTexture(texture);
    sprite.setPosition(500, 500);
    sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x/spriteCount.x, texture.getSize().y/spriteCount.y));
}

Player::~Player() {}

void Player::draw() {
    window->draw(sprite);
}

void Player::update(float deltaTime) {
    sf::Vector2f currPos = sprite.getPosition();

    if (speed < 0 && currPos.x <= target) {
        speed = 0;
    } else if (speed > 0 && currPos.x >= target) {
        speed = 0;
    }
    
    sprite.setPosition(currPos.x + speed*deltaTime, currPos.y);
}

void Player::moveTo(float x) {
    sf::Vector2f currPos = sprite.getPosition();
    target = x;
    speed = currPos.x > x ? MOVESPEED * -1 : MOVESPEED;
}