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

int qtdPacCadastrados = 0;

// STRUCTS

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
    char telefone[20];
    Data data_nascimento;
    Vacina vacina[MAX_DOSES];
} CarteiraVacinacao;

// PROTÓTIPOS

// Função que recebe uma string nome e retorna 1 se for válida e 0 se não for
int validaNome(char *dNome);

// Função que recebe uma string telefone e retorna 1 se for válida e 0 se não for
int validaTelefone(char *dTelefone);

// Função que recebe uma struct Data e retorna 1 se for válida e 0 se não for
int validaData(Data dData);

// Função para o cadastro de um novo paciente no sistema
void cadastraPaciente(CarteiraVacinacao *dPaciente);

/*
Busca um paciente pelo nome inserido e imprime as suas credenciais
registradas do banco de dados especificado
 */
void buscaNomePaciente(CarteiraVacinacao *dPaciente, char *dNomeBusca);

// Imprime os dados de todos os paciente em forma de uma tabela.
void listaDadosPacientes(CarteiraVacinacao *dPaciente);

// Imprime a quantidade doses aplicadas por fabricante
void qtdDosesFabricante(CarteiraVacinacao *dPaciente);

// Imprime a quantidade em valor e em porcentagem dos paciente que tomou cada uma das doses
void qtdDosesAplicadas(CarteiraVacinacao *dPaciente);

// Inicializa o sistema com os valores correspondentes de cada paciente no banco de dados especificado
void inicializaSistema(CarteiraVacinacao *dPaciente);

int main()
{
    CarteiraVacinacao paciente[MAX_PACIENTES];
    char nomeBuscaPac[50];
    int opcao;

    // system("clear");
    inicializaSistema(&paciente);

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
            cadastraPaciente(&paciente[qtdPacCadastrados]);
            break;
        case 2:
            printf("\n--- Busca de paciente ---\nDigite um nome: ");
            gets(nomeBuscaPac);
            buscaNomePaciente(&paciente, nomeBuscaPac);
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

    return 0;
}

int validaNome(char *dNome)
{
    int tam = strlen(dNome);

    // verifica se a string tem menos de 7 caracteres
    if (tam < 7)
        return 0;
    // verifica os espaços no inicio
    for (int i = 0; i < 3; i++)
        if (dNome[i] == ' ')
            return 0;
    // verifica os espaços no final
    for (int i = 0; i >= tam - 3; i--)
        if (dNome[i] == ' ')
            return 0;

    // verifica as sequencias de mais de 2 caracteres
    for (int i = 3; i <= tam - 3; i++)
        if (dNome[i] == ' ')
            if (dNome[i - 3] == ' ' || dNome[i - 2] == ' ' || dNome[i - 1] == ' ' ||
                dNome[i + 1] == ' ' || dNome[i + 2] == ' ' || dNome[i + 3] == ' ')
                return 0;
    return 1;
}

int validaTelefone(char *dTelefone)
{
    // verifica se a string tem de 11 a 12 caracteres e se
    // o caracter inicial é 0
    if (dTelefone[0] != '0' || strlen(dTelefone) > 12 ||
        strlen(dTelefone) < 11)
        return 0;
    else // verifica se os demais chars são dígitos de 0-9
        for (int i = 1; i < strlen(dTelefone); i++)
            // printf("%c %d\n", telefone[i], telefone[i] - '0');
            if (dTelefone[i] - '0' < 0 || dTelefone[i] - '0' > 9)
                return 0;
    return 1;
}

int validaData(Data dData)
{
    if (dData.dia >= 1 && dData.dia <= 30 &&
        dData.mes >= 1 && dData.mes <= 12 &&
        dData.ano >= 1900 && dData.ano <= 2022)
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
    qtdPacCadastrados++;
}

void buscaNomePaciente(CarteiraVacinacao *dPaciente, char *dNomeBusca)
{
    int encontrouPaciente = 0;

    for (int i = 0; i < qtdPacCadastrados; i++)
    {
        if (strcmp(dNomeBusca, dPaciente[i].nome) == 0)
        {
            encontrouPaciente = 1;
            printf("\n--- Dados do paciente ---\n");
            printf("Nome: %s\n", &dPaciente[i].nome);
            printf("Telefone: %s\n", &dPaciente[i].telefone);
            printf("Data de nacimento: %02d/%02d/%d\n", dPaciente[i].data_nascimento.dia,
                   dPaciente[i].data_nascimento.mes, dPaciente[i].data_nascimento.ano);

            if (validaData(dPaciente[i].vacina[0].data_aplicacao))
                for (int j = 0; j < qtdPacCadastrados; j++)
                {
                    if (validaData(dPaciente[i].vacina[j].data_aplicacao))
                    {
                        printf("--- %dª dose ---\n", j + 1);
                        printf("Fabricante da vacina: %s\n", dPaciente[i].vacina[j].fabricante);
                        printf("Lote: %s\n", dPaciente[i].vacina[j].lote);
                        printf("Data da aplicação: %02d/%02d/%d\n", dPaciente[i].vacina[j].data_aplicacao.dia,
                               dPaciente[i].vacina[j].data_aplicacao.mes, dPaciente[i].vacina[j].data_aplicacao.ano);
                    }
                }
            else
                printf("Não tomou nenhuma dose da vacina\n");
            break;
        }
    }
    if (!encontrouPaciente)
        printf("## Paciente não encontrado\n");
}

void listaDadosPacientes(CarteiraVacinacao *dPaciente)
{
    printf("\n----- Lista de pacientes -------------------------------\n");
    printf("| Nome | Telefone | Data de nascimento | Doses tomadas |\n");
    printf("--------------------------------------------------------\n");

    int dosesTomadas = 0;

    if (qtdPacCadastrados != 0)
    {
        int ordemAlfabetica[qtdPacCadastrados];

        // inicializa o vetor
        for (int i = 0; i < qtdPacCadastrados; i++)
            ordemAlfabetica[i] = i;

        // faz o bubble sort do vetor em ordem alfabetica
        for (int i = 0; i < qtdPacCadastrados - 1; i++)
            for (int j = i + 1, bolha; j < qtdPacCadastrados; j++)
                if (strcmp(dPaciente[ordemAlfabetica[i]].nome, dPaciente[ordemAlfabetica[j]].nome) > 0)
                { // parte de troca de indice
                    bolha = ordemAlfabetica[i];
                    ordemAlfabetica[i] = ordemAlfabetica[j];
                    ordemAlfabetica[j] = bolha;
                }

        // printa os dados cadastrais de cada paciente da base de dados passada em ordem alfabetica
        for (int i = 0; i < qtdPacCadastrados; i++)
        {
            printf("| %s |", dPaciente[ordemAlfabetica[i]].nome);
            printf(" %s |", dPaciente[ordemAlfabetica[i]].telefone);
            printf(" %02d/%02d/%d |", dPaciente[ordemAlfabetica[i]].data_nascimento.dia,
                   dPaciente[ordemAlfabetica[i]].data_nascimento.mes, dPaciente[ordemAlfabetica[i]].data_nascimento.ano);

            // conta quantas vacinas foram tomadas
            dosesTomadas = 0;
            for (int j = 0; j < MAX_DOSES; j++)
            {
                if (validaData(dPaciente[ordemAlfabetica[i]].vacina[j].data_aplicacao))
                    dosesTomadas++;
            }
            printf(" %d |", dosesTomadas);
            printf("\n--------------------------------------------------------\n");
        }
    }
    else
        printf("--------------------------------------------------------\n");
}

void qtdDosesFabricante(CarteiraVacinacao *dPaciente)
{
    // cria um vetor que guarda numero de pessoas que tomaram cada uma das doses
    // 0 = pfizer, 1 = janssen, 2 = astrazeneca, 3 = moderna, 4 = sinopharm, 5 = outro
    int vetDosesAplicadasFab[] = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < qtdPacCadastrados; i++)
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

void qtdDosesAplicadas(CarteiraVacinacao *dPaciente)
{
    // cria um vetor que guarda numero de pessoas que tomaram cada uma das doses
    int vetDosesAplicadas[MAX_DOSES] = {0};

    for (int i = 0; i < qtdPacCadastrados; i++)
        for (int j = 0; j < MAX_DOSES; j++)
            if (validaData(dPaciente[i].vacina[j].data_aplicacao))
                vetDosesAplicadas[j]++;
    printf("\n--- Quantidade de pacientes que receberam cada uma das doses ---\n");
    for (int i = 0; i < MAX_DOSES; i++)
        printf("%dª dose: %d - Porcentagem: %d %%\n", i + 1, vetDosesAplicadas[i], 100 * vetDosesAplicadas[i] / MAX_PACIENTES);
}

void inicializaSistema(CarteiraVacinacao *dPaciente)
{
    CarteiraVacinacao initPacientes[] = {{"João Ferreira Oliveira", "04648157523", {12, 11, 1988}, {{"pfizer", "XXII09_843", {14, 10, 2022}}, {"pfizer", "XXIV08_290", {27, 9, 2020}}, {"pfizer", "XXII09_170", {15, 5, 2021}}, {"pfizer", "XXII09_799", {14, 6, 2021}}, {"pfizer", "XXII09_603", {1, 7, 2020}}}},
                                         {"Manoel Costa Barbosa", "024564801934", {17, 7, 1957}, {{"pfizer", "XXII09_308", {24, 8, 2021}}, {"pfizer", "XXIV08_20", {1, 10, 2020}}, {"pfizer", "XXII09_808", {9, 4, 2020}}, {"pfizer", "XXII09_992", {1, 5, 2022}}, {"pfizer", "XXII09_379", {28, 7, 2021}}, {"pfizer", "XXII03_379", {30, 10, 2022}}}},
                                         {"Flávia Carvalhoso Abreu", "069244205532", {5, 7, 2014}, {{"moderna", "XXII09_320", {19, 6, 2022}}, {"pfizer", "XXIV08_721", {8, 8, 2022}}, {"astrazeneca", "XXII09_43", {7, 5, 2022}}}},
                                         {"Muhammad Vidigal Canedo", "09096051280", {19, 9, 2016}, {{"moderna", "XXII09_34", {4, 7, 2021}}, {"moderna", "XXIV08_838", {24, 7, 2021}}, {"moderna", "XXII09_817", {14, 5, 2021}}, {"moderna", "XXII09_168", {23, 12, 2020}}}},
                                         {"Alessandro Keil Durães", "05357082419", {16, 10, 2017}, {{"sinopharm", "XXII09_71", {24, 2, 2022}}, {"moderna", "XXIV08_511", {26, 10, 2021}}}},
                                         {"Vilma Bacelar Conceição", "01400677581", {26, 11, 1975}, {{"janssen", "XXII09_940", {20, 1, 2022}}, {"janssen", "XXIV08_7", {14, 12, 2022}}, {"janssen", "XXII09_544", {24, 9, 2022}}}},
                                         {"Micaela Mena Breia", "072090454763", {10, 2, 1973}},
                                         {"Marisa Varela Pureza", "02892867272", {17, 3, 1989}, {{"janssen", "XXII09_834", {15, 12, 2022}}, {"astrazeneca", "XXIV08_635", {6, 12, 2020}}, {"pfizer", "XXII09_998", {29, 7, 2020}}}},
                                         {"Brian Frazão Aranha", "012552830737", {13, 8, 2012}, {{"astrazeneca", "XXII09_697", {10, 6, 2021}}, {"astrazeneca", "XXIV08_97", {6, 2, 2021}}}},
                                         {"Vitória Alcoforado Mata", "08749787111", {4, 7, 1979}},
                                         {"Sasha Espinosa Júdice", "03133570897", {16, 12, 2001}, {{"astrazeneca", "XXII09_196", {20, 11, 2022}}}},
                                         {"Ezra Carregueiro Anjos", "058148591722", {7, 2, 1942}},
                                         {"Rahyssa Vital Mata", "045629148219", {26, 4, 1972}, {{"astrazeneca", "XXII09_303", {2, 4, 2022}}}},
                                         {"Cristina Rufino Colares", "04438880076", {19, 7, 1953}, {{"sinopharm", "XXII09_183", {5, 7, 2020}}}},
                                         {"Iago Anhaia Lameiras", "07248632472", {15, 10, 1976}}};

    for (int i = 0; i < sizeof initPacientes / sizeof initPacientes[0]; i++)
    {
        if (!validaNome(initPacientes[i].nome))
        {
            printf("Erro nome - Posição: %d\n", i);
            break;
        }
        if (!validaTelefone(initPacientes[i].telefone))
        {
            printf("Erro telefone - Posição: %d\n", i);
            break;
        }
        if (!validaData(initPacientes[i].data_nascimento))
        {
            printf("Erro data nascimento - Posição: %d\n", i);
            break;
        }
        dPaciente[i] = initPacientes[i];
        qtdPacCadastrados++;
    }
}