#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <mutex>
#include "Player.hpp"

using namespace sf;
using namespace std;

Player::Player(int x, int y, Texture &texture) {
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(13*8+8,7*8+7,16,8)); //Establece la posición inicial y la sección del sprite a usar (16*8)
    sprite.setPosition(x, y);
    sprite.setScale(3, 3);
    vida = 3;
    vel = 5;
    shoot = false;

}

void Player::Update() {
    if (Keyboard::isKeyPressed(Keyboard::Right) && sprite.getPosition().x + vel < 552) {  //552px es el limite al que se puede mover
        sprite.move(vel, 0);  //5px a la derecha
    }
    if (Keyboard::isKeyPressed(Keyboard::Left) && sprite.getPosition().x + vel * -1 > 0) { //La posición del spritesheet es cero, entonces el limite es 0
        sprite.move(vel * -1, 0); //5px a la izquierda
    }
    system("clear");
    std::cout << vida << '\n';
}

bool Player::Shoot() {
    if (Keyboard::isKeyPressed(Keyboard::Space) && !shoot) {
        shoot = true;
        return true;
    } else if (!Keyboard::isKeyPressed(Keyboard::Space)) {
        shoot = false;
    }
    return false;
}

Vector2f Player::Pos() {
    return sprite.getPosition();
}

void Player::QuitarVida() {
    vida--;
}

bool Player::Vivo() {
    return (vida != 0);
}

void Player::draw(RenderTarget &rt, RenderStates rs) const {
    rt.draw(sprite, rs);
}
