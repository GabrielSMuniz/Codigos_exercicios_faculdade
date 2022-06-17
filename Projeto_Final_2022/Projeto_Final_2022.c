/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Projeto: Fazer um programa em Linguagem C (ANSI C)
que simule uma carteira de vacinação (COVID).
*/

#include "stdio.h"
#include "string.h"

#define MAX_PACIENTES 100
#define MAX_DOSES 5

int qtd_pacientesCadastrados = 0;

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Vacina
{
    char fabricante[50];
    char lote[50];
    Data data_aplicacao;
} Vacina;

typedef struct CarteiraVacinacao
{
    char nome[50];
    char telefone[12];
    Data data_nascimento;
    Vacina vacina[MAX_DOSES];
} CarteiraVacinacao;

int validaNome(char nome[])
{
    // varifica se a string tem menos de 7 caracteres
    if (strlen(nome) < 7)
        return 0;
    // verifica se string possui 1 espaço e se a distacia dele ao início
    // e ao final é maior que 3
    for (int i = 0; i < strlen(nome); i++)
    {
        if (nome[i] == ' ')
        {
            if (i > 2 && i < strlen(nome) - 3)
            {
                for (i++; i < strlen(nome); i++)
                    if (nome[i] == ' ')
                        return 0;
                return 1;
            }
        }
    }
    return 0;
}

int validaTelefone(char telefone[])
{
    // verifica se a string tem de 11 a 12 caracteres e se
    // o caracter inicial é 0
    if (telefone[0] != '0' || strlen(telefone) > 12 ||
        strlen(telefone) < 11)
        return 0;
    else // verifica se os demais chars são dígitos de 0-9
        for (int i = 1; i < strlen(telefone); i++)
            // printf("%c %d\n", telefone[i], telefone[i] - '0');
            if (telefone[i] - '0' < 0 || telefone[i] - '0' > 9)
                return 0;
    return 1;
}

int validaData(Data data)
{
    if (data.dia >= 1 && data.dia <= 30 &&
        data.mes >= 1 && data.mes <= 12 &&
        data.ano >= 1900 && data.ano <= 2022)
        return 1;
    else
        return 0;
}

void cadastraPaciente(CarteiraVacinacao *dPaciente)
{
    int qtd_doses;

    printf("--- Credenciais do paciente ---\n");
    printf("Nome: ");
    gets(dPaciente->nome);
    while (!validaNome(dPaciente->nome))
    {
        printf("## Credencial negada - digite novamente\n");
        printf("Nome: ");
        gets(dPaciente->nome);
    }

    printf("Telefone: ");
    gets(dPaciente->telefone);
    while (!validaTelefone(dPaciente->telefone))
    {
        printf("## Credencial negada - digite novamente\n");
        printf("Telefone: ");
        gets(dPaciente->telefone);
    }

    printf("Data de nascimento (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &dPaciente->data_nascimento.dia,
          &dPaciente->data_nascimento.mes, &dPaciente->data_nascimento.ano);
    while (!validaData(dPaciente->data_nascimento))
    {
        printf("## Credencial negada - digite novamente\n");
        printf("Data de nascimento (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &dPaciente->data_nascimento.dia,
              &dPaciente->data_nascimento.mes, &dPaciente->data_nascimento.ano);
    }

    printf("Quantidade de doses tomadas: ");
    scanf("%d", &qtd_doses);
    while (qtd_doses > MAX_DOSES || qtd_doses < 0)
    {
        printf("## Credencial negada - digite novamente\n");
        printf("Quantidade de doses tomadas: ");
        scanf("%d", &qtd_doses);
    }

    __fpurge(stdin);

    for (int i = 0; i < qtd_doses; i++)
    {
        printf("--- Dados %dª dose ---\n", i + 1);

        printf("Fabricante da vacina: ");
        gets(dPaciente->vacina[i].fabricante);

        printf("Lote: ");
        gets(dPaciente->vacina[i].lote);

        printf("Data da aplicação: ");
        scanf("%d/%d/%d", &dPaciente->vacina[i].data_aplicacao.dia,
              &dPaciente->vacina[i].data_aplicacao.mes, &dPaciente->vacina[i].data_aplicacao.ano);
        while (!validaData(dPaciente->vacina[i].data_aplicacao))
        {
            printf("## Credencial negada - digite novamente\n");
            printf("Data da aplicação: ");
            scanf("%d/%d/%d", &dPaciente->vacina[i].data_aplicacao.dia,
                  &dPaciente->vacina[i].data_aplicacao.mes, &dPaciente->vacina[i].data_aplicacao.ano);
        }
        __fpurge(stdin);
    }
    qtd_pacientesCadastrados++;
}

void buscaNomePaciente(CarteiraVacinacao dPaciente[])
{
    char nomePaciente[50];
    printf("\n--- Busca de paciente ---\nDigite um nome: ");
    gets(nomePaciente);

    for (int i = 0; i < MAX_PACIENTES; i++)
    {
        if (strcmp(nomePaciente, dPaciente[i].nome) == 0)
        {
            printf("\n--- Dados do paciente ---\n");
            printf("Nome: %s\n", &dPaciente[i].nome);
            printf("Telefone: %s\n", &dPaciente[i].telefone);
            printf("Data de nacimento: %d/%d/%d\n", dPaciente[i].data_nascimento.dia,
                   dPaciente[i].data_nascimento.mes, dPaciente[i].data_nascimento.ano);

            for (int j = 0; j < MAX_PACIENTES; j++)
            {
                if (validaData(dPaciente[i].vacina[j].data_aplicacao))
                {
                    printf("--- %dª dose ---\n", j + 1);
                    printf("Fabricante da vacina: %s\n", dPaciente[i].vacina[j].fabricante);
                    printf("Lote: %s\n", dPaciente[i].vacina[j].lote);
                    printf("Data da aplicação: %d/%d/%d\n", dPaciente[i].vacina[j].data_aplicacao.dia,
                           dPaciente[i].vacina[j].data_aplicacao.mes, dPaciente[i].vacina[j].data_aplicacao.ano);
                }
            }

            break;
        }
    }
}

void listaDadosPaciente(CarteiraVacinacao dPaciente[])
{
    printf("\n----- Lista de pacientes -----\n");

    // printa os dados cadastrais de cada paciente da base de dados passada
    for (int i = 0; i < qtd_pacientesCadastrados; i++)
    {
        if (validaNome(dPaciente[i].nome))
        {
            printf("Nome: %s - ", &dPaciente[i].nome);
            printf("Telefone: %s - ", &dPaciente[i].telefone);
            printf("Data de nacimento: %d/%d/%d - ", dPaciente[i].data_nascimento.dia,
                   dPaciente[i].data_nascimento.mes, dPaciente[i].data_nascimento.ano);

            // verifica as vacinas que o paciente tomou
            if (validaData(dPaciente[i].vacina[0].data_aplicacao))
                for (int j = 0; j < MAX_DOSES; j++)
                {
                    if (validaData(dPaciente[i].vacina[j].data_aplicacao))
                    {
                        printf("%dª dose - ", j + 1);
                        printf("Fabricante da vacina: %s - ", dPaciente[i].vacina[j].fabricante);
                        printf("Lote: %s - ", dPaciente[i].vacina[j].lote);
                        printf("Data da aplicação: %d/%d/%d", dPaciente[i].vacina[j].data_aplicacao.dia,
                               dPaciente[i].vacina[j].data_aplicacao.mes, dPaciente[i].vacina[j].data_aplicacao.ano);
                    }
                }
            else
                printf("Não tomou nenhuma dose da vacina");
            printf("\n--------------------------\n");
        }
    }
}

int main()
{
    CarteiraVacinacao paciente[MAX_PACIENTES];

    int qtd_pacientes;
    printf("Digite quantos pacientes deseja cadastrar: ");

    scanf("%d", &qtd_pacientes);
    __fpurge(stdin);
    for (int i = 0; i < qtd_pacientes; i++)
    {
        printf("\n--- Paciente %d ---\n", i + 1);

        cadastraPaciente(&paciente[i]);
    }

    listaDadosPaciente(&paciente[0]);
}
