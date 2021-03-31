#include "Features.h"


template <typename T>
bool Contains(std::vector<T> l, T a)
{
	return std::find(l.begin(), l.end(), a) != l.end();
}


int OtherPixelDistance(sf::Image* input,int x, int y)
{
	//Gets the distance between the pixel and the nearest pixel that isn't water
	std::vector<sf::Vector2i> checked;
	std::vector<sf::Vector2i> current;
	std::vector<sf::Vector2i> next;

	bool found = false;
	int distance = 0;
	bool validTemp;
	current.push_back(sf::Vector2i(x,y));

	while (!found)
	{
		distance++;
		for (size_t i = 0; i < current.size(); i++)
		{
			validTemp = false;
			if (input->getPixel(current[i].x + 1,current[i].y) == sf::Color(196,0,0) || input->getPixel(current[i].x + 1, current[i].y) == sf::Color(128, 0, 0))
			{
				validTemp = true;
				if (!Contains(checked,sf::Vector2i(current[i].x + 1, current[i].y))) // check to make sure that the pixel hasn't already been checked.
				{
					next.push_back(sf::Vector2i(current[i].x + 1, current[i].y));
				}
			}


			if (input->getPixel(current[i].x - 1, current[i].y) == sf::Color(196, 0, 0) || input->getPixel(current[i].x + 1, current[i].y) == sf::Color(128, 0, 0))
			{
				validTemp = true;
				if (!Contains(checked, sf::Vector2i(current[i].x - 1, current[i].y))) // check to make sure that the pixel hasn't already been checked.
				{
					next.push_back(sf::Vector2i(current[i].x - 1, current[i].y));
				}
			}


			if (input->getPixel(current[i].x, current[i].y + 1) == sf::Color(196, 0, 0) || input->getPixel(current[i].x + 1, current[i].y) == sf::Color(128, 0, 0))
			{
				validTemp = true;
				if (!Contains(checked, sf::Vector2i(current[i].x, current[i].y + 1))) // check to make sure that the pixel hasn't already been checked.
				{
					next.push_back(sf::Vector2i(current[i].x, current[i].y + 1));
				}
			}


			if (input->getPixel(current[i].x, current[i].y - 1) == sf::Color(196, 0, 0) || input->getPixel(current[i].x + 1, current[i].y) == sf::Color(128, 0, 0))
			{
				validTemp = true;
				if (!Contains(checked, sf::Vector2i(current[i].x, current[i].y - 1))) // check to make sure that the pixel hasn't already been checked.
				{
					next.push_back(sf::Vector2i(current[i].x, current[i].y - 1));
				}
			}


			if (!validTemp)
			{
				found = true;
			}


		}

		for (size_t i = 0; i < current.size(); i++)
		{
			checked.push_back(current[i]);
		}
		current.clear();
		for (size_t i = 0; i < next.size(); i++)
		{
			current.push_back(next[i]);
		}
		next.clear();


	}


	
	return distance;



}

sf::Image OceanBaking(sf::Image input)
{
	int tempDistance;

	tempDistance = OtherPixelDistance(&input,250,180);
	for (size_t i = 0; i < input.getSize().x; i++)
	{
		for (size_t j = 0; j < input.getSize().y; j++)
		{
			if (input.getPixel(i,j) == sf::Color(196,0,0))
			{
				tempDistance = OtherPixelDistance(&input,i,j);



			}
		}

	}


	
	return input;
}
