#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h> 
#include<ctype.h>
#include<time.h>

const int MAX = 1000;// quantidade de usuario 

typedef struct endereco {  // sstruct endeereço que vai dentro da struct usuario
    char rua[50];
    char cidade[50];
    char estado[50];
    char cep[50];
} endereco;

typedef struct usuario {  // typedef - cria um novo nome para um determinado tipo, otimiza a sintaxe
    char nome[50];
    char email[50]; 
    endereco endereco;
    char sexo[13]; 
    double altura;
    int id;
    bool vacinado;
} usuario;

int menuEdita(){  // função que retorna o menu editar para o usuario 
    int opcao_edita;
    do
    {
        printf("+-----------------------------------------------+\n");
        printf("|            BEM VINDO AO MENU EDITA            |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        SELECIONE O DADO DESEJA EDITAR         |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        NOME                ||        [01]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        E-MAIL              ||        [02]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        SEXO                ||        [03]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        ENDERECO            ||        [04]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        ALTURA              ||        [05]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        VACINADO            ||        [06]     |\n");
        printf("+-----------------------------------------------+\n");        
        printf("|   EDITAR TODOS OS ITENS    ||        [07]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("+-----------------------------------------------+\n");        
        printf("| RETORNAR AO MENU PRINCIPAL ||        [08]     |\n");
        printf("+-----------------------------------------------+\n");
        scanf("%i", &opcao_edita);
        system("cls");
        if(opcao_edita < 1 || opcao_edita > 8){
            printf("Opção inválida !! Digite uma opção novamente");
        }
    } while (opcao_edita < 1 || opcao_edita > 8);
         

    return opcao_edita;
}
int menuPrincipal(){ // função que rettorna o menu principal para o usuario 
    int menu;

        printf("+-----------------------------------------------+\n");
        printf("|             BEM VINDO AO MENU                 |\n");
        printf("+-----------------------------------------------+\n");
        printf("|         SELECIONE A OPCAO DESEJADA            |\n");
        printf("+-----------------------------------------------+\n");
        printf("| INCLUIR USUARIO [MAX 1000]      ||   [1]      |\n");
        printf("+-----------------------------------------------+\n");
        printf("| EDITAR DADOS DE UM USUARIO      ||   [2]      |\n");
        printf("+-----------------------------------------------+\n");
        printf("| EXCLUIR USUARIO                 ||   [3]      |\n");
        printf("+-----------------------------------------------+\n");
        printf("| BUSCAR USUARIO [PELO E-MAIL]    ||   [4]      |\n");
        printf("+-----------------------------------------------+\n");
        printf("| IMPRIMIR USUARIOS CADASTRADOS   ||   [5]      |\n");
        printf("+-----------------------------------------------+\n");
        printf("| MENU BACKUP                     ||   [6]      |\n");
        printf("+-----------------------------------------------+\n");
        printf("| SAIR DO PROGRAMA                ||   [7]      |\n");
        printf("+-----------------------------------------------+\n");
        // ESCOLHE A OPCAO DA AÇÃO DESEJADA
        scanf("%i", &menu);
        system("cls");  

        system("cls");  	

        return menu;  
}
int validarNome(char nome[]){ // char nome vai receber um vetor, que nao importa o tamanho 
     if (strlen(nome) < 2){ // função retorna o comprimento da string, nesse caso ela nao pode ter menos de 2 espaços
        printf("Nome Informado invalido, por favor Digite um nome Valido: \n");
        return 0;
     }
    return 1;
}

int validarEmail(char email[]){
    if (strchr(email, '@')==0)// funçao para localizar um caractere em uma string, nesse caso a ocorrencia do "@"
    {
        printf("Endereco E-mail fornecido sem o caracter [@], por favor, digite um Email valido:\n");
        return 0;
    }
    return 1;
}

int validarSexo(char sexo[]){
    if (strcmp(sexo, "Masculino")!=0 && strcmp(sexo, "Feminino")!=0  && strcmp(sexo, "Nao declarar")!=0)
    { // strcmp compara duas strings, quando a comparação é igual, retorna um valor 0, wuando é diferente retorna != 0
        printf("Escolha do sexo Incorreta, por favor respeite as orientacoes!\n");
        printf("         Masculino / Feminino  / Nao declarar                \n");
        return 0;
    }  
    return 1;
}

bool validaCep(char cep[]){
    if(strlen(cep)<7){
        printf("Erro !! CEP Digitado é muito curto");
        sleep(3);
        return 0;
    }
    for (int i = 0; i < strlen(cep); i++)
        if(isalpha(cep[i])){
            printf("Erro !!! O CEP só pode conter numeros");
            sleep(3);
            return 0;
        }
    return 1;    
}

bool validarEndereco(char endereco[], int tipo){ // validando os atributos do endereço 
    switch (tipo)
    {
    case 1:
        if(strlen(endereco)<3){
            printf("Nome da rua muito curto\n");
            sleep(3);
            return 0;
        }
        break;
    case 2:
        if(strlen(endereco)<3){
            printf("Nome da cidade muito curto\n");
            sleep(3);
            return 0;
        }
        break;
    case 3:
        if(strlen(endereco)<3){
            printf("Nome do estado muito curto\n");
            sleep(3);
            return 0;
        }
        break;
    case 4:
        if(!validaCep(endereco))
        return 0;
            break;
    default:
        break;
    }
    return 1;
}

endereco inserirEndereco(){
    int isValid = 0;
    endereco cadastro;
    while(!isValid){
        printf("Digite o Estado\n");
        scanf(" %[^\n]", cadastro.estado);
        system("cls");  
        isValid = validarEndereco(cadastro.estado,3);
    }
    isValid = 0;



    while(!isValid){
        printf("Digite a cidade onde mora\n");
        scanf(" %[^\n]", cadastro.cidade);
        system("cls");  
        isValid = validarEndereco(cadastro.cidade,2);
    }
    isValid = 0;



    while(!isValid){
        printf("digite a rua onde mora\n");
        scanf(" %[^\n]", cadastro.rua);
        system("cls");  
        isValid = validarEndereco(cadastro.rua, 1);
    }
    isValid = 0;
    
    
    while(!isValid){
        printf("Digite o CEP da residencia\n");
        scanf(" %[^\n]", cadastro.cep);
        system("cls");  

        isValid = validarEndereco(cadastro.cep,4);
    }
    

    return cadastro;
    
}

double inserirAltura(){
    double cadastro;
    do
    {
        scanf("%lf", &cadastro);
        system("cls");  

    if (cadastro < 1 || cadastro > 2)
    {
        printf("+----------------------------------------------------+\n");
        printf("|Limite de altura!, por favor respeite as orientacoes|\n");
        printf("|             [Max 2 Metro/ Min 1 Metro]             |\n");
        printf("|             Digite a altura novamente:             |\n");
        printf("+----------------------------------------------------+\n");
    }
    } while (cadastro < 1 || cadastro > 2);
    return cadastro;
    
}

bool inserirVacina(){ 
    char vacina;
    printf("Usuario ja foi Vacinado? [S/N] \n");//Valida Vacinacao
    do
    {
        scanf("%1s", &vacina);
        system("cls");  

    if (vacina != 'S' && vacina != 'N')
        {
        printf("Digite apenas os caracteres [S/N]\n");
        printf(" Informe a vacinacao Novamente: \n");
        }
    } while (vacina != 'S' && vacina != 'N');

    return vacina=='S'?1:0; // operador ternario  - if else simplificado - vacina=='S' CONDIÇÃO ? se -if verdadeiro, return 1 se não(else) return 0 
}

usuario inserirUsuario(int id){ // cadastra usuario e retorna 
    usuario cadastro;
    /* FUNÇÃO PARA GERAR ID ALEATORIO */
    srand(time(0));  
    if (id == -1)// verifica se o id -1, significa que estou criando um usuario
        cadastro.id = rand() % 1000;
    else 
        cadastro.id = id;
    int isValid = 0; // começa como falso 
        printf("Digite o nome do usuario ID [%i]: \n", cadastro.id);//nome e validacao
    while(!isValid){
        scanf(" %[^\n]", cadastro.nome);
        system("cls");  

        isValid = validarNome(cadastro.nome);// se o nome tiver certo ele retorna 1 
    }


    isValid = 0;                      
    printf("Digite o E-mail do usuario ID [%i]: \n", cadastro.id);// Valida Email
    while(!isValid){
        scanf("%s", cadastro.email);
        system("cls");  

        isValid = validarEmail(cadastro.email); // se o dado tiver certo ele sa, se nao ele repete o laço 
    }


    isValid = 0;
    printf("+---------------------------------------+\n");
    printf("|       Digite o sexo por extenso       |\n");
    printf("|  Masculino / Feminino  /Nao declarar  |\n");
    printf("+---------------------------------------+\n");
    printf("Digite o Sexo do usuario ID [%i]: \n", cadastro.id);

    while(!isValid){
        scanf(" %[^\n]", cadastro.sexo);
        system("cls");  
        isValid = validarSexo(cadastro.sexo);
    }
    isValid = 0;
    
    printf("Digite o endereco do usuario ID [%i]: \n", cadastro.id);//nome e validacao
    cadastro.endereco = inserirEndereco();
    
    printf("Digite a altura do usuario ID [%i]\n", cadastro.id);//Altura

    cadastro.altura = inserirAltura();
    isValid = 0;

    cadastro.vacinado = inserirVacina(); 
 
    return cadastro;    // durante toda a função ele le os dados que precisa, vai montandop a struct e no final retorna a struct atualizada           
}

int escolheQuantidadeCadastro(int totalCadastro){ // valida quantos cadastrros o usuario quer cadastrar e verifica se pode ser feito ou nao 
    int qtd;
    printf("Digite a quantidade de usuarios que deseja cadastrar [MAX: %d]:\n", MAX-totalCadastro);

    do
    {
    scanf("%d", &qtd);
    system("cls");  

    if(qtd < 1 || qtd > MAX)
        printf("Limite de usuarios exedido, digite novamente:\n");
    
    } while (qtd < 1 || qtd > MAX-totalCadastro);

    return qtd;
}

void printVacina(bool vacina){
    char msg[20];
    if(vacina)
        strcpy(msg, "VACINADO");
    else 
        strcpy(msg, "NÃO VACINADO");

    printf("+--------------------------------+\n");
    printf("|          USUARIO %s            |\n", msg);
    printf("+--------------------------------+\n");
}

void printEndereco(endereco endereco){

    printf("+---------------------------------+\n");
    printf("|           ENDERECO              |\n");
    printf("+---------------------------------+\n");
    printf("|CEP: %s                          |\n", endereco.cep);
    printf("|ESTADO: %s                       |\n", endereco.estado);
    printf("|CIDADE: %s                       |\n", endereco.cidade);
    printf("|RUA: %s                          |\n", endereco.rua);
    printf("+---------------------------------+\n");

}
void printaUsuario(usuario usuario){ // funçaõ para printar dados de usuario 
        printf("\nId: %d\n", usuario.id);
        printf("Nome: %s\n", usuario.nome);
        printf("Email: %s\n", usuario.email);
        printf("Sexo: %s\n", usuario.sexo);
        printEndereco(usuario.endereco);
        printf("Altura: %.2lf\n", usuario.altura);
        printVacina(usuario.vacinado);
}
void apresentarDados(int qtd, usuario  cadastros[]){
    if (qtd > 0) 
        for (int i = 0; i < qtd; i++)
            printaUsuario(cadastros[i]);
    else
        printf("NENHUM USUÁRIO CADASTRADO NO SISTEMA\n");
    sleep(5);
    system("cls");

}
void buscaPorEmail(int qtd, usuario cadastros[]){
    char email_busca[50];
    int exists=-1, isValid=0;
    printf("Digite o E-mail do usuario para realizar a busca: \n");//Email
                while(!isValid){
                    scanf("%s",email_busca);
                    system("cls");  
                    isValid = validarEmail(email_busca); 
                }
                
                for (int i = 0; i < qtd; i++)
                    if (strcmp(email_busca, cadastros[i].email)==0){ // caso sejam iguais 
                        exists = i; // passsa a ter a posição que eu achar o email 
                        break;
                    }
                
                    if(exists!=-1){ // depois que achou o email os dados do da posição salva no id são pritados tambem 
                        printaUsuario(cadastros[exists]);
                        printf("\n\n");
                        exists=-1; 
                    }else 
                        printf("cadastro não encontrado");
                    sleep(5);
                    system("cls");
 
}
int searchID(usuario cadastros[], int qtd){ // recebe um array de cadastro e int qtdd
    int id, exists;
    printf("digite um ID: \n");
    scanf("%d", &id);// valor do id desejado 
    system("cls");  
    for ( int i = 0; i < qtd; i++)// procura para ver se existe id cadastro 
    {
        if(id == cadastros[i].id)// retorna posição do id se encontrado 
            return i;
    }
    
    return -1;
}
int main(){
    int menu, totalCadastro = 0 , qtdCadastro, exists = 0, searchId, opcao, qtdCadastroBackup, opcaoMenuEdita;
    int isValid; // cariavell que valida os campos, se verdadeiro valido
    usuario cadastros[MAX]; // recebe ate 1000
    usuario backup_cadastros[MAX];

    do
    {
        menu = menuPrincipal(); // printa o menu 

        switch (menu)
        {
        case 1: 
            qtdCadastro = escolheQuantidadeCadastro(totalCadastro);
            for (int i = 0; i < qtdCadastro; i++)
            {
                cadastros[totalCadastro] = inserirUsuario(-1);
                totalCadastro++;
            }
            break;
        case 2: // EDITAR
        do {
            searchId = searchID(cadastros, qtdCadastro); 
        } while(searchId == -1);// caso ele nao encontre ele repete tudo ate achar um id que exista 
        opcaoMenuEdita = menuEdita();// printa menu e usuario escolhe a opção

        switch (opcaoMenuEdita)
        {
        case 1:
        isValid = 0;
        printf("Digite o nome do usuario ID [%i]: \n", cadastros[searchId].id);//// marca a posição do vetor de id 
        while(!isValid){ // sempre que isValid = false ou não valido repete 
        scanf(" %[^\n]", cadastros[searchId].nome);
        system("cls");  

        isValid = validarNome(cadastros[searchId].nome);
        }
        break;
        case 2:
            isValid = 0;                      
            printf("Digite o E-mail do usuario ID [%i]: \n", cadastros[searchId].id);// Valida Email
            while(!isValid){
            scanf("%s", cadastros[searchId].email);
            system("cls");  

            isValid = validarEmail(cadastros[searchId].email);
    }
            break;
        case 3:
            isValid = 0;
            printf("+---------------------------------------+\n");
            printf("|       Digite o sexo por extenso       |\n");
            printf("|  Masculino / Feminino  /Nao declarar  |\n");
            printf("+---------------------------------------+\n");
            printf("Digite o Sexo do usuario ID [%i]: \n", cadastros[searchId].id);
            while(!isValid){
                scanf(" %[^\n]", cadastros[searchId].sexo);
                system("cls");  
                isValid = validarSexo(cadastros[searchId].sexo);
            }
            break;
        case 4:
            isValid = 0;
        
            printf("Digite o endereco do usuario ID [%i]: \n", cadastros[searchId].id);//nome e validacao
            cadastros[searchId].endereco = inserirEndereco();
            break;
        case 5:
            printf("Digite a altura do usuario ID [%i]\n", cadastros[searchId].id);//Altura
            cadastros[searchId].altura = inserirAltura();
            break;
        case 6:
            isValid = 0;
            cadastros[searchId].vacinado = inserirVacina(); 
            break;
        case 7:
            cadastros[searchId] = inserirUsuario(cadastros[searchId].id);
            break;
        case 8:
            printf("\n## Retornando ao [MENU PRINCIPAL] ##\n");
            system("cls");
            break;
        }
        break; 
        case 3: 
        exists = searchID(cadastros, qtdCadastro); // faz toda a validação se id existe ou não 
            if(exists != -1){     // caso o id exista 
            for ( int i = exists; i < qtdCadastro+1; i++) // vai jogando a posição para array para o final, ate que ele seja excluido 
                cadastros[i] = cadastros[i+1];
                printf("Exluido com sucesso !");
                qtdCadastro --;

            }
            else {
                printf("Não existe pessoa cadastrada com este ID");
            } 
            sleep(5);
            system("cls");
            break;
            break;
        case 4:
            buscaPorEmail(qtdCadastro, cadastros);  // funçao para buscar a partir do email 
            break;
        case 5:
            apresentarDados(qtdCadastro, cadastros);
            break;
        case 6:
            printf("Escolha o que deseja ser feito:\n[1] Realizar backup [2]Mostrar ultimo backup: \n");
        do
        {
            scanf("%d", &opcao);
            system("cls");  

            switch (opcao)
            {
                case 1: // realiza backup
                    qtdCadastroBackup = qtdCadastro;
                    for (int i = 0; i < qtdCadastro; i++)
                        backup_cadastros[i] = cadastros[i];
                    printf("Backup realizado com sucesso\n");
                    break;
                case 2: // mostra o backup mais atual
                    printf("+--------------------------------+\n");
                    printf("|      BACKUP DE CADASTROS       |\n");
                    printf("+--------------------------------+\n");
                    for (int i = 0; i < qtdCadastroBackup; i++)
                        printaUsuario(backup_cadastros[i]);
                    break;
                    default:
                        printf("Selecione uma opção valida: [1 ou 2]\n"); 
                        break;       
            }
            sleep(5);
            system("cls");
            
              
        } while (opcao != 1 && opcao != 2);
        break; 
    
     case 7: // PROGRAMA ENCERRADO 
        printf("O programa encerrou\n");
        sleep(5);

        break;
    default:
        printf("Opção invalida\n");
        sleep(5);

        break;  
        }
    } while (menu!=7);
}