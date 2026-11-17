# dump_o_core
Um projeto em C que visa colocar problemas de segurança de propósito no programa, como o famoso "buffer overflow" (que inclusive deu a ideia do repositório) para cativar essa determinação de encontrar problemas de lógica e explorar os erros no código tal qual aquela criança chata no banco de trás perguntando toda hora se chegou. E Cybersec também.

#Parte mais burocrática#

> Laboratório prático em C dedicado ao estudo de falhas de segurança de baixo nível, corrupção de memória e técnicas de exploração em ambiente controlado.

O **`dump_o_core`** vem com a ideia de simular sistemas aparentemente comuns — como terminais de controle de acesso, caixas eletrônicos e utilitários CLI — que escondem vulnerabilidades clássicas implementadas **propositalmente** para fins de estudo, testes de exploração (*exploitation*) e análise de código seguro.

>  **Aviso Legal:** Todo o código presente neste repositório possui falhas intencionais para fins estritamente educacionais. Nunca utilize esses padrões em sistemas de produção. Por enquanto, não tem nenhum com os problemas resolvidos.

---

##  Módulos Disponíveis

### 1. `catraca_vip` — Controle de Acesso VIP
Simulação de um terminal de autenticação de catraca. O usuário informa uma credencial na entrada e, dependendo da validação, o menu principal libera ou bloqueia o acesso à Área VIP.

* **Arquivo:** `Catraca-C.cpp` *(recomendado compilar como C99 puro)*
* **Tipo de desafio:** *Black-box* (o programa não exibe avisos de falha durante a execução).
* **Objetivo:** Conseguir acesso `VIP / ADMIN` no menu principal sem conhecer a senha correta.

<details>
  
<summary> Clique para ver a dica / spoiler da vulnerabilidade</summary>

---

##  Dependências e Compilação

O código foi escrito utilizando apenas bibliotecas padrão da linguagem C, sem necessidade de pacotes externos:

* **Bibliotecas utilizadas:** `<stdio.h>` e `<string.h>` (C Standard Library / `glibc`).
* **Compilador:** `gcc` (Linux / WSL / MinGW).

### Como compilar para o laboratório funcionar
### (Sobre Docker, mais abaixo <-- não fiz ainda)
Compiladores modernos ativam proteções de memória por padrão (como *Stack Canaries*) e bloqueiam funções obsoletas como `gets()`. Para reproduzir o comportamento vulnerável fielmente no Linux, compile desativando a proteção de stack:

```bash
gcc -x c Catraca-C.cpp -o catraca_vip -fno-stack-protector -Wno-deprecated-declarations
./catraca_vip
```
### SOBRE O DOCKER -> Ainda vou aprender a fazer ele pra você conseguir testar na sua máquina, ainda que seja contra o propósito do repositório, já que a ideia é você justamente explorar as falhas na sua IDE etc. Mas quem sabe, traduzimos os códigos em C para outra linguagem, sendo possível essa cooperação multi-linguagem.
