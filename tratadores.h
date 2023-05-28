#ifndef _TRATADORES_H_
#define _TRATADORES_H_

#include "dados.h"
void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno);
Endereco *construir_endereco();

Aluno *construir_aluno();

/*
    Busca um aluno
*/
Aluno *buscar_aluno(Aluno **alunos, int *posicao);

void imprimir_aluno(Aluno *aluno);

void imprimir_endereco(Endereco *endereco);

void tratador_menu_prof(Professor **professores, int *qtd_atual_prof);

Professor *construir_professor();

Professor *buscar_professor(Professor **professores, int *posicao);

void imprimir_professor(Professor *professor);


#endif