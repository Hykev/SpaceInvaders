#include <pthread.h>
#include <unistd.h> // Para usleep
#include "Bullet.hpp"

// Función que será ejecutada por el hilo
void* threadFunction(void* arg) {
    Bullet* bullet = static_cast<Bullet*>(arg);
    while (true) {
        bullet->Update();
        usleep(10000); // 10 ms
    }
    return nullptr;
}

// Constructor de Bullet con creación de hilo
Bullet::Bullet(int x, int y, Texture &texture, IntRect intRect, int v) {
    sprite.setTexture(texture);
    sprite.setTextureRect(intRect);
    sprite.setPosition(x, y);
    sprite.setScale(3, 3);
    vel = v;
}

void Bullet::Update() {
    sprite.move(0, vel);
}

Vector2f Bullet::Pos() {
    return sprite.getPosition();
}

void Bullet::draw(RenderTarget &rt, RenderStates rs) const {
    rt.draw(sprite, rs);
}
