#pragma once
#include <iostream>  
class Datum{
  public:  
  Datum(int god,int mjesec, int dan)
    :godina_{god},mjesec_{mjesec},dan_{dan}{};
  int datumZaMapu(){
  return godina_+mjesec_*12+dan_*30;
  }
  void printDatum();
  private:
  int godina_;
  int mjesec_;
  int dan_;
  };

