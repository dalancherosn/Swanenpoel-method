#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

float indice_sustrato(float Trans);

int main()
{
  std::cout.precision(6);
  std::cout.setf(std::ios::scientific);
  
  int Total = 801;
  
  int Longitud_Onda[Total];
  float Trans_Pelicula[Total];
  float Trans_Sustrato[Total];
  
  std::ifstream Transmitancia;
  Transmitancia.open("datos.data");
  int n = 0;
  
  while(!Transmitancia.eof())
    {
      Transmitancia >> Longitud_Onda[n] >> Trans_Pelicula[n] >> Trans_Sustrato[n];
      n += 1;
    }
  
  for(int j = 0; j <= Total-1; ++j)
    {
      std::cout << Longitud_Onda[j] << "\t" << Trans_Sustrato[j] << "\t" << indice_sustrato(Trans_Sustrato[j]) << std::endl;
    } 
  
  Transmitancia.close();
  
  return 0;
}


float indice_sustrato(float Trans)
{
  return (1.0/Trans) + std::pow((1.0/Trans)-1, 0.5);
}
