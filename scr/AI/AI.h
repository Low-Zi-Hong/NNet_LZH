#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "MATH/math.h"
//try not to add other more header files, make it as simple as posible for furture use

#define Num_Of_Input				10
#define Num_Of_Output				10
#define Array_Of_Neuron_Hidden		{3,4,3}

namespace N_Net {

	class Neuron_Network
	{
	public:
		std::vector<float> Input_Matrix;
		std::vector<float> Output_Matrix;		
		std::vector<std::vector<float>> bias;	//all of these are horizontal matrix, need to transpost be4 use

		std::vector<std::vector<std::vector<float>>> weight_matrix;

	private:
		std::vector<int> Array_Of_Hidden_Layer = Array_Of_Neuron_Hidden;

	public:
		Neuron_Network()
		{
			Input_Matrix.resize(Num_Of_Input, 0.0);	//Init Input
			Output_Matrix.resize(Num_Of_Output, 0.0);	//Init Output

			/*
				for exmple hidden layer of 3 , 5 , 3

				bias =	[	
							[ 0 , 0 , 0 ]			,
							[ 0 , 0 , 0 , 0 , 0 ]	,
							[ 0 , 0 , 0 ] 
						];
				Hope so lol...
			*/

			bias.resize(Array_Of_Hidden_Layer.size(), std::vector<float>(0.0));
			for (int i = 0; i < Array_Of_Hidden_Layer.size(); i++)
			{
				bias[i].resize(Array_Of_Hidden_Layer[i], 0.0);
			}

			/*
				for weight it seem a bit complicates, as example we have 2 inp, 2 oup and hidden layer with {3,3}
						x	n	n	y
							n	n
						x	n	n	y
				add:	0	1	2	3
			
				since 0 is a 2x1 matrix and 1 is a 3x1 matrix so we need a 3x2 matrix as weight_matrix, determines as follow

				(3 x 2)	 *	(2 x 1)	 =	(3 x 1)
				weight		Input		Output

				matrix = (inp.size(), out.size());
				
				ok it works
				for usage matrix[index of weight_matrix][row][column]
			*/
			
			weight_matrix.resize(Array_Of_Hidden_Layer.size() + 1, std::vector<std::vector<float>>(0.0));

			weight_matrix[0].resize(Input_Matrix.size(), std::vector<float>(Array_Of_Hidden_Layer[0]));
			for (int i = 1; i < weight_matrix.size() - 1; i++)
			{
				weight_matrix[i].resize(Array_Of_Hidden_Layer[i-1], std::vector<float>(Array_Of_Hidden_Layer[i]));
			}
			weight_matrix[weight_matrix.size() - 1].resize(Array_Of_Hidden_Layer.size(), std::vector<float>(Output_Matrix.size()));

		}

		std::string NNet_to_string()
		{
			//here is the network form to string
		
			std::string _buffer;

			//Input to string
			_buffer += "Input:\t[";
			for (float i : Input_Matrix)
			{
				_buffer += std::to_string(i);
				_buffer += " , ";
			}
			_buffer.resize(_buffer.size() - 3);
			_buffer += "]\n";

			//Bias to string
			_buffer += "Bias:\t[";
			for (std::vector<float> i : bias)
			{
				_buffer += "[";
				for (float o : i)
				{
					_buffer += std::to_string(o);
					_buffer += " , ";
				}
				_buffer.resize(_buffer.size() - 3);
				_buffer += "] , ";
			}
			_buffer.resize(_buffer.size() - 3);
			_buffer += "]\n";
			
			//weight to string
			_buffer += "Weight:\t[";
			for (std::vector<std::vector<float>> i : weight_matrix)
			{
				_buffer += "\n[";
				for (std::vector<float> o : i)
				{
					_buffer += "[";
					for (float p : o)
					{
						_buffer += std::to_string(p);
						_buffer += " , ";
					}
					_buffer.resize(_buffer.size() - 3);
					_buffer += "] , ";
				}
				_buffer.resize(_buffer.size() - 3);
				_buffer += "] , ";
			}
			_buffer.resize(_buffer.size() - 3);
			_buffer += "]\n";

			//output to string
			_buffer += "Output:\t[";
			for (float i : Output_Matrix)
			{
				_buffer += std::to_string(i);
				_buffer += " , ";
			}
			_buffer.resize(_buffer.size() - 3);
			_buffer += "]\n";

			return _buffer;
		}
	};


	N_Net::Neuron_Network Init_Generate_Neuron_Network();

	N_Net::Neuron_Network Run_Neural_Network();

	N_Net::Neuron_Network Back_Propagation_Neural_Network();

	std::vector<float> Calculate_Cost_Function();

}