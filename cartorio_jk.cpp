#include <stdio.h> //biblioteca de comunica��o do usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> // biblioteca respons�vel por cuidar das string

    int registro()//fun��o respons�vel por cadastrar os usu�rios no sistema
{
         //in�cio cria��o de vari�veis/string
	     char arquivo[40]; //criamos as vari�veis
		 char cpf[40];//o nome do do arquivo vai ser o cpf,pq � unico
		 char nome[40];
         char sobrenome[40];
	 	 char cargo[40];
		 //final da cria��o de vari�veis/string
		
	 	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
		 scanf("%s", cpf); // %s para strings
		
		 strcpy(arquivo, cpf);// respons�vel por copiar os valores das string
		
		 FILE *file; // cria o arquivo
		 file = fopen(arquivo,"w"); // cria o arquivo
		 fprintf(file,cpf);//salvo o valor da vari�vel
	  	fclose(file); //fecha o arquivo
		
		 file = fopen(arquivo, "a"); //a pq queremos apenas atualizar
		 fprintf(file,","); // para criarmos a virgula
		 fclose(file);		
		
		 printf("Digite o nome a ser cadastrado: ");
		 scanf("%s", nome);
		
		 file = fopen(arquivo, "a");
		 fprintf(file,nome);
		 fclose(file); 
		
		 file = fopen(arquivo, "a");
		 fprintf(file,",");
		 fclose(file);
		
		 printf("Digite o sobrenome a ser cadastrado: ");
		 scanf("%s",sobrenome);
		
		 file = fopen(arquivo, "a");
		 fprintf(file,sobrenome);
		 fclose(file);
		
		 file = fopen(arquivo,"a");
		 fprintf(file,",");
		 fclose(file);
		
		 printf("Digite o cargo a ser cadastrado:");
	 	scanf("%s", cargo);
		
	 	file = fopen(arquivo, "a");
	 	fprintf(file,cargo);
		 fclose(file);
		
	 	system("pause");	
			
}

     int consulta()
{

         setlocale(LC_ALL, "Portuguese"); // Definindo de novo, pois � outra fun��o
       
	     char cpf[40];// a onde vamos armazenar a resposta do usu�rio
	     char conteudo[200];// a onde vamos armazenar o conte�do que est� dentro do arquivo 
	   
	     printf("Digite o CPF a ser consultado: ");
	     scanf("%s", cpf);
	   
	     FILE *file;
	     file = fopen(cpf,"r");//abre o arquivo e ler tudo que estiver dentro do cpf
   
	     if(file == NULL)// Para caso o cpf que o usu�rio colocar n�o existir
	       {
	     	printf("N�o foi poss�vel abrir arquivo, n�o localizado! \n");
	       }	
	   
	     while(fgets(conteudo,200,file) != NULL)// ele vai rodar 200 vezes no arquivo at� trazer todas as informa��es
	        {
	      	printf("\nEssas s�o as informa��es do usu�rio: ");
	     	printf("%s", conteudo);
	   	    printf("\n\n");
	        }
	      system("pause");
	
	   
	   
}

    int deletar()
{
		
	 	char cpf[40];
		
	 	printf("Digite o CPF do usu�rio a ser deletado:");
	 	scanf("%s",cpf);
	 	
	  	remove(cpf);
		
	 	FILE *file;
	 	file= fopen(cpf,"r");
		
	    	if(file == NULL)
	    	{
	     	 printf("O usu�rio n�o se encontra no sistema!.\n");
		     system("pause");
		    }
		
 
}

int main()
{
	
     int opcao=0; //Definindo as vari�veis
     int laco=1;
     char senhadigitada[]="a";
     int comparacao;
     
	 printf("### Cart�rio da EBAC ###\n\n");
     printf("Login de adminstrador!\n\nDigite a sua senha: ");
     scanf("%s",senhadigitada);
 
     comparacao =strcmp(senhadigitada, "adimin");
     
     if(comparacao == 0)
       {

         system ("cls");
         
         for(laco=1;laco=1;)
         {
	
         system("cls");
	
         setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem

         printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
         printf("Escolha a op��o desejada do menu:\n\n");
         printf("\t1 - Registrar Nomes\n");
         printf("\t2 - Consultar Nomes\n");
         printf("\t3 - Deletar Nomes\n\n");
         printf("\t4 - Sair do Sistema\n\n");
         printf("\tOp��o:"); //Fim do menu

         scanf("%d",&opcao); //Armazenando as escolhas do usu�rio

         system("cls");//Para deixar mais limpo, apaga o que estava escrito anteriormente

       
	     switch(opcao)
	       {
	     	 case 1: //In�cio da sele��o
             registro();
	         break;
		   
	         case 2:
	  	     consulta();
   	         break;
		   	
	     	 case 3:
			 deletar();
	         break;
	    
	          case 4:
	      	printf("Obrigado por utilizar o sistema!\n");
	       	return 0;
		  	break;
	    
	         default: 
	         printf("Essa op��o n�o est� dispon�vel!\n");
	         system("pause");
	         break; //Fim da sele��o
	    
		   	
	   }


    }

       }
      
	  else
	    printf("Senha incorreta!");
       
}





