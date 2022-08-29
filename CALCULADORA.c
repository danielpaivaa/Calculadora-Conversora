#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(){
	
	setlocale(LC_ALL, "portuguese");
	
	char op_menu, opcao;
	
	while (1){
	
		puts("   ______________________________________________________       ________________________________________________ ");
		puts("  | __  __        __            __   __    __   __   __  |     |  __  __                __  __   ____  __   __  | ");
		puts("  ||   |  | |    |    |  | |   |  | |  \\  |  | |  \\ |  | |     | |   |  | |\\  | \\    / |   |  \\  \\__  |  | |  \\ |");
		puts("  ||   |__| |    |    |  | |   |__| |   | |  | |  / |__| |     | |   |  | | \\ |  \\  /  |-- |  /     | |  | |  / | ");
		puts("  ||__ |  | |___ |__  |__| |__ |  | |__/  |__| |  \\ |  | |     | |__ |__| |  \\|   \\/   |__ |  \\  ___| |__| |  \\ | ");
		puts("  |______________________________________________________|     |________________________________________________| ");
		
			
		printf("\n\t\t\t\t***** Digite qual op��o voc� deseja executar *****\n\n");
		printf("\t(1) Calculadora Decimal \t\t\t\t    (3) Conversor Decimal -> Bin�rio \n\t(2) Calculadora Bin�ria \t\t\t\t    (4) Conversor Bin�rio -> Decimal\n\n\t");
		
		op_menu = getch();
		
		if(op_menu!= '1' && op_menu!= '2' && op_menu!= '3' && op_menu!= '4'){
			system ("cls");
			continue;
		}
		
		printf("Op��o (%c) ", op_menu);
		
		if(op_menu=='1'){    //CALCULADORA DECIMAL
		
			puts("Calculadora decimal.");
			int int1, int2, resultdiv, cont;			//int1-numerador da divis�o inteira, int2-denominador da divis�o inteira
			double num1=0.0 , num2=0.0 , result = 0;			//num1-primeiro n�mero, num2-segundo numero, result-resultado.
			char opdiv[4], opcao, op, numero1[20], numero2[20];			//opdiv-leitura do operador, op-operador final, opcao-saber se o usu�rio deseja fazer uma nova opera��o
		
			while (1){
				
				setbuf(stdin,NULL);
				
				printf("\n\tDigite a express�o decimal desejada:\t");
				
				scanf(" %lf", &num1);			//leitura do primeiro n�mero
				scanf(" %s", opdiv);			//leitura do operador
				scanf(" %lf", &num2);			//leitura do segundo n�mero
				
				if(opdiv[0]=='d' && opdiv[1]=='i' && opdiv[2]=='v'){	//verifica se o usu�rio digitou 'div'
					op = opdiv[0];		//op recebe a letra 'd' para divis�o inteira
					int1=num1;
					int2=num2;
				}else if(opdiv[0]=='+' || opdiv[0]=='-' || opdiv[0]=='/' || opdiv[0]=='*' || opdiv[0]=='^'){			//verifica qual operador foi digitado pelo usu�rio
					if(opdiv[1] != '\0' && opdiv[2] != '\0'){			//verifica se o usu�rio digitou alguma coisa ap�s o operador
						printf("\n\tERRO!\n\n\a");
						continue;
					}else {
						op = opdiv[0];
					}
				}
				
				switch (op){		//cases para realizar as opera��es
				
					case '+': 
						result=num1+num2;
						printf("\n\t--> O resultado da sua express�o �: %.4lf\n\n", result);
						result = 0.0;
						break;
						
					case '-':
						result=num1-num2;
						printf("\n\t--> O resultado da sua express�o �: %.4lf\n\n", result);
						result = 0.0;
						break;
						
					case '*':
						result=num1*num2;
						printf("\n\t--> O resultado da sua express�o �: %.4lf\n\n", result);
						result = 0.0;
						break;
					
					case 'd':
						if(int2 == 0){			//verifica se o segundo n�mero (denominador) � igual a 0
							printf("\n\tDivis�o inv�lida!\n\n\a");
							continue;
						}
						if(int2 != 0){			//se o numerador for diferente de 0, executa a opera��o
							resultdiv=int1/int2;
							printf("\n\t--> O resultado da sua express�o �: %d\n\n", resultdiv);
							resultdiv = 0;
							break;
						}
					
					case '/':
						if(num2 == 0){			//verifica se o segundo n�mero (denominador) � igual a 0
							printf("\n\tDivis�o inv�lida!\n\n\a");
							continue;
						}
						if(num2 != 0){			//se o numerador for diferente de 0, executa a opera��o
							result=num1/num2;
							printf("\n\t--> O resultado da sua express�o �: %.4lf\n\n", result);
							result = 0.0;
							break;
						}
						
					case '^':
						result=pow(num1, num2);
						printf("\n\t--> O resultado da sua express�o �: %.4lf\n\n", result);
						result = 0.0;
						break;
						
					default:
						printf("\n\tERRO!\n\a");
						continue;
				}
				
				opdiv[0]='0';
				op='0';
				num1=0.0;
				num2=0.0;
			
				while(1){
					
					printf("\n\tDeseja fazer uma nova opera��o? Digite 's' para continuar, 'n' para voltar ao menu e 'x' para sair.\n\t");
					
					opcao=getch();
					printf("%c\n", opcao);
					
					if(opcao=='s' || opcao=='S'){
						break;
					}
					if(opcao=='n' || opcao=='N'){
						system ("cls");
						break;
					}
					if(opcao=='x' || opcao=='X' ){
						exit(1);
					}
					else{
						printf("\n\tDigite uma op��o v�lida!\n\n\a");
					}
				}
				
				if(opcao=='n' || opcao=='N'){
					break;
				}
			}
		}
		
		if(op_menu=='2'){    //CALCULADORA BIN�RIA
			
			puts("Calculadora bin�ria.");
			
			char bin1[40], bin2[40], opbin[4], opcao;
			double res1=0.0, res2=0.0, resbin=0.0;
		
			while (1){
				
				printf("\n\tDigite a express�o bin�ria desejada,\n\t(Lembrando que o primeiro bit deve ser de sinal):\t");
				
				scanf(" %s", bin1);
				scanf(" %s", opbin);
				scanf(" %s", bin2);	
				
				setbuf (stdin, NULL);	
			
			    //BLOCO 1 DO PRIMEIRO N�MERO (BIN1)
				{
					char binario[40];
					int cont_laco=0, cont_numeros=0, cont_pos_ponto=0, cont_espaco=0, cont_espaco2=0, val_erros=0;		//variaveis dos contadores
					int tamanho=0, aux=0; 												//variaveis auxiliadoras
					int convertido_decimal=0;											//variavel do coversor deciaml interio
					double fracionado_total=0, convertido_fracionado=0;					//variavel do coversor deciaml fracionado
					
					strcpy(binario, bin1);
					
					for(cont_laco=0; cont_laco<strlen(binario); cont_laco++){
						if(binario[cont_laco]!= ' ' && binario[cont_laco]!= '0' && binario[cont_laco]!= '1'){
							val_erros++;																	//La�o para testar se tem outros algarismos incompat�veis
							if(binario[cont_laco]== ',' || binario[cont_laco]==  '.'){
								aux++;
							}
						}
					}
					
					if(aux>1){
						val_erros+=aux;
					}else{
						val_erros-=aux;
					}
					
					if(val_erros!=0||strlen(binario)<=1||binario[0]==','||binario[0]== '.'|(binario[strlen(binario)-1])=='.'||(binario[strlen(binario)-1])==','){
						printf("\n\tN�O FOI POSS�VEL FAZER A OPERA��O!!\n\a");
						continue;
					}
						
					for(cont_laco=0; cont_laco<=strlen(binario); cont_laco++){			//laco para contar os numeros antes da virgula
						if(isdigit(binario[cont_laco])){
							cont_numeros++;
						}
						
						if(binario[cont_laco]== ' '){									//la�o para contar espa�os na parte inteira do numero
							cont_espaco++;
						}	
						
						if(binario[cont_laco]== ',' || binario[cont_laco]==  '.'){
							for(cont_laco; cont_laco<=strlen(binario); cont_laco++){	//laco para contar os numeros p�s da virgula
								if(isdigit(binario[cont_laco])){
									cont_pos_ponto++;
								}
								if(binario[cont_laco]== ' '){							//la�o para contar espa�os na parte fracionada do numero
									cont_espaco2++;
								}
							}
							cont_laco=strlen(binario);
						}
					}
				
					//Bloco para realizar o complemento de 2 para parte inteira do n�mero
					if(binario[0]=='1'){
						for(cont_laco = (cont_numeros+cont_espaco)-1; cont_laco >= 1; cont_laco--){
							if(binario[cont_laco]==' '){
								continue;
							}	
						
							if(binario[cont_laco]=='1'){
							    break;
							}
						}															
							
						for(cont_laco-=1 ; cont_laco >= 1; cont_laco--){
							if(binario[cont_laco]==' '){
								continue;
							}
						
							if(binario[cont_laco]=='1'){
								binario[cont_laco]= '0';
								 
							}else if(binario[cont_laco=='0']){
								binario[cont_laco]='1';
									
							}
						}
					}
				
					tamanho = cont_numeros-1;
					aux = tamanho-1;
					
					//la�o para convers�o da parte inteira do n�mero
					for(cont_laco=1; cont_laco<=tamanho; cont_laco++){		
						if(binario[cont_laco]=='1'){
							convertido_decimal += pow(2, aux);
				
						}else if(binario[cont_laco]==' '){
							tamanho++;
							aux++;
						}
						aux--;
					}
					
					//Bloco para realizar o complemento de 2 para parte fracionada do n�mero
					if(binario[0]=='1' && cont_pos_ponto>0){
						for(cont_laco = (strlen(binario)+cont_espaco2)-1; cont_laco > (cont_numeros+cont_espaco)+1; cont_laco--){
							if(binario[cont_laco]==' '){
								continue;
							}	
						
							if(binario[cont_laco]=='1'){
							    break;
							}
						}															
							
						for(cont_laco-=1 ; cont_laco >= (cont_numeros+cont_espaco)+1; cont_laco--){
							if(binario[cont_laco]==' '){
								continue;
							}
						
							if(binario[cont_laco]=='1'){
								binario[cont_laco]= '0';
								 
							}else if(binario[cont_laco=='0']){
								binario[cont_laco]='1';
									
							}
						}
					}
					
					tamanho = tamanho+(cont_pos_ponto+1);
					
					//la�o para conversao da parte fracionada do n�mero
					if(binario[0]=='.' || binario[0]==','){
						aux = 1;
					}else{
						aux = 0;	
					}
					
					for(cont_laco; cont_laco<=tamanho; cont_laco++){			
						if(binario[cont_laco]=='1'){
							convertido_fracionado += pow(2, -aux);
				
						}else if(binario[cont_laco]==' '){
							tamanho++;
							aux--;
						}
						aux++;
					}
						
					fracionado_total = convertido_decimal+convertido_fracionado;
					
					if(binario[0]=='1'){       		//verificando a primeira posi��o para definir se � positivo ou negativo
				        fracionado_total *= -1;
				    }
				    
				    if(fracionado_total==-0){
						fracionado_total=0;
					}
				    
					res1 = fracionado_total;
				}
				
				setbuf (stdin, NULL);
				
				//BLOCO 2 DO SEGUNDO N�MERO (BIN2)
				{
					
					char binario[40];
					int cont_laco=0, cont_numeros=0, cont_pos_ponto=0, cont_espaco=0, cont_espaco2=0, val_erros=0;		//variaveis dos contadores
					int tamanho=0, aux=0; 												//variaveis auxiliadoras
					int convertido_decimal=0;											//variavel do coversor deciaml interio
					double fracionado_total=0, convertido_fracionado=0;					//variavel do coversor deciaml fracionado
				
					strcpy(binario, bin2);
					
					//La�o para testar se tem outros algarismos incompat�veis
					for(cont_laco=0; cont_laco<strlen(binario); cont_laco++){
						if(binario[cont_laco]!= ' ' && binario[cont_laco]!= '0' && binario[cont_laco]!= '1'){
							val_erros++;																	
							if(binario[cont_laco]== ',' || binario[cont_laco]==  '.'){
								aux++;
							}
						}
					}
					
					if(aux>1){
						val_erros+=aux;
					}else{
						val_erros-=aux;
					}
					 
					if(val_erros!=0||strlen(binario)<=1||binario[0]==','||binario[0]== '.'|(binario[strlen(binario)-1])=='.'||(binario[strlen(binario)-1])==','){
						printf("\n\tN�O FOI POSS�VEL FAZER A OPERA��O!!\n\a");
						continue;
					}
					
					//la�o para contar os n�meros antes da v�rgula
					for(cont_laco=0; cont_laco<=strlen(binario); cont_laco++){		
						if(isdigit(binario[cont_laco])){
							cont_numeros++;
						}
						
						if(binario[cont_laco]== ' '){
							cont_espaco++;
						}	
						
						//la�o para contar os numeros p�s da v�rgula
						if(binario[cont_laco]== ',' || binario[cont_laco]==  '.'){
							for(cont_laco; cont_laco<=strlen(binario); cont_laco++){	
								if(isdigit(binario[cont_laco])){
									cont_pos_ponto++;
								}
								if(binario[cont_laco]== ' '){
									cont_espaco2++;
								}
							}
							cont_laco=strlen(binario);
						}
					}
				
					if(binario[0]=='1'){
						for(cont_laco = (cont_numeros+cont_espaco)-1; cont_laco >= 1; cont_laco--){
							if(binario[cont_laco]==' '){
								continue;
							}
						
							if(binario[cont_laco]=='1'){
							    break;
							}
						}															//Bloco para realizar o complemento de 2 para parte inteira do n�mero
							
						for(cont_laco-=1 ; cont_laco >= 1; cont_laco--){
							if(binario[cont_laco]==' '){
								continue;
							}
						
							if(binario[cont_laco]=='1'){
								binario[cont_laco]= '0';
							}else if(binario[cont_laco=='0']){
								binario[cont_laco]='1';
							 }
						}
					}
				
					tamanho = cont_numeros-1;
					aux = tamanho-1;
					
					//la�o para convers�o da parte inteira do n�mero
					for(cont_laco=1; cont_laco<=tamanho; cont_laco++){		
						if(binario[cont_laco]=='1'){
							convertido_decimal += pow(2, aux);
						}else if(binario[cont_laco]==' '){
							tamanho++;
							aux++;
						}
						aux--;
					}
					
					if(binario[0]=='1' && cont_pos_ponto>0){
						for(cont_laco = (strlen(binario)+cont_espaco2)-1; cont_laco > (cont_numeros+cont_espaco)+1; cont_laco--){
							if(binario[cont_laco]==' '){
								continue;
							}	
						
							if(binario[cont_laco]=='1'){
							    break;
							}
						}															
						
						//Bloco para realizar o complemento de 2 para parte fracionada do n�mero	
						for(cont_laco-=1 ; cont_laco >= (cont_numeros+cont_espaco)+1; cont_laco--){
							if(binario[cont_laco]==' '){
								continue;
							}
						
							if(binario[cont_laco]=='1'){
								binario[cont_laco]= '0';
								 
							}else if(binario[cont_laco=='0']){
								binario[cont_laco]='1';		
							}
						}
					}
					
					tamanho = tamanho+(cont_pos_ponto+1);
					
					if(binario[0]=='.' || binario[0]==','){
						aux = 1;
					}else{
						aux = 0;	
					}
					
					//la�o para convers�o da parte fracionada do n�mero
					for(cont_laco; cont_laco<=tamanho; cont_laco++){			
						if(binario[cont_laco]=='1'){
							convertido_fracionado += pow(2, -aux);
				
						}else if(binario[cont_laco]==' '){
							tamanho++;
							aux--;
						}
						aux++;
					}
						
					fracionado_total = convertido_decimal+convertido_fracionado;
					
					if(binario[0]=='1'){       				// verificando a primeira posi��o para definir se � positivo ou negativo
				        fracionado_total *= -1;
				    }
				    
				    if(fracionado_total==-0){
						fracionado_total=0;
					}
				    
					res2 = fracionado_total;
				}
				
				setbuf (stdin, NULL);
				
				//BLOCO 3 - CALCULADORA
				{
					int int1, int2, resultdiv;			//int1-numerador da divis�o inteira, int2-denominador da divis�o inteira
					double num1=0.0 , num2=0.0 , result = 0;			//num1-primeiro n�mero, num2-segundo numero, result-resultado.
					char opdiv[4], opcao, op;			//opdiv-leitura do operador, op-operador final, opcao-saber se o usu�rio deseja fazer uma nova opera��o
					
					num1 = res1;
					num2 = res2;
					
					strcpy (opdiv, opbin);
						
					if(opdiv[0]=='d' && opdiv[1]=='i' && opdiv[2]=='v'){
						op = opdiv[0];
						int1=num1;
						int2=num2;
					}else if(opdiv[0]=='+' || opdiv[0]=='-' || opdiv[0]=='/' || opdiv[0]=='*' || opdiv[0]=='^'){			//verifica qual operador foi digitado pelo usu�rio
						if(opdiv[1] != '\0' && opdiv[2] != '\0'){			//verifica se o usu�rio digitou alguma coisa ap�s o operador
							printf("\n\tERRO!\n\n\a");
							continue;
						}else {
							op = opdiv[0];
						}
					}
					
					switch (op){
						
						case '+': 
							result=num1+num2;
							resbin = result;
							break;
							
						case '-':
							result=num1-num2;
							resbin = result;
							break;
							
						case '*':
							result=num1*num2;
							resbin = result;
							break;
						
						case 'd':
							if(int2 == 0){			//verifica se o segundo numero (denominador) � igual a 0
								printf("\n\tDivis�o inv�lida!\n\n\a");
								break;
							}
							if(int2 != 0){			//se o numerador for diferente de 0, executa a opera��o
								resultdiv=int1/int2;
								resbin = resultdiv;
								break;
							}
						
						case '/':
							if(num2 == 0){			//verifica se o segundo numero (denominador) � igual a 0
								printf("\n\tDivis�o inv�lida!\n\n\a");
								continue;
							}
							if(num2 != 0){			//se o numerador for diferente de 0, executa a opera��o
								result=num1/num2;
								resbin = result;
								break;
							}
							
						case '^':
							result=pow(num1, num2);
							resbin = result;
							break;
							
						default:
							printf("\n\tERRO!\n\n\a");
							continue;
					}
					
					opdiv[0]='0';
					op='0';
				}
				
				setbuf (stdin, NULL);
				
				//BLOCO 4 - DECIMAL-BIN�RIO
				{
					double num=0.0, fracionario=0.0, fra_fracionario=0.0;
					int sinal, decimal=0, cont=0, fra_decimal=0, complemento = 0;
					char binario[40], fra[4];
					
					for(cont = 0; cont < strlen(binario); cont++){ // zera os dois vetores, pois pode ocorrer uma nova opera��o
						binario[cont]=' ';
						fra[cont]=' ';
					}
					
					num = resbin;
					
					if(num < 0){   				//convertendo o sinal para bit de magnitude
						num = num * (-1);
						sinal = 1;
					}else{
						sinal = 0;
					}
					
					decimal = num;			// atribuindo as partes de num, as devidaas vari�veis
					fracionario = num - decimal;
					cont = 0;
				
					while(cont < 4){		//convertendo a parte fracionaria do n�mero
						fra_decimal = fracionario * 2;
						fracionario = (fracionario*2)- fra_decimal;
						
						if(fra_decimal == 0){
							fra[cont] = '0';
						}else if(fra_decimal){
							fra[cont] = '1';
						}
						cont++;
					}
					
					cont = 0;
					  
					while(1){			// convertendo a parte decimal do n�mero
						if(decimal%2==0){
							binario [cont] = '0';
						}else if(decimal%2==1){
							binario [cont] = '1';
						}
						
						decimal = decimal /2;
						cont ++;
						if(decimal==0){
							break;
						}
					}
					strrev(binario);
					cont =0;
					
					if(sinal==1){		//caso o n�mero seja negativo
						complemento = 0;
						cont = strlen(binario) -1;
						while(cont > -1){ //realizando o complmento de 2 na parte decimal
							
							if(binario[cont]=='1' && complemento == 0){
								complemento = 1;
								cont --;
								continue;
							}
							
							if(binario[cont]=='1' && complemento == 1){
								binario[cont] = '0';
							
							}else if(binario[cont]=='0' && complemento == 1){
								binario[cont] = '1';
							}
							cont --;
						}
						
						cont = strlen(fra)-1;
						complemento = 0;
						
						while(cont>-1){ 	//realizando o complmento de 2 na parte fracion�ria
							
							if(fra[cont]=='1' && complemento == 0){
								complemento = 1;
								cont --;
								continue;
							}
							
							if(fra[cont]=='1'  && complemento==1){
								fra [cont] = '0';
							}else if(fra[cont]=='0' && complemento ==1){
								fra [cont] = '1';
							}
							cont --;
						}
					}
					
					printf("\n\t--> O n�mero em bin�rio �: %d", sinal); // imprime o bit de sinal
					
					for(cont = 0; cont < strlen(binario); cont++){ //imprime a parte inteira do n�mero convertido
						if(binario[cont]=='0'|| binario[cont]=='1')
							printf("%c", binario[cont]);
					}
					cont =0;
					printf(",");
					
					for(cont=0; cont < 4; cont ++){ // imprime a parte fracion�ria do n�mero convertido
						printf("%c", fra[cont]);
					}
				
					printf("\n\tObs.: No primeiro bit � representado o sinal do n�mero.\n");
					
					for(cont = 0; cont < strlen(binario); cont++){ // zera os dois vetores, pois pode ocorrer uma nova opera��o
						binario[cont]=' ';
						fra[cont]=' ';
					}
					
					num=0, fracionario=0, fra_fracionario=0;
					sinal=0, decimal=0, cont=0, fra_decimal=0, complemento = 0;
					resbin=0.0;
					setbuf (stdin, NULL);
				}
				
				while(1){
					
					printf("\n\tDeseja fazer uma nova opera��o? Digite 's' para continuar, 'n' para voltar ao menu e 'x' para sair.\n\t");
					
					opcao=getch();
					printf("%c\n", opcao);
					
					if(opcao=='s' || opcao=='S'){
						break;
					}
					if(opcao=='n' || opcao=='N'){
						system ("cls");
						break;
					}
					if(opcao=='x' || opcao=='X' ){
						exit(1);
					}
					else{
						printf("\n\tDigite uma op��o v�lida!\n\n\a");
					}
				}
				
				if(opcao=='n' || opcao=='N'){
					break;
				}
			}
		}
		
		if(op_menu=='3'){    //CONVERSOR DECIMAL-BIN�RIO
			
			puts("Conversor Decimal -> Bin�rio.");
		
			while(1){
			
				double num, fracionario, fra_fracionario;  		 // num: recebe o n�mero inserido, fracionario: recebe a parte fracion�rio do n�mero, fra_fracionario: auxuliar pra convers�o
				int sinal, decimal, cont, fra_decimal, complemento = 0; 		//sinal: sinal para converter em bit de magnitude, decimal: part decimal do n�mero recebido, fra_decimal: auxiliar, complmento: auxiliar para fazer o complmento de 2
				char binario [40], fra[4];		// binario [40]: recebe a parte decimal convertida, fra[4]: recebe a parte fracionario convertida
			
				printf("\n\tInsira um n�mero decimal para a convers�o:\t");
				if(scanf(" %lf", &num)!=0){ // leitura do n�mero para converter
							
					printf("\n");
					
					if(num < 0){   				//convertendo o sinal do bit de sinal
					
						num = num * (-1);
						sinal = 1;
					}else{
						sinal = 0;
					}
					
					decimal = num;			// atribuindo as partes de num, as devidas vari�veis
					fracionario = num - decimal;
					cont = 0;
				
					while(cont < 4){		//convertendo a parte fracion�ria do n�mero
						fra_decimal = fracionario * 2;
						fracionario = (fracionario*2)- fra_decimal;
						
						if(fra_decimal == 0){
							fra[cont] = '0';
						}else if(fra_decimal){
							fra[cont] = '1';
						}
						cont++;
					}
					
					cont = 0;
					  
					while(1){			// convertendo a parte decimal do n�mero
						if(decimal%2==0){
							binario [cont] = '0';
						}else if(decimal%2==1){
							binario [cont] = '1';
						}
						
						decimal = decimal /2;
						cont ++;
						if(decimal==0){
							break;
						}
					}
					strrev(binario);
					cont =0;
					
					if(sinal==1){		//caso o n�mero seja negativo
						complemento = 0;
						cont = strlen(binario) -1;
						
						while(cont > -1){ 		//realizando o complmento de 2 na parte decimal
							
							if(binario[cont]=='1' && complemento == 0){
								complemento = 1;
								cont --;
								continue;
							}
							
							if(binario[cont]=='1' && complemento == 1){
								binario[cont] = '0';
							
							}else if(binario[cont]=='0' && complemento == 1){
								binario[cont] = '1';
							}
							cont --;
						}
						
						cont = strlen(fra)-1;
						complemento = 0;
						
						while(cont>-1){ 	//realizando o complmento de 2 na parte fracion�ria
							
							if(fra[cont]=='1' && complemento == 0){
								complemento = 1;
								cont --;
								continue;
							}
							
							if(fra[cont]=='1'  && complemento==1){
								fra [cont] = '0';
							}else if(fra[cont]=='0' && complemento ==1){
								fra [cont] = '1';
							}
							cont --;
						}
					}
					
					printf("\t--> O n�mero em bin�rio �: %d", sinal); // imprime o bit de magnitude 
					
					for(cont = 0; cont < strlen(binario); cont++){ //imprime a parte inteira do n�mero convertido
						if(binario[cont]=='0'|| binario[cont]=='1')
							printf("%c", binario[cont]);
					}
					
					cont =0;
					printf(",");
					
					for(cont=0; cont < 4; cont ++){ // imprime a parte fracion�ria do n�mero convertido
						printf("%c", fra[cont]);
					}
				
					printf("\n\tObs.: No primeiro bit � representado o sinal do n�mero.\n");
					
					for(cont = 0; cont < strlen(binario); cont++){ // zera os dois vetores, pois pode ocorrer uma nova opera��o
						binario[cont]=' ';
						fra[cont]=' ';
					}
					
					num=0, fracionario=0, fra_fracionario=0;
					sinal=0, decimal=0, cont=0, fra_decimal=0, complemento = 0;// zera as vari�veis pois pode ocorrer uma nova oper��o
					
					while(1){ 		//menu simples para tomada de decis�es do usu�rio
						
							printf("\n\tDeseja fazer uma nova opera��o? Digite 's' para continuar, 'n' para voltar ao menu e 'x' para sair.\n\t");
						
							opcao=getch();
							printf("%c\n", opcao);
						
							if(opcao=='s' || opcao=='S'){
								break;
							}
							if(opcao=='n' || opcao=='N'){
								system ("cls");
								break;
							}
							if(opcao=='x' || opcao=='X' ){
								exit(1);
							}
							else{
								printf("\n\tDigite uma op��o v�lida!\n\n\a");
							}
						}
				}else{
					printf("\n\tERRO NA CONVERS�O!\n\a");
					
					while(1){ // menu caso ocorra um erro na opera��o
					
						printf("\n\tDeseja fazer uma nova opera��o? Digite 's' para continuar, 'n' para voltar ao menu e 'x' para sair.\n\t");
					
						opcao=getch();
						printf("%c\n", opcao);
					
						if(opcao=='s' || opcao=='S'){
							break;
						}
						if(opcao=='n' || opcao=='N'){
							break;
						}
						if(opcao=='x' || opcao=='X' ){
							exit(1);
						}
						else{
							printf("\n\tDigite uma op��o v�lida!\n\n\a");
						}
					}
				}
				
				setbuf(stdin, NULL);
				
				if(opcao=='n' || opcao=='N'){
					break;
				}
			}
		}
		
		if(op_menu=='4'){    //CONVERSOR BIN�RIO-DECIMAL
			
			puts("Conversor Bin�rio -> Decimal.");
			
			while (1){
				
				char binario[40], opcao;						//binario - n�mero a ser convertido
				int cont_laco=0, cont_numeros=0, cont_pos_ponto=0, cont_espaco=0, cont_espaco2=0, val_erros=0;		//variaveis dos contadores
				int tamanho=0, aux=0; 												//variaveis auxiliadoras
				int convertido_decimal=0;											//variavel do coversor deciaml interio
				float fracionado_total=0, convertido_fracionado=0;					//variavel do coversor deciaml fracionado
				
				printf("\n\tInsira um n�mero bin�rio para a convers�o. \n\t(Lembrando que o primeiro bit ser� de sinal):\t");
				setbuf(stdin, NULL);
				gets(binario);
				
				for(cont_laco=0; cont_laco<strlen(binario); cont_laco++){
					if(binario[cont_laco]!= ' ' && binario[cont_laco]!= '0' && binario[cont_laco]!= '1'){
						val_erros++;																	//La�o para testar se tem outros algarismos incompat�veis
						if(binario[cont_laco]== ',' || binario[cont_laco]==  '.'){
							aux++;
						}
					}
				}
				
				if(aux>1){
					val_erros+=aux;
				}else{
					val_erros-=aux;
				 }
				if(val_erros!=0||strlen(binario)<=1||binario[0]==','||binario[0]== '.'|(binario[strlen(binario)-1])=='.'||(binario[strlen(binario)-1])==','){
					printf("\n\tN�O FOI POSS�VEL FAZER A CONVERS�O!\n\a");
					continue;
				}
					
				for(cont_laco=0; cont_laco<=strlen(binario); cont_laco++){			//laco para contar os n�meros antes da v�rgula
					if(isdigit(binario[cont_laco])){
						cont_numeros++;
					}
					
					if(binario[cont_laco]== ' '){
						cont_espaco++;
					}	
					
					if(binario[cont_laco]== ',' || binario[cont_laco]==  '.'){
						for(cont_laco; cont_laco<=strlen(binario); cont_laco++){	//laco para contar os numeros p�s da virgula
							if(isdigit(binario[cont_laco])){
								cont_pos_ponto++;
							}
							if(binario[cont_laco]== ' '){
								cont_espaco2++;
							}
						}
						cont_laco=strlen(binario);
					}
				}
			
				if(binario[0]=='1'){
					for(cont_laco = (cont_numeros+cont_espaco)-1; cont_laco >= 1; cont_laco--){   //Bloco para realizar o complemento de 2 para parte inteira do n�mero
						if(binario[cont_laco]==' '){
							continue;
						}	
					
						if(binario[cont_laco]=='1'){
						    break;
						}
					}															
					
					
					for(cont_laco-=1 ; cont_laco >= 1; cont_laco--){
						if(binario[cont_laco]==' '){
							continue;
						}
					
						if(binario[cont_laco]=='1'){
							binario[cont_laco]= '0';
							 
						}else if(binario[cont_laco=='0']){
							binario[cont_laco]='1';
								
						}
					}
				}
			
				tamanho = cont_numeros-1;
				aux = tamanho-1;
				
				for(cont_laco=1; cont_laco<=tamanho; cont_laco++){			//la�o para convers�o da parte inteira do n�mero
					if(binario[cont_laco]=='1'){
						convertido_decimal += pow(2, aux);
			
					}else if(binario[cont_laco]==' '){
						tamanho++;
						aux++;
					}
					aux--;
				}
				
				if(binario[0]=='1' && cont_pos_ponto>0){
					for(cont_laco = (strlen(binario)+cont_espaco2)-1; cont_laco > (cont_numeros+cont_espaco)+1; cont_laco--){   //Bloco para realizar o complemento de 2 para parte fracionada do n�mero
						if(binario[cont_laco]==' '){
							continue;
						}	
					
						if(binario[cont_laco]=='1'){
						    break;
						}
					}															
					
					
					for(cont_laco-=1 ; cont_laco >= (cont_numeros+cont_espaco)+1; cont_laco--){
						if(binario[cont_laco]==' '){
							continue;
						}
					
						if(binario[cont_laco]=='1'){
							binario[cont_laco]= '0';
							 
						}else if(binario[cont_laco=='0']){
							binario[cont_laco]='1';
								
						}
					}
				}
				
				tamanho = tamanho+(cont_pos_ponto+1);
				
				if(binario[0]=='.' || binario[0]==','){
					aux = 1;
				}else{
					aux = 0;	
				}
				
				for(cont_laco; cont_laco<=tamanho; cont_laco++){			//la�o para convers�o da parte fracionada do n�mero
					if(binario[cont_laco]=='1'){
						convertido_fracionado += pow(2, -aux);
			
					}else if(binario[cont_laco]==' '){
						tamanho++;
						aux--;
					}
					aux++;
				}
					
				fracionado_total = convertido_decimal+convertido_fracionado;
				
				if(binario[0]=='1'){       								 // verificando a primeira posi��o para definir se � positivo ou negativo
			        fracionado_total *= -1;
			    }
			    
			    if(fracionado_total==-0){
					fracionado_total=0;
				}	
				
				printf("\n\t--> O n�mero em decimal �: %.4f\n", fracionado_total);
				
				while(1){
					
					printf("\n\tDeseja fazer uma nova opera��o? Digite 's' para continuar, 'n' para voltar ao menu e 'x' para sair.\n\t\t");
					
					opcao=getch();
					printf("%c\n", opcao);
					
					if(opcao=='s' || opcao=='S'){
						break;
					}
					if(opcao=='n' || opcao=='N'){
						system ("cls");
						break;
					}
					if(opcao=='x' || opcao=='X' ){
						exit(1);
					}
					else{
						printf("\n\tDigite uma op��o v�lida!\n\n\a");
					}
				}
				
				if(opcao=='n' || opcao=='N'){
					break;
				}
			}
		}	
	}
	return 0;
}
