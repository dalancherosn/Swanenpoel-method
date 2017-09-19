#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

double indice_sustrato(double Trans_Sustrato);

int main()
{
  std::cout.precision(6);
  std::cout.setf(std::ios::scientific);
  
  int Total = 801;
  
  int Longitud_Onda[Total];
  double Trans_Pelicula[Total];
  double Trans_Sustrato[Total];
  
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


double indice_sustrato(double Trans_Sustrato)
{
  double a = (1/Trans_Sustrato);
  double b = 1/std::pow(Trans_Sustrato, 2);
  double c = std::pow(b-1, 0.5);
  return a + c;  
}
