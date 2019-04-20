
#include "cities.hh"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <utility>
#include <algorithm>
#include <cstdlib>
std::istream& operator>> (std::istream& is, Cities& cities)
{
	Cities::coord_t currentXY;
	char currentX[4];
	is.getline(currentX,4,' ');
	char currentY[4];
	is.getline(currentY, 4);
	std::string XString=std::string(currentX);	
	std::string YString=std::string(currentY);
	std::string::size_type sz;
	int XInt= std::stoi(XString,&sz);
	int YInt= std::stoi(YString,&sz);
	currentXY.first=XInt;
	currentXY.second=YInt;
	cities.add_city(currentXY);
	return is;

}

void Cities::add_city(Cities::coord_t currentXY)
{
	cityLocations.push_back(currentXY);	
}
std::ostream& operator<< (std::ostream& os, Cities& cities)
{
	for (int i=0; i<cities.get_size(); i++)
	{
		auto currentCoord=cities.get_coord(i);
		int currentX=std::get<0>(currentCoord);
		int currentY=std::get<1>(currentCoord);
		os<<currentX<<" "<<currentY;
		os<<"\n";
	}
	return os;
}

double Cities::total_path_distance(const Cities::permutation_t& ordering) const
{
	double total_distance=0;
	for(int i=0; i<=ordering.size(); i++)
	{
		if (i==ordering.size()) 
		{
			total_distance+=abs(hypot(cityLocations[i].first-cityLocations[0].first,cityLocations[i].second-cityLocations[0].second));
		}
		else
		{

			total_distance+=abs(hypot(cityLocations[i].first-cityLocations[i+1].first,cityLocations[i].second-cityLocations[i+1].second));
		}
	}
	return total_distance;
}
//Cities::Cities Cities::reorder(const Cities::permutation_t& ordering) const
//{
//	Cities newCity;
//	for(int i=0; i<ordering.size();i++)
//	{
//		newCity.add_city(cityLocations[ordering[i]]);
//	}
//	return newCity;	
//}

void Cities::random_permutation(unsigned len)
{
	std::random_shuffle(currentOrder.begin(), currentOrder.end());
}
