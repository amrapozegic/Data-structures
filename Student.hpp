#pragma once
#include<vector>
#include<iostream>
#include"RezultatIspita.hpp"

class Student{
  public:
Student()=default;
Student(int index,std::string ime,std::string prezime);

int index(){
return index_;
}

std::string imePrezime(){
return ime_+" "+prezime_;
}


void polozeniIspit(RezultatIspita polIspit){
polozeniIspiti_.push_back(polIspit);
}
void dohvatiPolozeneIspiteProsjek();

  private:
    int index_;
    std::string ime_;
    std::string prezime_;
    std::vector<RezultatIspita> polozeniIspiti_;
};
