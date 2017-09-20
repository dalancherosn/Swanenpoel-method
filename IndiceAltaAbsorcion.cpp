#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

double indice_sustrato(double Trans_Sustrato);
double Constante_N(double Trans_Sustrato, double Longitud_Onda);
double Minimos(double x);
double Maximos(double x);
double indice(double Trans_Sustrato, double Longitud_Onda); 

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
  
  for(int k = 241; k <= 371; ++k)
    {
      std::cout << Longitud_Onda[k] << "\t" 
	//	<< Trans_Sustrato[k] << "\t"
	//	<< indice_sustrato(Trans_Sustrato[k]) << "\t"
	//	<< Minimos(Longitud_Onda[k]) << "\t"
	//	<< Maximos(Longitud_Onda[k]) << "\t"
	//	<< Constante_N(Trans_Sustrato[k], Longitud_Onda[k]) << "\t"
		<< indice(Trans_Sustrato[k], Longitud_Onda[k]) << "\t"
		<< std::endl;
    }

  return 0;
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


double Maximos(double x)
{
  if(540.0 <= x && x < 740.0)
    {
      return -35.8213 + (0.0811269*x) + (0.0000575861*std::pow(x, 2)) - (8.24222e-08*std::pow(x, 3)) - (1.99735e-10*std::pow(x, 4)) - (1.01387e-13*std::pow(x, 5)) + (2.77914e-16*std::pow(x, 6)) + (5.5642e-19*pow(x, 7)) - (5.81518e-22*pow(x, 8));
    }
  else if(740.0 <= x  && x < 1100.0)
    {
      return 0.911005 + (4.10085e-06*x);
    }
  else
    {
      return 0;
    }
}


double Constante_N(double Trans_Sustrato, double Longitud_Onda)
{
  double T_m = Minimos(Longitud_Onda);
  double T_M = Maximos(Longitud_Onda);
  double s = indice_sustrato(Trans_Sustrato);

  double a = T_M - T_m;
  double b = T_M * T_m;
  double c = a / b;
  double d = (std::pow(s, 2) + 1)/2;
  double Resultado = (2*s*c) + d;
  return Resultado;
}

double indice(double Trans_Sustrato, double Longitud_Onda)
{
  double N = Constante_N(Trans_Sustrato, Longitud_Onda);
  double s = indice_sustrato(Trans_Sustrato);
  double a = std::pow(N, 2) - std::pow(s, 2);
  double b = std::pow(a, 0.5);
  double c = N + b;
  double resultado = std::pow(c, 0.5);
  return resultado;
}
