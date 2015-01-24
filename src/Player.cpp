#include "Player.h"

Player::Player(sf::RenderWindow *wndw) : texture(Resources::player), spriteNum(sf::Vector2i(0, 0)), spriteCount(sf::Vector2i(4, 3)) {
    window = wndw;
    sprite.setTexture(texture);
    sprite.setPosition(500, 800);
    sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x/spriteCount.x, texture.getSize().y/spriteCount.y));
    sprite.setOrigin(texture.getSize().x/spriteCount.x/2, texture.getSize().y/spriteCount.y/2);
    ChangeTimer = 0.0f;
}

Player::~Player() {}

void Player::draw() {
    window->draw(sprite);
}

void Player::update(float deltaTime) {

    sf::Vector2f currPos = sprite.getPosition();
    ChangeTimer += deltaTime;

    if(ChangeTimer >= 0.25f && speed != 0) {
        spriteNum = sf::Vector2i(spriteNum.x + 1, spriteNum.y);
        if (spriteNum.x >= spriteCount.x) {
            spriteNum = sf::Vector2i(0, spriteNum.y);
        }

        ChangeTimer = 0.0f;

        sprite.setTextureRect(sf::IntRect(
            spriteNum.x*(texture.getSize().x/spriteCount.x),
            spriteNum.y*(texture.getSize().y/spriteCount.y), 
            texture.getSize().x/spriteCount.x, texture.getSize().y/spriteCount.y));
    }

    if (speed < 0 && currPos.x <= target) {
        speed = 0;
        sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x/spriteCount.x, texture.getSize().y/spriteCount.y));
    } else if (speed > 0 && currPos.x >= target) {
        speed = 0;
        sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x/spriteCount.x, texture.getSize().y/spriteCount.y));
    }
    
    sprite.setPosition(currPos.x + speed*deltaTime, currPos.y);
}

void Player::moveTo(float x) {
    sf::Vector2f currPos = sprite.getPosition();
    target = x;
    speed = currPos.x > x ? MOVESPEED * -1 : MOVESPEED;
    sprite.setScale(speed/MOVESPEED, 1.f);
}