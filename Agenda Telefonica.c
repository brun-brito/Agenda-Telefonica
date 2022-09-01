#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

struct endereco
{
    char rua [20];
    char bairro [20];
    char cidade [20];
    char uf [5];
    char pais [15];
    char complemento [20];
    int numero, cep;
};

struct telefone
{
    int ddd, numero;
};

struct aniversario
{
    int dia, mes, ano;
};

struct agenda
{
    char nome [30];
    char email [25];
    struct endereco end; 
    struct telefone tel;
    struct aniversario aniv;
    char obs [100];
}; typedef struct agenda Agenda;


int main (){  
    Agenda vet[100]; //capacidade de 100 cadastros
    int op, dia, mes, i = 0, a, b = 0, laco = 0;
    char name[20];
    char excluir[20];

    do{
        system("CLS || clear");
        
        do{

            printf("\n--- OPCOES DE CADASTRO ---\n");
            printf("1. Buscar pelo primeiro nome\n");       //se tiver mais de uma com o mesmo nome imprime todas
            printf("2. Buscar por mes os aniversariantes\n");   //ex: buscar todos os aniversariantes de setembro (imprime os dados de todos)
            printf("3. Buscar por dia e mes os aniversariantes\n");
            printf("4. Cadastrar novo contato\n");
            printf("5. Excluir contato\n");
            printf("6. Mostrar contatos da agenda\n");      //duas opcoes de impressao
            printf("7. Fechar menu\n");
            printf("\nEscolha uma opcao acima: ");
            scanf("%d", &op);
            if((op < 1) || (op > 7))
                printf("Opcao invalida. Escolha um numero entre 1 e 7.\n");
            fflush(stdin);
        } while((op < 1) || (op > 7));

        switch (op)
        {
        case 1:
            if(i == 0)
                printf("\nAgenda vazia! Pressione qualquer tecla para voltar ao menu.\n");
            else{
                a = 0;
                printf("De quem voce gostaria de ver os dados? ");
                gets(name);        //guarda o nome digitado na variavel 'name'
                for(laco = 0; laco < i; laco++){
                    if(strcmp(name, vet[laco].nome) == 0){     //compara se a string de entrada eh igual a algum nome da agenda
                        a = 1;
                        printf("\nNOME: %s\n", vet[laco].nome);
                        printf("E-MAIL: %s\n", vet[laco].email);
                        printf("RUA: %s\n", vet[laco].end.rua);
                        printf("NRO: %d\n", vet[laco].end.numero);
                        printf("COMPLEMENTO: %s\n", vet[laco].end.complemento);
                        printf("BAIRRO: %s\n", vet[laco].end.bairro);
                        printf("CIDADE: %s\n", vet[laco].end.cidade);
                        printf("ESTADO: %s\n", vet[laco].end.uf);
                        printf("CEP: %d\n", vet[laco].end.cep);
                        printf("PAIS: %s\n", vet[laco].end.pais);
                        printf("TEL: (%d) %d\n", vet[laco].tel.ddd,vet[laco].tel.numero);
                        printf("ANIVERSARIO: %d/%d/%d\n", vet[laco].aniv.dia, vet[laco].aniv.mes, vet[laco].aniv.ano);
                        printf("OBS: %s\n", vet[laco].obs);
                        printf("\nDados impressos com sucesso. Pressione qualquer tecla para voltar ao menu.\n");
                    }
                }
                if (a != 1) //a variavel 'a' guarda 1 se a string digitada for igual a algum contato salvo
                    printf("\nNome nao encontrado. Aperte 1 e tente outro nome.\n");
            }
            getch();
            break;
        
        case 2:
            if(i == 0)
                printf("\nAgenda vazia! Pressione qualquer tecla para voltar ao menu.\n");
            else{
                a = 0;
                printf("Digite o mes para ver os aniversariantes (numeral): ");
                scanf("%d", &mes);
                if(mes < 1 || mes > 12)
                    printf("\nMes invalido. Aperte 2 e tente outro mes.\n");
                for(laco = 0; laco < i; laco++){
                    if(mes == vet[laco].aniv.mes){     //compara se a string de entrada eh igual a algum nome da agenda
                        a = 1; 
                        printf("\nNOME: %s\n", vet[laco].nome);
                        printf("E-MAIL: %s\n", vet[laco].email);
                        printf("RUA: %s\n", vet[laco].end.rua);
                        printf("NRO: %d\n", vet[laco].end.numero);
                        printf("COMPLEMENTO: %s\n", vet[laco].end.complemento);
                        printf("BAIRRO: %s\n", vet[laco].end.bairro);
                        printf("CIDADE: %s\n", vet[laco].end.cidade);
                        printf("ESTADO: %s\n", vet[laco].end.uf);
                        printf("CEP: %d\n", vet[laco].end.cep);
                        printf("PAIS: %s\n", vet[laco].end.pais);
                        printf("TEL: (%d) %d\n", vet[laco].tel.ddd,vet[laco].tel.numero);
                        printf("ANIVERSARIO: %d/%d/%d\n", vet[laco].aniv.dia, vet[laco].aniv.mes, vet[laco].aniv.ano);
                        printf("OBS: %s\n", vet[laco].obs);
                        printf("\nDados impressos com sucesso. Pressione qualquer tecla para voltar ao menu.\n");
                    }
                }
                if (a != 1) //a variavel 'a' guarda 1 se o mes digitado for igual ao de algum contato salvo
                    printf("Nenhum aniversariante nesse mes. Aperte 2 e tente outro mes.\n");
            }    
            getch();
            break;
        
        case 3:
            if(i == 0)
                printf("\nAgenda vazia! Pressione qualquer tecla para voltar ao menu.\n");
            else{
                a = 0;
                printf("Digite o dia e o mes para ver os aniversariantes (DD MM): ");
                scanf("%d %d", &dia, &mes);
                if(dia < 1 || dia > 31)
                    printf("\nDia invalido. Aperte 3 e escreva um dia de 1 a 31: ");
                else if(mes < 1 || mes > 12)
                    printf("\nMes invalido. Aperte 3 e escreva um mes de 1 a 12.\n");
                for(laco = 0; laco < i; laco++){
                    if(dia == vet[laco].aniv.dia && mes == vet[laco].aniv.mes){     //compara se a string de entrada eh igual a algum nome da agenda
                        a = 1; 
                        printf("\nNOME: %s\n", vet[laco].nome);
                        printf("E-MAIL: %s\n", vet[laco].email);
                        printf("RUA: %s\n", vet[laco].end.rua);
                        printf("NRO: %d\n", vet[laco].end.numero);
                        printf("COMPLEMENTO: %s\n", vet[laco].end.complemento);
                        printf("BAIRRO: %s\n", vet[laco].end.bairro);
                        printf("CIDADE: %s\n", vet[laco].end.cidade);
                        printf("ESTADO: %s\n", vet[laco].end.uf);
                        printf("CEP: %d\n", vet[laco].end.cep);
                        printf("PAIS: %s\n", vet[laco].end.pais);
                        printf("TEL: (%d) %d\n", vet[laco].tel.ddd,vet[laco].tel.numero);
                        printf("ANIVERSARIO: %d/%d/%d\n", vet[laco].aniv.dia, vet[laco].aniv.mes, vet[laco].aniv.ano);
                        printf("OBS: %s\n", vet[laco].obs);
                        printf("\nDados impressos com sucesso. Pressione qualquer tecla para voltar ao menu.\n");
                    }
                }
                if (a != 1) //a variavel 'a' guarda 1 se o mes digitado for igual ao de algum contato salvo
                    printf("Nenhum aniversariante nessa data. Aperte 3 e tente outra data.\n");
            }
            getch();
            break;
       
        case 4:
            if(i >= 100)
                printf("\nAgenda lotada!! Pressione qualquer tecla para voltar ao menu.\n");
            else{      
                printf("\nCADASTRAR CONTATO:\n");      
                printf("\nNome: ");
                gets(vet[i].nome);
                printf("E-mail: ");
                gets(vet[i].email);
                printf("Endereco (Rua): ");
                gets(vet[i].end.rua);
                printf("Endereco (numero): ");
                scanf("%d", &vet[i].end.numero);
                fflush(stdin);
                printf("Endereco (complemento): ");
                gets(vet[i].end.complemento);        //20 caracteres pra escrever por ex: apto 401
                printf("Endereco (Bairro): ");
                gets(vet[i].end.bairro);
                printf("Endereco (Cidade): ");
                gets(vet[i].end.cidade);
                printf("Endereco (UF): ");
                scanf("%s", vet[i].end.uf);
                printf("Endereco (CEP): ");
                scanf("%d", &vet[i].end.cep);
                fflush(stdin);
                printf("Endereco (Pais): ");
                gets(vet[i].end.pais);
                printf("Telefone (somente DDD): ");
                scanf("%d", &vet[i].tel.ddd);
                printf("Telefone (somente numero): ");
                scanf("%d", &vet[i].tel.numero);
                printf("Dia do aniversario: ");
                scanf("%d", &vet[i].aniv.dia);
                if(vet[i].aniv.dia < 1 || vet[i].aniv.dia > 31){
                    printf("Dia invalido. Escreva uma data de 1 a 31: ");
                    scanf("%d", &vet[i].aniv.dia);            
                }
                printf("Mes do aniversario (numeral): ");
                scanf("%d", &vet[i].aniv.mes);
                if(vet[i].aniv.mes < 1 || vet[i].aniv.mes > 12){
                    printf("Mes invalido. Escreva uma data de 1 a 12: ");
                    scanf("%d", &vet[i].aniv.mes);            
                }
                printf("Ano do aniversario: ");
                scanf("%d", &vet[i].aniv.ano);
                fflush(stdin);
                printf("Observacoes: ");
                gets(vet[i].obs);
                printf("\n%s inserido com sucesso. Pressione qualquer tecla para voltar ao menu.\n", vet[i].nome);

                if(i < 100)
                    i++;
                else
                    printf("\nAgenda lotada!! Pressione qualquer tecla para voltar ao menu.\n");
                fflush(stdin);
            }
            getch();
            break;
        
        case 5:
            if(i == 0)
                printf("\nAgenda vazia! Pressione qualquer tecla para voltar ao menu.\n");
            else{
                a = 0;
                printf("Digite o nome do contato que deseja excluir: ");
                gets(excluir);
                for(laco = 0; laco < i; laco++){
                    if(strcmp(excluir, vet[laco].nome) == 0){     //compara se a string de entrada eh igual a algum nome da agenda
                        a = 1;
                        printf("\nNOME: %s\n", vet[laco].nome);
                        printf("E-MAIL: %s\n", vet[laco].email);
                        printf("TEL: (%d) %d\n", vet[laco].tel.ddd,vet[laco].tel.numero);
                        printf("\nDeseja EXCLUIR esse contato? SIM(1)/NAO(2): ");
                        scanf("%d",&b);
                        if (b == 1){
                            strcpy(vet[laco].nome, vet[laco+1].nome);
                            strcpy(vet[laco].email, vet[laco+1].email);
                            strcpy(vet[laco].end.rua, vet[laco+1].end.rua);
                            vet[laco].end.numero = vet[laco+1].end.numero;
                            strcpy(vet[laco].end.complemento, vet[laco+1].end.complemento);
                            strcpy(vet[laco].end.bairro, vet[laco+1].end.bairro);
                            strcpy(vet[laco].end.cidade, vet[laco+1].end.cidade);
                            strcpy(vet[laco].end.uf, vet[laco+1].end.uf);
                            vet[laco].end.cep = vet[laco+1].end.cep;
                            strcpy(vet[laco].end.pais, vet[laco+1].end.pais);
                            vet[laco].tel.ddd = vet[laco+1].tel.ddd;
                            vet[laco].tel.numero = vet[laco+1].tel.numero;
                            vet[laco].aniv.dia = vet[laco+1].aniv.dia;
                            vet[laco].aniv.mes = vet[laco+1].aniv.mes;
                            vet[laco].aniv.ano = vet[laco+1].aniv.ano;
                            strcpy(vet[laco].obs, vet[laco+1].obs);
                            i--;
                            printf("'%s' apagado com sucesso. Pressione qualquer tecla para voltar ao menu.\n", excluir);
                        }

                        else if(b == 2){
                            printf("\nOk, nenhum contato excluido. Pressione qualquer tecla para voltar ao menu.\n");                        
                            continue;
                        }                        
                        else{
                            printf("\nOPCAO INVALIDA! Escolha somente SIM(1) ou NAO(2): ");
                            scanf("%d",&b);
                        }
                    }
                    else
                        printf("\nNome nao encontrado. Aperte 5 e tente outro nome.\n");

                }
            }    
            getch();
            break;
        
        case 6:
            if(i == 0)
                printf("\nAgenda vazia! Pressione qualquer tecla para voltar ao menu.\n");
            else{
                for(laco = 0; laco < i; laco++){
                    printf("\n-- CONTATO %d --\n", laco);
                    printf("\nNOME: %s\n", vet[laco].nome);
                    printf("E-MAIL: %s\n", vet[laco].email);
                    printf("RUA: %s\n", vet[laco].end.rua);
                    printf("NRO: %d\n", vet[laco].end.numero);
                    printf("COMPLEMENTO: %s\n", vet[laco].end.complemento);
                    printf("BAIRRO: %s\n", vet[laco].end.bairro);
                    printf("CIDADE: %s\n", vet[laco].end.cidade);
                    printf("ESTADO: %s\n", vet[laco].end.uf);
                    printf("CEP: %d\n", vet[laco].end.cep);
                    printf("PAIS: %s\n", vet[laco].end.pais);
                    printf("TEL: (%d) %d\n", vet[laco].tel.ddd,vet[laco].tel.numero);
                    printf("ANIVERSARIO: %d/%d/%d\n", vet[laco].aniv.dia, vet[laco].aniv.mes, vet[laco].aniv.ano);
                    printf("OBS: %s\n", vet[laco].obs);
                }
                printf("\nAgenda impressa com sucesso. Pressione qualquer tecla para voltar ao menu.\n");
            }
            getch();
            break;
        
        default:
            printf("Menu encerrado.\n");
            break;
        }

    } while(op != 7);


return 0;      
}