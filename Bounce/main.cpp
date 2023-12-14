#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Bounce");

	//establecer posicion//
	Vector2f position(400.0f, 100.0f);

	//establecer velocidad vertical//
	float velocity(0.0f);

	//establecer aceleracion de la gravedad//
	float acceleration(0.1f);

	//booleano para activar el rozamiento
	bool rozamiento;

	//empezar sin el rozamiento//
	rozamiento = false;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			// Opción por teclado (tecla R) para activar o desactivar el rozamiento del rebote de la esfera

			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Key::R) {

					if (!rozamiento) {
						rozamiento = true;
					}
					else {
						rozamiento = false;
					}
					//controlar por consola si el rozamiento está activado o no//
					cout << rozamiento << endl;

				}
			}
		}
		//establecer el deltaTime a 60fps//
		float deltaTime = 1.0f / 60.0f;

		//aplicar la gravedad a la velocidad
		velocity += acceleration * deltaTime;

		//aplicar el movimiento ajustando la posición a la velocidad//
		position.y += velocity * deltaTime;


		//condicional para aplicar el rebote con el suelo con o sin el rozamiento

		if ((rozamiento) && (position.y >= 550.0f))
		{
			//Establecer el límite vertical o suelo
			position.y = 550.0f;
			//invertir el sentido de la velocidad para efectuar el rebote
			velocity = -velocity;
			//aquí se le aplica el rozamiento a la velocidad
			velocity *= 0.75f;
		}

		if ((!rozamiento) && (position.y >= 550.0f))
		{
			position.y = 550.0f;
			velocity = -velocity;
			
		}


		//dibujar la esfera
		window.clear();

		CircleShape object;
		object.setRadius(25);
		object.setPosition(position);
		object.setFillColor(Color::Blue);
		window.draw(object);

		window.display();

	}
}