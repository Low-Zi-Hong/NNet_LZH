#include <iostream>
#include <vector>
#include <random>

#include "AI/AI.h"
#include "MATH/math.h"
//try not to add other more header files, make it as simple as posible for furture use

N_Net::Neuron_Network N_Net::Init_Generate_Neuron_Network()
{
	N_Net::Neuron_Network _buffer;

	std::default_random_engine gen;

	std::normal_distribution<float> normal_distribution{ 0.0,1.0 }; //normal_distribution
	//here is to generate the initial form of network which contain just random variables

	for (int i = 0; i < _buffer.bias.size(); i++) // row
	{
		for (int o = 0; o < _buffer.bias[i].size();o++)
		{
			_buffer.bias[i][o] = normal_distribution(gen);
		}
	}

	for (int i = 0; i < _buffer.weight_matrix.size(); i++) // row
	{
		for (int o = 0; o < _buffer.weight_matrix[i].size(); o++)
		{
			for (int p = 0; p < _buffer.weight_matrix[i][o].size(); p++)
			{
				_buffer.weight_matrix[i][o][p] = normal_distribution(gen);
			}
		}
	}

	return _buffer;
}

N_Net::Neuron_Network N_Net::Run_Neural_Network()
{
	N_Net::Neuron_Network _buffer;
	//This is for the real calculation of neural network

	return _buffer;
}

N_Net::Neuron_Network N_Net::Back_Propagation_Neural_Network()
{
	N_Net::Neuron_Network _buffer;
	//This is where the Network learn

	return _buffer;
}

std::vector<float> N_Net::Calculate_Cost_Function()
{
	std::vector<float> _cost;
	//This is for calculating the Cost Function of the Current Network especially for Back propagation
	// C(w,b)

	return _cost;
}