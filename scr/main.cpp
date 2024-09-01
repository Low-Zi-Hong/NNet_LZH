// Ai_V1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "AI/AI.h"
#include "OTHER/other.h"


N_Net::Neuron_Network m_Neu_Net;

int main()
{
    std::cout << "Hello World!\n";
    
    
    if (OTHER::Check_Old_Network)
    {
        m_Neu_Net = OTHER::Load_N_Net_From_File();
    }
    else
    {
        //m_Neu_Net = N_Net::Init_Generate_Neuron_Network();
        OTHER::Save_N_Net_To_File(m_Neu_Net);
    }

    m_Neu_Net = N_Net::Init_Generate_Neuron_Network();

    std::cout << m_Neu_Net.NNet_to_string();

    std::vector<std::vector<float>> m_A = { {1,2,3},{6,7,8},{11,12,13},{16,17,18},{21,22,23} };
    std::vector<std::vector<float>> m_B = { {1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15} };
    std::vector<std::vector<float>> m_C = MATH::Matrix_Addition(m_A, m_B);

    for (std::vector<float> i : m_C)
    {
        for (float o : i)
        {
            std::cout << std::to_string(o) << "\t";
        }
        std::cout << std::endl;
    }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
