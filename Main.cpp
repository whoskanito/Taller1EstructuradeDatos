#include <iostream>
#include <fstream>
#include <string>
#include "Paciente.hpp"
#include "Servicio.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "List.hpp"
using namespace std;

int main() 
{
    cout << "Hola" << endl;

    return 0;
}

Paciente* extraerPaciente(string linea)
{
    string datos[4];
    int indice = 0;

    const char* inicio = linea.c_str(); 
    const char* actual = inicio;

    while (*actual != '\0') 
    {
        if (*actual == ';') 
        {
            datos[indice].assign(inicio, actual - inicio); 
            indice++;
            actual++;
            
            if (*actual == ' ') 
            {
                actual++; 
            }
            inicio = actual;
        } 
        else 
        {
            actual++; 
        }
    }
    datos[indice].assign(inicio, actual - inicio);

    return new Paciente(datos[0], datos[1], stoi(datos[2]), datos[3]);
}

Servicio* buscarServicio(List<Servicio*>& hospital, string nombre) 
{
    for (int i = 0; i < hospital.getSize(); i++) 
    {
        Servicio* s = hospital.get(i);
        if (s->getNombre() == nombre) 
        {
            return s;
        }
    }
    return nullptr;
}















