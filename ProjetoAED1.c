//Projeto desenvolvido por Lerry Henique e Nicolas Martins
//controle de estoque e registro de doadores e receptores de sangue para um hemocentro


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
{
    char nome[20];
    char sexo;
    int idade;
    float peso;
    char tipoS[4];
    int bolsas;
} doador;
typedef struct
{
    char nome[20];
    char sexo;
    int idade;
    float peso;
    char tipoS[4];
    int bolsas;
} receptor;

main()
{
    float idadem=0,pesom=0;
    int i,n,contador1=4,ndoadores,nreceptores,qbolsas,status,contador2=4,contador;
    int ap=0,an=0,bp=0,bn=0,abp=0,abn=0,op=0,on=0,bt=0,br=0;

    doador doador[20]= {"jose",'m',30,65.2,"ab-",1, //0=contador1
                        "ana",'f',40,61.8,"a+",2,
                        "joaquim",'m',70,93.9,"o-",2,
                        "zelia",'f',30,66.5,"a-",1
                       };

    receptor receptor[20]= {"beatriz",'f',20,52.4,"b+",2, //1=contador2
                            "maria",'f',18,50,"o+",1,
                            "luiza",'f',20,76.1,"ab+",1,
                            "paulo",'m',50,80,"b-",1
                           };

    contador= contador1 + contador2;
    printf("\n------------///////// Registro de hemocentro \\\\\\\\\\\\\\\\\\\------------\n\n");
    while(n!=4)
    {
        printf("------------------------------------------------------------------\n");
        printf("Digite uma opcao\n");
        printf("Opcao 1 registrar doador/receptor\n");
        printf("Opcao 2 mostar registros\n");
        printf("Opcao 3 mostrar relatorios finais\n");
        printf("Opcao 4 sair do programa \n");
        printf("------------------------------------------------------------------\n");
        scanf("%d",&n);
        system("cls");
        switch(n)
        {
        case 1://registrar doador/receptor


            printf("\nDigite 0 para doar sangue, Digite 1 para receber: ");
            scanf("%d",&status);
            if(status==0)
            {
                fflush(stdin);

                printf("\nDigite seu nome: ");
                scanf(doador[contador1].nome);


                fflush(stdin);
                printf("\nDigite seu sexo usando M para masculino e F para feminino: ");
                scanf("%c",&doador[contador1].sexo);


                printf("\nDigite sua idade: ");
                scanf("%d",&doador[contador1].idade);

                printf("\nDigite seu peso em kgs: ");
                scanf("%f",&doador[contador1].peso);
                fflush(stdin);
                printf("\nDigite seu tipo sanguineo incluindo seu RH: ");
                scanf(doador[contador1].tipoS);

                printf("\nQuantas bolsas voce deseja doar: ");
                scanf("%d",&doador[contador1].bolsas);
                contador1++;
            }
            if(status==1)
            {
                fflush(stdin);
                printf("\nDigite seu nome: ");
                scanf(receptor[contador2].nome);


                fflush(stdin);
                printf("\nDigite seu sexo usando M para masculino e F para feminino: ");
                scanf("%c",&receptor[contador2].sexo);


                printf("\nDigite sua idade: ");
                scanf("%d",&receptor[contador2].idade);

                printf("\nDigite seu peso em kgs: ");
                scanf("%f",&receptor[contador2].peso);
                fflush(stdin);
                printf("\nDigite seu tipo sanguineo incluindo seu RH: ");
                scanf(receptor[contador2].tipoS);

                printf("\nQuantas bolsas voce deseja receber: ");
                scanf("%d",&receptor[contador2].bolsas);

                contador2++;
            }


            break;
        case 2://registros

            printf("Gerando Registros...\n");
            printf("Doadores: \n");
            printf("| Id |   Nome   | Sexo | Idade |  Peso  | Tipo Sanguineo | Quant.Bolsas |\n");
            for (i=0; i < contador1; i++)
            {
                printf(" %2d %9s %7c  %5d   %7.2f    %7s %15d \n",
                       i,doador[i].nome,doador[i].sexo,doador[i].idade, doador[i].peso,doador[i].tipoS,doador[i].bolsas);
            }
            printf("Receptores: \n");
            printf("| Id |   Nome   | Sexo | Idade |  Peso  | TipoSanguineo | Quant.Bolsas |\n");
            for (i=0; i < contador2; i++)
            {
                printf(" %2d %9s %7c  %5d   %7.2f    %7s %15d \n",
                       i,receptor[i].nome,receptor[i].sexo,receptor[i].idade, receptor[i].peso,receptor[i].tipoS,receptor[i].bolsas);
            }
            break;
        case 3://relatorios
            for (i=0; i < contador1; i++)
            {
                if(strcmpi(doador[i].tipoS, "a+")==0)ap++;
                if(strcmpi(doador[i].tipoS, "a-")==0)an++;
                if(strcmpi(doador[i].tipoS, "b+")==0)bp++;
                if(strcmpi(doador[i].tipoS, "b-")==0)bn++;
                if(strcmpi(doador[i].tipoS, "ab+")==0)abp++;
                if(strcmpi(doador[i].tipoS, "ab-")==0)abn++;
                if(strcmpi(doador[i].tipoS, "o+")==0)op++;
                if(strcmpi(doador[i].tipoS, "o-")==0)on++;
                bt+=doador[i].bolsas;
                //qbolsas += re
            }

            if(contador1 > contador2)
            {


                for (i=0; i < contador1; i++)
                {
                    idadem = idadem+doador[i].idade;
                    pesom = pesom+doador[i].peso;
                    pesom= pesom+receptor[i].peso;
                    idadem= idadem+receptor[i].idade;

                }

            }
            else
            {
                for (i=0; i < contador2; i++)
                {
                    idadem = idadem+doador[i].idade;
                    pesom = pesom+doador[i].peso;
                    pesom= pesom+receptor[i].peso;
                    idadem= idadem+receptor[i].idade;
                }
            }

            for (i=0; i < contador2; i++)
            {
                br+=receptor[i].bolsas;
            }
            idadem = idadem/(float)contador;
            pesom = pesom/(float)contador;

            printf("Mostrando relatorio de dados\n\n");
            printf("O peso medio de todas as pessoas registradas e %5.2f\n",pesom);
            printf("A idade media de todas as pessoas registradas e %5.2f\n",idadem);
            printf("Tipos sanguineos doados: \n");
            printf("A+:%d\nA-:%d\nB+:%d\nB-:%d\nAB+:%d\nAB-:%d\nO+:%d\nO-:%d\n",ap,an,bp,bn,abp,abn,op,on);
            printf("Quantidade total de bolsas doadas %d\n",bt);
            printf("Quantdade de bolsas disponiveis %d\n",bt-br);
            break;
        case 4://sair
            exit(0);
            break;
        default:
            printf("Opcao nao encontrada\n");
        }
    }
}


