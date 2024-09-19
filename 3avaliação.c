#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct
{
    char tipo[10];
    char status[10];
    int numero;
    float preco;
} quarto;

typedef struct
{
    char nome[50];
    char email[50];
    char telefone[15];
    char endereco[50];
    char cpf[15];
    char rg[15];
} cliente;

typedef struct
{
    char nome[50];
    int numero;
    int dia;
    int mes;
    int ano;
    char hora_inicial[15];
    char hora_final[15];
    char status_pagamento[30];
    float total;
    int cod;
    int julianai,julianaf;
}reserva;

void menu()
{
    printf("╔════════════════════════════════════╗\n");
    printf("║          MENU PRINCIPAL            ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║ [1] MENU DO FUNCIONÁRIO            ║\n");
    printf("║ [2] MENU DO CLIENTE                ║\n");
    printf("║ [3] GESTÃO FINANÇEIRA              ║\n");
    printf("║ [0] SAIR                           ║\n");
    printf("╚════════════════════════════════════╝\n\n");
}

void menu_cliente()
{
    printf("╔════════════════════════════════════╗\n");
    printf("║            MENU CLIENTE            ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║ [1] DEFINIR QUANTIDADE DE CLIENTES ║\n");
    printf("║ [2] CADASTRAR CLIENTE              ║\n");
    printf("║ [3] CONSULTAR CLIENTE              ║\n");
    printf("║ [4] EDITAR CLIENTE                 ║\n");
    printf("║ [5] EXCLUIR CLIENTE                ║\n");
    printf("║ [0] MENU ANTERIOR                  ║\n");
    printf("╚════════════════════════════════════╝\n\n");
}

void menu_funcionario()
{
    printf("\n");
    printf("╔════════════════════════════════════╗\n");
    printf("║          MENU FUNCIONÁRIO          ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║ [1] DEFINIR QUANTIDADE DE QUARTOS  ║\n");
    printf("║ [2] CADASTRAR QUARTO               ║\n");
    printf("║ [3] CONSULTAR QUARTO               ║\n");
    printf("║ [4] EDITAR QUARTO                  ║\n");
    printf("║ [5] EXCLUIR QUARTO                 ║\n");
    printf("║ [0] MENU ANTERIOR                  ║\n");
    printf("╚════════════════════════════════════╝\n\n");
}

void menu_financeiro()
{
    printf("╔════════════════════════════════════╗\n");
    printf("║ [1] REALIZAR RESERVA               ║\n");
    printf("║ [2] CONSULTAR RESERVA              ║\n");
    printf("║ [3] EXCLUIR RESERVA                ║\n");
    printf("║ [4] REALIZAR CHECK-IN              ║\n");
    printf("║ [5] REALIZAR PAGAMENTO             ║\n");
    printf("║ [6] VALORES RECEBIDOS              ║\n");
    printf("║ [0] MENU ANTERIOR                  ║\n");
    printf("╚════════════════════════════════════╝\n\n");


}

void Entrada_invalida_num(){
    printf("\n-------------------------------------------\n");
    printf(" ENTRADA INVÁLIDA. DIGITE APENAS NÚMEROS !\n");
    printf("-------------------------------------------\n\n");
}

void menu_editar_quarto(){
    printf("╔════════════════════════════════════╗\n");
    printf("║ [1] EDITAR O TIPO DO QUARTO        ║\n");
    printf("║ [2] EDITAR O PREÇO DO QUARTO       ║\n");
    printf("║ [0] MENU ANTERIOR                  ║\n");
    printf("╚════════════════════════════════════╝\n\n");

}

void definir_quantidade_de_quartos(int *quantidade_de_quartos)
{
    printf("QUANTOS QUARTOS DESEJA CADASTRAR: ");
    scanf("%d", quantidade_de_quartos);
    printf("\n");
}

void escolher_quarto(){
    printf("╔════════════════════════════════════╗\n");
    printf("║ [1] SIMPLES                        ║\n");
    printf("║ [2] DUPLO                          ║\n");
    printf("║ [3] SUITE                          ║\n");
    printf("╚════════════════════════════════════╝\n\n");
}

void cadastrar_quarto(int *quantidade_de_quartos, FILE *banco,FILE *banco1)
{
    int i = 0,aux2,aux3,op9;
    quarto aux4,quartos;
    if (*quantidade_de_quartos == 0)
    {
        printf("\n----------------------------------------------------------\n");
        printf(" VOCÊ AINDA NÃO DEFINIU UMA QUANTIDADE A SER CADASTRADA !\n");
        printf("----------------------------------------------------------\n\n");
    }
    else if (i < *quantidade_de_quartos)
    {    
        while (i < *quantidade_de_quartos)
        {                               
            banco = fopen("banco.txt", "a");
            banco1 = fopen("banco.txt", "r");
            if (banco)
            {
                while(1){
                    aux3=0;

                    do {
                        printf("INFORME O NÚMERO DO QUARTO: ");
                        if (scanf("%d", &aux2) != 1 || getchar() != '\n') {
                            while (getchar() != '\n');
                            Entrada_invalida_num();
                            aux2 = -1;
                        }
                    } while (aux2 == -1);


                    rewind(banco1);
                    while (fscanf(banco1, "%d %9s %9s %f", &aux4.numero, aux4.tipo, aux4.status, &aux4.preco) == 4) {
                        if (aux2 == aux4.numero) {
                            printf("\n---------------------------------\n");
                            printf(" ESSE QUARTO JÁ FOI CADASTRADO !\n");
                            printf("---------------------------------\n\n");
                            aux3++;
                            break;  
                        }
                    }

                    

                    if (aux3==0)
                    {
                        break;
                    }
                    
                }
                
                quartos.numero=aux2;
                
                do
                {
                    printf("INFORME O TIPO DO QUARTO: \n");
                    escolher_quarto();
                    scanf("%d",&op9);
                    switch (op9)
                    {
                    case 0:
                        break;

                    case 1:
                        strcpy(quartos.tipo,"SIMPLES");
                        op9=0;
                        break;

                    case 2:
                        strcpy(quartos.tipo,"DUPLO");
                        op9=0;
                        break;

                    case 3:
                        strcpy(quartos.tipo,"SUITE");
                        op9=0;
                        break;
                    
                    default:
                        printf("\n------------------\n");
                        printf(" OPÇÃO INVÁLIDA !\n");
                        printf("------------------\n\n");
                        break;
                    }
                } while (op9!=0);
                

                scanf("%*c");
                strcpy(quartos.status,"LIVRE");

                do {
                    printf("INFORME O PREÇO COBRADO POR DIA NESSE QUARTO: ");
                    if (scanf("%f", &quartos.preco) != 1 || getchar() != '\n') {
                        while (getchar() != '\n');
                        Entrada_invalida_num();
                        quartos.preco = -1.0;
                    }
                } while (quartos.preco == -1.0);



                fprintf(banco, "%d %s %s %.2f\n", quartos.numero,
                        quartos.tipo, quartos.status,
                        quartos.preco);

                printf("\n\n");

                i++;
                fclose(banco);
                fclose(banco1);
                printf("---------------------------------\n");
                printf(" QUARTO CADASTRADO COM SUCESSO !\n");
                printf("---------------------------------\n\n");
            }

            else
            {
                printf("Erro ao abrir o arquivo banco.txt\n");
                exit(1);
            }
        }

        *quantidade_de_quartos = 0;
            
    }
    else
    {
        printf("\n----------------------------------------------\n");
        printf("VOCE JÁ CADASTROU A QUANTIDADE QUE DESEJAVA !\n");
        printf("----------------------------------------------\n\n");
    }
}



void consultar_quarto()
{
    printf("╔════════════════════════════════════╗\n");
    printf("║ [1] LISTAR TODOS OS QUARTOS        ║\n");
    printf("║ [2] BUSCAR POR NÚMERO DO QUARTO    ║\n");
    printf("║ [3] BUSCAR PELO TIPO DO QUARTO     ║\n");
    printf("║ [4] BUSCAR PELO STATUS DO QUARTO   ║\n");
    printf("║ [0] MENU ANTERIOR                  ║\n");
    printf("╚════════════════════════════════════╝\n\n");

    
}

void buscar_por_numero(FILE *banco){
    int num,aux=0;
    quarto quartos;
        banco=fopen("banco.txt","r");

        if (banco)
        {
            do {
                printf("INFORME O NÚMERO DO QUARTO QUE DESEJA BUSCAR: ");
                if (scanf("%d", &num) != 1 || getchar() != '\n') {
                    // Limpar o buffer do teclado em caso de entrada inválida
                    while (getchar() != '\n');
                    Entrada_invalida_num();
                    num = -1;  // Valor inválido para continuar no loop
                }
            } while (num == -1);

            while (fscanf(banco, "%d %9s %9s %f", &quartos.numero, quartos.tipo, quartos.status, &quartos.preco) == 4)
            {

                if (num==quartos.numero)
                {
                    printf("╔══════════════════════════════════════════════════╗\n");
                    printf("║ NÚMERO ║ TIPO         ║ STATUS       | PREÇO     ║\n");
                    printf("╠══════════════════════════════════════════════════╣\n");
                    printf("║ %-6d ║ %-12s ║ %-12s ║ %-8.2f  ║\n", quartos.numero, quartos.tipo, quartos.status, quartos.preco);
                    printf("╚══════════════════════════════════════════════════╝\n\n");
                    aux++;                  
                }
            }
            if (aux==0)
            {
                printf("\n-------------------------\n");
                printf(" QUARTO NÃO ENCONTRADO !\n");
                printf("-------------------------\n\n");
            }
            fclose(banco);
        }
        else{
            printf("\n----------------------------\n");
            printf(" NENHUM QUARTO CADASTRADO !\n");
            printf("----------------------------\n\n");
        }
           
}

void buscar_todos(FILE *banco){
    quarto quartos;


    banco=fopen("banco.txt","r");

    if (banco)
    {

        printf("╔══════════════════════════════════════════════════╗\n");
        printf("║ NÚMERO ║ TIPO         ║ STATUS       | PREÇO     ║\n");
        printf("╠══════════════════════════════════════════════════╣\n");

        while (fscanf(banco, "%d %9s %9s %f", &quartos.numero, quartos.tipo, quartos.status, &quartos.preco) == 4)
        {
            printf("║ %-6d ║ %-12s ║ %-12s ║ %-8.2f  ║\n", quartos.numero, quartos.tipo, quartos.status, quartos.preco);                  
            
        }
        printf("╚══════════════════════════════════════════════════╝\n\n");
        
        fclose(banco);
        
        
            
    }

    else
    {       
        printf("\n----------------------------\n");
        printf(" NENHUM QUARTO CADASTRADO !\n");
        printf("----------------------------\n\n");
    }
    
}

void Remover_quarto(FILE *banco){
    quarto quartos,aux2;
    int num,aux=0;
    char resp;

    banco=fopen("banco.txt","r");
    if (banco)
    {
        do {
            printf("INFORME O NÚMERO DO QUARTO QUE DESEJA EXCLUIR: ");
            if (scanf("%d", &num) != 1 || getchar() != '\n') {
                
                while (getchar() != '\n');
                Entrada_invalida_num();
                num = -1;
            }
        } while (num == -1);

        
        rewind(banco);
        while (fscanf(banco, "%d %9s %9s %f", &quartos.numero, quartos.tipo, quartos.status, &quartos.preco) == 4)
        {  
            if (num==quartos.numero && strcmp(quartos.status,"LIVRE")==0)
            {
                
                printf("╔══════════════════════════════════════════════════╗\n");
                printf("║ NÚMERO ║ TIPO         ║ STATUS       | PREÇO     ║\n");
                printf("╠══════════════════════════════════════════════════╣\n");
                printf("║ %-6d ║ %-12s ║ %-12s ║ %-8.2f  ║\n", quartos.numero, quartos.tipo, quartos.status, quartos.preco);
                printf("╚══════════════════════════════════════════════════╝\n\n");
                aux++;

            }
            else if (num==quartos.numero && strcmp(quartos.status,"LIVRE")!=0)
            {
                printf("------------------------------------------------------\n");
                printf(" NÃO É POSSIVEL REMOVER O QUARTO, POIS ESTÁ OCUPADO !\n");
                printf("------------------------------------------------------\n");
                aux=2;
            }
        }

        if (aux==1)
        {   
            printf("VOCE DESEJA MESMO EXCLUIR ESSE QUARTO? [S/N]: ");
            scanf(" %c",&resp);

            if (resp=='S' || resp=='s')
            {
                FILE *temp = fopen("temp.txt", "w");
                rewind(banco);
                while (fscanf(banco, "%d %9s %9s %f", &quartos.numero, quartos.tipo, quartos.status, &quartos.preco) == 4)
                {
                    if (num==quartos.numero && strcmp(quartos.status,"LIVRE")==0)
                    {
                    }
                    else
                    {
                        fprintf(temp, "%d %s %s %.2f\n", quartos.numero, quartos.tipo, quartos.status, quartos.preco);
                    }
                    
                }
                fclose(banco);
                fclose(temp);

                remove("banco.txt");
                
                rename("temp.txt", "banco.txt");

                printf("\n-------------------------------\n");
                printf(" QUARTO REMOVIDO COM SUCESSO !\n");
                printf("-------------------------------\n\n");
            }

            else
            {
                printf("\n----------------------\n");
                printf(" EXCLUSÃO CANCELADA !\n");
                printf("----------------------\n");
            }
                        
        }
    
        else if (aux==0)
        {
            printf("\n-------------------------\n");
            printf(" QUARTO NÃO ENCONTRADO !\n");
            printf("-------------------------\n\n");
        }

        fclose(banco);
    }

    else{
        printf("\n----------------------------\n");
        printf(" NENHUM QUARTO CADASTRADO !\n");
        printf("----------------------------\n\n");
    }

}

void editar_tipo_quarto(FILE *banco){
    int num,aux=0,op11;
    quarto quartos;
    char resp;
    
    banco = fopen("banco.txt", "r");

    if (banco){
        do {
        printf("INFORME O NÚMERO DO QUARTO: ");
        if (scanf("%d", &num) != 1 || getchar() != '\n') {
            while (getchar() != '\n');
            Entrada_invalida_num();
            num = -1;
        }
    } while (num == -1);

        while (fscanf(banco, "%d %9s %9s %f", &quartos.numero, quartos.tipo, quartos.status, &quartos.preco) == 4)
        {
            if (num==quartos.numero && strcmp(quartos.status,"LIVRE")==0)
            {  
                printf("╔══════════════════════════════════════════════════╗\n");
                printf("║ NÚMERO ║ TIPO         ║ STATUS       | PREÇO     ║\n");
                printf("╠══════════════════════════════════════════════════╣\n");
                printf("║ %-6d ║ %-12s ║ %-12s ║ %-8.2f  ║\n", quartos.numero, quartos.tipo, quartos.status, quartos.preco);
                printf("╚══════════════════════════════════════════════════╝\n\n");

                printf("DESEJA EDITAR AS INFORMAÇÕES ? [S/N]: ");
                scanf(" %c",&resp);

                if (resp=='S' || resp=='s')
                {
                    FILE *temp = fopen("temp.txt", "w");
                    rewind(banco);
                    while (fscanf(banco, "%d %9s %9s %f", &quartos.numero, quartos.tipo, quartos.status, &quartos.preco) == 4)
                    {
                        if (num==quartos.numero )
                        {
                            printf("INFORME O NOVO TIPO DO QUARTO: \n");
                            escolher_quarto();
                            scanf("%d",&op11);
                            switch (op11)
                            {
                            case 0:
                                break;

                            case 1:
                                strcpy(quartos.tipo,"SIMPLES");
                                break;

                            case 2:
                                strcpy(quartos.tipo,"DUPLO");
                                break;

                            case 3:
                                strcpy(quartos.tipo,"SUITE");
                                break;
                            
                            default:
                                printf("\n------------------\n");
                                printf(" OPÇÃO INVÁLIDA !\n");
                                printf("------------------\n\n");
                                break;
                            }
                                        
                        }
                        fprintf(temp, "%d %s %s %.2f\n", quartos.numero, quartos.tipo, quartos.status, quartos.preco);
                    }
                    fclose(banco);
                    fclose(temp);

                    // Remover o arquivo original
                    remove("banco.txt");
                    
                    // Renomear o arquivo temporÃ¡rio para o original
                    rename("temp.txt", "banco.txt");

                    printf("\n-----------------------------\n");
                    printf(" TIPO ALTERADO COM SUCESSO !\n");
                    printf("-----------------------------\n\n");
                }
                else
                {
                    printf("\n--------------------\n");
                    printf(" EDIÇÃO CANCELADA !\n");
                    printf("--------------------\n");

                }
                
                aux++;    
            }

            else if (num==quartos.numero && strcmp(quartos.status,"LIVRE")!=0)
            {
                aux=2;
            }
            
        }

        if (aux==0)
        {
            printf("\n------------------------\n");
            printf(" QUARTO NÃO ENCONTRADO !\n");
            printf("-----------------------\n\n");
        }

        else if (aux==2)
        {
            printf("\n-----------------------\n");
            printf(" QUARTO NÃO ESTA LIVRE !\n");
            printf("------------------------\n\n");
        }
        
        fclose(banco);
    }

    else{
        printf("\n----------------------------\n");
        printf(" NENHUM QUARTO CADASTRADO !\n");
        printf("----------------------------\n\n");
    }
        
}

void buscar_pelo_tipo(FILE *banco){
    char tipo[10];
    int aux=0,op13;
    quarto quartos;
        
        banco=fopen("banco.txt","r");

        if (banco)
        {
            do
            {
                printf("INFORME O TIPO DO QUARTO: \n");
                escolher_quarto();
                scanf("%d",&op13);
                switch (op13)
                {
                case 0:
                    break;

                case 1:
                    strcpy(quartos.tipo,"SIMPLES");
                    op13=0;
                    break;

                case 2:
                    strcpy(quartos.tipo,"DUPLO");
                    op13=0;
                    break;

                case 3:
                    strcpy(quartos.tipo,"SUITE");
                    op13=0;
                    break;
                
                default:
                    printf("\n------------------\n");
                    printf(" OPÇÃO INVÁLIDA !\n");
                    printf("------------------\n\n");
                    break;
                }
            } while (op13!=0);

            printf("╔══════════════════════════════════════════════════╗\n");
            printf("║ NÚMERO ║ TIPO         ║ STATUS       | PREÇO     ║\n");
            printf("╠══════════════════════════════════════════════════╣\n");

            while (fscanf(banco, "%d %9s %9s %f", &quartos.numero, quartos.tipo, quartos.status, &quartos.preco) == 4)
            {
                if (strcmp(quartos.tipo, tipo) == 0)
                {
                    printf("║ %-6d ║ %-12s ║ %-12s ║ %-8.2f  ║\n", quartos.numero, quartos.tipo, quartos.status, quartos.preco);
                    aux++; 
                }
            }

            printf("╚══════════════════════════════════════════════════╝\n\n");
            
            if (aux==0)
            {
                printf("\n-------------------------\n");
                printf(" QUARTO NÃO ENCONTRADO !\n");
                printf("-------------------------\n\n");
            }
            fclose(banco);
        }
        else{
            printf("\n----------------------------\n");
            printf(" NENHUM QUARTO CADASTRADO !\n");
            printf("----------------------------\n\n");
        }
        
}

void editar_preco_quarto(FILE *banco) {
    char tipo[10];
    int aux = 0,op12, aux2=0;
    float novo_preco;
    quarto quartos;

    banco = fopen("banco.txt", "r+");

    if (banco) {
        do
        {
        printf("INFORME O TIPO DO QUARTO QUE DESEJA ALTERAR O PREÇO: \n");
        escolher_quarto();
        scanf("%d",&op12);
        switch (op12)
        {
        case 0:
            break;

        case 1:
            strcpy(tipo,"SIMPLES");
            op12=0;
            break;

        case 2:
            strcpy(tipo,"DUPLO");
            op12=0;
            break;

        case 3:
            strcpy(tipo,"SUITE");
            op12=0;
            break;
        
        default:
            printf("\n------------------\n");
            printf(" OPÇÃO INVÁLIDA !\n");
            printf("------------------\n\n");
            break;
        }
        } while (op12!=0);

        printf("\n\n");

        do {
            printf("INFORME O NOVO PREÇO: ");
            if (scanf("%f", &novo_preco) != 1 || getchar() != '\n') {
                while (getchar() != '\n');
                Entrada_invalida_num();
                novo_preco = -1.0;
            }
        } while (novo_preco == -1.0);

        // Usar um arquivo temporÃ¡rio para salvar as alteraÃ§Ãµes
        FILE *temp = fopen("temp.txt", "w");

        while (fscanf(banco, "%d %9s %9s %f", &quartos.numero, quartos.tipo, quartos.status, &quartos.preco) == 4) {
            if (strstr(quartos.tipo, tipo) != NULL && strcmp(quartos.status,"LIVRE")==0) {
                quartos.preco = novo_preco;
                aux++;
            }
            else if (strstr(quartos.tipo, tipo) != NULL && strcmp(quartos.status,"LIVRE")!=0) {
                aux++;
            }
            fprintf(temp, "%d %s %s %.2f\n", quartos.numero, quartos.tipo, quartos.status, quartos.preco);
        }

        fclose(banco);
        fclose(temp);
     
        remove("banco.txt");
        
        rename("temp.txt", "banco.txt");

        printf("\n-------------------------------------------------------\n");
        if (aux == 0) {
            printf(" TIPO NÃO ENCONTRADO !\n");
        } 
        else {
            printf(" PREÇO DOS QUARTOS LIVRES ALTERADO COM SUCESSO !\n");
        }
        printf("-------------------------------------------------------\n\n");
    } else {
        printf("\n----------------------------\n");
        printf(" NENHUM QUARTO CADASTRADO !\n");
        printf("----------------------------\n\n");
    }
}



void buscar_pelo_status(FILE *banco){
    char status[10];
    int aux=0;
    quarto quartos;

    banco=fopen("banco.txt","r");

    if (banco)
    {
        printf("INFORME O STATUS DO QUARTO QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%9[^\n]",status);
        for (int j = 0; status[j]; j++)
        {
            status[j] = toupper(status[j]);
        }

        

        printf("╔══════════════════════════════════════════════════╗\n");
        printf("║ NÚMERO ║ TIPO         ║ STATUS       | PREÇO     ║\n");
        printf("╠══════════════════════════════════════════════════╣\n");
        while (fscanf(banco, "%d %9s %9s %f", &quartos.numero, quartos.tipo, quartos.status, &quartos.preco) == 4)
            {
                if (strcmp(quartos.status,status) == 0)
                {
                    printf("║ %-6d ║ %-12s ║ %-12s ║ %-8.2f  ║\n", quartos.numero, quartos.tipo, quartos.status, quartos.preco);
                    aux++; 
                }
            }

        printf("╚══════════════════════════════════════════════════╝\n\n");
        
        if (aux==0)
        {
            printf("\n-------------------------\n");
            printf(" QUARTO NÃO ENCONTRADO !\n");
            printf("-------------------------\n\n");
        }
        fclose(banco);
    }
    else{
        printf("\n----------------------------\n");
        printf(" NENHUM QUARTO CADASTRADO !\n");
        printf("----------------------------\n\n");
    }
}

void definir_quantidade_de_clientes(int *quantidade_de_clientes)
{
    printf("QUANTOS CLIENTES DESEJA CADASTRAR: ");
    scanf("%d", quantidade_de_clientes);
    printf("\n");
}

void cadastrar_cliente(int *quantidade_de_clientes, FILE *pessoas, FILE *pessoas1) {
    int i = 0,aux3;
    char cpf_temp[15];
    cliente clientes,aux4;

    if (*quantidade_de_clientes == 0) {

        printf("\n----------------------------------------------------------\n");
        printf(" VOCÊ AINDA NÃO DEFINIU UMA QUANTIDADE A SER CADASTRADA !\n");
        printf("----------------------------------------------------------\n\n");

    } 
    
    else if (i < *quantidade_de_clientes) {
        
        while (i < *quantidade_de_clientes){
                        
            scanf("%*c");
            printf("INFORME SEU NOME: ");
            scanf("%[^\n]", clientes.nome);
            for (int j = 0; clientes.nome[j]; j++) {
                clientes.nome[j] = toupper(clientes.nome[j]);
            }
            
            
            while(1){
                aux3=0;
                
                pessoas = fopen("pessoas.txt", "a");
                pessoas1 = fopen("pessoas.txt", "r");
                
                if (pessoas) {
                
                    scanf("%*c");
                    printf("INFORME SEU CPF: ");
                    scanf("%[^\n]", cpf_temp);

                    rewind(pessoas1);

                    while (fscanf(pessoas1, "%s %s %s %s %s %[^\n]", aux4.cpf, aux4.rg, aux4.telefone, aux4.endereco, aux4.email, aux4.nome) == 6) {
                        if (strcmp(cpf_temp,aux4.cpf)==0) {
                            printf("\n\n----------------------------------\n");
                            printf(" ESSE CLIENTE JÁ FOI CADASTRADO !\n");
                            printf("----------------------------------\n\n");
                            aux3++;
                            break;  
                        }
                        
                    }
                    
                    
                }

                else{
                printf("ERRO AO ABRIR ARQUIVO pessoas.txt");
                exit(1);
                }

                if (aux3==0)
                {
                    break;
                }
            }  
            strcpy(clientes.cpf,cpf_temp);

            scanf("%*c");
            printf("INFORME SEU RG: ");
            scanf("%[^\n]", clientes.rg);

            scanf("%*c");
            printf("INFORME SEU TELEFONE: ");
            scanf("%[^\n]", clientes.telefone);

            scanf("%*c");
            printf("INFORME SEU ENDEREÇO: ");
            scanf("%[^\n]", clientes.endereco);

            for (int j = 0; clientes.endereco[j]; j++) {
                clientes.endereco[j]=toupper(clientes.endereco[j]);
                if (clientes.endereco[j] == ' ') {
                    clientes.endereco[j] = '_';
                }
            }

            scanf("%*c");
            printf("INFORME SEU EMAIL: ");
            scanf("%49[^\n]", clientes.email);

            fprintf(pessoas, "%s %s %s %s %s %s\n", clientes.cpf,
                    clientes.rg, clientes.telefone,
                    clientes.endereco, clientes.email, clientes.nome);

            printf("\n\n");

            i++;
            fclose(pessoas);
            fclose(pessoas1);
            printf("\n----------------------------------\n");
            printf(" CLIENTE CADASTRADO COM SUCESSO !\n");
            printf("----------------------------------\n\n");
        

        }

        *quantidade_de_clientes = 0;
    }

    else {
        printf("\n----------------------------------------------\n");
        printf("VOCE JÁ CADASTROU A QUANTIDADE QUE DESEJAVA !\n");
        printf("----------------------------------------------\n\n");
    }
}


void consultar_cliente()
{
    printf("╔════════════════════════════════════╗\n");
    printf("║ [1] LISTAR TODOS OS CLIENTES       ║\n");
    printf("║ [2] BUSCAR CLIENTE PELO NOME       ║\n");
    printf("║ [3] BUSCAR CLIENTE PELO CPF        ║\n");
    printf("║ [4] BUSCAR CLIENTE PELO EMAIL      ║\n");
    printf("║ [5] BUSCAR CLIENTE PELO ENDEREÇO   ║\n");
    printf("║ [6] BUSCAR CLIENTE PELO TELEFONE   ║\n");
    printf("║ [0] MENU ANTERIOR                  ║\n");
    printf("╚════════════════════════════════════╝\n\n");

}

void listar_todos_clientes(FILE *pessoas) {
    cliente clientes;

    pessoas = fopen("pessoas.txt", "r");

    if (pessoas) {
        printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
        printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6) {
            printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
        }

        printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");

        fclose(pessoas);
    } else {
        printf("\n-----------------------------\n");
        printf(" NENHUM CLIENTE CADASTRADO !\n");
        printf("-----------------------------\n\n");
    }
}

void buscar_cliente_pelo_nome(FILE *pessoas){
    char nome[50];
    int aux=0;
    cliente clientes;

    pessoas=fopen("pessoas.txt","r");

    if (pessoas)
    {
        printf("INFORME O NOME DO CLIENTE QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%49[^\n]",nome);
        printf("\n\n");

        for (int j = 0; nome[j]; j++)
        {
            nome[j] = toupper(nome[j]);
        }


        

        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
        {
            if(strstr(clientes.nome, nome) != NULL)
            {
                printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
                printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
                printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
                printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
                printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
                aux++;
            }
        }

        

        if (aux==0)
            {
                printf("\n--------------------------\n");
                printf(" CLIENTE NÃO ENCONTRADO !\n");
                printf("--------------------------\n\n");
            }
            fclose(pessoas);
    }
    else{
            printf("\n-----------------------------\n");
            printf(" NENHUM CLIENTE CADASTRADO !\n");
            printf("-----------------------------\n\n");
        }
}

void buscar_cliente_pelo_endereco(FILE *pessoas){
    char endereco[50];
    int aux = 0;
    cliente clientes;

    pessoas = fopen("pessoas.txt", "r");

    if (pessoas) {
        printf("INFORME O ENDEREÇO DO CLIENTE QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%49[^\n]", endereco);
        printf("\n\n");

        for (int j = 0; endereco[j]; j++) {
            endereco[j] = toupper(endereco[j]);
            if (endereco[j] == ' ') {
                endereco[j] = '_';
            }
        }

        printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
        printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6) {
            char endereco_temp[50];
            strcpy(endereco_temp, clientes.endereco);

            for (int j = 0; endereco_temp[j]; j++) {
                if (endereco_temp[j] == ' ') {
                    endereco_temp[j] = '_';
                }
            }

            if (strstr(endereco_temp, endereco) != NULL) {
                printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
                
                aux++;
            }
        }

        printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");

        if (aux == 0) {
            printf("\n-------------------------\n");
            printf(" CLIENTE NÃO ENCONTRADO !\n");
            printf("-------------------------\n\n");
        }
        fclose(pessoas);
    } else {
        printf("\n-----------------------------\n");
        printf(" NENHUM CLIENTE CADASTRADO !\n");
        printf("-----------------------------\n\n");
    }
}


void buscar_cliente_pelo_cpf(FILE *pessoas){
    char cpf[15];
    int aux=0;
    cliente clientes;

    pessoas=fopen("pessoas.txt","r");

    if (pessoas)
    {
        printf("INFORME O CPF DO CLIENTE QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%14[^\n]",cpf);
        for (int j = 0; cpf[j]; j++)
        {
            cpf[j] = toupper(cpf[j]);
        }

        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
        {
            if(strstr(clientes.cpf, cpf) != NULL)
            {
                printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
                printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
                printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
                printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
                printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
                aux++;
            }
        }
        if (aux==0)
            {
                printf("\n--------------------------\n");
                printf(" CLIENTE NÃO ENCONTRADO !\n");
                printf("--------------------------\n\n");
            }
            fclose(pessoas);
    }
    else{
            printf("\n-----------------------------\n");
            printf(" NENHUM CLIENTE CADASTRADO !\n");
            printf("-----------------------------\n\n");
        }
}

void buscar_cliente_pelo_telefone(FILE *pessoas){
    char telefone[15];
    int aux=0;
    cliente clientes;

    pessoas=fopen("pessoas.txt","r");

    if (pessoas)
    {
        printf("INFORME O TELEFONE DO CLIENTE QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%14[^\n]",telefone);
        for (int j = 0; telefone[j]; j++)
        {
            telefone[j] = toupper(telefone[j]);
        }

        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
        {
            if(strstr(clientes.telefone, telefone) != NULL)
            {
                printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
                printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
                printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
                printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
                printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
                aux++;
                aux++;
            }
        }
        if (aux==0)
            {
                printf("\n--------------------------\n");
                printf(" CLIENTE NÃO ENCONTRADO !\n");
                printf("--------------------------\n\n");
            }
            fclose(pessoas);
    }
    else{
            printf("\n-----------------------------\n");
            printf(" NENHUM CLIENTE CADASTRADO !\n");
            printf("-----------------------------\n\n");
        }
}

void buscar_cliente_pelo_email(FILE *pessoas){
    char email[50];
    int aux=0;
    cliente clientes;

    pessoas=fopen("pessoas.txt","r");

    if (pessoas)
    {
        printf("INFORME O EMAIL DO CLIENTE QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%49[^\n]",email);

        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
        {
            if(strstr(clientes.email, email) != NULL)
            {
                printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
                printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
                printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
                printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
                printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
                aux++;
            }
        }
        if (aux==0)
            {
                printf("\n--------------------------\n");
                printf(" CLIENTE NÃO ENCONTRADO !\n");
                printf("--------------------------\n\n");
            }
            fclose(pessoas);
    }
    else{
            printf("\n-----------------------------\n");
            printf(" NENHUM CLIENTE CADASTRADO !\n");
            printf("-----------------------------\n\n");
        }
}


void menu_editar_cliente(){
    printf("╔════════════════════════════════════╗\n");
    printf("║ [1] EDITAR TUDO DO CLIENTE         ║\n");
    printf("║ [2] EDITAR O NOME DO CLIENTE       ║\n");
    printf("║ [3] EDITAR O CPF DO CLIENTE        ║\n");
    printf("║ [4] EDITAR O RG DO CLIENTE         ║\n");
    printf("║ [5] EDITAR O TELEFONE DO CLIENTE   ║\n");
    printf("║ [6] EDITAR O ENDEREÇO DO CLIENTE   ║\n");
    printf("║ [7] EDITAR O EMAIL DO CLIENTE      ║\n");
    printf("║ [0] MENU ANTERIOR                  ║\n");
    printf("╚════════════════════════════════════╝\n");

}


void editar_tudo_cliente(FILE *pessoas){ 
    char nome[50],resp;
    int aux=0;
    cliente clientes;

    pessoas = fopen("pessoas.txt", "r+");

    if (pessoas)
    {
        printf("INFORME O NOME DO CLIENTE QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%49[^\n]", nome);
        for (int j = 0; nome[j]; j++)
        {
            nome[j] = toupper(nome[j]);
        }
        printf("\n\n");


        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
        {
            if(strstr(clientes.nome, nome) != NULL)
            {
                printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
                printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
                printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
                printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
                printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");

                printf("DESEJA EDITAR AS INFORMAÇÕES ? [S/N]: ");
                scanf(" %c",&resp);

                if (resp=='S' || resp=='s')
                {
                    FILE *temp = fopen("temp.txt", "w");
                    rewind(pessoas);
                    while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
                    {
                        if(strstr(clientes.nome, nome) != NULL)
                        {
                            scanf("%*c");
                            printf("INFORME SEU NOVO NOME: ");
                            scanf("%[^\n]", clientes.nome);
                            for (int j = 0; clientes.nome[j]; j++)
                            {
                                clientes.nome[j] = toupper(clientes.nome[j]);
                            }

                            scanf("%*c");
                            printf("INFORME SEU NOVO CPF: ");
                            scanf("%[^\n]", clientes.cpf);

                            scanf("%*c");
                            printf("INFORME SEU NOVO RG: ");
                            scanf("%[^\n]", clientes.rg);

                            scanf("%*c");
                            printf("INFORME SEU NOVO TELEFONE: ");
                            scanf("%[^\n]", clientes.telefone);

                            scanf("%*c");
                            printf("INFORME SEU NOVO ENDEREÇO: ");
                            scanf("%[^\n]", clientes.endereco);
                            for (int j = 0; clientes.endereco[j]; j++)
                            {
                                clientes.endereco[j] = toupper(clientes.endereco[j]);
                                if (clientes.endereco[j] == ' ') {
                                    clientes.endereco[j] = '_';
                                }
                            }

                            scanf("%*c");
                            printf("INFORME SEU NOVO EMAIL: ");
                            scanf("%49[^\n]", clientes.email);

                           
                        }
                        fprintf(temp, "%s %s %s %s %s %s\n", clientes.cpf,
                        clientes.rg, clientes.telefone,
                        clientes.endereco, clientes.email, clientes.nome);
                    }
                    

                    fclose(pessoas);
                    fclose(temp);

                    // Remover o arquivo original
                    remove("pessoas.txt");
                    
                    // Renomear o arquivo temporÃ¡rio para o original
                    rename("temp.txt", "pessoas.txt");

                    printf("\n--------------------------------\n");
                    printf(" CLIENTE ALTERADO COM SUCESSO !\n");
                    printf("--------------------------------\n\n");

                }

                else
                {
                    printf("\n--------------------\n");
                    printf(" EDIÇÃO CANCELADA !\n");
                    printf("--------------------\n");

                }
                aux++;
            }
        }
        if (aux==0)
        {
            printf("\n--------------------------\n");
            printf(" CLIENTE NÃO ENCONTRADO !\n");
            printf("--------------------------\n\n");
        }
        fclose(pessoas);
    }

    else{
        printf("\n-----------------------------\n");
        printf(" NENHUM CLIENTE CADASTRADO !\n");
        printf("-----------------------------\n\n");
    }
}

void Remover_cliente(FILE *pessoas){
    cliente clientes;
    int aux=0;
    char nome[50],resp;

    pessoas=fopen("pessoas.txt","r");
    if (pessoas)
    {
        printf("INFORME O NOME DO CLIENTE QUE DESEJA REMOVER: ");
        fflush(stdin);
        scanf("%49[^\n]", nome);
        for (int j = 0; nome[j]; j++)
        {
            nome[j] = toupper(nome[j]);
        }
        printf("\n\n");

        rewind(pessoas);
        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
        {  
            if(strcmp(clientes.nome, nome)==0)
            {
                printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
                printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
                printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
                printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
                printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
                printf("VOCE DESEJA MESMO EXCLUIR ESSE CLIENTE? [S/N]: ");
                scanf(" %c",&resp);

                if (resp=='S' || resp=='s')
                {
                    FILE *temp = fopen("temp.txt", "w");
                    rewind(pessoas);
                    while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
                    {
                        if(strcmp(clientes.nome, nome)==0)
                        {
                        }
                        else{
                            fprintf(temp, "%s %s %s %s %s %s\n", clientes.cpf,
                                    clientes.rg, clientes.telefone,
                                    clientes.endereco, clientes.email, clientes.nome);
                        }
                    }

                    fclose(pessoas);
                    fclose(temp);

                    remove("pessoas.txt");
                    
                    rename("temp.txt", "pessoas.txt");

                    printf("\n--------------------------------\n");
                    printf(" CLIENTE EXCLUIDO COM SUCESSO !\n");
                    printf("--------------------------------\n\n");
                    

                }

                else
                {
                    printf("\n----------------------\n");
                    printf(" EXCLUSÃO CANCELADA !\n");
                    printf("----------------------\n");
                }
                
                aux++;
            }

            

        }
        
         if (aux==0)
        {
            printf("\n--------------------------\n");
            printf(" CLIENTE NÃO ENCONTRADO !\n");
            printf("--------------------------\n\n");
        }
        fclose(pessoas);
    }

    else{
        printf("\n-----------------------------\n");
        printf(" NENHUM CLIENTE CADASTRADO !\n");
        printf("-----------------------------\n\n");
    }
    

}

void editar_nome_cliente(FILE *pessoas){
    char cpf[15],resp;
    int aux=0;
    cliente clientes;

    pessoas = fopen("pessoas.txt", "r");

    if (pessoas)
    {
        printf("INFORME O NÚMERO DO CPF DO CLIENTE QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%14[^\n]", cpf);
        printf("\n\n");

        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
        {
            if(strstr(clientes.cpf, cpf) != NULL)
            {
                printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
                printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
                printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
                printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
                printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
                
                printf("VOCE DESEJA MESMO RENOMEAR ESSE CLIENTE? [S/N]: ");
                scanf(" %c",&resp);

                if (resp=='S' || resp=='s')
                {
                    FILE *temp = fopen("temp.txt", "w");
                    rewind(pessoas);
                    while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
                    {
                        if(strstr(clientes.cpf, cpf) != NULL)
                        {
                            printf("INFORME O NOVO NOME PARA O CLIENTE: ");
                            fflush(stdin);
                            scanf("%49[^\n]", clientes.nome);
                            for (int j = 0; clientes.nome[j]; j++)
                            {
                                clientes.nome[j] = toupper(clientes.nome[j]);
                            }
                        }

                        fprintf(temp, "%s %s %s %s %s %s\n", clientes.cpf,
                        clientes.rg, clientes.telefone,
                        clientes.endereco, clientes.email, clientes.nome);
                    }

                    fclose(pessoas);
                    fclose(temp);

                    
                    remove("pessoas.txt");
                    
                    rename("temp.txt", "pessoas.txt");

                    printf("---------------------------\n");
                    printf(" NOME ALTERADO COM SUCESSO\n");
                    printf("---------------------------\n\n");
                }

                else
                {
                    printf("\n--------------------\n");
                    printf(" EDIÇÃO CANCELADA !\n");
                    printf("--------------------\n");

                }

                aux++;
                
            }
            
        }
        

        if (aux==0)
        {
            printf("\n--------------------------\n");
            printf(" CLIENTE NÃO ENCONTRADO !\n");
            printf("--------------------------\n\n");
        }

        fclose(pessoas);
    }

    else{
        printf("\n-----------------------------\n");
        printf(" NENHUM CLIENTE CADASTRADO !\n");
        printf("-----------------------------\n\n");
    }
}

void obterHoraAtual(char *horaAtual) {
    // Obter o tempo atual
    time_t tempoAtual;
    struct tm *infoTempo;

    time(&tempoAtual);
    infoTempo = localtime(&tempoAtual);

    // Formatar a hora como uma string
    strftime(horaAtual, 9, "%H:%M:%S", infoTempo);
}

void editar_cpf_cliente(FILE *pessoas){
    char nome[50],resp;
    int aux=0;
    cliente clientes;

    pessoas = fopen("pessoas.txt", "r+");

    if (pessoas)
    {
        printf("INFORME O NOME DO CLIENTE QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%49[^\n]", nome);
        for (int j = 0; nome[j]; j++)
        {
            nome[j] = toupper(nome[j]);
        }
        printf("\n\n");

        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
        {
            if(strstr(clientes.nome, nome) != NULL)
            {
                printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
                printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
                printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
                printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
                printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
                
                printf("VOCÊ DESEJA MESMO RENOMEAR ESSE CLIENTE? [S/N]: ");
                scanf(" %c",&resp);

                if (resp=='S' || resp=='s')
                {
                    FILE *temp = fopen("temp.txt", "w");
                    rewind(pessoas);
                    while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
                    {
                        if(strstr(clientes.nome, nome) != NULL)
                        {
                            printf("INFORME O NOVO CPF PARA O CLIENTE: ");
                            fflush(stdin);
                            scanf("%14[^\n]", clientes.cpf);
                        }

                        fprintf(temp, "%s %s %s %s %s %s\n", clientes.cpf,
                        clientes.rg, clientes.telefone,
                        clientes.endereco, clientes.email, clientes.nome);
                    }

                    fclose(pessoas);
                    fclose(temp);

                    
                    remove("pessoas.txt");
                    
                    rename("temp.txt", "pessoas.txt");

                    printf("----------------------------\n");
                    printf(" CPF ALTERADO COM SUCESSO !\n");
                    printf("----------------------------\n\n");
                }

                else
                {
                    printf("\n--------------------\n");
                    printf(" EDIÇÃO CANCELADA !\n");
                    printf("--------------------\n");

                }

                aux++;
                
            }
            
        }

        if (aux==0)
        {
            printf("\n--------------------------\n");
            printf(" CLIENTE NÃO ENCONTRADO !\n");
            printf("--------------------------\n\n");
        }
        fclose(pessoas);
    }

    else{
        printf("\n-----------------------------\n");
        printf(" NENHUM CLIENTE CADASTRADO !\n");
        printf("-----------------------------\n\n");
    }
}

void editar_rg_cliente(FILE *pessoas){
    char nome[50],resp;
    int aux=0;
    cliente clientes;

    pessoas = fopen("pessoas.txt", "r+");

    if (pessoas)
    {
        printf("INFORME O NOME DO CLIENTE QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%49[^\n]", nome);
        for (int j = 0; nome[j]; j++)
        {
            nome[j] = toupper(nome[j]);
        }
        printf("\n\n");

        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
        {
            if(strstr(clientes.nome, nome) != NULL)
            {
                printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
                printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
                printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
                printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
                printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
                
                printf("VOCÊ DESEJA MESMO ALTERAR O RG DESSE CLIENTE? [S/N]: ");
                scanf(" %c",&resp);

                if (resp=='S' || resp=='s')
                {
                    FILE *temp = fopen("temp.txt", "w");
                    rewind(pessoas);
                    while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
                    {
                        if(strstr(clientes.nome, nome) != NULL)
                        {
                            printf("INFORME O NOVO RG PARA O CLIENTE: ");
                            fflush(stdin);
                            scanf("%14[^\n]", clientes.rg);
                        }

                        fprintf(temp, "%s %s %s %s %s %s\n", clientes.cpf,
                        clientes.rg, clientes.telefone,
                        clientes.endereco, clientes.email, clientes.nome);
                    }

                    fclose(pessoas);
                    fclose(temp);

                    
                    remove("pessoas.txt");
                    
                    rename("temp.txt", "pessoas.txt");

                    printf("---------------------------\n");
                    printf(" RG ALTERADO COM SUCESSO !\n");
                    printf("---------------------------\n\n");
                }

                else
                {
                    printf("\n--------------------\n");
                    printf(" EDIÇÃO CANCELADA !\n");
                    printf("--------------------\n");

                }

                aux++;
                
            }
            
        }

        if (aux==0)
        {
            printf("\n--------------------------\n");
            printf(" CLIENTE NÃO ENCONTRADO !\n");
            printf("--------------------------\n\n");
        }
        fclose(pessoas);
    }

    else{
        printf("\n-----------------------------\n");
        printf(" NENHUM CLIENTE CADASTRADO !\n");
        printf("-----------------------------\n\n");
    }
}

void editar_telefone_cliente(FILE *pessoas){
    char nome[50],resp;
    int aux=0;
    cliente clientes;

    pessoas = fopen("pessoas.txt", "r+");

    if (pessoas)
    {
        printf("INFORME O NOME DO CLIENTE QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%49[^\n]", nome);
        for (int j = 0; nome[j]; j++)
        {
            nome[j] = toupper(nome[j]);
        }
        printf("\n\n");

        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
        {
            if(strstr(clientes.nome, nome) != NULL)
            {
                printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
                printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
                printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
                printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
                printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
                
                printf("VOCÊ DESEJA MESMO ALTERAR O TELEFONE DESSE CLIENTE? [S/N]: ");
                scanf(" %c",&resp);

                if (resp=='S' || resp=='s')
                {
                    FILE *temp = fopen("temp.txt", "w");
                    rewind(pessoas);
                    while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
                    {
                        if(strstr(clientes.nome, nome) != NULL)
                        {
                            printf("INFORME O NOVO TELEFONE PARA O CLIENTE: ");
                            fflush(stdin);
                            scanf("%14[^\n]", clientes.telefone);
                        }

                        fprintf(temp, "%s %s %s %s %s %s\n", clientes.cpf,
                        clientes.rg, clientes.telefone,
                        clientes.endereco, clientes.email, clientes.nome);
                    }

                    fclose(pessoas);
                    fclose(temp);

                    
                    remove("pessoas.txt");
                    
                    rename("temp.txt", "pessoas.txt");

                    printf("---------------------------\n");
                    printf(" RG ALTERADO COM SUCESSO !\n");
                    printf("---------------------------\n\n");
                }

                else
                {
                    printf("\n--------------------\n");
                    printf(" EDIÇÃO CANCELADA !\n");
                    printf("--------------------\n");

                }

                aux++;
                
            }
            
        }

        if (aux==0)
        {
            printf("\n--------------------------\n");
            printf(" CLIENTE NÃO ENCONTRADO !\n");
            printf("--------------------------\n\n");
        }
        fclose(pessoas);
    }

    else{
        printf("\n-----------------------------\n");
        printf(" NENHUM CLIENTE CADASTRADO !\n");
        printf("-----------------------------\n\n");
    }
}



void editar_endereco_cliente(FILE *pessoas){
     char nome[50],resp;
    int aux=0;
    cliente clientes;

    pessoas = fopen("pessoas.txt", "r+");

    if (pessoas)
    {
        printf("INFORME O NOME DO CLIENTE QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%49[^\n]", nome);
        for (int j = 0; nome[j]; j++)
        {
            nome[j] = toupper(nome[j]);
        }
        printf("\n\n");

        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
        {
            if(strstr(clientes.nome, nome) != NULL)
            {
                printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
                printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
                printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
                printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
                printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
                
                printf("VOCÊ DESEJA MESMO ALTERAR O ENDEREÇO DESSE CLIENTE? [S/N]: ");
                scanf(" %c",&resp);

                if (resp=='S' || resp=='s')
                {
                    FILE *temp = fopen("temp.txt", "w");
                    rewind(pessoas);
                    while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
                    {
                        if(strstr(clientes.nome, nome) != NULL)
                        {
                            printf("INFORME O NOVO ENDEREÇO PARA O CLIENTE: ");
                            fflush(stdin);
                            scanf("%49[^\n]", clientes.endereco);
                            for (int j = 0; clientes.endereco[j]; j++)
                            {
                                clientes.endereco[j]=toupper(clientes.endereco[j]);
                                if (clientes.endereco[j] == ' ') {
                                    clientes.endereco[j] = '_';
                                }
                            }
                        }

                        fprintf(temp, "%s %s %s %s %s %s\n", clientes.cpf,
                        clientes.rg, clientes.telefone,
                        clientes.endereco, clientes.email, clientes.nome);
                    }

                    fclose(pessoas);
                    fclose(temp);

                    
                    remove("pessoas.txt");
                    
                    rename("temp.txt", "pessoas.txt");

                    printf("---------------------------------\n");
                    printf(" ENDEREÇO ALTERADO COM SUCESSO !\n");
                    printf("---------------------------------\n\n");
                }

                else
                {
                    printf("\n--------------------\n");
                    printf(" EDIÇÃO CANCELADA !\n");
                    printf("--------------------\n");

                }

                aux++;
                
            }
            
        }

        if (aux==0)
        {
            printf("\n--------------------------\n");
            printf(" CLIENTE NÃO ENCONTRADO !\n");
            printf("--------------------------\n\n");
        }
        fclose(pessoas);
    }

    else{
        printf("\n-----------------------------\n");
        printf(" NENHUM CLIENTE CADASTRADO !\n");
        printf("-----------------------------\n\n");
    }
}

int gregoriana_juliana(int dia, int mes, int ano)
{
	int juliana;

	juliana = (1461 * (ano + 4800 + (mes - 14) / 12)) / 4 + (367 * (mes - 2 - 12 * ((mes - 14) / 12))) / 12 - (3 * ((ano + 4900 + (mes - 14) / 12) / 100)) / 4 + dia - 32075;
	
	return juliana;
}
   
void juliana_gregoriana(int juliana, char *data) {
    int b, n, k, j;
    int dia, mes, ano;

    b = juliana + 68569;
    n = (4 * b) / 146097;
    b = b - ((146097 * n + 3) / 4);
    k = 4000 * (b + 1) / 1461001;
    b = b - (1461 * k) / 4 + 31;
    j = (80 * b) / 2447;
    dia = b - (2447 * j) / 80;
    b = (j / 11);
    mes = j + 2 - (12 * b);
    ano = 100 * (n - 49) + k + b;

    sprintf(data, "%02d/%02d/%04d", dia, mes, ano);
}

void editar_email_cliente(FILE *pessoas){
    char nome[50],resp;
    int aux=0;
    cliente clientes;

    pessoas = fopen("pessoas.txt", "r+");

    if (pessoas)
    {
        printf("INFORME O NOME DO CLIENTE QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%49[^\n]", nome);
        for (int j = 0; nome[j]; j++)
        {
            nome[j] = toupper(nome[j]);
        }
        printf("\n\n");

        while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
        {
            if(strstr(clientes.nome, nome) != NULL)
            {
                printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
                printf("║             NOME               ║       CPF        ║        RG        ║     TELEFONE     ║            ENDEREÇO            ║              EMAIL             ║\n");
                printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
                printf("║ %-30s ║ %-16s ║ %-16s ║ %-16s ║ %-30s ║ %-30s ║\n", clientes.nome, clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email);
                printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
                
                printf("VOCÊ DESEJA MESMO ALTERAR O EMAIL DESSE CLIENTE? [S/N]: ");
                scanf(" %c",&resp);

                if (resp=='S' || resp=='s')
                {
                    FILE *temp = fopen("temp.txt", "w");
                    rewind(pessoas);
                    while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
                    {
                        if(strstr(clientes.nome, nome) != NULL)
                        {
                            printf("INFORME O NOVO EMAIL PARA O CLIENTE: ");
                            fflush(stdin);
                            scanf("%49[^\n]", clientes.email);
                        }

                        fprintf(temp, "%s %s %s %s %s %s\n", clientes.cpf,
                        clientes.rg, clientes.telefone,
                        clientes.endereco, clientes.email, clientes.nome);
                    }

                    fclose(pessoas);
                    fclose(temp);

                    
                    remove("pessoas.txt");
                    
                    rename("temp.txt", "pessoas.txt");

                    printf("------------------------------\n");
                    printf(" EMAIL ALTERADO COM SUCESSO !\n");
                    printf("------------------------------\n\n");
                }

                else
                {
                    printf("\n--------------------\n");
                    printf(" EDIÇÃO CANCELADA !\n");
                    printf("--------------------\n");

                }

                aux++;
                
            }
            
        }

        if (aux==0)
        {
            printf("\n--------------------------\n");
            printf(" CLIENTE NÃO ENCONTRADO !\n");
            printf("--------------------------\n\n");
        }
        fclose(pessoas);
    }

    else{
        printf("\n-----------------------------\n");
        printf(" NENHUM CLIENTE CADASTRADO !\n");
        printf("-----------------------------\n\n");
    }
}

void realizar_rezerva(FILE *dados,FILE *banco,FILE *dados1,FILE *pessoas){
    reserva reserva1;
    quarto quarto1;
    cliente clientes;
    int num, clienteValido,aux,aux1;
    float preco;
    char nome[50];

    dados=fopen("dados.txt","a");
    dados1=fopen("dados.txt","r");
    banco=fopen("banco.txt","r");
    pessoas=fopen("pessoas.txt", "r");


    if (banco)
    {
        
        if (dados && dados1 && pessoas)
        {
            do {

                printf("INFORME SEU NOME: "); 
                fflush(stdin);                
                scanf("%[^\n]",nome);
                for (int j = 0; nome[j]; j++)
                {
                    nome[j] = toupper(nome[j]);
                }
                printf("\n");

                rewind(pessoas);

                while (fscanf(pessoas, "%s %s %s %s %s %[^\n]", clientes.cpf, clientes.rg, clientes.telefone, clientes.endereco, clientes.email, clientes.nome) == 6)
                {
                    
                    if (strcmp(clientes.nome, nome)==0)
                    {
                        strcpy(reserva1.nome, clientes.nome);
                        clienteValido = 1;
                        break;
                    }
                    else{
                        clienteValido = 0;
                    }
                }
                if (!clienteValido)
                {
                    printf("---------------------------------\n");
                    printf(" VOCÊ AINDA NÃO FOI CADASTRADO !\n");
                    printf("---------------------------------\n\n");
                }
            } while(!clienteValido);

            printf("INFORME O NÚMERO DO QUARTO: ");
            scanf("%d",&num);
            printf("\n");

            while(1){
                rewind(banco);
                aux1=0;
                while (fscanf(banco, "%d %9s %9s %f", &quarto1.numero, quarto1.tipo, quarto1.status, &quarto1.preco) == 4)
                {
                    if (num==quarto1.numero)
                    {
                        aux1++;
                        reserva1.numero=num;
                        
                    }
                }
                if (aux1==0)
                {
                    printf("QUARTO NÃO ENCONTRADO\n");
                    printf("ESCOLHA UM DESSES:\n");
                    

                    printf("╔══════════════════════════════════════════════════╗\n");
                    printf("║ NÚMERO ║ TIPO         ║ STATUS       | PREÇO     ║\n");
                    printf("╠══════════════════════════════════════════════════╣\n");

                    rewind(banco);
                    
                    while (fscanf(banco, "%d %9s %9s %f", &quarto1.numero, quarto1.tipo, quarto1.status, &quarto1.preco) == 4)
                    {
                        
                        printf("║ %-6d ║ %-12s ║ %-12s ║ %-8.2f  ║\n", quarto1.numero, quarto1.tipo, quarto1.status, quarto1.preco);
                        
                        
                    }
                    
                    printf("╚══════════════════════════════════════════════════╝\n\n");

                    scanf("%d",&num);


                }
                
                else{
                    break;
                }
            }

            rewind(banco);
            while (fscanf(banco, "%d %9s %9s %f", &quarto1.numero, quarto1.tipo, quarto1.status, &quarto1.preco) == 4)
            {  
                if(reserva1.numero==quarto1.numero && strcmp(quarto1.status,"LIVRE")==0){
                    
                    int datavalida=0;

                    do
                    {
                       
                        printf("INSIRA A DATA DE INICIO (DD/MM/AAAA): ");
                        scanf("%d/%d/%d", &reserva1.dia,&reserva1.mes,&reserva1.ano);
                        printf("\n");

                        reserva1.julianai=gregoriana_juliana(reserva1.dia,reserva1.mes,reserva1.ano);

                        printf("INSIRA A DATA DE FIM (DD/MM/AAAA): ");
                        scanf("%d/%d/%d", &reserva1.dia,&reserva1.mes,&reserva1.ano);
                        printf("\n");

                        reserva1.julianaf=gregoriana_juliana(reserva1.dia,reserva1.mes,reserva1.ano);

                        if (reserva1.julianai <= reserva1.julianaf)
                        {
                            datavalida = 1;
                        }
                        
                        else{
                            printf("\n--------------------------------\n");
                            printf(" DATA INVÁLIDA! DIGITE DE NOVO.\n");
                            printf("--------------------------------\n\n");
                        }
                        
                    } while (!datavalida);
                    
                    

                    srand(time(NULL));


                    int intervalo=reserva1.julianaf-reserva1.julianai+1;

                    if (dados1)
                    {
                        int cod_temp;
                        reserva aux2;

                        do
                        {
                            rewind(dados1);
                            aux=0;
                            cod_temp=rand() % 100;
                            while (fscanf(dados1,"%d %d %d %d %f %29s %s %[^\n]",&aux2.numero,&aux2.cod,&aux2.julianai
                                    ,&aux2.julianaf,&aux2.total,aux2.status_pagamento,aux2.hora_inicial,aux2.nome)==8)
                            {
                                if (cod_temp==aux2.cod)
                                {
                                    aux++;
                                }
                                
                            }

                        } while (aux!=0);

                        reserva1.cod=cod_temp;

                    }
                            
                    else
                    {
                        reserva1.cod=rand() % 100;

                    }

                    if (quarto1.numero==num && strcmp(quarto1.tipo,"SIMPLES")==0)
                    {
                        preco=quarto1.preco;
                    }

                    else if (quarto1.numero==num && strcmp(quarto1.tipo,"DUPLO")==0)
                    {
                        preco=quarto1.preco;
                    }

                    else if (quarto1.numero==num && strcmp(quarto1.tipo,"SUITE")==0)
                    {
                        preco=quarto1.preco;
                    }

                    reserva1.total=intervalo*preco;

                    obterHoraAtual(&reserva1.hora_inicial);

                    strcpy(reserva1.status_pagamento,"PENDENTE");
                    fprintf(dados,"%d %d %d %d %.2f %s %s %s\n",reserva1.numero,reserva1.cod
                    ,reserva1.julianai,reserva1.julianaf,reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome);

                    rewind(banco);

                    FILE *temp = fopen("temp.txt", "w");

                    while (fscanf(banco, "%d %9s %9s %f", &quarto1.numero, quarto1.tipo, quarto1.status, &quarto1.preco) == 4)
                    {
                        if (reserva1.numero==quarto1.numero)
                        {
                            strcpy(quarto1.status,"RESERVADO");
                        }
                        fprintf(temp, "%d %s %s %.2f\n", quarto1.numero,
                        quarto1.tipo, quarto1.status,
                        quarto1.preco);
                    }

                    fclose(banco);
                    fclose(temp);

                    // Remover o arquivo original
                    remove("banco.txt");
                    
                    // Renomear o arquivo temporÃ¡rio para o original
                    rename("temp.txt", "banco.txt");
                    
                    printf("---------------------------------\n");
                    printf(" RESERVA REALIZADA COM SUCESSO !\n");
                    printf("---------------------------------\n\n");

                    printf("-----------------------------\n");
                    printf(" SEU CÓDIGO DE RESERVA É %d\n",reserva1.cod);
                    printf("-----------------------------\n");

                    fclose(dados1);

                } 

                else if(reserva1.numero==quarto1.numero && strcmp(quarto1.status,"RESERVADO")==0 || reserva1.numero==quarto1.numero && strcmp(quarto1.status,"OCUPADO")==0)  
                {
                    int datavalida=0;
                    reserva aux2;

                    if (dados1)
                    {
                        do
                        {
                            rewind(dados1);
                            printf("INSIRA A DATA DE INICIO (DD/MM/AAAA): ");
                            scanf("%d/%d/%d", &reserva1.dia,&reserva1.mes,&reserva1.ano);
                            printf("\n");

                            reserva1.julianai=gregoriana_juliana(reserva1.dia,reserva1.mes,reserva1.ano);

                            printf("INSIRA A DATA DE FIM (DD/MM/AAAA): ");
                            scanf("%d/%d/%d", &reserva1.dia,&reserva1.mes,&reserva1.ano);
                            printf("\n");

                            reserva1.julianaf=gregoriana_juliana(reserva1.dia,reserva1.mes,reserva1.ano);

                            while (fscanf(dados1,"%d %d %d %d %f %29s %s %[^\n]",&aux2.numero,&aux2.cod,&aux2.julianai
                                    ,&aux2.julianaf,&aux2.total,aux2.status_pagamento,aux2.hora_inicial,aux2.nome)==8)
                            {
                                if (reserva1.julianai < aux2.julianai && reserva1.julianaf < aux2.julianai && reserva1.julianai < reserva1.julianaf)
                                {
                                    datavalida=1;
                                }

                                else if (reserva1.julianai > aux2.julianaf && reserva1.julianaf > aux2.julianaf && reserva1.julianai < reserva1.julianaf)
                                {
                                    datavalida=1;
                                }

                                else
                                {
                                    datavalida=0;
                                }
                                
                            }
                            
                            if(datavalida==0)
                            {
                                char datai[15];
                                char dataf[15];
                                printf("\n-------------------------------------------\n");
                                printf(" ESSE DIA JÁ ESTA RESERVADO! ESCOLHA OUTRO\n");
                                printf("-------------------------------------------\n\n");
                                rewind(dados1);

                                printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
                                printf("║             NOME               ║ NÚMERO ║ CÓDIGO ║ DATA INICIAL ║ DATA FINAL ║   TOTAL   ║ PAGAMENTO ║     HORA     ║\n");
                                printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");


                                while (fscanf(dados1,"%d %d %d %d %f %29s %s %[^\n]",&aux2.numero,&aux2.cod,&aux2.julianai
                                    ,&aux2.julianaf,&aux2.total,aux2.status_pagamento,aux2.hora_inicial,aux2.nome)==8)
                                {
                                    if (num == aux2.numero)
                                    {
                                        juliana_gregoriana(aux2.julianai,datai);
                                        juliana_gregoriana(aux2.julianaf,dataf);

                                        printf("║ %-30s ║ %-6d ║ %-6d ║ %-12s ║ %-10s ║ %-9.2f ║ %-9s ║ %-12s ║\n"
                                        ,aux2.nome, aux2.numero, aux2.cod
                                        ,datai, dataf, aux2.total
                                        ,aux2.status_pagamento, aux2.hora_inicial);


                                    }
                                }

                                printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
                            }
                        } while (!datavalida);

                        int intervalo=reserva1.julianaf-reserva1.julianai+1;

                        if (dados1)
                        {
                            int cod_temp;
                            reserva aux2;

                            do
                            {
                                rewind(dados1);
                                aux=0;
                                cod_temp=rand() % 100;
                                while (fscanf(dados1,"%d %d %d %d %f %29s %s %[^\n]",&aux2.numero,&aux2.cod,&aux2.julianai
                                        ,&aux2.julianaf,&aux2.total,aux2.status_pagamento,aux2.hora_inicial,aux2.nome)==8)
                                {
                                    if (cod_temp==aux2.cod)
                                    {
                                        aux++;
                                    }
                                    
                                }

                            } while (aux!=0);

                            reserva1.cod=cod_temp;

                        }
                                
                        else
                        {
                            reserva1.cod=rand() % 100;

                        }

                        if (quarto1.numero==num && strcmp(quarto1.tipo,"SIMPLES")==0)
                        {
                            preco=quarto1.preco;
                        }

                        else if (quarto1.numero==num && strcmp(quarto1.tipo,"DUPLO")==0)
                        {
                            preco=quarto1.preco;
                        }

                        else if (quarto1.numero==num && strcmp(quarto1.tipo,"SUITE")==0)
                        {
                            preco=quarto1.preco;
                        }

                        reserva1.total=intervalo*preco;


                        obterHoraAtual(&reserva1.hora_inicial);

                        strcpy(reserva1.status_pagamento,"PENDENTE");
                        fprintf(dados,"%d %d %d %d %.2f %s %s %s\n",reserva1.numero,reserva1.cod
                        ,reserva1.julianai,reserva1.julianaf,reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome);

                        rewind(banco);

                        FILE *temp = fopen("temp.txt", "w");

                        while (fscanf(banco, "%d %9s %9s %f", &quarto1.numero, quarto1.tipo, quarto1.status, &quarto1.preco) == 4)
                        {
                            if (reserva1.numero==quarto1.numero)
                            {
                                strcpy(quarto1.status,"RESERVADO");
                            }
                            fprintf(temp, "%d %s %s %.2f\n", quarto1.numero,
                            quarto1.tipo, quarto1.status,
                            quarto1.preco);
                        }

                        fclose(banco);
                        fclose(temp);

                        // Remover o arquivo original
                        remove("banco.txt");
                        
                        // Renomear o arquivo temporÃ¡rio para o original
                        rename("temp.txt", "banco.txt");
                        
                        printf("---------------------------------\n");
                        printf(" RESERVA REALIZADA COM SUCESSO !\n");
                        printf("---------------------------------\n\n");

                        printf("-----------------------------\n");
                        printf(" SEU CÓDIGO DE RESERVA É %d\n",reserva1.cod);
                        printf("-----------------------------\n");

                        fclose(dados1);
                    }
                }               
            }

            fclose(dados);
            
        }

        else{
            printf("---------------------------------\n");
            printf(" ERRO AO ABRIR ARQUIVO dados.txt\n");
            printf("---------------------------------\n\n");

            exit(1);
        }
        
        fclose(banco);
    
    }


    else
    {
        printf("\n--------------------------\n");
        printf(" NENHUM QUARTO CADASTRADO\n");
        printf("--------------------------\n\n");
    }
    
    
}

void consultar_reservas(){
    printf("╔════════════════════════════════════╗\n");
    printf("║ [1] CONSULTAR PELO CÓDIGO          ║\n");
    printf("║ [2] CONSULTAR PELO NOME            ║\n");
    printf("║ [0] MENU ANTERIOR                  ║\n");
    printf("╚════════════════════════════════════╝\n");


}

void exclui_reserva(FILE *dados, FILE *banco){
    dados=fopen("dados.txt","r");
    banco=fopen("banco.txt", "r");
    reserva reserva1;
    quarto quarto1;
    char datai[15];
    char dataf[15];
    int cod_temp, num, cont_res=0;
    int aux=0;
    char resp;

    if (dados)
    {
        printf("INFORME O CODIGO DE RESERVA: ");
        scanf("%d",&cod_temp);

        printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║             NOME               ║ NÚMERO ║ CÓDIGO ║ DATA INICIAL ║ DATA FINAL ║   TOTAL   ║ PAGAMENTO ║     HORA     ║\n");
        printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        while (fscanf(dados,"%d %d %d %d %f %29s %s %[^\n]",&reserva1.numero,&reserva1.cod,&reserva1.julianai
            ,&reserva1.julianaf,&reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome)==8)
        {
            if (cod_temp == reserva1.cod)
            {
                num = reserva1.numero;

                juliana_gregoriana(reserva1.julianai,datai);
                juliana_gregoriana(reserva1.julianaf,dataf);

                printf("║ %-30s ║ %-6d ║ %-6d ║ %-12s ║ %-10s ║ %-9.2f ║ %-9s ║ %-12s ║\n"
                ,reserva1.nome, reserva1.numero, reserva1.cod
                ,datai, dataf, reserva1.total
                ,reserva1.status_pagamento, reserva1.hora_inicial);
                aux++;
            }
        }
        printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");

        if (aux==1)
        {
            printf("DESEJA EXCLUIR A RESERVA ? [S/N]: ");
            scanf(" %c",&resp);

            if (resp=='S'||resp=='s')
            {
                rewind(dados);

                FILE *temp = fopen("temp.txt", "w");

                while (fscanf(dados,"%d %d %d %d %f %29s %s %[^\n]",&reserva1.numero,&reserva1.cod,&reserva1.julianai
                    ,&reserva1.julianaf,&reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome)==8)
                {
                    if (cod_temp == reserva1.cod)
                    {
                        num=reserva1.numero;
                    }

                    else{
                        fprintf(temp,"%d %d %d %d %.2f %s %s %s\n",reserva1.numero,reserva1.cod
                        ,reserva1.julianai,reserva1.julianaf,reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome);
                    }                
                }

                rewind(dados);
                while (fscanf(dados,"%d %d %d %d %f %29s %s %[^\n]",&reserva1.numero,&reserva1.cod,&reserva1.julianai
                    ,&reserva1.julianaf,&reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome)==8)
                {
                    if (num == reserva1.numero)
                    {
                        cont_res++;
                    }
                }

                if (cont_res == 1)
                {
                    FILE *temp1 = fopen("temp1.txt", "w");


                    while (fscanf(banco, "%d %9s %9s %f", &quarto1.numero, quarto1.tipo, quarto1.status, &quarto1.preco) == 4)
                    {
                        if (num == quarto1.numero)
                        {
                            strcpy(quarto1.status,"LIVRE");
                        }

                        fprintf(temp1, "%d %s %s %.2f\n", quarto1.numero,
                        quarto1.tipo, quarto1.status,
                        quarto1.preco);
                    }
                    fclose(banco);
                    fclose(temp1);
                    remove("banco.txt");
                    rename("temp1.txt", "banco.txt");
                }
                
                
                printf("\n--------------------------------\n");
                printf(" RESERVA EXCLUIDA COM SUCESSO !\n");
                printf("--------------------------------\n");

                fclose(dados);
                fclose(temp);
                remove("dados.txt");
                rename("temp.txt", "dados.txt");
            }
            else if (resp=='N'||resp=='n')
            {
                printf("\n----------------------\n");
                printf(" EXCLUSÃO CANCELADA !\n");
                printf("----------------------\n");
            }

        }
        

        else if (aux==0)
        {
            printf("\n-------------------------\n");
            printf(" RESERVA NÃO ENCONTRADA !\n");
            printf("-------------------------\n\n");
        }

        fclose(dados);
    }
    
    else{
        printf("\n------------------------------\n");
        printf(" NENHUMA RESERVA CADASTRADA !\n");
        printf("------------------------------\n\n");
    }
}

void consultar_pelo_cod(FILE *dados){
    dados=fopen("dados.txt","r");
    reserva reserva1;
    char datai[15];
    char dataf[15];
    int cod_temp;
    int aux=0;
    
    
    if (dados)
    {

        printf("INFORME O CODIGO DA RESERVA: ");
        scanf("%d",&cod_temp);

        printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║             NOME               ║ NÚMERO ║ CÓDIGO ║ DATA INICIAL ║ DATA FINAL ║   TOTAL   ║ PAGAMENTO ║     HORA     ║\n");
        printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        while (fscanf(dados,"%d %d %d %d %f %29s %s %[^\n]",&reserva1.numero,&reserva1.cod,&reserva1.julianai
            ,&reserva1.julianaf,&reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome)==8)
        {
            if (cod_temp == reserva1.cod)
            {
                juliana_gregoriana(reserva1.julianai,datai);
                juliana_gregoriana(reserva1.julianaf,dataf);

                printf("║ %-30s ║ %-6d ║ %-6d ║ %-12s ║ %-10s ║ %-9.2f ║ %-9s ║ %-12s ║\n"
                ,reserva1.nome, reserva1.numero, reserva1.cod
                ,datai, dataf, reserva1.total
                ,reserva1.status_pagamento, reserva1.hora_inicial);
                aux++;
            }
        }
        printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");

        if (aux==0)
        {
            printf("\n------------------------\n");
            printf(" RESERVA NAO ENCONTRADA\n");
            printf("------------------------\n\n");
        }
        
        fclose(dados);
    }

    else{
        printf("\n-----------------------\n");
        printf(" NENHUMA RESERVA FEITA\n");
        printf("-----------------------\n\n");
    }
    
}

void consultar_r_pelo_nome(FILE *dados){
    dados=fopen("dados.txt","r");
    reserva reserva1;
    char datai[15];
    char dataf[15];
    char nome[50];
    int aux=0;
    
    
    if (dados)
    {

        printf("INFORME O NOME DO CLIENTE QUE DESEJA BUSCAR: ");
        fflush(stdin);
        scanf("%49[^\n]",nome);

        for (int j = 0; nome[j]; j++)
        {
            nome[j] = toupper(nome[j]);
        }

        printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║             NOME               ║ NÚMERO ║ CÓDIGO ║ DATA INICIAL ║ DATA FINAL ║   TOTAL   ║ PAGAMENTO ║     HORA     ║\n");
        printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        while (fscanf(dados,"%d %d %d %d %f %29s %s %[^\n]",&reserva1.numero,&reserva1.cod,&reserva1.julianai
            ,&reserva1.julianaf,&reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome)==8)
        {
            if (strcmp(nome,reserva1.nome)==0)
            {
                juliana_gregoriana(reserva1.julianai,datai);
                juliana_gregoriana(reserva1.julianaf,dataf);

                printf("║ %-30s ║ %-6d ║ %-6d ║ %-12s ║ %-10s ║ %-9.2f ║ %-9s ║ %-12s ║\n"
                ,reserva1.nome, reserva1.numero, reserva1.cod
                ,datai, dataf, reserva1.total
                ,reserva1.status_pagamento, reserva1.hora_inicial);
                aux++;
            }
        }
        printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");

        if (aux==0)
        {
            printf("\n--------------------------\n");
            printf(" RESERVA NÃO ENCONTRADA !\n");
            printf("--------------------------\n\n");
        }
        
        fclose(dados);
    }

    else{
        printf("\n-------------------------\n");
        printf(" NENHUMA RESERVA FEITA !\n");
        printf("-------------------------\n\n");
    }
}

void realizar_pagamento(FILE *dados,FILE *banco,FILE *financeiro){
    reserva reserva1;
    quarto quarto1;
    int cod, found=0;
    char resposta;
    float total_temp=0;

    dados=fopen("dados.txt","r");
    //dados1=fopen("dados.txt","r");
    //banco=fopen("banco.txt","r");
    financeiro=fopen("pague.txt", "a");

    if (banco)
    {
        if (dados)
        {

            printf("INFORME O CODIGO DA RESERVA QUE DESEJA REALIZAR O PAGAMENTO: ");
            scanf("%d", &cod);

            rewind(dados);

            while (fscanf(dados,"%d %d %d %d %f %29s %s %[^\n]",&reserva1.numero,&reserva1.cod,&reserva1.julianai
                                ,&reserva1.julianaf,&reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome)==8)
            {
                if (cod == reserva1.cod)
                {
                    total_temp = reserva1.total;
                    found++;
                }

            }

            if (found == 1)
            {
                printf("\n-------------------------------\n");
                printf(" VALOR TOTAL A PAGAR R$ %.2f\n", total_temp);
                printf("---------------------------------\n");

                fflush(stdin);
                printf("DESEJA REALIZAR O PAGAMENTO? [S/N]: ");
                scanf(" %c", &resposta);

                if (resposta == 'S' || resposta == 's')
                {
                    FILE *temp=fopen("temp.txt", "a");
                    rewind(dados);
                    while (fscanf(dados,"%d %d %d %d %f %29s %s %[^\n]",&reserva1.numero,&reserva1.cod,&reserva1.julianai
                                ,&reserva1.julianaf,&reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome)==8)
                    {
                        if (cod == reserva1.cod)
                        {
                            strcpy(reserva1.status_pagamento, "PAGO");
                        }
                        fprintf(temp,"%d %d %d %d %.2f %s %s %s\n",reserva1.numero,reserva1.cod
                        ,reserva1.julianai,reserva1.julianaf,reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome);

                    }
                    
                    rewind(dados);
                    while (fscanf(dados,"%d %d %d %d %f %29s %s %[^\n]",&reserva1.numero,&reserva1.cod,&reserva1.julianai
                                ,&reserva1.julianaf,&reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome)==8)
                    {
                        if (cod == reserva1.cod)
                        {
                            printf("INSIRA A DATA ATUAL (DD/MM/AAAA): ");
                            scanf("%d/%d/%d", &reserva1.dia,&reserva1.mes,&reserva1.ano);
                            printf("\n");

                            reserva1.julianai=gregoriana_juliana(reserva1.dia,reserva1.mes,reserva1.ano);
                            obterHoraAtual(&reserva1.hora_inicial);
                            fprintf(financeiro, "%d %d %.2f %s\n", reserva1.cod, reserva1.julianai, reserva1.total, reserva1.hora_inicial);
                        }

                    }

                    fclose(dados);
                    fclose(temp);
                    fclose(financeiro);

                    // Remover o arquivo original
                    remove("dados.txt");
                    
                    // Renomear o arquivo temporÃ¡rio para o original
                    rename("temp.txt", "dados.txt");
                    
                    printf("--------------------------\n");
                    printf(" VALOR PAGO COM SUCESSO !\n");
                    printf("--------------------------\n\n");

                    //fclose(dados1);


                }

                else{
                    printf("-----------------------\n");
                    printf(" PAGAMENTO CANCELADO !\n");
                    printf("-----------------------\n\n");
                }

            }
            else if(found == 0)
            {
                printf("CODIGO NAO ENCONTRADO\n");
            }

        }
    }
    else
    {
        printf("\n--------------------------\n");
        printf(" NENHUM QUARTO CADASTRADO\n");
        printf("--------------------------\n\n");
    }
}

void fazer_check_in(FILE *dados,FILE *banco,FILE *financeiro){
    reserva reserva1;
    quarto quarto1;
    int num, cod, aux, found=0, found1=0, found2=0;
    char resposta;
    float total_temp;
    // pegar o numero do quarto | abrir o arquivo banco e comparar o número
    // pegar o codigo | abrir o arquivo dados e comparar o código
    // realizar pagamento | antes devo verificar se o pagamento foi feito anteriormente | abrir o arquivo financeiro

    banco=fopen("banco.txt","r");
    dados=fopen("dados.txt","r");
    financeiro=fopen("pague.txt","a");

    if (banco)
    {
        if (dados)
        {
            printf("INFORME O NÚMERO DO QUARTO QUE DESEJA REALIZAR CHECK-IN: ");
            scanf("%d",&num);
            printf("\n");

            while(1){
                rewind(banco);
                aux=0;
                while (fscanf(banco, "%d %9s %9s %f", &quarto1.numero, quarto1.tipo, quarto1.status, &quarto1.preco) == 4)
                {
                    if (num==quarto1.numero && strcmp(quarto1.status,"RESERVADO")==0)
                    {
                        aux++;
                        reserva1.numero=num;
                        
                    }

                    else if (num==quarto1.numero && strcmp(quarto1.status,"LIVRE")==0 || num==quarto1.numero && strcmp(quarto1.status,"OCUPADO")==0)
                    {
                        aux=2;
                    }
                    
                }
                if (aux==0)
                {
                    printf("QUARTO NAO ENCONTRADO\n");
                    printf("ESCOLHA UM DESSES:\n");
                    
                    printf("╔══════════════════════════════════════════════════╗\n");
                    printf("║ NÚMERO ║ TIPO         ║ STATUS       | PREÇO     ║\n");
                    printf("╠══════════════════════════════════════════════════╣\n");
                    rewind(banco);
                    
                    while (fscanf(banco, "%d %9s %9s %f", &quarto1.numero, quarto1.tipo, quarto1.status, &quarto1.preco) == 4)
                    {
                        
                        printf("║ %-6d ║ %-12s ║ %-12s ║ %-8.2f  ║\n", quarto1.numero, quarto1.tipo, quarto1.status, quarto1.preco);  
                        
                        
                    }
                    
                    printf("╚══════════════════════════════════════════════════╝\n\n");

                    scanf("%d",&num);


                }
                
                
                else if (aux==2)
                {
                    
                    printf("NÃO É POSSIVEL FAZER CHECK-IN, POIS O QUARTO JÁ ESTÁ OCUPADO OU AINDA NÃO POSSUI RESERVA !\n");
                    printf("ESCOLHA UM DESSES:\n");
                    
                    printf("╔══════════════════════════════════════════════════╗\n");
                    printf("║ NÚMERO ║ TIPO         ║ STATUS       | PREÇO     ║\n");
                    printf("╠══════════════════════════════════════════════════╣\n");
                    rewind(banco);
                    
                    while (fscanf(banco, "%d %9s %9s %f", &quarto1.numero, quarto1.tipo, quarto1.status, &quarto1.preco) == 4)
                    {
                        if (strcmp(quarto1.status,"RESERVADO")==0)
                        {
                           printf("║ %-6d ║ %-12s ║ %-12s ║ %-8.2f  ║\n", quarto1.numero, quarto1.tipo, quarto1.status, quarto1.preco);
                        }
                        
                    }
                    
                    printf("╚══════════════════════════════════════════════════╝\n\n");

                    scanf("%d",&num);


                    
                }
                

                else if(aux==1){
                    break;
                }
            }

            printf("INFORME O CÓDIGO DA RESERVA QUE DESEJA REALIZAR O PAGAMENTO: ");
            scanf("%d", &cod);

            rewind(dados);

            while (fscanf(dados,"%d %d %d %d %f %29s %s %[^\n]",&reserva1.numero,&reserva1.cod,&reserva1.julianai
                                ,&reserva1.julianaf,&reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome)==8)
            {
                if (cod == reserva1.cod)
                {
                    found++;
                }

            }

            if (found == 1)
            {

                rewind(dados);

                while (fscanf(dados,"%d %d %d %d %f %29s %s %[^\n]",&reserva1.numero,&reserva1.cod,&reserva1.julianai
                                    ,&reserva1.julianaf,&reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome)==8)
                {
                    if (cod == reserva1.cod && strcmp(reserva1.status_pagamento,"PENDENTE")==0)
                    {
                        total_temp = reserva1.total;
                        found1++;
                    }
                    

                }

                if (found1 == 1)
                {
                    printf("\n-------------------------------\n");
                    printf(" VALOR TOTAL A PAGAR R$ %.2f\n", total_temp);
                    printf("---------------------------------\n");

                    fflush(stdin);
                    printf("DESEJA REALIZAR O PAGAMENTO? [S/N]: ");
                    scanf(" %c", &resposta);

                    if (resposta == 'S' || resposta == 's')
                    {
                        FILE *temp=fopen("temp.txt", "a");
                        rewind(banco);
                        while (fscanf(banco, "%d %9s %9s %f", &quarto1.numero, quarto1.tipo, quarto1.status, &quarto1.preco) == 4)
                        {
                            if (num==quarto1.numero)
                            {
                                strcpy(quarto1.status, "OCUPADO");
                            }
                            fprintf(temp, "%d %s %s %.2f\n", quarto1.numero,
                            quarto1.tipo, quarto1.status,
                            quarto1.preco);
                        }

                        FILE *temp1=fopen("temp1.txt", "a");
                        rewind(dados);
                        while (fscanf(dados,"%d %d %d %d %f %29s %s %[^\n]",&reserva1.numero,&reserva1.cod,&reserva1.julianai
                                    ,&reserva1.julianaf,&reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome)==8)
                        {
                            if (cod == reserva1.cod)
                            {
                                strcpy(reserva1.status_pagamento, "PAGO");
                            }
                            fprintf(temp1,"%d %d %d %d %.2f %s %s %s\n",reserva1.numero,reserva1.cod
                            ,reserva1.julianai,reserva1.julianaf,reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome);

                        }
                        
                        rewind(dados);
                        while (fscanf(dados,"%d %d %d %d %f %29s %s %[^\n]",&reserva1.numero,&reserva1.cod,&reserva1.julianai
                                    ,&reserva1.julianaf,&reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome)==8)
                        {
                            if (cod == reserva1.cod)
                            {
                                printf("INSIRA A DATA ATUAL (DD/MM/AAAA): ");
                                scanf("%d/%d/%d", &reserva1.dia,&reserva1.mes,&reserva1.ano);
                                printf("\n");

                                reserva1.julianai=gregoriana_juliana(reserva1.dia,reserva1.mes,reserva1.ano);
                                obterHoraAtual(&reserva1.hora_inicial);
                                fprintf(financeiro, "%d %d %.2f %s\n", reserva1.cod, reserva1.julianai, reserva1.total, reserva1.hora_inicial);
                            }

                        }

                        fclose(banco);
                        fclose(dados);
                        fclose(temp);
                        fclose(temp1);
                        fclose(financeiro);

                        // Remover o arquivo original
                        remove("banco.txt");
                        remove("dados.txt");
                        
                        // Renomear o arquivo temporÃ¡rio para o original
                        rename("temp.txt", "banco.txt");
                        rename("temp1.txt", "dados.txt");
                        
                        printf("\n--------------------------\n");
                        printf(" VALOR PAGO COM SUCESSO !\n");
                        printf("--------------------------\n\n");
                    }
                    else{
                        printf("\n-----------------------\n");
                        printf(" CHECK-IN CANCELADO !\n");
                        printf("-----------------------\n\n");
                        
                    }
                }

                else if (found1 == 0)
                {
                    while (fscanf(dados,"%d %d %d %d %f %29s %s %[^\n]",&reserva1.numero,&reserva1.cod,&reserva1.julianai
                                    ,&reserva1.julianaf,&reserva1.total,reserva1.status_pagamento,reserva1.hora_inicial,reserva1.nome)==8)
                    {
                        if (cod == reserva1.cod && strcmp(reserva1.status_pagamento,"PAGO")==0)
                        {
                            found2++;
                        }

                    }

                    printf("\n-------------------------------\n");
                    printf(" VALOR TOTAL JA PAGO\n");
                    printf("---------------------------------\n");

                    fflush(stdin);
                    printf("DESEJA REALIZAR O CHECK-IN? [S/N]: ");
                    scanf(" %c", &resposta);

                    if (resposta == 'S' || resposta == 's')
                    {
                        FILE *temp=fopen("temp.txt", "a");
                        rewind(banco);
                        while (fscanf(banco, "%d %9s %9s %f", &quarto1.numero, quarto1.tipo, quarto1.status, &quarto1.preco) == 4)
                        {
                            if (num==quarto1.numero)
                            {
                                strcpy(quarto1.status, "OCUPADO");
                            }
                            fprintf(temp, "%d %s %s %.2f\n", quarto1.numero,
                            quarto1.tipo, quarto1.status,
                            quarto1.preco);
                        }
                        

                        fclose(banco);
                        fclose(dados);
                        fclose(temp);
                        fclose(financeiro);

                        // Remover o arquivo original
                        remove("banco.txt");
                        
                        // Renomear o arquivo temporÃ¡rio para o original
                        rename("temp.txt", "banco.txt");
                        
                        printf("\n-----------------------\n");
                        printf(" CHECK-IN CONCLUIDO !\n");
                        printf("-----------------------\n\n");
                    }
                    else{
                        printf("\n-----------------------\n");
                        printf(" CHECK-IN CANCELADO !\n");
                        printf("-----------------------\n\n");
                        
                    }

                }
                
            }
            else if(found == 0)
            {
                printf("CÓDIGO NÃO ENCONTRADO\n");
                
            }

            fclose(banco);
            fclose(dados);
            fclose(financeiro);
        }
        else
        {
            printf("---------------------------------\n");
            printf(" NENHUM RESERVA REALIZADA!\n");
            printf("---------------------------------\n\n");

        }
    }
    else
    {
        printf("\n----------------------------\n");
        printf(" NENHUM QUARTO CADASTRADO !\n");
        printf("----------------------------\n\n");
    }

}

void valores_recebidos(FILE *financeiro){
    reserva reserva1;
    int dataInicial=0, dataFinal=0;
    float total_recebidos=0;

    financeiro=fopen("pague.txt","r");

    int datavalida=0;

    do
    {
        
        printf("INSIRA A DATA DE INICIO (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &reserva1.dia,&reserva1.mes,&reserva1.ano);
        printf("\n");

        dataInicial=gregoriana_juliana(reserva1.dia,reserva1.mes,reserva1.ano);

        printf("INSIRA A DATA DE FIM (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &reserva1.dia,&reserva1.mes,&reserva1.ano);
        printf("\n");

        dataFinal=gregoriana_juliana(reserva1.dia,reserva1.mes,reserva1.ano);

        if (dataInicial <= dataFinal)
        {
            datavalida = 1;
        }
        
        else{
            printf("\n--------------------------------\n");
            printf(" DATA INVÁLIDA! DIGITE DE NOVO.\n");
            printf("--------------------------------\n\n");
        }
        
    } while (!datavalida);

    if (financeiro)
    {
        while (fscanf(financeiro, "%d %d %f %s", &reserva1.cod, &reserva1.julianai, &reserva1.total, reserva1.hora_inicial) == 4)
        {
            if (reserva1.julianai >= dataInicial && reserva1.julianai <= dataFinal)
            {
                total_recebidos += reserva1.total;
            }
        }

        printf("\n-----------------------------------------\n");
        printf(" TOTAL RECEBIDO: %.2f\n", total_recebidos);
        printf("------------------------------------------\n\n");

        fclose(financeiro);
    }
    else
    {
        printf("\n--------------------------------------------\n");
        printf(" NENHUM PAGAMENTO REALIZADO ATE O MOMENTO !\n");
        printf("--------------------------------------------\n\n");
    }

}

int main()
{
    int op, op2, op3, op4, op5, op6, op7, op8, op10, quantidade_de_quartos = 0;
    int quantidade_de_clientes = 0;

    FILE *banco;

    FILE *banco1;

    FILE *pessoas;

    FILE *pessoas1;

    FILE *dados;

    FILE *dados1; 

    FILE *financeiro;

    do
    {
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            break;

        case 1:
            do
            {
                menu_funcionario();
                scanf("%d", &op2);
                switch (op2)
                {
                case 0:
                    break;

                case 1:
                    definir_quantidade_de_quartos(&quantidade_de_quartos);
                    break;

                case 2:
                    cadastrar_quarto(&quantidade_de_quartos,banco,banco1);
                    break;

                case 3:
                    do
                    {
                        consultar_quarto();
                        scanf("%d", &op5);
                        switch (op5)
                        {
                        case 0:
                            break;

                        case 1:
                            buscar_todos(banco);
                            break;
                        case 2:
                            buscar_por_numero(banco);
                            break;

                        case 3:
                            buscar_pelo_tipo(banco);
                            break;

                        case 4:
                            buscar_pelo_status(banco);
                            break;

                        default:
                            printf("\n------------------\n");
                            printf(" OPÇÃO INVÁLIDA !\n");
                            printf("------------------\n\n");
                            break;
                        }

                    } while (op5!=0);
                    break;

                case 4:
                    do
                    {
                        menu_editar_quarto();
                        scanf("%d", &op6);
                        switch (op6)
                        {
                        case 0:
                            break;

                        case 1:
                            editar_tipo_quarto(banco);
                            break;

                        case 2:
                           editar_preco_quarto(banco);
                        
                        default:
                            break;
                        }

                    } while (op6 != 0);
                    break;

                case 5:
                    Remover_quarto(banco);
                    break;



                default:
                    printf("\n------------------\n");
                    printf(" OPÇÃO INVÁLIDA !\n");
                    printf("------------------\n\n");
                    break;
                }
            } while (op2 != 0);
            break;

        case 2:
            do
            {
                menu_cliente();
                scanf("%d", &op3);
                switch (op3)
                {
                case 0:
                    break;

                case 1:
                    definir_quantidade_de_clientes(&quantidade_de_clientes);
                    break;
                
                case 2:
                    cadastrar_cliente(&quantidade_de_clientes, pessoas, pessoas1);
                    break;

                case 3:
                    do{

                        consultar_cliente();
                        scanf("%d", &op7);
                        switch (op7)
                        {
                        case 0:
                            break;
                        
                        case 1:
                            listar_todos_clientes(pessoas);
                            break;

                        case 2:
                            buscar_cliente_pelo_nome(pessoas);
                            break;

                        case 3:
                            buscar_cliente_pelo_cpf(pessoas);
                            break;

                        case 4:
                            buscar_cliente_pelo_email(pessoas);
                            break;

                        case 5:
                            buscar_cliente_pelo_endereco(pessoas);
                            break;

                        case 6:
                            buscar_cliente_pelo_telefone(pessoas);
                            break;
                        

                        default:
                            break;
                        }
                    }while (op7 != 0);
                    break;
                
                case 4:
                    do
                    {
                        menu_editar_cliente();
                        scanf("%d", &op8);
                        switch (op8)
                        {
                        case 0:
                            break;

                        case 1:
                            editar_tudo_cliente(pessoas);
                            break;

                        case 2:
                            editar_nome_cliente(pessoas);
                            break;

                        case 3:
                            editar_cpf_cliente(pessoas);
                            break;

                        case 4:
                            editar_rg_cliente(pessoas);
                            break;

                        case 5:
                            editar_telefone_cliente(pessoas);
                            break;

                        case 6:
                            editar_endereco_cliente(pessoas);
                            break;

                        case 7:
                            editar_email_cliente(pessoas);
                            break;
                        
                        default:
                            printf("\n------------------\n");
                            printf(" OPÇÃO INVÁLIDA !\n");
                            printf("------------------\n\n");
                            break;
                        }
                    } while (op8 != 0);
                    break;
                
                case 5:
                    Remover_cliente(pessoas);
                    break;


                default:
                    printf("\n------------------\n");
                    printf(" OPÇÃO INVÁLIDA !\n");
                    printf("------------------\n\n");
                    break;
                }
            } while (op3 != 0);
            break;

        case 3:
            do
            {
                menu_financeiro();
                scanf("%d", &op4);
                switch (op4)
                {
                case 0:
                    break;

                case 1:
                    realizar_rezerva(dados,banco,dados1,pessoas);
                    break;

                case 2:
                    consultar_reservas();
                    scanf("%d",&op10);
                    switch (op10)
                    {
                    case 0:
                        break;
                    
                    case 1:
                        consultar_pelo_cod(dados);
                        break;
                    
                    case 2:
                        consultar_r_pelo_nome(dados);
                        break;

                    default:
                        printf("\n------------------\n");
                        printf(" OPÇÃO INVÁLIDA !\n");
                        printf("------------------\n\n");
                        break;
                    }
                    break;

                case 3:
                    exclui_reserva(dados,banco);
                    break;

                case 4:
                    fazer_check_in(dados,banco,financeiro);
                    break;

                case 5:
                    realizar_pagamento(dados,banco,financeiro);
                    break;
                case 6:
                    valores_recebidos(financeiro);
                    break;
                default:
                    printf("\n------------------\n");
                    printf(" OPÇÃO INVÁLIDA !\n");
                    printf("------------------\n\n");
                    break;
                }
            } while (op4 != 0);
            break;

        default:
            printf("\n------------------\n");
            printf(" OPÇÃO INVÁLIDA !\n");
            printf("------------------\n\n");
            break;
        }
    } while (op != 0);
    
    return 0;
}