#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //Biblioteca de strings

int registro() //Função responsavel por cadastrar os suários no sistema
{
	//Inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];       //Variáveis
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //escrever na tela 
	scanf("%s", cpf);//%s refere-se a string //Scanf: Coletando informações do usuário
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo 
	file = fopen(arquivo, "w"); //Cria o arquivo, "w" ultiliza quando for escrever novo arquivo
	fprintf(file,"CPF:");
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abri o arquivo, "a" para atualizar o arquivo com novas informações
	fprintf(file,","); //salva o valor da atualização 
	fprintf(file,"Nome:");
	fclose(file); //Fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //Escrever na tela
	scanf("%s",nome); //Coletnado informações do usuário
	
	file = fopen(arquivo, "a");  //Abrir arquivo, "a" para atualizazar o arquivo com as novas informações
	fprintf(file,nome); //SAlva o valor da atualização
	fclose(file); //Fecha o arquivo 
	
	file = fopen(arquivo, "a"); //Abrir o arquivo, "a" para atualizar o arquivo com as novas atualizações
	fprintf(file,","); //salva o valor da atualizaçõa
	fprintf(file,"Sobrenome:");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); //escrever na tela 
	scanf("%s",sobrenome); //coletar informação do usuário
	
	file = fopen(arquivo, "a"); //abrir arquivo e atualizar com as novas informações 
	fprintf(file,sobrenome); // salva o valor da atualização 
	fclose(file); // fechar o arquivo 
	
	file = fopen(arquivo, "a"); //Abrir arquivo e atualizar com novas informações
	fprintf(file,","); //salva o valor da informação
	fprintf(file,"Cargo:"); 
	fclose(file); //fechar o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); //escrever na tela 
	scanf("%s",cargo); //coletar informação do usuário
	
	file = fopen(arquivo, "a"); //abrir arquivo e atualizar as informações 
	fprintf(file,cargo); //Salvar a informação 
	fclose(file); //fechar o arquivo 
	
	system("pause"); //pausar a tela 
	
}

int consulta() //Função responsavel para consultar os usuários no sitema  
{

    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
//variaveis
	char cpf[40]; 
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Escrever na tela 
	scanf("%s",cpf); //coletar informações do usuário 
	
	FILE *file; //chama o arquivo
	file = fopen(cpf,"r"); // abrir o arquivo e ler 
	
	if(file == NULL) //se nao forlacalizado a informação do usuário
	{
		printf("Usuário não localizado!.\n"); //escrever na tela caso ocorra de nao encontrar o usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) // 
	{
		printf("\nEssas são as informações do usuário:\n "); //escrever na tela 
		printf("%s",conteudo); // escrever na tela o conteudo selecionado pelo usuário 
		printf("\n\n"); // pular linha 
	}
	fclose(file); // fechar o arquivo 
	system("pause"); // pausar 
}

int deletar() //função responsavel por deletar os dados do usuário 
{
	char cpf[40]; //variavel 
	
	printf("Digite o cpf do usuário a ser deletado:"); //escrever na tela 
	scanf("%s",cpf); //coletar informações do usuário
	
	remove(cpf); // remover o usuario pela variavel do cpf 
	
	FILE *file; // chamar o arquivo 
	file = fopen(cpf,"r"); //abrir e ler 
	printf("Usuário deletado com sucesso!\n"); // escrever na tela que foi excluido 
	
	if(file == NULL) // caso não tenha o cpf selecionado 
	{
		printf("\nO usuário não se encontra no sistema!.\n\n"); // escrever na tela que nao encontrou o usuário 
		system("pause"); //pausar 
	}
}

int main() //Função main serve como ponto de partida para a execução do programa
{
	int opcao=0; //Definindo variáveis
	int laco=1; //Definindo repetição 
	
	for(laco=1;laco=1;) 
	{
	
	  system("cls"); //Limpar a tela 
	  
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	  printf("*** Cartório da EBAC ***\n\n"); //Inicio do menu
	  printf("Escolha a opção deseja do menu:\n\n"); //escrever na tela 
	  printf("\t1 - Registrar nomes\n"); //escrever na tela 
	  printf("\t2 - Consultar nomes\n"); //escrever na tela 
	  printf("\t3 - Deletar nomes\n\n");  //escrever na tela  
	  printf("Opção:"); //fim do menu 
	
	  scanf("%d",&opcao); //armazenando a escolha do usuário
	
	  system("cls"); //limpar a tela 
	  
	  
	  switch(opcao)//Inicio do menu 
	   //utiliza SE como opção para executar o comando, Exemplo: SE a opção escolhida pelo usuario for 1 execute o comando X, SE for 2 execute o comando Y, assim por diante, todas opções SE dentro da estrutura SWITCH 
	  {
	    case 1: //SE esxolheu a opção 1 
	    registro(); 
	    break; //Fim do comando 
	    
	    case 2: //se escolher 2 ir para 
	    consulta();
	    break; // fim do comando 
	    
	    case 3: //se escolheu a opção 3 ir para 
	    deletar();
		break; //fim do comando 
		
		default: // para quando o usuario escolher alguma opção que não esteja disponivel executar o comando abaixo 
		printf("Essa opção não está disponivel\n"); //escrever na tela 
		system("pause"); //pausa 
		break; //fim do comando 
	  }
	
	
    }
}
