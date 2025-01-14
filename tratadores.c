#include "tratadores.h"
#include "menus.h"
#include <stdio.h>
#include "constantes.h"
#include <string.h>

void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno)
{
    int opcao = menu_crud_aluno();
    Aluno *aluno = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_aluno >= MAX_ALUNO)
        {
            printf("Número máximo de alunos atingido\n");
        }
        else
        {
            // Passo 1: buscar posicao disponível
            int i = 0;
            for (; i < *qtd_atual_aluno; i++)
            {
                if (alunos[i] != NULL)
                {
                    // significa que esta posição está livre para uso
                    break;
                }
            }
            Aluno *aluno = construir_aluno();
            alunos[i] = aluno;
            *qtd_atual_aluno++;
        }
        break;
    case 2:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            imprimir_aluno(aluno);
        }
        else
        {
            printf("Aluno nao encontrado!!\n");
        }
    }
    break;
    case 3:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);

        if (aluno)
        {
            imprimir_aluno(aluno);
            printf("Atualizar aluno\n");
            printf("Nova Matricula\t> ");
            fgets(aluno->matricula, 9, stdin);
            printf("Novo CPF\t> ");
            fgets(aluno->cpf, 9, stdin);
            printf("Novo Nome\t> ");
            fgets(aluno->nome, 49, stdin);
            aluno->endereco = construir_endereco();
            printf("Aluno atualizado!\n");
        }
        else
        {
            printf("Aluno nao encontrado!!\n");
        }
        
    }

    break;
    case 4:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            destruirAluno(aluno);
            alunos[posicao] = NULL;
            printf("Aluno destruido\n");
        }
        else
        {
            printf("Aluno nao encontrado!!\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

Endereco *construir_endereco()
{
    Endereco endereco;

    printf("Logradouro\t> ");
    fgets(endereco.logradouro, 49, stdin);
    printf("Bairro\t> ");
    fgets(endereco.bairro, 49, stdin);
    printf("Cidade\t> ");
    fgets(endereco.cidade, 49, stdin);
    printf("Estado\t> ");
    fgets(endereco.estado, 9, stdin);
    printf("Número\t> ");
    fgets(endereco.numero, 9, stdin);

    return criarEndereco(endereco.logradouro, endereco.bairro, endereco.cidade, endereco.estado, endereco.numero);
}

Aluno *construir_aluno()
{
    Aluno aluno;
    printf("Matricula\t> ");
    fgets(aluno.matricula, 9, stdin);
    printf("CPF\t> ");
    fgets(aluno.cpf, 9, stdin);
    printf("Nome\t> ");
    fgets(aluno.nome, 49, stdin);
    aluno.endereco = construir_endereco();
    return criarAluno(aluno.matricula, aluno.cpf, aluno.nome, aluno.endereco);
}

Aluno *buscar_aluno(Aluno **alunos, int *posicao)
{
    char matricula[50];
    printf("Matricula > ");
    fgets(matricula, 49, stdin);
    Aluno *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_ALUNO; i++)
    {
        // Vamos testar se o aluno existe e se a matricula e a buscada
        // strcmp compara strings. Se for 0 indica que são iguais
        if (alunos[i] && !strcmp(matricula, alunos[i]->matricula))
        {
            resultado = alunos[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void imprimir_aluno(Aluno *aluno)
{
    printf("Matricula: %s", aluno->matricula);
    printf("Nome: %s", aluno->nome);
    printf("CPF: %s", aluno->cpf);
    imprimir_endereco(aluno->endereco);
}

void imprimir_endereco(Endereco *endereco)
{
    printf("Logradouro: %s", endereco->logradouro);
    printf("Numero: %s", endereco->numero);
    printf("Bairro: %s", endereco->bairro);
    printf("Cidade: %s", endereco->cidade);
    printf("Estado: %s", endereco->estado);
}

//professores 

Professor *construir_professor()
{
    Professor professor;
    printf("Matrícula\t> ");
    fgets(professor.matricula, 9, stdin);
    printf("CPF\t> ");
    fgets(professor.cpf, 9, stdin);
    printf("Nome\t> ");
    fgets(professor.nome, 49, stdin);
    professor.endereco = construir_endereco();
    
    return criarProfessor(professor.matricula, professor.cpf, professor.nome, professor.endereco);
}

Professor *buscar_professor(Professor **professores, int *posicao)
{
    char matricula[50];
    printf("Matricula > ");
    fgets(matricula, 49, stdin);
    Professor *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_PROFESSOR; i++)
    {

        if (professores[i] && !strcmp(matricula, professores[i]->matricula))
        {
            resultado = professores[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void imprimir_professor(Professor *professor)
{
    printf("Matricula: %s", professor->matricula);
    printf("Nome: %s", professor->nome);
    printf("CPF: %s", professor->cpf);
    imprimir_endereco(professor->endereco);
}

void tratador_menu_prof(Professor **professores, int *qtd_atual_prof){
    int opcao = menu_crud_professor();
    Professor *professor = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_prof >= MAX_PROFESSOR)
        {
            printf("Número máximo de professores atingido\n");
        }
        else
        {
            int i = 0;
            for (; i < *qtd_atual_prof; i++)
            {
                if (professores[i] != NULL)
                {
                    break;
                }
            }
            Professor *professor = construir_professor();
            professores[i] = professor;
            (*qtd_atual_prof)++;
        }
        break;
    case 2:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            imprimir_professor(professor);
        }
        else
        {
            printf("Professor nao encontrado!!\n");
        }
    }
    break;
    case 3:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);

        if (professor)
        {
            imprimir_professor(professor);
            printf("Atualizar professor\n");
            printf("Nova Matricula\t> ");
            fgets(professor->matricula, 9, stdin);
            printf("Novo CPF\t> ");
            fgets(professor->cpf, 9, stdin);
            printf("Novo Nome\t> ");
            fgets(professor->nome, 49, stdin);
            professor->endereco = construir_endereco();
            printf("Professor atualizado!\n");
        }
        else
        {
            printf("Professor nao encontrado!!\n");
        }
        
    }

    break;
    case 4:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            destruirProfessor(professor);
            professores[posicao] = NULL;
            printf("Professor destruido\n");
        }
        else
        {
            printf("Professor nao encontrado!!\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");

}
}

//turmas
Turma *construir_turma()
{
    Turma turma;
    printf("Código\t> ");
    fgets(turma.codigo, 9, stdin);
    printf("Nome da disciplina\t> ");
    fgets(turma.nome_disciplina, 49, stdin);
    printf("Matricula do professor\t> ");
    fgets(turma.matriculaProf, 9, stdin);
    printf("Lista de Alunos\t> ");
    fgets(turma.lista_alunos, 49, stdin);
    printf("Media da turma\t> ");
    fgets(turma.media_turma, 49, stdin);


    void buscarProfessorPorMatricula(Professor **professores, int qtd_atual_prof, char matriculaProf)
{   
        for (int i = 0; i < qtd_atual_prof; i++)
    {
        if (strcmp(professores[i]->matricula, matricula) == 0)
        {
            char nomeProfTurma = professores[i]->nome;
            return nomeProfTurma;
        }
    }

    return NULL;

    }
    
    return criarTurma(turma.codigo, turma.nome_disciplina, professor, turma.lista_alunos, turma.media_turma);
}

void imprimir_turma(Turma *turma, char nomeProfTurma)
{
    printf("Código: %s", turma->codigo);
    printf("Nome da disciplina: %s", turma->nome_disciplina);
    printf("Professor: %s", nomeProfTurma);
    printf("Lista de Alunos: %s", turma->lista_alunos);
    printf("Média da turma: %s", turma->media_turma);
}

Turma  *buscar_turma(Turma **turmas, int *posicao) {
    char codigo[50];
    printf("Código > ");
    fgets(codigo, 49, stdin);
    Turma *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_TURMA; i++)
    {

        if (turmas[i] && !strcmp(codigo, turmas[i]->codigo))
        {
            resultado = turmas[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void tratador_menu_turma(Turma **turmas, int *qtd_atual_turma, Professor **professores, int *qtd_atual_prof)
{
    int opcao = menu_crud_turma();
    Turma *turma = NULL;
    switch (opcao)
    {
    case 1:
    //criar
        if (*qtd_atual_turma >= MAX_TURMA)
        {
            printf("Número máximo de turmas atingido\n");
        }
        else
        {
            int i = 0;
            for (; i < *qtd_atual_turma; i++)
            {
                if (turmas[i] != NULL)
                {
                    break;
                }
            }
            Turma *turma = construir_turma();
            turmas[i] = turma;
            (*qtd_atual_turma)++;
        }
        break;
    case 2:
    //buscar
    {
        int posicao = 0;
        turma = buscar_turma(turmas, &posicao);
        if (turma)
        {
            imprimir_turma(turma, nomeProfTurma);
        }
        else
        {
            printf("Turma nao encontrada!!\n");
        }
    }
    break;
    case 3:
    //atualizar
    {
        int posicao = 0;
        turma = buscar_turma(turmas, &posicao);

        if (turma)
        {
            imprimir_turma(turma, &nomeProfTurma);
            printf("Atualizar turma\n");
            printf("Novo Código\t> ");
            fgets(turma->codigo, 9, stdin);
            printf("Nova Disciplina\t> ");
            fgets(turma->nome_disciplina, 49, stdin);
            printf("Novo Professor\t> ");
            fgets(turma->matriculaProf, 49, stdin);
            printf("Nova Lista de Alunos\t> ");
            fgets(turma->lista_alunos, 49, stdin);
            printf("Nova Média da turma\t> ");
            fgets(turma->media_turma, 49, stdin);
            printf("Turma atualizada!\n");
        }
        else
        {
            printf("Turma nao encontrada!!\n");
        }
        
    }

    break;
    case 4:
    {
        int posicao = 0;
        turma = buscar_turma(turmas, &posicao);
        if (turma)
        {
            destruirTurma(turma);
            turmas[posicao] = NULL;
            printf("Turma destruida\n");
        }
        else
        {
}
    }
    break;
    default:
        printf("Retorno ao menu principal\n");

    }

}

//estatísticas

