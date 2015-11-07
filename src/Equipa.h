#ifndef EQUIPA_H
#define EQUIPA_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

#include "Desporto.h"
#include "Atleta.h"
#include "Modalidade.h"

// falta header files
using namespace std;

class Equipa {
private:
	string nameFile; // nome do ficheiro txt que vai guardar(depende consoante o idN)
	string nome;

	vector<Desporto *> desportosInscritos;
	vector<medalha> medalhas;
	vector<Atleta> atletasInscritos;

public:
	/*
	 * Cria uma equipa, pedindo ao utilizador que introduza o nome
	 * Atualiza o nome do ficheiro onde vai ser guardada a equipa para nome.txt, sendo nome o nome da equipa
	 */
	Equipa();

	/*
	 * @param filename nome do ficheiro de equipa
	 *
	 * Cria uma equipa, lendo de um ficheiro a seua configuracao.
	 */
	Equipa(string filename);

	/*
	 * Le a configuracao da equipa a partir do ficheiro
	 */
	void addAthletesFromFile();

	/*
	 * @param nome nome do atleta a criar
	 *
	 * Cria um atleta com o nome pretendido e adiciona-o ao vetor atletasInscritos.
	 *
	 * @return true se for possivel adicionar o atleta
	 * @return false se ja existir esse atleta e nao for possivel adiciona-lo
	 */
	bool addAtleta(string nome);

	/*
	 * @param nome nome do atleta a criar
	 *
	 * Remove o atleta com o nome pretendido do vetor atletasInscritos.
	 *
	 * @return true se for possivel remover o atleta
	 * @return false se nao existir esse atleta e nao for possivel remove-lo
	 */
	bool removeAtleta(string nome);

	/*
	 * Grava num ficheiro .txt com o nome igual ao nome da equipa
	 * as informacoes necessarias para carregar a equipa quando voltar a abrir o programa
	 */
	void writetoFile(); //TODO falta tudo

	/*
	 * @return nome da equipa
	 */
	string getNomeEquipa() const;

	/*
	 * @return vetor de atletas da equipa
	 */
	vector<Atleta> getAtletas() const;

	/*
	 * @param Atletas vetor de atletas
	 *
	 * Substitui o vetor atletasInscritos, que contem os atletas da equipa, pelo vetor Atletas
	 */
	void setAtletas(vector<Atleta> Atletas);

	/*
	 * @param equipa a comparar
	 *
	 * Compara duas equipas
	 *
	 * @return true se o nome for igual
	 * @return false se o nome for diferente
	 */
	bool operator == (const Equipa& eqi) const;

	/*
	 * @param desporto nome do desporto
	 * @param modalidade nome da modalidade
	 *
	 * Remove a modalidade especificada
	 */
	void removeModalidade(string desporto,string modalidade);

	class EquipaNaoExistente
	{
	public:
		string nomeficheiro;
		EquipaNaoExistente(string nomeficheiro);
	};
};
bool ordenaAlfaEquipa(const Equipa A, const Equipa B);
#endif
