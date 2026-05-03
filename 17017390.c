#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int linhas, colunas, container;
int total_ilhas = 0;

int *matriz, *mapa, *visitado;
int *prof_ilhas, *comb_final;
int achou = 0, tam_comb = 0;

void ler_entrada(int argc, char *argv[]);
void ler_arquivo(char *nome);
void combina();
void liberar();
void dfs(int pos, int id);
void calc_profundidades();
void marcar_ilhas();
void busca(int idx, int soma, int *temp, int tam);
int arred(double v);

int main(int argc, char *argv[])
{
    ler_entrada(argc, argv);
    marcar_ilhas();

    printf("%d\n", total_ilhas);

    if (total_ilhas > 0)
    {
        calc_profundidades();
        for (int i = 0; i < total_ilhas; i++)
        {
            printf("%d%s", prof_ilhas[i], (i == total_ilhas - 1) ? "" : " ");
        }
        printf("\n");
        combina();
    }
    else
    {
        printf("\nNao ha resposta valida!\n");
    }

    liberar();
    return 0;
}

void ler_entrada(int argc, char *argv[])
{
    if (argc != 5)
    {
        fprintf(stderr, "Uso: %s <Profundidade> <Linhas> <Colunas> <Arquivo>\n", argv[0]);
        exit(1);
    }

    container = atoi(argv[1]);
    linhas = atoi(argv[2]);
    colunas = atoi(argv[3]);
    ler_arquivo(argv[4]);
}

void ler_arquivo(char *nome)
{
    int n = linhas * colunas;
    matriz = malloc(n * sizeof(int));
    mapa = malloc(n * sizeof(int));
    visitado = malloc(n * sizeof(int));

    if (!matriz || !mapa || !visitado)
    {
        fprintf(stderr, "Erro de memoria.\n");
        exit(1);
    }

    FILE *f = fopen(nome, "r");
    if (!f)
    {
        fprintf(stderr, "Erro ao abrir arquivo.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &matriz[i]);
        mapa[i] = 0;
        visitado[i] = 0;
    }
    fclose(f);
}

void marcar_ilhas()
{
    int n = linhas * colunas;
    for (int i = 0; i < n; i++)
    {
        if (matriz[i] > 0 && visitado[i] == 0)
        {
            total_ilhas++;
            dfs(i, total_ilhas);
        }
    }
}

void dfs(int pos, int id)
{
    if (pos < 0 || pos >= linhas * colunas)
        return;
    if (matriz[pos] == 0 || visitado[pos])
        return;

    visitado[pos] = 1;
    mapa[pos] = id;

    int r = pos / colunas, c = pos % colunas;

    if (r > 0)
        dfs(pos - colunas, id);
    if (r < linhas - 1)
        dfs(pos + colunas, id);
    if (c > 0)
        dfs(pos - 1, id);
    if (c < colunas - 1)
        dfs(pos + 1, id);
}

void calc_profundidades()
{
    prof_ilhas = calloc(total_ilhas, sizeof(int));
    if (!prof_ilhas)
    {
        fprintf(stderr, "Erro de memoria.\n");
        exit(1);
    }

    for (int i = 0; i < linhas * colunas; i++)
    {
        int id = mapa[i];
        if (id != 0)
            prof_ilhas[id - 1] += matriz[i];
    }

    for (int i = 0; i < total_ilhas; i++)
    {
        double p = (double)prof_ilhas[i] / 6.0;
        prof_ilhas[i] = arred(p);
    }
}

int arred(double v)
{
    if (v <= 0.0)
        return 0;
    if (v < 1.0)
        return 1;
    return (int)v;
}

void combina()
{
    int *temp = malloc(total_ilhas * sizeof(int));
    comb_final = malloc(total_ilhas * sizeof(int));

    if (!temp || !comb_final)
    {
        fprintf(stderr, "Erro de memoria.\n");
        exit(1);
    }

    busca(0, 0, temp, 0);

    if (achou)
    {
        for (int i = 0; i < tam_comb; i++)
        {
            printf("%d%s", comb_final[i], (i == tam_comb - 1) ? "" : " ");
        }
        printf("\n");
    }
    else
    {
        printf("Nao ha resposta valida!\n");
    }

    free(temp);
}

void busca(int idx, int soma, int *temp, int tam)
{
    if (achou)
        return;
    if (soma == container)
    {
        achou = 1;
        tam_comb = tam;
        for (int i = 0; i < tam; i++)
            comb_final[i] = temp[i];
        return;
    }
    if (soma > container || idx >= total_ilhas)
        return;

    temp[tam] = prof_ilhas[idx];
    busca(idx + 1, soma + prof_ilhas[idx], temp, tam + 1);

    if (!achou)
        busca(idx + 1, soma, temp, tam);
}

void liberar()
{
    free(matriz);
    free(mapa);
    free(visitado);
    free(prof_ilhas);
    free(comb_final);
}