//bibliotecas usadas
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.c>
#include <time.h>

//Variáveis global
//variáveis de login
char email[40],senha[10],enfermidade[47];
//variáveis de cadastro
char nome[20],sobrenome[20],senhaTMP[10],senhaC[10],emailC[40]; 
//variáveis de cadastro segunda tela
float altura, peso;
int dia,mes,ano;
//dicas da primeira página
char dicas[10][100],dicas2[10][100];
//outras
int selecao_inicio, p=1,x;
bool teste_email,teste_senha,t,in;

void dicas_entrada(){
     strcpy(dicas[0],"   - Faça as refeições com calma.");
     strcpy(dicas[1],"   - Mastigue bem os alimentos.");
     strcpy(dicas[2],"   - Horários para as refeições.");
     strcpy(dicas[3],"   - Alimente-se a cada 3 horas.");
     strcpy(dicas[4],"   - De preferência à alimentos integrais.");
     strcpy(dicas[5],"   - Consuma frutas e hortaliças.");
     strcpy(dicas[6],"   - Evitar a ingestão de líquidos durante as refeições.");
     strcpy(dicas[7],"   - Evite alimentos refinados.");
     strcpy(dicas[8],"   - Mastigue muito bem os alimentos.");
     strcpy(dicas[9],"   - Evite os alimentos industrializados.");
     
     strcpy(dicas2[0],"   - Prepare um espaço arejado para realizar seus exercícios.");
     strcpy(dicas2[1],"   - Estipule um horário fixo para treinar.");
     strcpy(dicas2[2],"   - Faça uma boa alimentação pré e pós-treino.");
     strcpy(dicas2[3],"   - Respeite seus limites físicos.");
     strcpy(dicas2[4],"   - Faça alongamentos antes de qualquer exercício.");
     strcpy(dicas2[5],"   - Faça caminhadas.");
     strcpy(dicas2[6],"   - Pratique meditação.");
     strcpy(dicas2[7],"   - Comece com os treinos básicos.");
     strcpy(dicas2[8],"   - Sentir dor ao praticar exercícios não é normal, procure ajuda.");
     strcpy(dicas2[9],"   - Cuidado com a postura ao realizar exercícios.");
     
}

//PROCEDIMENTO INICIO
void inicio(){
    
    int tecla;
    textcolor(12);
    printf("     ¦¦¦¦         ¦¦¦¦¦        \n");
    printf("___¦¦¦¦¦¦¦    ¦¦¦      ¦¦      \n");
    printf("_¦¦¦¦¦¦¦¦¦¦¦¦      M     ¦     \n");
    printf("¦¦¦¦¦¦¦¦¦¦¦        A      ¦    \n");
    printf("¦¦¦¦¦¦             I       ¦   \n");
    printf("¦¦¦¦¦¦             S      ¦    \n");
    printf("¦¦¦¦¦¦          S        ¦     \n");
    printf("_¦¦¦¦¦          A       ¦      \n");
    printf("___¦¦¦¦¦¦       Ú      ¦       \n");
    printf("_______¦¦¦¦¦    D    ¦         \n");
    printf("__________¦¦¦¦  E ¦¦           \n");
    printf("____________¦¦¦¦¦¦             \n");
    printf("_____________¦¦¦               \n");
    textcolor(15);
    do{ //menu interativo
        textbackground(0);            
        textcolor(15);
        gotoxy(45,10);printf("LOGIN");
        gotoxy(45,11);printf("CADASTRE-SE");
        gotoxy(45,23);printf("SAIR");
        gotoxy(45,23);printf("SAIR\n\n\n\n\n");
        printf("  Todos os direitos reservados: Gabriel Busato, Gabriela Rosa, Lucas Garcia e Lucas Ropelli. @2021");
        textbackground(15);
        textcolor(0);
          
        switch (p){
            case 1:gotoxy(45,10);printf("LOGIN"); break;
            case 2:gotoxy(45,11);printf("CADASTRE-SE"); break;
            case 3:gotoxy(45,23);printf("SAIR"); break;
        }
        tecla=getch();
        
        if (tecla==224 || tecla==0)
            tecla=getch();
        switch (tecla){
            case 72:p--; break;
            case 80:p++; break;
        }
        if (p==0) p=3;
        if (p==4) p=1;      
    }
    while(tecla!=13);
    system("cls");
}

//tela de cadastro
void cadastro (){ 
    system("color 0F");
    //entrada de dados
    gotoxy(45,8);printf("CADASTRO");
    gotoxy(45,10);printf("Nome: ");
    gotoxy(45,11);gets(nome);
    gotoxy(45,13);printf("Sobrenome: ");
    gotoxy(45,14);gets(sobrenome); 
    gotoxy(45,16);printf("Email: ");
    gotoxy(45,17);gets(emailC); 
    gotoxy(45,19);printf("Senha: ");
    gotoxy(45,20);gets(senhaC); 
    gotoxy(45,22);printf("Confirmar a senha: ");
    gotoxy(45,23);gets(senhaTMP);
    while(strcmp(senhaC,senhaTMP)!=0){ //validação da senha
        system("cls");
        gotoxy(45,8);printf("As senhas não coincidem!!!");
        gotoxy(45,11);printf("Senha: ");
        gotoxy(45,12);gets(senhaC); 
        gotoxy(45,14);printf("Confirmar a senha: ");
        gotoxy(45,15);gets(senhaTMP);
    } 
    system("cls"); 
    
    //entrada de dados segunda tela
    gotoxy(45,8);printf("CADASTRO");
    gotoxy(45,10);printf("Altura: (Colocar vírgula ex: 1,80)");
    gotoxy(45,11);scanf("%f",&altura);
    fflush(stdin);
    gotoxy(45,13);printf("Peso: ");
    gotoxy(45,14);scanf("%f",&peso);
    fflush(stdin); 
    
    gotoxy(45,16);printf("Data de nascimento: ");
    do{
        gotoxy(45,17);printf("Dia: ");scanf("%d",&dia);
        fflush(stdin);
        if (dia <=0 || dia >=32){
           gotoxy(45,17);printf("Dia inválido! Digite novamente.");
           gotoxy(45,18);scanf("%d",&dia);fflush(stdin);
        }
        else{
           gotoxy(45,18);printf("                               ");
        }
    }while(dia<=0 || dia>=32);
    do{
       gotoxy(45,19);printf("Mês: ");scanf("%d",&mes);
       fflush(stdin);
       if (mes <=0 || mes >=13){
           gotoxy(45,19);printf("Mês inválido! Digite novamente.");
           gotoxy(45,20);scanf("%d",&mes);fflush(stdin);
       }
       else{
           gotoxy(45,20);printf("                               ");
       }
    }while(mes<=0 || mes>=13);
    do{
       gotoxy(45,21);printf("Ano: ");scanf("%d",&ano);
       fflush(stdin);
       if (ano <=1900 || ano >=2022){
           gotoxy(45,21);printf("Ano inválido! Digite novamente.");
           gotoxy(45,22);scanf("%d",&ano);fflush(stdin);
       }
       else{
           gotoxy(45,21);printf("                               ");
       }
    }while(ano <=1900 || ano>=2022);
    
    
    
    
    system("cls");
    int teclaposs,poss=1;
    do{ 
        textbackground(0);    
        textcolor(15);
        gotoxy(40,10);printf("Possuí alguma enfermidade?");
        gotoxy(47,12);printf("SIM");
        gotoxy(52,12);printf("NÃO");
        
        textbackground(15);
        textcolor(0);
          
        switch (poss){
            case 1:gotoxy(47,12);printf("SIM"); break;
            case 2:gotoxy(52,12);printf("NÃO"); break;
        }
        teclaposs=getch();
        
        if (teclaposs==224 || teclaposs==0)
            teclaposs=getch();
        switch (teclaposs){
            case 77:poss++; break;
            case 75:poss--; break;
        }
        if (poss==0) poss=2;
        if (poss==3) poss=1;      
    }while(teclaposs!=13);
    if(poss==1){
        textbackground(0);    
        textcolor(15);
        gotoxy(45,13);printf("Quais: ");
        gets(enfermidade);
    } 
    system("cls");
    system("color 0F");
}

//tela de login
void login (){
    system("color 0F");
    bool teste=false;
    do{
    teste_email=false; teste_senha=false;
    //entrada de dados junto com validação do email
    gotoxy(45,8);printf("LOGIN");   
    gotoxy(45,10);printf("Email: ");
    gotoxy(45,11);gets(email);
    if (strcmp(email,emailC)==0) 
       teste_email=true;
    
    //entrada de dados junto com validação da senha  
    gotoxy(45,13);printf("Senha: ");
    gotoxy(45,14);gets(senha);
    if (strcmp(senha,senhaC)==0)
       teste_senha=true;
    
    if(teste_email==true && teste_senha==true)
       teste=true;
    system("cls");
    
    //menu interativo de cadastro ou login novamente
    if (teste==false){
       gotoxy(45,8);printf("Credênciais incorretas!!!\n");
       int tecla_log,plog=1;
    do{ 
        system("color 0F");
        textbackground(0);
        textcolor(15);
        gotoxy(45,10);printf("NÃO POSSUI CADASTRO??");
        gotoxy(45,11);printf("CONTINUAR LOGIN??");
        
        textbackground(15);
        textcolor(0);
          
        switch (plog){
            case 1:gotoxy(45,10);printf("NÃO POSSUI CADASTRO??"); break;
            case 2:gotoxy(45,11);printf("CONTINUAR LOGIN??"); break;
        }
        tecla_log=getch();
        
        if (tecla_log==224 || tecla_log==0)
            tecla_log=getch();
        switch (tecla_log){
            case 72:plog--; break;
            case 80:plog++; break;
        }
        if (plog==0) plog=3;
        if (plog==4) plog=1;      
    }
    while(tecla_log!=13);
    system("cls");
    system("color 0F"); 
    if (plog==1)
        cadastro();  
    
    
    }//fechamento do if (teste==false)   
    }while(teste==false);
    t=true;
}

//primeira página do programa
void pagprincipal(){
     int teclapagp, ppag=3;
     system("cls");
     system("color 0F");  
     do{ //menu interativo
        // DICAS
        if (ppag==3){
           system("cls");
           system("color 0F");          
           textbackground(0);            
           textcolor(15);
           gotoxy(47,5);printf("DICAS");
           int sorteio_dicas=rand()%9, sorteio_dicas2=rand()%10;
           gotoxy(30,10);printf("%s",dicas[sorteio_dicas]);
           gotoxy(30,15);printf("%s",dicas[sorteio_dicas+1]);
           gotoxy(30,20);printf("%s",dicas2[sorteio_dicas2]);
           gotoxy(33,25);printf("EXERCÍCIOS");
           gotoxy(45,25);printf("NUTRIÇÃO");
           gotoxy(55,25);printf("DICAS");
           gotoxy(62,25);printf("PERFIL\n\n\n\n");
           printf("                                                                          Pressione ESC para sair...");
           textbackground(15);
           textcolor(0);
           
           switch (ppag){
                  case 1:gotoxy(33,25);printf("EXERCÍCIOS"); break;
                  case 2:gotoxy(45,25);printf("NUTRIÇÃO"); break;
                  case 3:gotoxy(55,25);printf("DICAS"); break;
                  case 4:gotoxy(62,25);printf("PERFIL"); break;
           }
           teclapagp=getch();
           
           if (teclapagp==224 || teclapagp==0)
              teclapagp=getch();
           switch (teclapagp){
              case 75:ppag--; break;
              case 77:ppag++; break;
           }
           if (ppag==0) ppag=5;
           if (ppag==6) ppag=1;
        }
        //EXERCÍCIOS
        if (ppag==1){
           system("cls");
           system("color 0F");
           textbackground(0);            
           textcolor(15);
           gotoxy(47,5);printf("EXERCÍCIOS");
           gotoxy(20,9);printf("Flexão de braço: 0/2 30s");gotoxy(55,9);printf("Agachamento na cadeira: 0/4 30s");
           gotoxy(20,12);printf("Agachamento na parede: 0/2 30s");gotoxy(55,12);printf("Prancha: 0/2 30s");
           gotoxy(20,15);printf("Abdominal: 0/2 30s");gotoxy(55,15);printf("Subir e descer escadas: 0/6 30s");
           gotoxy(20,18);printf("Pular corda: 0/4 30s");gotoxy(55,18);printf("Bicicleta imaginária: 0/2 30s");
           gotoxy(20,21);printf("Tríceps no banco: 0/2 30s");gotoxy(55,21);printf("Corrida estacionária: 0/4 30s");
           gotoxy(33,25);printf("EXERCÍCIOS");
           gotoxy(45,25);printf("NUTRIÇÃO");
           gotoxy(55,25);printf("DICAS");
           gotoxy(62,25);printf("PERFIL\n\n\n\n");
           printf("                                                                          Pressione ESC para sair...");
           textbackground(15);
           textcolor(0);
          
           switch (ppag){
                  case 1:gotoxy(33,25);printf("EXERCÍCIOS"); break;
                  case 2:gotoxy(45,25);printf("NUTRIÇÃO"); break;
                  case 3:gotoxy(55,25);printf("DICAS"); break;
                  case 4:gotoxy(62,25);printf("PERFIL"); break;
           }
           teclapagp=getch();
        
           if (teclapagp==224 || teclapagp==0)
              teclapagp=getch();
           switch (teclapagp){
              case 75:ppag--; break;
              case 77:ppag++; break;
           }
           if (ppag==0) ppag=4;
           if (ppag==5) ppag=1;
        }    
        //NUTRIÇÃO
        if (ppag==2){
           system("cls");
           system("color 0F");
           textbackground(0);            
           textcolor(15);
           gotoxy(47,5);printf("RECEITA");
           gotoxy(35,7);printf("Smoothie - Beterraba & Abacaxi");
           gotoxy(43,9);printf("Ingredientes: ");
           gotoxy(30,11);printf("- Copo de água gelada        500ml;");
           gotoxy(30,12);printf("- Cubos de gelo               4.un;");
           gotoxy(30,13);printf("- Fatias de abacaxi (picados) 2.un;");
           gotoxy(30,14);printf("- Beterraba crua (picada)      1/4;");
           gotoxy(30,15);printf("- Gengibre pequeno             1/4;");
           gotoxy(30,16);printf("- Açucar ou adoçante a gosto     ?;");
           gotoxy(41,19);printf("Modo de preparo: ");
           gotoxy(18,21);printf("Leve ao liquidificador e bata bastante! Não precisa coar, sirva-se!");
           gotoxy(33,25);printf("EXERCÍCIOS");
           gotoxy(45,25);printf("NUTRIÇÃO");
           gotoxy(55,25);printf("DICAS");
           gotoxy(62,25);printf("PERFIL\n\n\n\n");
           printf("                                                                          Pressione ESC para sair...");
        
           textbackground(15);
           textcolor(0);
          
           switch (ppag){
                  case 1:gotoxy(33,25);printf("EXERCÍCIOS"); break;
                  case 2:gotoxy(45,25);printf("NUTRIÇÃO"); break;
                  case 3:gotoxy(55,25);printf("DICAS"); break;
                  case 4:gotoxy(62,25);printf("PERFIL"); break;
           }
           teclapagp=getch();
        
           if (teclapagp==224 || teclapagp==0)
              teclapagp=getch();
           switch (teclapagp){
              case 75:ppag--; break;
              case 77:ppag++; break;
           }
           if (ppag==0) ppag=4;
           if (ppag==5) ppag=1;
        }    
        //PERFIL 
        if (ppag==4){
           system("cls");
           system("color 0F");
           textbackground(0);            
           textcolor(15);
           gotoxy(47,5);printf("PERFIL");
           gotoxy(37,8);printf("Nome de usuário: %s %s",nome,sobrenome);
           gotoxy(37,10);printf("Email: %s",email);
           gotoxy(40,12);printf("INFORMAÇÕES PESSOAIS");
           gotoxy(37,14);printf("Altura: %.2f",altura);
           gotoxy(37,16);printf("Peso: %.2f",peso);
           gotoxy(37,18);printf("IMC: %.2f",peso/(altura*altura));
           gotoxy(37,20);printf("Data de nascimento: %d/%d/%d",dia,mes,ano);
           if (strcmp(enfermidade,"")==0){
              gotoxy(37,22);printf("Enfermidades: Não possui!");}
           else{
              gotoxy(37,22);printf("Enfermidades: %s",enfermidade);}
           gotoxy(33,25);printf("EXERCÍCIOS");
           gotoxy(45,25);printf("NUTRIÇÃO");
           gotoxy(55,25);printf("DICAS");
           gotoxy(62,25);printf("PERFIL\n\n\n\n");
           printf("                                                                          Pressione ESC para sair...");
        
           textbackground(15);
           textcolor(0);
          
           switch (ppag){
                  case 1:gotoxy(33,25);printf("EXERCÍCIOS"); break;
                  case 2:gotoxy(45,25);printf("NUTRIÇÃO"); break;
                  case 3:gotoxy(55,25);printf("DICAS"); break;
                  case 4:gotoxy(62,25);printf("PERFIL"); break;
           }
           teclapagp=getch();
        
           if (teclapagp==224 || teclapagp==0)
              teclapagp=getch();
           switch (teclapagp){
              case 75:ppag--; break;
              case 77:ppag++; break;
           }
           if (ppag==0) ppag=4;
           if (ppag==5) ppag=1;
        }      
    }
    while(teclapagp!=27);
    system("cls");
    system("color 0F"); 
}
  
//Programa principal
int main (){
    
    srand(time(NULL));
    dicas_entrada();
    system("mode 100,30");
    system("color 0F");
    setlocale(LC_ALL, "Portuguese"); //Coloca linguagem em português
    //pagprincipal();
    
    while(t==false){
    inicio();
    if (p==1)
        login();
        if (t==true)
           pagprincipal();  
    if (p==2)
        cadastro();
    if (p==3)
       t=true;
    }  
    
       
    system("color 0F");
    system("PAUSE");
    return(0);
}


