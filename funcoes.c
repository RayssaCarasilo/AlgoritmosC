#include <stdio.h>
#include <math.h>
#include <locale.h>

float x, x1, x2, a, b, c, delta;
int opcao = 0;

int funcaoPrimeiroGrau(float a, float b)
{
    printf("=== Resolucao passo-a-passo: Equacao do Primeiro Grau ===\n");
    printf("Fórmula completa: ax + b = 0 => Fórmula simplificada: -b/a \n");
    printf("Digite o valor de a: ");
    scanf("%f", &a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);

    x = (-b) / a;

    printf("Equacao informada %.2fx %.2f = 0 \n", a, b);
    printf("Passos:\n");

    printf("%2.fx = -%.2f\n", a, b);
    printf("x = -%.2f / %.2f\n", b, a);

    x = (-b) / a;

    printf("\n resultado: \n");
    printf("x = %.2f \n", x);
}

int funcaoSegundoGrau(float a, float b, float c)
{
    printf("=== Resolucao passo-a-passo: Equacao do Segundo Grau ===\n");
    printf("Fórmula: x² + bx + c \n");
    printf("Digite o valor de a: ");
    scanf("%f", &a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);
    printf("Digite o valor de c: ");
    scanf("%f", &c);

    delta = (b * b) - (4 * a * c);

    printf("\nEquacao informada: %.2fx² + %.2fx + %.2f = 0 \n", a, b, c);
    printf("Passos 1, calcular a discriminante\n");
    printf("Delta = b² - 4ac\n");
    printf("Delta = (%.2f)² - 4 * (%.2f) * (%.2f)\n", b, a, c);
    printf("Delta = %.2f - %.2f\n", (b * b), (4 * a * c));
    printf("Delta = %.2f\n", delta);

    if (delta < 0)
    {
        printf("\nDelta é negativo, a equação não possui raízes reais.\n");
        return -1; // retorna um valor de erro para indicar que a equação não possui raízes reais
    }
    else if (delta == 0)
    {
        x = -b / (2 * a);
        printf("\nDelta é zero, a equação possui uma raiz real");
        printf("\nx = -b / (2a) = -%.2f / (2 * %.2f)", b, a);
        printf("\nResultado: x = %.2f\n", x);
    }
    else
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("\nDelta é positivo, a equação possui duas raízes reais");
        printf("\nx1 = (-b + √Delta) / (2a)");
        printf("\nSubstituindo:\n");
        printf("x1 = (-%.2f + √%.2f) / (2 * %.2f)", b, delta, a);
        printf("\nResultado: x1 = %.2f\n\n", x1);
        printf("\nPassos para calcular x2:\n");
        printf("\nx2 = (-b - √Delta) / (2a)");
        printf("\nSubstituindo:\n");
        printf("x2 = (-%.2f - √%.2f) / (2 * %.2f)", b, delta, a);
        printf("\nResultado: x2 = %.2f\n", x2);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    do
    {
        printf("\n1 - Resolver equacao de primeiro grau (mostrar passos)\n");
        printf("2 - Resolver equacao de segundo grau (mostrar passos)\n");
        printf("0 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao); // capta a escolha do usuario entre as opcoes

        switch (opcao)
        {
        case 1:
            funcaoPrimeiroGrau(a, b);
            break; // finaliza o case para que não passe ao próximo

        case 2:

            funcaoSegundoGrau(a, b, c);
            break; // finaliza o case para que não passe ao próximo

        case 0:
            break;

        default:
            printf("Opcao invalida. Tente novamente\n");
            break;
        }
    } while (opcao != 0); // repete ate o usuario escolher sair

    printf("Saindo do programa\n");
    return 0;
}