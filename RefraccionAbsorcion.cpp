#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

double indice_sustrato(double Trans_Sustrato);
double Minimos(double x);
double Constante_M(double Trans_Sustrato, double Longitud_Onda);
double Indice(double Trans_Sustrato, double Longitud_Onda);

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

  for(int k = 371; k < Total; ++k)
    {
      std::cout << Longitud_Onda[k] << "\t" << Indice(Trans_Sustrato[k], Longitud_Onda[k]) << std::endl;
    }


  Transmitancia.close();
}

double indice_sustrato(double Trans_Sustrato)
{
  double a = (1/Trans_Sustrato);
  double b = 1/std::pow(Trans_Sustrato, 2);
  double c = std::pow(b-1, 0.5);
  return a + c;
}


double Minimos(double x)
{
  return -15.1254 + (0.0739107*x) - (0.000129765*std::pow(x, 2)) + (1.00331e-07*std::pow(x, 3)) - (2.88078e-11*std::pow(x, 4));
}

double Constante_M(double Trans_Sustrato, double Longitud_Onda)
{
  double s = indice_sustrato(Trans_Sustrato);
  double T_m = Minimos(Longitud_Onda);
  double resultado = ((2.0*s)/T_m) - ((std::pow(s, 2) + 1.0)/2.0);
  return resultado;
}

double Indice(double Trans_Sustrato, double Longitud_Onda)
{
  double M = Constante_M(Trans_Sustrato, Longitud_Onda);
  double s = indice_sustrato(Trans_Sustrato);
  double resultado = std::pow(M + std::pow((std::pow(M, 2)) - (std::pow(s, 2)), 0.5), 0.5);
  return resultado;
}
