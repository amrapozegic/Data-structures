#include "Student.hpp"
#include <iostream>

 Student::Student(int index, std::string ime,std::string prezime)
    : index_{index}, ime_{ime},prezime_{prezime}{}

void Student::dohvatiPolozeneIspiteProsjek(){
  if(polozeniIspiti_.size()==0){
  std::cout << "Student "<<imePrezime()<<" nema položenih ispita" << std::endl;
  return;
  }
  std::cout << "Student "<<imePrezime()<<" je položio ispite iz sledećih predmeta " << std::endl;
 double temp=0;
  for(auto& polIspit:polozeniIspiti_){
  std::cout <<"Datum: ";
  polIspit.datum().printDatum();
  temp+=polIspit.ocjena();  
  std::cout<<" Predmet: "<< polIspit.nazivPredmeta() <<" Ocjena: "<<polIspit.ocjena()<< std::endl;
}
std::cout << "Prosječna ocjena studenta iznosi: " <<temp/polozeniIspiti_.size()<< std::endl;
}


