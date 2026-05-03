# 🗑️ Removendo Ilhas de Lixo

Primeiro Exercício-Programa (EP1) da disciplina **ACH2002 – Introdução à Análise de Algoritmos**  
Escola de Artes, Ciências e Humanidades – EACH/USP | 2º Semestre de 2025

---

## 📖 Sobre o Projeto

Programa em C que analisa dados de varredura de drones sobre oceanos para identificar e categorizar **ilhas de lixo**. A partir de uma matriz onde cada célula representa a altura do lixo acumulado (em m²), o programa:

1. **Identifica** quantas ilhas de lixo distintas existem na região
2. **Calcula** a profundidade necessária de contêiner para transportar cada ilha
3. **Determina** uma combinação de ilhas que preencha exatamente um contêiner de profundidade dada

---

## 🚀 Como Compilar e Executar

```bash
gcc 17017390.c -o EP1 -lm
./EP1 <profundidade_container> <linhas> <colunas> <arquivo.txt>
```

**Exemplo:**
```bash
./EP1 4 3 4 teste1.txt
```

---

## 📥 Formato de Entrada

- **Argumento 1:** Profundidade total do contêiner (inteiro)
- **Argumento 2:** Número de linhas da matriz
- **Argumento 3:** Número de colunas da matriz
- **Argumento 4:** Arquivo `.txt` com a matriz (valores separados por espaço, `0` = mar)

---

## 📤 Formato de Saída

```
<número de ilhas>
<profundidade de cada ilha separada por espaço>
<combinação de profundidades que soma exatamente o contêiner>
```

Se não houver combinação válida:
```
Nao ha resposta valida!
```

---

## 🧪 Exemplos de Teste

### Teste 1 — `./EP1 4 3 4 teste1.txt`
```
Entrada (teste1.txt):
2 3 0 1
1 0 0 2
0 0 12 0

Saída:
3
1 1 2
2 1 1
```

### Teste 2 — `./EP1 10 3 3 teste2.txt`
```
Entrada (teste2.txt):
5 5 0
0 4 0
0 0 9

Saída:
2
2 1
Nao ha resposta valida!
```

---

## ⚙️ Algoritmos Utilizados

- **DFS (Busca em Profundidade):** para identificar e rotular ilhas conectadas na matriz
- **Backtracking (Subset Sum):** para encontrar combinação de ilhas que preencha exatamente o contêiner
- **Arredondamento customizado:** profundidade decimal truncada para inteiro, exceto valores entre 0 e 1 que são arredondados para 1

---

## 📐 Fórmula de Profundidade

```
Profundidade = soma das alturas das células da ilha / 6
```

O denominador 6 vem da base do contêiner: **2m × 3m = 6 m²**

---

## 🗂️ Estrutura do Repositório

```
.
├── 17017390.c      # Código-fonte principal
├── teste1.txt      # Caso de teste 1
├── teste2.txt      # Caso de teste 2
├── teste3.txt      # Caso de teste 3
├── teste4.txt      # Caso de teste 4
└── README.md
```

---

## 👤 Autor

**Otávio Martins**  
Número USP: 17017390  
EACH – Universidade de São Paulo
