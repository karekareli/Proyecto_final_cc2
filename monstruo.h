#ifndef MONSTRUO_H
#define MONSTRUO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include <stdexcept>

class Monstruo {//Esta es la clase abstracta, de la que se dibujarán más clases posteriormente
public:

    sf::Sprite monstruo;
    sf::Vector2f seEstaMoviendo;
    sf::RectangleShape barraVidaMonstruo;
    sf::Vector2f direccion;

    int vida;
    bool persiguiendo;
    float velocidad;

    //Las varables boolenas son para establecer una textura dependiendo del movimiento
    bool moverArriba;
    bool moverAbajo;
    bool moverDerecha;
    bool moverIzquierda;
    bool mostrar;

    float angle;

    bool estaPersiguiendo;

    const float distanciaMaxima;//Para actuar dependiendo de si el srpite jugador esta dentro del rango

    Monstruo() :distanciaMaxima(300),estaPersiguiendo(false), direccion(1.f, 0.f), angle(0.f), persiguiendo(false), moverArriba(false), moverAbajo(false),
        moverDerecha(false), moverIzquierda(false), mostrar(false) {}

    virtual void perseguir(sf::Sprite& personaje) = 0;
    virtual void actualizarDirecciones() = 0;
    virtual void actualizarTexturas(sf::Texture&, sf::Texture&, sf::Texture&, sf::Texture&) = 0;
};


class Zombie : public Monstruo {

public:
    Zombie(sf::Texture&, sf::Vector2f&);
    void perseguir(sf::Sprite&) override;
    void actualizarDirecciones() override;
    void actualizarTexturas(sf::Texture& subiendo, sf::Texture& bajando, sf::Texture& derecha, sf::Texture& izquierda) override;

};
 
void Zombie::actualizarTexturas(sf::Texture& subiendo, sf::Texture& bajando, sf::Texture& derecha, sf::Texture& izquierda) {
    if (moverArriba) {
        monstruo.setTexture(subiendo);
    }
    if (moverAbajo) {
        monstruo.setTexture(bajando);
    }
    if (moverDerecha) {
        monstruo.setTexture(izquierda);
    }
    if (moverIzquierda) {
        monstruo.setTexture(derecha);
    }
}

Zombie::Zombie(sf::Texture& textura, sf::Vector2f& posicion) : Monstruo() {
    vida = 10;
    velocidad = 2.f;

    monstruo.setTexture(textura);
    monstruo.setOrigin(textura.getSize().x / 2.0f, textura.getSize().y / 2.0f);
    monstruo.setPosition(posicion);
    monstruo.setScale(2.0f, 2.0f);

    barraVidaMonstruo.setFillColor(sf::Color::Red);
    barraVidaMonstruo.setSize(sf::Vector2f(10.f, 5.f));
    barraVidaMonstruo.setPosition(monstruo.getPosition().x - 40, monstruo.getPosition().y - 30);

}

void Zombie::actualizarDirecciones() {
    if (seEstaMoviendo.x < 0) {
        moverDerecha = false;
        moverIzquierda = true;
        moverArriba = false;
        moverAbajo = false;
    }
    else if (seEstaMoviendo.x > 0) {
        moverIzquierda = false;
        moverDerecha = true;
        moverAbajo = false;
        moverArriba = false;
    }
    else if (seEstaMoviendo.y < 0) {
        moverAbajo = false;
        moverArriba = true;
        moverDerecha = false;
        moverIzquierda = false;
    }
    else if (seEstaMoviendo.y > 0) {
        moverArriba = false;
        moverAbajo = true;
        moverDerecha = false;
        moverIzquierda = false;
    }
    else {
        moverArriba = moverAbajo = moverDerecha = moverIzquierda = false;
    }
}



void Zombie::perseguir(sf::Sprite& personaje) {
    sf::Vector2f objetivo = personaje.getPosition();
    sf::Vector2f direccion = objetivo - monstruo.getPosition();
    float distancia = std::sqrt(direccion.x * direccion.x + direccion.y * direccion.y);

    if (distancia > 0) {


        if (distancia != 0) {
            direccion /= distancia;
        }
        seEstaMoviendo = direccion * velocidad;
        monstruo.move(seEstaMoviendo);

        barraVidaMonstruo.setSize(sf::Vector2f(vida * 10.f, 5.f));
        barraVidaMonstruo.setPosition(monstruo.getPosition().x - 40, monstruo.getPosition().y - 30);
        actualizarDirecciones();
        estaPersiguiendo = true;
    }
    else {
        estaPersiguiendo = false;
    }
}

//=============================== CLASE FANTASMA ==============================================================================================//
class Fantasma : public Monstruo {
public:
    Fantasma(sf::Texture&, sf::Vector2f&);
    void perseguir(sf::Sprite&) override;
    void actualizarDirecciones() override;
    void actualizarTexturas(sf::Texture& subiendo, sf::Texture& bajando, sf::Texture& derecha, sf::Texture& izquierda) override;
    

};

void Fantasma::actualizarTexturas(sf::Texture& subiendo, sf::Texture& bajando, sf::Texture& derecha, sf::Texture& izquierda) {
    if (moverArriba ) {
        monstruo.setTexture(subiendo);
    }
    if (moverAbajo) {
        monstruo.setTexture(bajando);
    }
    if (moverDerecha) {
        monstruo.setTexture(izquierda);
    }
    if (moverIzquierda) {
        monstruo.setTexture(derecha);
    }
}

Fantasma::Fantasma(sf::Texture& textura, sf::Vector2f& posicion) : Monstruo() {
    vida = 5;
    velocidad = 1.5f;
    monstruo.setTexture(textura);
    monstruo.setOrigin(textura.getSize().x / 2.0f, textura.getSize().y / 2.0f);
    monstruo.setPosition(posicion);
    monstruo.setScale(2.0f, 2.0f);

    barraVidaMonstruo.setFillColor(sf::Color::Red);
    barraVidaMonstruo.setSize(sf::Vector2f(8.f, 5.f));
    barraVidaMonstruo.setPosition(monstruo.getPosition().x - 18, monstruo.getPosition().y - 30);

}

void Fantasma::actualizarDirecciones() {
    if (seEstaMoviendo.x < 0) {
        moverDerecha = false;
        moverIzquierda = true;
        moverArriba = false;
        moverAbajo = false;
    }
    else if (seEstaMoviendo.x > 0) {
        moverIzquierda = false;
        moverDerecha = true;
        moverAbajo = false;
        moverArriba = false;
    }
    else if (seEstaMoviendo.y < 0) {
        moverAbajo = false;
        moverArriba = true;
        moverDerecha = false;
        moverIzquierda = false;
    }
    else if (seEstaMoviendo.y > 0) {
        moverArriba = false;
        moverAbajo = true;
        moverDerecha = false;
        moverIzquierda = false;
    }
    else {
        moverArriba = moverAbajo = moverDerecha = moverIzquierda = false;
    }
}





void Fantasma::perseguir(sf::Sprite& personaje) {
    sf::Vector2f objetivo = personaje.getPosition();
    sf::Vector2f direccion = objetivo - monstruo.getPosition();
    float distancia = std::sqrt(direccion.x * direccion.x + direccion.y * direccion.y);

    if (distancia > 0) {


        if (distancia != 0) {
            direccion /= distancia;
        }
        seEstaMoviendo = direccion * velocidad;
        monstruo.move(seEstaMoviendo);

        barraVidaMonstruo.setSize(sf::Vector2f(vida * 8.f, 5.f));
        barraVidaMonstruo.setPosition(monstruo.getPosition().x - 18, monstruo.getPosition().y - 30);
        actualizarDirecciones();
        estaPersiguiendo = true;
    }
    else {
        estaPersiguiendo = false;
    }
}
#endif 
