#ifndef MAPA_H
#define MAPA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class ParametrosCreacion {
public:
    std::vector<sf::RectangleShape> caminos;
    std::vector<sf::RectangleShape> pastos2;
    std::vector<sf::Sprite> flores;
    sf::Texture texturaFlor;
    std::vector<sf::Sprite> flores2;
    sf::Texture texturaFlor2;
    std::vector<sf::Sprite> tumba1;
    sf::Texture texturaTumba1;
    std::vector<sf::Sprite> tumba2;
    sf::Texture texturaTumba2;
    std::vector<sf::Sprite> tumba3;
    sf::Texture texturaTumba3;
    std::vector<sf::Sprite> tumba4;
    sf::Texture texturaTumba4;
    std::vector<sf::Sprite> piedra1;
    sf::Texture texturaPiedra1;
    std::vector<sf::Sprite> piedra2;
    sf::Texture texturaPiedra2;
    std::vector<sf::Sprite> pasto1;
    sf::Texture texturaPasto1;
    std::vector<sf::Sprite> pasto3;
    sf::Texture texturaPasto3;
    std::vector<sf::Sprite> pasto2;
    sf::Texture texturaPasto2;
    std::vector<sf::Sprite> casa;
    sf::Texture texturaCasa;
    std::vector<sf::Sprite> lago;
    sf::Texture texturalago;


};

// Interfaz para crear elementos
class creareelemento {
public:
    virtual ~creareelemento() = default;
    virtual void crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const = 0;
};

// Clases concretas
class crearcamino : public creareelemento {
public:
    void crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const override;
};

class crearpasto : public creareelemento {
public:
    void crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const override;
};

class crearflor : public creareelemento {
public:
    void crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const override;
};

class crearflor2 : public creareelemento {
public:
    void crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const override;
};

class creartumba1 : public creareelemento {
public:
    void crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const override;
};
class creartumba2 : public creareelemento {
public:
    void crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const override;
};
class creartumba3 : public creareelemento {
public:
    void crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const override;
};
class creartumba4 : public creareelemento {
public:
    void crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const override;
};

class crearpasto1 : public creareelemento {
public:
    void crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const override;
};

class crearpasto2 : public creareelemento {
public:
    void crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const override;
};
class crearcasa : public creareelemento {
public:
    void crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const override;
};
class crearlago : public creareelemento {
public:
    void crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const override;
};


class Mapa {
public:
    Mapa();

    void creacion(std::unique_ptr<creareelemento> generador);
    void crearelemento(const std::vector<sf::Vector2f>& posiciones);
    void dibujar(sf::RenderWindow& ventana);

    const std::vector<sf::RectangleShape>& obtenercaminos() const { return parametros.caminos; }
    const std::vector<sf::RectangleShape>& obtenerpastos2() const { return parametros.pastos2; }
    const std::vector<sf::Sprite>& obtenerflores() const { return parametros.flores; }
    const std::vector<sf::Sprite>& obtenerflores2() const { return parametros.flores2; }
    const std::vector<sf::Sprite>& obtenertumba1() const { return parametros.tumba1; }
    const std::vector<sf::Sprite>& obtenertumba2() const { return parametros.tumba2; }
    const std::vector<sf::Sprite>& obtenertumba3() const { return parametros.tumba3; }
    const std::vector<sf::Sprite>& obtenertumba4() const { return parametros.tumba4; }
    const std::vector<sf::Sprite>& obtenerpiedra1() const { return parametros.piedra1; }
    const std::vector<sf::Sprite>& obtenerpasto1() const { return parametros.pasto1; }
    const std::vector<sf::Sprite>& obtenerpasto3() const { return parametros.pasto3; }
    const std::vector<sf::Sprite>& obtenercasa() const { return parametros.casa; }
    const std::vector<sf::Sprite>& obtenerlago() const { return parametros.lago; }

private:
    void cargarTextura();
    ParametrosCreacion parametros;
    std::unique_ptr<creareelemento> generadorElemento;
};


void crearcamino::crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const {
    parametros.caminos.clear();
    for (const auto& pos : posiciones) {
        sf::RectangleShape camino(sf::Vector2f(300.f, 400.f));
        camino.setPosition(pos);
        camino.setFillColor(sf::Color(
            63, 49, 12));
        parametros.caminos.push_back(camino);
    }
}

void crearpasto::crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const {
    parametros.pastos2.clear();
    for (const auto& pos : posiciones) {
        sf::RectangleShape pasto(sf::Vector2f(50.f, 50.f));
        pasto.setPosition(pos);
        pasto.setFillColor(sf::Color(12, 74, 41));
        parametros.pastos2.push_back(pasto);
    }
}

void crearflor::crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const {
    parametros.flores.clear();
    for (const auto& pos : posiciones) {
        sf::Sprite flor;
        flor.setTexture(parametros.texturaFlor);
        flor.setPosition(pos);
        parametros.flores.push_back(flor);
    }
}

void crearflor2::crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const {
    parametros.flores2.clear();
    for (const auto& pos : posiciones) {
        sf::Sprite flor2;
        flor2.setTexture(parametros.texturaFlor2);
        flor2.setPosition(pos);
        parametros.flores2.push_back(flor2);
    }
}

void creartumba1::crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const {
    parametros.tumba1.clear();
    for (const auto& pos : posiciones) {
        sf::Sprite tb1;
        tb1.setTexture(parametros.texturaTumba1);
        tb1.setPosition(pos);
        tb1.setScale(4.f, 4.f);
        parametros.tumba1.push_back(tb1);

    }
}
void creartumba2::crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const {
    parametros.tumba2.clear();
    for (const auto& pos : posiciones) {
        sf::Sprite tb2;
        tb2.setTexture(parametros.texturaTumba2);
        tb2.setPosition(pos);
        tb2.setScale(3.f, 3.f);
        parametros.tumba2.push_back(tb2);
    }
}
void creartumba3::crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const {
    parametros.tumba3.clear();
    for (const auto& pos : posiciones) {
        sf::Sprite tb3;
        tb3.setTexture(parametros.texturaTumba3);
        tb3.setPosition(pos);
        tb3.setScale(3.f, 3.f);
        parametros.tumba3.push_back(tb3);

    }
}
void creartumba4::crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const {
    parametros.tumba4.clear();
    for (const auto& pos : posiciones) {
        sf::Sprite tb4;
        tb4.setTexture(parametros.texturaTumba4);
        tb4.setPosition(pos);
        tb4.setScale(3.f, 3.f);
        parametros.tumba4.push_back(tb4);

    }
}


void crearpasto1::crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const {
    parametros.pasto1.clear();
    for (const auto& pos : posiciones) {
        sf::Sprite pt1;
        pt1.setTexture(parametros.texturaPasto1);
        pt1.setPosition(pos);
        parametros.pasto1.push_back(pt1);
    }
}

void crearpasto2::crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const {
    parametros.pasto2.clear();
    for (const auto& pos : posiciones) {
        sf::Sprite pt2;
        pt2.setTexture(parametros.texturaPasto2);
        pt2.setPosition(pos);
        parametros.pasto2.push_back(pt2);
    }
}

void crearcasa::crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const {
    parametros.casa.clear();
    for (const auto& pos : posiciones) {
        sf::Sprite cs;
        cs.setTexture(parametros.texturaCasa);
        cs.setPosition(pos);
        cs.setScale(2.f, 2.f);
        parametros.casa.push_back(cs);
    }
}
void crearlago::crear(const std::vector<sf::Vector2f>& posiciones, ParametrosCreacion& parametros) const {
    parametros.lago.clear();
    for (const auto& pos : posiciones) {
        sf::Sprite lg;
        lg.setTexture(parametros.texturalago);
        lg.setPosition(pos);
        lg.setScale(3.f, 3.f);
        parametros.lago.push_back(lg);
    }
}


Mapa::Mapa() {
    cargarTextura();
}

void Mapa::cargarTextura() {
    if (!parametros.texturaFlor.loadFromFile("./texturas/flor1.png") ||
        !parametros.texturaFlor2.loadFromFile("./texturas/flor2.png") ||
        !parametros.texturaTumba1.loadFromFile("./texturas/tumbas_0001.png") ||
        !parametros.texturaTumba2.loadFromFile("./texturas/tumbas_0002.png") ||
        !parametros.texturaTumba3.loadFromFile("./texturas/tumbas_0003.png") ||
        !parametros.texturaTumba4.loadFromFile("./texturas/tumbas_0004.png") ||
        !parametros.texturaPiedra1.loadFromFile("./texturas/piedra1.png") ||
        !parametros.texturaPiedra2.loadFromFile("./texturas/piedra2.png") ||
        !parametros.texturaPasto1.loadFromFile("./texturas/pasto1.png") ||
        !parametros.texturaPasto2.loadFromFile("./texturas/pasto2.png") ||
        !parametros.texturaPasto3.loadFromFile("./texturas/pasto3.png") ||

        !parametros.texturaCasa.loadFromFile("./texturas/casa.png") ||
        !parametros.texturalago.loadFromFile("./texturas/lago.png"))
    {

    }
}

void Mapa::creacion(std::unique_ptr<creareelemento> generador) {
    generadorElemento = std::move(generador);
}

void Mapa::crearelemento(const std::vector<sf::Vector2f>& posiciones) {
    if (generadorElemento) {
        generadorElemento->crear(posiciones, parametros);
    }
}

void Mapa::dibujar(sf::RenderWindow& ventana) {
    for (const auto& camino : parametros.caminos) {
        ventana.draw(camino);
    }
    for (const auto& pasto : parametros.pastos2) {
        ventana.draw(pasto);
    }
    for (const auto& flor : parametros.flores) {
        ventana.draw(flor);
    }
    for (const auto& flor2 : parametros.flores2) {
        ventana.draw(flor2);
    }
    for (const auto& tb1 : parametros.tumba1) {
        ventana.draw(tb1);
    }
    for (const auto& tb2 : parametros.tumba2) {
        ventana.draw(tb2);
    }
    for (const auto& tb3 : parametros.tumba3) {
        ventana.draw(tb3);
    }
    for (const auto& tb4 : parametros.tumba4) {
        ventana.draw(tb4);
    }
    for (const auto& piedra1 : parametros.piedra1) {
        ventana.draw(piedra1);
    }
    for (const auto& piedra2 : parametros.piedra2) {
        ventana.draw(piedra2);
    }
    for (const auto& pasto1 : parametros.pasto1) {
        ventana.draw(pasto1);
    }
    for (const auto& pasto3 : parametros.pasto3) {
        ventana.draw(pasto3);
    }

    for (const auto& casa : parametros.casa) {
        ventana.draw(casa);
    }
    for (const auto& lago : parametros.lago) {
        ventana.draw(lago);
    }
}

#endif 
