#include <stdio.h> //biblioteca de comunicação do usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> // biblioteca responsável por cuidar das string

    int registro()//função responsável por cadastrar os usuários no sistema
{
         //início criação de variáveis/string
	     char arquivo[40]; //criamos as variáveis
		 char cpf[40];//o nome do do arquivo vai ser o cpf,pq é unico
		 char nome[40];
         char sobrenome[40];
	 	 char cargo[40];
		 //final da criação de variáveis/string
		
	 	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
		 scanf("%s", cpf); // %s para strings
		
		 strcpy(arquivo, cpf);// responsável por copiar os valores das string
		
		 FILE *file; // cria o arquivo
		 file = fopen(arquivo,"w"); // cria o arquivo
		 fprintf(file,cpf);//salvo o valor da variável
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

         setlocale(LC_ALL, "Portuguese"); // Definindo de novo, pois é outra função
       
	     char cpf[40];// a onde vamos armazenar a resposta do usuário
	     char conteudo[200];// a onde vamos armazenar o conteúdo que está dentro do arquivo 
	   
	     printf("Digite o CPF a ser consultado: ");
	     scanf("%s", cpf);
	   
	     FILE *file;
	     file = fopen(cpf,"r");//abre o arquivo e ler tudo que estiver dentro do cpf
   
	     if(file == NULL)// Para caso o cpf que o usuário colocar não existir
	       {
	     	printf("Não foi possível abrir arquivo, não localizado! \n");
	       }	
	   
	     while(fgets(conteudo,200,file) != NULL)// ele vai rodar 200 vezes no arquivo até trazer todas as informações
	        {
	      	printf("\nEssas são as informações do usuário: ");
	     	printf("%s", conteudo);
	   	    printf("\n\n");
	        }
	      system("pause");
	
	   
	   
}

    int deletar()
{
		
	 	char cpf[40];
		
	 	printf("Digite o CPF do usuário a ser deletado:");
	 	scanf("%s",cpf);
	 	
	  	remove(cpf);
		
	 	FILE *file;
	 	file= fopen(cpf,"r");
		
	    	if(file == NULL)
	    	{
	     	 printf("O usuário não se encontra no sistema!.\n");
		     system("pause");
		    }
		
 
}

int main()
{
	
     int opcao=0; //Definindo as variáveis
     int laco=1;
     char senhadigitada[]="a";
     int comparacao;
     
	 printf("### Cartório da EBAC ###\n\n");
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

         printf("### Cartório da EBAC ###\n\n"); //Início do menu
         printf("Escolha a opção desejada do menu:\n\n");
         printf("\t1 - Registrar Nomes\n");
         printf("\t2 - Consultar Nomes\n");
         printf("\t3 - Deletar Nomes\n\n");
         printf("\t4 - Sair do Sistema\n\n");
         printf("\tOpção:"); //Fim do menu

         scanf("%d",&opcao); //Armazenando as escolhas do usuário

         system("cls");//Para deixar mais limpo, apaga o que estava escrito anteriormente

       
	     switch(opcao)
	       {
	     	 case 1: //Início da seleção
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
	         printf("Essa opção não está disponível!\n");
	         system("pause");
	         break; //Fim da seleção
	    
		   	
	   }


    }

       }
      
	  else
	    printf("Senha incorreta!");
       
}





