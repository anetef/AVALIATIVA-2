/*Com a proposta para ampliação da terceirização da mão de obra, o Ministério da Fazenda está empenhado 
em elaborar uma análise sobre o recebimento de salário regular através do registro em carteira profissional dos 
funcionários no país.
Assim, elabore um algoritmo que obtenha, para cada assalariado, com carteira profissional assinada, 
o seu sexo M(masculino) e F(feminino) e o valor de seu salário,
devendo este salário ser maior que um real (R$1,00). Seu algoritmo deverá analisar e classificar este assalariado em Acima, 
Igual ou Abaixo do salário mínimo.
Sabe-se que o salário mínimo nacional é de R$ 1400,00.

Após a leitura dos dados de cada assalariado cadastrado pelo ministério deverá ser apresentado o seu salário em reais,
a classificação por extenso em relação ao salário mínimo e o sexo por extenso (Masculino ou Feminino).
A classificação em relação ao salário mínimo nacional deverá ser feita pelo sub-algoritmo classificaSalario e os 
resultados solicitados para cada assalariado deverão ser apresentados pelo sub-algoritmo denominado mostraClassifica.

Você deverá fazer a entrada de dados para todos os assalariados que foram pesquisados pelo ministério,
lembrando de fazer sempre a validação de todos os dados informados em sub-algoritmos específicos.
Na solução deste problema os resultados finais de cada assalariado que participou desta pesquisa deverão ser apresentados.
Após a leitura dos dados de todos os assalariados pesquisados o seu algoritmo deverá apresentar
a quantidade de assalariados com salário abaixo do salário mínimo e a quantidade assalariados com salário acima do 
salário mínimo*/
#include <stdio.h>

typedef enum{
    MASCULINO,
    FEMININO
} Sexo;

typedef struct{
    char nome[20];
    Sexo sexo;
    float salario;
} Assalariado;

void classificaSalario(float salario){
    if (salario > 1400){
        printf("Acima do salario minimo\n");
    } else if (salario == 1400){
        printf("Igual ao salario minimo\n");
    } else{
        printf("Abaixo do salario minimo\n");
    }
}

float validarSalario(){
    float salario;
    do{
        printf("Informe o salario em reais: ");
        scanf("%f", &salario);
        if (salario > 1.0){
            return salario;
        } else {
            printf("salario invalido! tente novamente\n");
        }
    } while (1);
}

Sexo validarSexo(){
    char sexo;
    do{
        printf("Informe o genero (M ou F): ");
        scanf(" %c", &sexo);
        if (sexo == 'M'){
            return MASCULINO;
        } else if (sexo == 'F'){
            return FEMININO;
        } else {
            printf("Opcao invalida, tente novamente!\n");
        }
    } while (1);
}

void cadastro(Assalariado *funcionarios){
    printf("Informe o nome:");
    scanf("%s", funcionarios->nome);

    funcionarios->sexo = validarSexo();
    funcionarios->salario = validarSalario();
}

void mostraClassifica(Assalariado *funcionarios){
    printf("\nNome: %s\n", funcionarios->nome);
    printf("Salario: %.2f\n", funcionarios->salario);
    printf("Classificacao em relacao ao salario minimo: ");
    classificaSalario(funcionarios->salario);
    printf("Genero: %s\n", (funcionarios->sexo == MASCULINO) ? "Masculino" : "Feminino");
}

int main(){
    int abaixoSalarioM = 0, acimaSalarioM = 0;
    #define TAM 50
    Assalariado funcionarios[TAM];

    for (int i = 0; i < TAM; i++){
        printf("\nAssalariados %d\n", i + 1);
        cadastro(&funcionarios[i]);
        mostraClassifica(&funcionarios[i]);

        if (funcionarios[i].salario > 1400){
            acimaSalarioM++;
        } else {
            abaixoSalarioM++;
        }
    }
    printf("\nQuantidade de assalariados abaixo do salario minimo: %d\n", abaixoSalarioM);
    printf("Quantidade de assalariados acima do salario minimo: %d\n", acimaSalarioM);
}