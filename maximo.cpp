#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  cout.precision(6);
  cout.setf(ios::scientific);

  int Total = 801;
  
  int col1[Total];
  float col2[Total];
  float col3[Total];
  
  ifstream datos;
  datos.open("datos.data");
  int num = 0;
  /*for(int j = 0; j <= Total - 1; ++j)
    {
      datos >> col1[j];
      datos >> col2[j];
      datos >> col3[j];
    }
  */
  while(!datos.eof())
    {
      datos >> col1[num] >> col2[num] >> col3[num]; 
      //datos >> col2[num];
      //datos >> col3[num];
      num++;
    }
  datos.close();
  
  /*
  for(int j = 0; j <= Total - 1; ++j)
    {
      cout << j  << "\t" <<col2[j] << "\t" << col3[j] << endl; 
    }
  */

  cout << "MAXIMOS:" << endl;
  
  
  for(int j = 0; j <= Total - 2; ++j)
    {
      if(col2[j-1] < col2[j] && col2[j] > col2[j+1])
	{
	  cout 
	    << "Longitud de Onda:" 
	    << "\t" 
	    << col1[j] 
	       << "\t" << "Reflactancia:" 
	    << "\t" << col2[j] << endl;
	}
    }
    

  
  cout << "MINIMOS:" << endl;
  
  for(int j = 0; j <= Total - 2; ++j)
    {
      if(col2[j-1] > col2[j] && col2[j] < col2[j+1])
	{
	  cout 
	    << "Longitud de Onda:" 
	    << "\t" 
	    << col1[j] 
	    << "\t" 
	    << "Reflactancia:" 
	    << "\t" << col2[j] << endl;
	}
    }
  
  
  return 0;
}
