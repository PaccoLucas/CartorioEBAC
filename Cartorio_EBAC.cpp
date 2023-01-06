#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca de strings

int registro() //Fun��o responsavel por cadastrar os su�rios no sistema
{
	//Inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];       //Vari�veis
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //escrever na tela 
	scanf("%s", cpf);//%s refere-se a string //Scanf: Coletando informa��es do usu�rio
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo 
	file = fopen(arquivo, "w"); //Cria o arquivo, "w" ultiliza quando for escrever novo arquivo
	fprintf(file,"CPF:");
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abri o arquivo, "a" para atualizar o arquivo com novas informa��es
	fprintf(file,","); //salva o valor da atualiza��o 
	fprintf(file,"Nome:");
	fclose(file); //Fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //Escrever na tela
	scanf("%s",nome); //Coletnado informa��es do usu�rio
	
	file = fopen(arquivo, "a");  //Abrir arquivo, "a" para atualizazar o arquivo com as novas informa��es
	fprintf(file,nome); //SAlva o valor da atualiza��o
	fclose(file); //Fecha o arquivo 
	
	file = fopen(arquivo, "a"); //Abrir o arquivo, "a" para atualizar o arquivo com as novas atualiza��es
	fprintf(file,","); //salva o valor da atualiza��a
	fprintf(file,"Sobrenome:");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); //escrever na tela 
	scanf("%s",sobrenome); //coletar informa��o do usu�rio
	
	file = fopen(arquivo, "a"); //abrir arquivo e atualizar com as novas informa��es 
	fprintf(file,sobrenome); // salva o valor da atualiza��o 
	fclose(file); // fechar o arquivo 
	
	file = fopen(arquivo, "a"); //Abrir arquivo e atualizar com novas informa��es
	fprintf(file,","); //salva o valor da informa��o
	fprintf(file,"Cargo:"); 
	fclose(file); //fechar o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); //escrever na tela 
	scanf("%s",cargo); //coletar informa��o do usu�rio
	
	file = fopen(arquivo, "a"); //abrir arquivo e atualizar as informa��es 
	fprintf(file,cargo); //Salvar a informa��o 
	fclose(file); //fechar o arquivo 
	
	system("pause"); //pausar a tela 
	
}

int consulta() //Fun��o responsavel para consultar os usu�rios no sitema  
{

    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
//variaveis
	char cpf[40]; 
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Escrever na tela 
	scanf("%s",cpf); //coletar informa��es do usu�rio 
	
	FILE *file; //chama o arquivo
	file = fopen(cpf,"r"); // abrir o arquivo e ler 
	
	if(file == NULL) //se nao forlacalizado a informa��o do usu�rio
	{
		printf("Usu�rio n�o localizado!.\n"); //escrever na tela caso ocorra de nao encontrar o usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) // 
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n "); //escrever na tela 
		printf("%s",conteudo); // escrever na tela o conteudo selecionado pelo usu�rio 
		printf("\n\n"); // pular linha 
	}
	fclose(file); // fechar o arquivo 
	system("pause"); // pausar 
}

int deletar() //fun��o responsavel por deletar os dados do usu�rio 
{
	char cpf[40]; //variavel 
	
	printf("Digite o cpf do usu�rio a ser deletado:"); //escrever na tela 
	scanf("%s",cpf); //coletar informa��es do usu�rio
	
	remove(cpf); // remover o usuario pela variavel do cpf 
	
	FILE *file; // chamar o arquivo 
	file = fopen(cpf,"r"); //abrir e ler 
	printf("Usu�rio deletado com sucesso!\n"); // escrever na tela que foi excluido 
	
	if(file == NULL) // caso n�o tenha o cpf selecionado 
	{
		printf("\nO usu�rio n�o se encontra no sistema!.\n\n"); // escrever na tela que nao encontrou o usu�rio 
		system("pause"); //pausar 
	}
}

int main() //Fun��o main serve como ponto de partida para a execu��o do programa
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //Definindo repeti��o 
	
	for(laco=1;laco=1;) 
	{
	
	  system("cls"); //Limpar a tela 
	  
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	  printf("*** Cart�rio da EBAC ***\n\n"); //Inicio do menu
	  printf("Escolha a op��o deseja do menu:\n\n"); //escrever na tela 
	  printf("\t1 - Registrar nomes\n"); //escrever na tela 
	  printf("\t2 - Consultar nomes\n"); //escrever na tela 
	  printf("\t3 - Deletar nomes\n\n");  //escrever na tela  
	  printf("Op��o:"); //fim do menu 
	
	  scanf("%d",&opcao); //armazenando a escolha do usu�rio
	
	  system("cls"); //limpar a tela 
	  
	  
	  switch(opcao)//Inicio do menu 
	   //utiliza SE como op��o para executar o comando, Exemplo: SE a op��o escolhida pelo usuario for 1 execute o comando X, SE for 2 execute o comando Y, assim por diante, todas op��es SE dentro da estrutura SWITCH 
	  {
	    case 1: //SE esxolheu a op��o 1 
	    registro(); 
	    break; //Fim do comando 
	    
	    case 2: //se escolher 2 ir para 
	    consulta();
	    break; // fim do comando 
	    
	    case 3: //se escolheu a op��o 3 ir para 
	    deletar();
		break; //fim do comando 
		
		default: // para quando o usuario escolher alguma op��o que n�o esteja disponivel executar o comando abaixo 
		printf("Essa op��o n�o est� disponivel\n"); //escrever na tela 
		system("pause"); //pausa 
		break; //fim do comando 
	  }
	
	
    }
}
