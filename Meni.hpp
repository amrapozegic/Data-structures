#pragma once
#include<unordered_map>
#include <vector>

#include"Predmet.hpp"
#include"Student.hpp"
#include"Ispit.hpp"

#include"RezultatIspita.hpp"

class Meni{
public:
void dodajNovogaStudenta();

void dodajIspit();

void dodajPredmet();

void dodajRezultat();

void dohvatiIspitePoDatumu();

void dohvatiStudenteKojiSuPolozili();

void dohvatiSvePolozeneIspiteStudenta();

private:
  std::unordered_map<int,Student> popisStudenata_;
  std::unordered_map<int,std::vector<Ispit>> popisIspita_;
  std::unordered_map<std::string,Predmet> popisPredmeta_;
  std::unordered_map<int,std::unordered_map<std::string,std::vector<RezultatIspita>>> rezultati_;
};
