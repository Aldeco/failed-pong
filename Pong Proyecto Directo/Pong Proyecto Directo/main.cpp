#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow ventana(VideoMode(1280, 720), "Pong");
	
	//float x = 0.f;
	//float y = 0.f;
	float movimiento = 5.f;
	int puntaje = 0;
	float dx = 0.f;
	float dy = 0.f;
	// pongo la png de la cancha
	Texture cancha_texture;
	Sprite cancha;
	cancha_texture.loadFromFile("Assets/Media/cuadricula.png");
	cancha.setTexture(cancha_texture);
	
	//creacion de rectangulo
	//RectangleShape rec(Vector2f(200, 200));
	//rec.setPosition(200, 200);
	//rec.setFillColor(Color::Cyan);
	// creacion de texto
	Font fuente;
	fuente.loadFromFile("Assets/Fonts/Sansation.ttf");
	Text texto(" ", fuente);
	texto.setFont(fuente);
	texto.setString(" Puntaje : ");
	texto.setStyle(Text::Bold);
	texto.setCharacterSize(50);
	texto.setFillColor(Color::Cyan);
	texto.setPosition(0, 0);

	// sprite bola y poss
	Texture bola;
	Sprite sprbola;
	bola.loadFromFile("Assets/Media/MushroomBall.png");
	sprbola.setTexture(bola);
	sprbola.setPosition(640, 360);
	//sprite.setColor(Color::Green);
	
	//sprite tuneles
	Texture tunel_Izq;
	Texture tunel_Der;
	Sprite tunelIzq;
	Sprite tunelDer;
	tunel_Izq.loadFromFile("Assets/Media/tunelizq.png");
	tunel_Der.loadFromFile("Assets/Media/tunelder.png");
	tunelIzq.setTexture(tunel_Izq);
	tunelDer.setTexture(tunel_Der);
	tunelIzq.setPosition(0,340);
	tunelDer.setPosition(1232, 340);

	//movimiento
	// loop ventana
	while (ventana.isOpen())
	{
		//////////////////MOVIMIENTOS , OBT COORD /////////////////////
		Vector2f bPos = sprbola.getPosition(); //obtengo posiciones de
		Vector2f pPos = tunelIzq.getPosition();// la bola y del jugador

		if (bPos.x < 0) dx = -movimiento;
		else if (bPos.x > 1100 - 10) dx = -movimiento;
		else if (bPos.y > 700 - 10) {
			//if (Keyboard::isKeyPressed(Keyboard::Numpad6)) sprbola.move(15.f,0.f);
			dx = 0;
			dy = 0;
		}

		if (bPos.x >= pPos.x && bPos.x <= pPos.x + 150)
		{
			if (bPos.y >= pPos.y - 10) {
				puntaje++;
				texto.setString(to_string(puntaje));
				dy = -movimiento;
			}
		}
		sprbola.move(dx, dy);

		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			dx = movimiento;
			dy = movimiento;
			puntaje = 0;
		}

		//////////////////////////////////////////////////////////////
		Event evento;
		while (ventana.pollEvent(evento))
		{
			if (evento.type == Event::Closed) 
			{
				ventana.close();
			}
			// movimientos del hongo w a s d
			else if (evento.type == Event::KeyPressed) {
				/*
				switch (evento.key.code) {
				// TUNEL IZQ
				case Keyboard::W: 
					tunelIzq.move(0.f, -movimiento);
					break;
				case Keyboard::S:
					tunelIzq.move(0.f, movimiento);
					break;
				// TUNEL DER
				case Keyboard::Numpad8:
					tunelDer.move(0.f, -movimiento);
					break;
				case Keyboard::Numpad2:
					tunelDer.move(0.f, movimiento);
					break;
				}*/
				if (Keyboard::isKeyPressed(Keyboard::W))
				{
					tunelIzq.move(0.f, -movimiento);
				}
				else if (Keyboard::isKeyPressed(Keyboard::S)) 
				{
					tunelIzq.move(0.f, movimiento);
				}
				if (Keyboard::isKeyPressed(Keyboard::Numpad8))
				{
					tunelDer.move(0.f, -movimiento);
				}
				else if (Keyboard::isKeyPressed(Keyboard::Numpad2))
				{
					tunelDer.move(0.f, movimiento);
				}
			}
		}
		ventana.clear(Color::Transparent);
		ventana.draw(cancha);
		ventana.draw(texto);
		//ventana.draw(rec);
		ventana.draw(sprbola);
		ventana.draw(tunelIzq);
		ventana.draw(tunelDer);
		ventana.display();
	}
	return 0;
}