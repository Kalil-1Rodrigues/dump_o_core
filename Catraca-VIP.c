/*
 * Sistema de Controle de Acesso - Catraca VIP
 * Terminal de verificacao de credenciais e liberacao de acesso.
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char password[16];
    int  nivel_acesso; // 0 = usuario padrao | 1 = VIP/ADMIN
} sessao_t;

static void exibir_banner(void) {
    printf("==================================\n");
    printf("   CATRACA VIP - CONTROLE DE ACESSO\n");
    printf("==================================\n");
}

static void realizar_login(sessao_t *sessao, const char *senha_real) {
    printf("\nBem-vindo ao terminal de acesso.\n");
    printf("Digite a senha para liberar a catraca: ");
    fflush(stdout);

    // Leitura da senha digitada pelo usuario
    gets(sessao->password);

    // Validacao das credenciais
    if (strcmp(sessao->password, senha_real) == 0) {
        sessao->nivel_acesso = 1;
        printf("\n[OK] Senha correta. Catraca liberada (nivel VIP).\n");
    } else {
        printf("\n[NEGADO] Senha incorreta. Acesso padrao (sem VIP).\n");
    }
}

int main(void) {
    // Declaracao de variaveis e configuracao inicial da sessao
    sessao_t sessao;
    const char *senha_real = "SenhaSegura123";
    int opcao;

    sessao.nivel_acesso = 0; // Inicia todos os usuarios sem privilegio VIP

    // Etapa 1: Apresentacao do sistema e autenticacao
    exibir_banner();
    realizar_login(&sessao, senha_real);

    // Etapa 2: Loop principal do menu interativo da catraca
    do {
        // Exibicao do cabecalho e opcoes disponiveis
        printf("\n==================================\n");
        printf("   MENU DA CATRACA\n");
        printf("   Nivel atual: %s\n",
               sessao.nivel_acesso != 0 ? "VIP / ADMIN" : "PADRAO");
        printf("==================================\n");
        printf("1 - Ver meu nivel de acesso\n");
        printf("2 - Tentar entrar na Area VIP\n");
        printf("0 - Sair do sistema\n");
        printf("Escolha uma opcao: ");

        // Leitura e verificacao de entrada numerica do menu
        if (scanf("%d", &opcao) != 1) {
            printf("\nErro: Entrada invalida. Encerrando programa.\n");
            break;
        }

        // Processamento da acao selecionada pelo usuario
        switch (opcao) {
            case 1: // Consulta de status da sessao
                printf("\nSeu nivel de acesso atual e: %s\n",
                       sessao.nivel_acesso != 0 ? "VIP / ADMIN" : "PADRAO");
                break;

            case 2: // Verificacao de permissao para passagem na catraca
                if (sessao.nivel_acesso != 0) {
                    printf("\n[CATRACA LIBERADA] Bem-vindo a Area VIP!\n");
                } else {
                    printf("\n[CATRACA BLOQUEADA] Acesso negado. Area\n");
                    printf("restrita a usuarios VIP/ADMIN.\n");
                }
                break;

            case 0: // Encerramento normal do terminal
                printf("\nObrigado por utilizar o terminal de acesso. Ate logo!\n\n");
                break;

            default: // Tratamento de opcoes fora do intervalo esperado
                printf("\nOpcao invalida. Escolha 1, 2 ou 0.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
