#include "cities.hh"
#include <istream>
#include <string>
#include <cmath>
#include <iostream>
#include <assert.h>
#include <fstream>
int main()
{
	std::string problem;
	problem= "challenge.tsv";
	Cities cities;
	std::ifstream myfile;
	myfile.open(problem);
	if (myfile.is_open())
	
	{
		std::cout<<"this works";
		myfile>>cities;
		if (myfile.eof())
		{
			myfile.close();
		}
	}

	int trials;
	trials=1000000;
	double shortest=cities.total_path_distance(cities.get_current_permutation());
	Cities::permutation_t shortestRoute;
	for(int i=0; i<trials; i++)
	{	double current=cities.total_path_distance(cities.get_current_permutation());
		if (shortest<current)
		{
			std::cout<<i<<"       "<<cities.total_path_distance(cities.get_current_permutation())<<"\n";
			shortest=current;
			shortestRoute=cities.get_current_permutation();
		}
		cities.random_permutation(cities.get_size());
	
	}
	//std::ofstream optimalPath("optimalpath.tsv");
	//otpimalPath>>cities;
	return 0;
}
