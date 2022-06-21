/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Projeto: Fazer um programa em Linguagem C (ANSI C)
que simule uma carteira de vacinação (COVID).
*/

#include "stdio.h"
#include "string.h"
#include "math.h"

#define MAX_PACIENTES 100
#define MAX_DOSES 5

int qtdPacientesCadastrados = 0;

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
    // verifica se a string tem menos de 7 caracteres
    int tam = strlen(nome);
    if (tam < 7)
        return 0;
    // verifica se string possui 1 espaço e se a distacia dele ao início
    // e ao final é maior que 3
    for (int i = 0; i < tam; i++)
    {
        if (nome[i] == ' ')
        {
            if (i > 2 && i < tam - 3)
                return 1;
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
    int qtdDosesPaciente;

    printf("\n--- Credenciais do paciente ---\n");
    printf("Nome: ");
    gets(dPaciente->nome);
    while (!validaNome(dPaciente->nome))
    {
        printf("## Credencial inválida - digite novamente\n");
        printf("Nome: ");
        gets(dPaciente->nome);
    }

    printf("Telefone: ");
    gets(dPaciente->telefone);
    while (!validaTelefone(dPaciente->telefone))
    {
        printf("## Credencial inválida - digite novamente\n");
        printf("Telefone: ");
        gets(dPaciente->telefone);
    }

    printf("Data de nascimento (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &dPaciente->data_nascimento.dia,
          &dPaciente->data_nascimento.mes, &dPaciente->data_nascimento.ano);
    while (!validaData(dPaciente->data_nascimento))
    {
        printf("## Credencial inválida - digite novamente\n");
        printf("Data de nascimento (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &dPaciente->data_nascimento.dia,
              &dPaciente->data_nascimento.mes, &dPaciente->data_nascimento.ano);
    }

    printf("Quantidade de doses tomadas: ");
    scanf("%d", &qtdDosesPaciente);
    while (qtdDosesPaciente > MAX_DOSES || qtdDosesPaciente < 0)
    {
        printf("## Credencial inválida - digite novamente\n");
        printf("Quantidade de doses tomadas: ");
        scanf("%d", &qtdDosesPaciente);
    }

    for (int i = 0, fabricanteVacina = 0; i < qtdDosesPaciente; i++)
    {
        printf("--- Dados %dª dose ---\n", i + 1);

        printf("Fabricante da vacina (1. pfizer, 2. janssen, 3. astrazeneca, 4. moderna, 5. sinopharm, 6. outro): ");
        while (fabricanteVacina == 0)
        {
            __fpurge(stdin);

            scanf("%d", &fabricanteVacina);

            __fpurge(stdin);

            switch (fabricanteVacina)
            {
            case 1:
                strcpy(dPaciente->vacina[i].fabricante, "pfizer");
                break;
            case 2:
                strcpy(dPaciente->vacina[i].fabricante, "janssen");
                break;
            case 3:
                strcpy(dPaciente->vacina[i].fabricante, "astrazeneca");
                break;
            case 4:
                strcpy(dPaciente->vacina[i].fabricante, "moderna");
                break;
            case 5:
                strcpy(dPaciente->vacina[i].fabricante, "sinopharm");
                break;
            case 6:
                printf("Digite o nome do fabricante: ");
                gets(dPaciente->vacina[i].fabricante);
                break;
            default:
                printf("## Credencial inválida - digite novamente\n");
                printf("Fabricante da vacina (1. pfizer, 2. janssen, 3. astrazeneca, 4. moderna, 5. sinopharm, 6. outro): ");
                break;
            }
        }
        fabricanteVacina = 0;

        __fpurge(stdin);

        printf("Lote: ");
        gets(dPaciente->vacina[i].lote);

        printf("Data da aplicação: ");
        scanf("%d/%d/%d", &dPaciente->vacina[i].data_aplicacao.dia,
              &dPaciente->vacina[i].data_aplicacao.mes, &dPaciente->vacina[i].data_aplicacao.ano);
        while (!validaData(dPaciente->vacina[i].data_aplicacao))
        {
            printf("## Credencial inválida - digite novamente\n");
            printf("Data da aplicação: ");
            scanf("%d/%d/%d", &dPaciente->vacina[i].data_aplicacao.dia,
                  &dPaciente->vacina[i].data_aplicacao.mes, &dPaciente->vacina[i].data_aplicacao.ano);
        }
        __fpurge(stdin);
    }
    qtdPacientesCadastrados++;
}

//
void buscaNomePaciente(CarteiraVacinacao *dPaciente)
{
    char nomeBuscaPaciente[50];
    printf("\n--- Busca de paciente ---\nDigite um nome: ");
    gets(nomeBuscaPaciente);

    for (int i = 0; i < MAX_PACIENTES; i++)
    {
        if (strcmp(nomeBuscaPaciente, dPaciente[i].nome) == 0)
        {
            printf("\n--- Dados do paciente ---\n");
            printf("Nome: %s\n", &dPaciente[i].nome);
            printf("Telefone: %s\n", &dPaciente[i].telefone);
            printf("Data de nacimento: %d/%d/%d\n", dPaciente[i].data_nascimento.dia,
                   dPaciente[i].data_nascimento.mes, dPaciente[i].data_nascimento.ano);

            if (validaData(dPaciente[i].vacina[0].data_aplicacao))
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
            else
                printf("Não tomou nenhuma dose da vacina\n");
            break;
        }
    }
}

// Retorna os dados de todos os paciente em forma de uma tabela.
void listaDadosPacientes(CarteiraVacinacao *dPaciente)
{
    printf("\n----- Lista de pacientes -----\n");

    int dosesTomadas = 0;

    // printa os dados cadastrais de cada paciente da base de dados passada
    for (int i = 0; i < qtdPacientesCadastrados; i++)
    {
        printf("| %s |", &dPaciente[i].nome);
        printf(" %s |", &dPaciente[i].telefone);
        printf(" %d/%d/%d |", dPaciente[i].data_nascimento.dia,
               dPaciente[i].data_nascimento.mes, dPaciente[i].data_nascimento.ano);

        // conta quantas vacinas foram tomadas
        for (int j = 0; j < MAX_DOSES; j++)
        {
            if (validaData(dPaciente[i].vacina[j].data_aplicacao))
                dosesTomadas++;
        }
        printf(" %d |", dosesTomadas);
        printf("\n------------------------------\n");
    }
}

//
void qtdDosesFabricante(CarteiraVacinacao dPaciente[])
{
    // cria um vetor que guarda numero de pessoas que tomaram cada uma das doses
    // 0 = pfizer, 1 = janssen, 2 = astrazeneca, 3 = moderna, 4 = sinopharm, 5 = outro
    int vetDosesAplicadasFab[] = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < qtdPacientesCadastrados; i++)
        for (int j = 0; j < MAX_DOSES; j++)
            if (validaData(dPaciente[i].vacina[j].data_aplicacao))
            {
                // printf("%s", dPaciente[i].vacina[j].fabricante);
                if (strcmp(dPaciente[i].vacina[j].fabricante, "pfizer") == 0)
                    vetDosesAplicadasFab[0]++;
                else if (strcmp(dPaciente[i].vacina[j].fabricante, "janssen") == 0)
                    vetDosesAplicadasFab[1]++;
                else if (strcmp(dPaciente[i].vacina[j].fabricante, "astrazeneca") == 0)
                    vetDosesAplicadasFab[2]++;
                else if (strcmp(dPaciente[i].vacina[j].fabricante, "moderna") == 0)
                    vetDosesAplicadasFab[3]++;
                else if (strcmp(dPaciente[i].vacina[j].fabricante, "sinopharm") == 0)
                    vetDosesAplicadasFab[4]++;
                else
                    vetDosesAplicadasFab[5]++;
            }

    printf("\n--- Quantidade de dose aplicadas de cada uma das fabricantes ---\n");
    printf("Pfizer: %d\n", vetDosesAplicadasFab[0]);
    printf("Janssen: %d\n", vetDosesAplicadasFab[1]);
    printf("Astrazeneca: %d\n", vetDosesAplicadasFab[2]);
    printf("Moderna: %d\n", vetDosesAplicadasFab[3]);
    printf("Sinopharm: %d\n", vetDosesAplicadasFab[4]);
    printf("Outras: %d\n", vetDosesAplicadasFab[5]);
}

//
void qtdDosesAplicadas(CarteiraVacinacao dPaciente[])
{
    // cria um vetor que guarda numero de pessoas que tomaram cada uma das doses
    int vetDosesAplicadas[MAX_DOSES] = {0};

    for (int i = 0; i < qtdPacientesCadastrados; i++)
        for (int j = 0; j < MAX_DOSES; j++)
            if (validaData(dPaciente[i].vacina[j].data_aplicacao))
                vetDosesAplicadas[j]++;
    printf("\n--- Quantidade de pacientes que receberam cada uma das doses ---\n");
    for (int i = 0; i < MAX_DOSES; i++)
        printf("%dª dose: %d - Porcentagem: %d %%\n", i + 1, vetDosesAplicadas[i], vetDosesAplicadas[i] / MAX_PACIENTES * 100);
}

void inicializaSistema()
{

}

int main()
{
    system("clear");
    CarteiraVacinacao paciente[MAX_PACIENTES];
    int opcao;
    do
    {
        printf("\n=========== SISTEMA COVID ==========================\n");
        printf("(1) Cadastrar um paciente\n");
        printf("(2) Buscar paciente pelo nome\n");
        printf("(3) Listar pacientes cadastrados\n");
        printf("(4) Quantidade doses aplicadas de cada fabricante\n");
        printf("(5) Quantidade de pacientes vacinados por cada dose\n");
        printf("(6) Sair do sistema\n");

        printf("============== MENU ================================\n");
        printf("Digite uma opção: ");

        scanf("%d", &opcao);
        __fpurge(stdin);

        switch (opcao)
        {
        case 1:
            cadastraPaciente(&paciente[qtdPacientesCadastrados]);
            break;
        case 2:
            buscaNomePaciente(&paciente);
            break;
        case 3:
            listaDadosPacientes(&paciente);
            break;
        case 4:
            qtdDosesFabricante(&paciente);
            break;
        case 5:
            qtdDosesAplicadas(&paciente);
            break;
        case 6:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("## Opção inválida\n");
            break;
        }
    } while (opcao != 6);
}
