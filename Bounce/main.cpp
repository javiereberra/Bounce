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

	//establecer aceleracion en 0//
	float acceleration(0.1f);

	//booleano para activar el rozamiento
	bool rozamiento;

	rozamiento = false;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();


			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Key::R) {

					if (!rozamiento) {
						rozamiento = true;
					}
					else {
						rozamiento = false;
					}
					cout << rozamiento << endl;

				}
			}
		}
		//establecer el deltaTime a 60fps//
		float deltaTime = 1.0f / 60.0f;

		//la aceleración aplicada a la velocidad
		velocity += acceleration * deltaTime;

		//aplicar el movimiento ajustando la posición a la velocidad//
		position.y += velocity * deltaTime;

		if ((rozamiento) && (position.y >= 550.0f))
		{
			position.y = 550.0f;
			velocity = -velocity;
			velocity *= 0.75f;
		}


		if ((!rozamiento) && (position.y >= 550.0f))
		{
			position.y = 550.0f;
			velocity = -velocity;
			
		}





		window.clear();

		CircleShape object;
		object.setRadius(25);
		object.setPosition(position);
		object.setFillColor(Color::Blue);
		window.draw(object);

		window.display();

	}
}