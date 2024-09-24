#include <SFML/Graphics.hpp>
#include <pthread.h>
#include <iostream>
#include <unistd.h> // For usleep
#include "Enemie.hpp"

using namespace sf;

// Enemie class implementation (constructor)
Enemie::Enemie(int x, int y, Texture &texture, Vector2f p) { //Constructor de la clase Enemie, se le pasa la posición inicial, la textura de los enemigos y p que es la posición del enemigo en forma de un vector 2d
    point = p;
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(point.x, point.y, 8, 8)); //Delimita una sección (rectangular) en la textura para respresentar a los enemigos, usa la posición de cada uno y le suma 8 en x, y para cambiar entre estados
    sprite.setPosition(x, y);   //Posición del enemigo
    sprite.setScale(3, 3);  //Escala al 300%
    state = 0;  //Dos estados para la animación (primer o segundo bloque del spritesheet)
    timer = 0;    
    vel = 24;   //La velocidad es positiva, empiezan moviendose hacia la derecha
    cadencia = 150;
}

void Enemie::Update() {
    if (timer >= cadencia) {    //Si el contador llega a 150, los enemigos cambian de estado y velocidad
        sprite.move(vel, 0);
        state++;
        state %= 2;
        sprite.setTextureRect(IntRect(point.x + state * 9, point.y, 8, 8)); //Mueve los enemigos hacia un lado cuando cambia el estado, además cambia la textura al estado 1 o 2
        timer = 0;
    }
    timer++;
}

void Enemie::ChangeDir() {  //Cambia la dirección de los enemigos
    vel *= -1;
    sprite.move(0, abs(vel));
}

Vector2f Enemie::Pos() {
    return sprite.getPosition();
}

void Enemie::AumentarCadencia() {
    cadencia--;
}

void Enemie::draw(RenderTarget &rt, RenderStates rs) const {
    rt.draw(sprite, rs);
}


