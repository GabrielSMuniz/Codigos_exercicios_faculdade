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

int validaNome(char dNome[])
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

int validaTelefone(char dTelefone[])
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

//
void buscaNomePaciente(CarteiraVacinacao *dPaciente)
{
    char nomeBuscaPaciente[50];
    int encontrouPaciente = 0;

    printf("\n--- Busca de paciente ---\nDigite um nome: ");
    gets(nomeBuscaPaciente);

    for (int i = 0; i < qtdPacCadastrados; i++)
    {
        if (strcmp(nomeBuscaPaciente, dPaciente[i].nome) == 0)
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

// Retorna os dados de todos os paciente em forma de uma tabela.
void listaDadosPacientes(CarteiraVacinacao *dPaciente)
{
    printf("\n----- Lista de pacientes -------------------------------\n");
    printf("| Nome | Telefone | Data de nascimento | Doses tomadas |\n");
    printf("--------------------------------------------------------\n");

    int dosesTomadas = 0;
    int ordemAlfabetica[qtdPacCadastrados];
    // inicializa o vetor
    for (int i = 0; i < qtdPacCadastrados; i++)
        ordemAlfabetica[i] = i;
    // faz o bubble sort do vetor em ordem alfabetica
    if (qtdPacCadastrados != 0)
    {
        for (int i = 0; i < qtdPacCadastrados; i++)
            for (int j = i, bolha; j < qtdPacCadastrados; j++)
                if (strcmp(dPaciente[i].nome, dPaciente[j].nome) > 0)
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

//
void qtdDosesFabricante(CarteiraVacinacao dPaciente[])
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

//
void qtdDosesAplicadas(CarteiraVacinacao dPaciente[])
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
    char nomeAleatorio[][50] = {"João Ferreira Oliveira", "Manoel Costa Barbosa", "Flávia Carvalhoso Abreu", "Muhammad Vidigal Canedo", "Alessandro Keil Durães", "Vilma Bacelar Conceição", "Micaela Mena Breia", "Marisa Varela Pureza", "Brian Frazão Aranha", "Vitória Alcoforado Mata", "Sasha Espinosa Júdice", "Ezra Carregueiro Anjos", "Rahyssa Vital Mata", "Cristina Rufino Colares", "Iago Anhaia Lameiras"};
    char telefoneAleatorio[][13] = {"04648157523", "024564801934", "069244205532", "09096051280", "05357082419", "01400677581", "072090454763", "02892867272", "012552830737", "08749787111", "03133570897", "058148591722", "045629148219", "04438880076", "07248632472"};
    Data dataNascimentoAleatorio[] = {{3, 6, 2000}, {3, 2, 2012}, {13, 1, 2000}, {30, 10, 1962}, {18, 5, 1955}, {25, 4, 2009}, {2, 5, 2013}, {16, 12, 1985}, {25, 1, 2018}, {10, 12, 1968}, {4, 6, 1964}, {8, 8, 2013}, {19, 9, 1927}, {26, 10, 2006}, {3, 10, 1931}};

    for (int i = 0; i < 15; i++)
    {

        if (!validaNome(nomeAleatorio[i]))
        {
            printf("Erro nome - Posição: %d\n", i);
            break;
        }
        if (!validaTelefone(telefoneAleatorio[i]))
        {
            printf("Erro telefone - Posição: %d\n", i);
            break;
        }
        if (!validaData(dataNascimentoAleatorio[i]))
        {
            printf("Erro data nascimento - Posição: %d\n", i);
            break;
        }
        strcpy(dPaciente[i].nome, nomeAleatorio[i]);
        strcpy(dPaciente[i].telefone, telefoneAleatorio[i]);
        dPaciente[i].data_nascimento = dataNascimentoAleatorio[i];

        qtdPacCadastrados++;
    }
}

int main()
{
    system("clear");
    CarteiraVacinacao paciente[MAX_PACIENTES];

    inicializaSistema(&paciente);
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
            cadastraPaciente(&paciente[qtdPacCadastrados]);
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
