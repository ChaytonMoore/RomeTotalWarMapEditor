#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Features.h"


sf::Color BackGrey(62,62,66);

enum MapMode
{
	RegionsMapMode,
	GroundMapMode
};

MapMode CurrentMapMode;

int Brushsize;


Button BakeOcean(sf::Vector2i(10,10),"Bake Ocean");

void BrushWindowRender(sf::RenderWindow* window)
{

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}


		
		window->clear(BackGrey);


		window->display();

}

void OptionWindowRender(sf::RenderWindow* window)
{

	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}



	window->clear(BackGrey);
	BakeOcean.Render(window);

	window->display();

}

int main()
{



	//This part of the code loads all of the maps
	sf::Texture Regions;
	Regions.loadFromFile("map_regions.tga");

	sf::Texture Ground;
	sf::Image GroundImage = Ground.copyToImage();
	Ground.loadFromFile("map_ground_types.tga");


	//Open windows
	sf::RenderWindow window(sf::VideoMode(Regions.getSize().x*4 + 2, Regions.getSize().y*4 + 2), "Rome Total War Map Editor");
	sf::RenderWindow BrushWindow(sf::VideoMode(150, 700), "Brushes", sf::Style::Titlebar);
	sf::RenderWindow OptionWindow(sf::VideoMode(150, 700), "Options", sf::Style::Titlebar);
	
	BrushWindow.setPosition(sf::Vector2i(1500,100));
	OptionWindow.setPosition(sf::Vector2i(50, 100));

	


	CurrentMapMode = GroundMapMode; // Temp


	//Setting up all the potential sprites
	sf::Sprite RegionsSprite;
	RegionsSprite.setTexture(Regions);
	RegionsSprite.setScale(4,4);

	sf::Sprite GroundSprite;
	GroundSprite.setTexture(Ground);
	GroundSprite.setScale(2, 2);

	OceanBaking(GroundImage);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		//Rendering, uses a switch based on what's being renderd
		window.clear();
		switch (CurrentMapMode)
		{
		case RegionsMapMode: window.draw(RegionsSprite); break;
		case GroundMapMode: window.draw(GroundSprite); break;
		}
		BrushWindowRender(&BrushWindow);
		OptionWindowRender(&OptionWindow);
		window.display();
	}

	return 0;
}
