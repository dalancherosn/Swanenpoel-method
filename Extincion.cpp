#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath> 

double Indice_Sustrato(double Trans_Sustrato);
double Minimos(double x);
double Maximos(double x);
double Constante_M(double Trans_Sustrato, double Longitud_Onda);
double Indice(double Trans_Sustrato, double Longitud_Onda);
double Extincion1(double Trans_Sustrato, double Longitud_Onda);
double Extincion2(double Trans_Sustrato, double Longitud_Onda);
double Extincion3(double Trans_Sustrato, double Longitud_Onda);
double Extincion4(double Trans_Sustrato, double Longitud_Onda);
double Extincion5(double Trans_Sustrato, double Longitud_Onda);

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

  for(int k = 1; k < Total - 1; ++k)
    {
      std::cout << "\t" << Longitud_Onda[k] 
		<< "\t" << Extincion1(Trans_Sustrato[k], Longitud_Onda[k])
		<< "\t" << Extincion2(Trans_Sustrato[k], Longitud_Onda[k])
		<< "\t" << Extincion3(Trans_Sustrato[k], Longitud_Onda[k])
		<< "\t" << Extincion4(Trans_Sustrato[k], Longitud_Onda[k])
		<< "\t" << Extincion5(Trans_Sustrato[k], Longitud_Onda[k])
		<< std::endl;
    }

  Transmitancia.close();
}

double Indice_Sustrato(double Trans_Sustrato)
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


double Constante_M(double Trans_Sustrato, double Longitud_Onda)
{
  double s = Indice_Sustrato(Trans_Sustrato);
  double T_m = Minimos(Longitud_Onda);
  double resultado = ((2.0*s)/T_m) - ((std::pow(s, 2) + 1.0)/2.0);
  return resultado;
}

double Indice(double Trans_Sustrato, double Longitud_Onda)
{
  double M = Constante_M(Trans_Sustrato, Longitud_Onda);
  double s = Indice_Sustrato(Trans_Sustrato);
  double resultado = std::pow(M + std::pow((std::pow(M, 2)) - (std::pow(s, 2)), 0.5), 0.5);
  return resultado;
}

double Extincion1(double Trans_Sustrato, double Longitud_Onda)
{
  double n = Indice(Trans_Sustrato, Longitud_Onda);
  double s = Indice_Sustrato(Trans_Sustrato);
  double Max = Maximos(Longitud_Onda);
  double E_M = ((8*std::pow(n, 2)*s)/(Max)) + ((std::pow(n, 2) - 1) * (std::pow(n, 2) - std::pow(s, 2)));
  double a = std::pow(E_M, 2) - std::pow(std::pow(n, 2) - 1, 3)*(std::pow(n, 2) - std::pow(s, 4));
  double b = std::pow(a, 0.5);
  double c = E_M - b;
  double d = std::pow(n - 1, 3)*(n - std::pow(s, 2));
  double x = c/d;
  return x;
}

double Extincion2(double Trans_Sustrato, double Longitud_Onda)
{
  double n = Indice(Trans_Sustrato, Longitud_Onda);
  double s = Indice_Sustrato(Trans_Sustrato);
  double Min = Minimos(Longitud_Onda);
  double E_m = ((8*std::pow(n, 2)*s)/(Min)) - ((std::pow(n, 2) - 1) * (std::pow(n, 2) - std::pow(s, 2)));
  double a = std::pow(E_m, 2) - std::pow(std::pow(n, 2) - 1, 3)*(std::pow(n, 2) - std::pow(s, 4));
  double b = std::pow(a, 0.5);
  double c = E_m - b;
  double d = std::pow(n - 1, 3)*(n - std::pow(s, 2));
  double x = c/d;
  return x;
}

double Extincion3(double Trans_Sustrato, double Longitud_Onda)
{
  double n = Indice(Trans_Sustrato, Longitud_Onda);
  double s = Indice_Sustrato(Trans_Sustrato);
  double T_1 = (2*Maximos(Longitud_Onda)*Minimos(Longitud_Onda))/(Maximos(Longitud_Onda) + Minimos(Longitud_Onda));
  double F = (8*std::pow(n, 2)*s)/(T_1);
  double a = std::pow(F, 2) - std::pow(std::pow(n, 2) - 1, 3)*(std::pow(n, 2) - std::pow(s, 4));
  double b = std::pow(a, 0.5);
  double c = F - b;
  double d = std::pow(n - 1, 3)*(n - std::pow(s, 2));
  double x = c/d;
}

double Extincion4(double Trans_Sustrato, double Longitud_Onda)
{
  double n = Indice(Trans_Sustrato, Longitud_Onda);
  double s = Indice_Sustrato(Trans_Sustrato);
  double T_a = std::pow(Maximos(Longitud_Onda)*Minimos(Longitud_Onda), 0.5);
  double a = std::pow(n, 2)*std::pow(std::pow(n, 2) - 1, 2)*std::pow(std::pow(s, 2) - 1, 2);
  double b = std::pow(std::pow(n, 2) - 1, 2)*std::pow(std::pow(n, 2) - std::pow(s, 2), 2);
  double c = (128*std::pow(n, 4)*std::pow(s, 2))/(std::pow(T_a, 2));
    double G = c + a + b;
    double A = std::pow(std::pow(G, 2) - std::pow(std::pow(n, 2) - 1, 6) * std::pow(std::pow(n, 2) - std::pow(s, 4), 2), 0.5);
    double B = std::pow(G - A, 0.5);
    double C = std::pow(n - 1, 3)*(n - std::pow(s, 2));
    double x = B/C;
    return x;
}

double Extincion5(double Trans_Sustrato, double Longitud_Onda)
{
  double s = Indice_Sustrato(Trans_Sustrato);
   double T_a = std::pow(Maximos(Longitud_Onda)*Minimos(Longitud_Onda), 0.5);
   double H = (4*std::pow(s, 2))/((std::pow(s, 2) + 1)*std::pow(T_a, 2)) - (std::pow(s, 2) + 1)/2;
   double T_m = Minimos(Longitud_Onda);
   double T_M = Maximos(Longitud_Onda);
   double D = T_M/T_m;
   double n = std::pow(H + std::pow(std::pow(H, 2) - std::pow(s, 2), 0.5), 0.5);
   double x = ((n+1)*(s+n)*(1-std::pow(D, 0.5)))/((n-1)*(s-n)*(1+std::pow(D, 0.5)));
   return x;
}
