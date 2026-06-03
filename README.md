# grafos
 
Matheus Lara Leriano
Mariano 
Estrutura de dados aplicada - UP

# Grafos no Mundo Real — Mapa do Campus Universidade Positivo

## Problema escolhido

Modelagem do campus da Universidade Positivo (Curitiba) como um grafo, onde cada local do campus é um vértice e os caminhos entre eles são as arestas.



## Representação

| Elemento | Representa |
|----------|-----------|
| Vértice  | Um local do campus (bloco, biblioteca, ponto de ônibus, etc.) |
| Aresta   | Um caminho direto entre dois locais |

## Locais modelados (vértices)

| ID | Local |
|----|-------|
| 0  | Entrada |
| 1  | Teatro Positivo |
| 2  | Ponto de Ônibus Oeste |
| 3  | Bloco Marrom |
| 4  | Pós-Graduação |
| 5  | Reitoria |
| 6  | Biblioteca |
| 7  | Eixo de Vivência |
| 8  | Bloco Azul |
| 9  | Bloco Amarelo / Praça de Alimentação |
| 10 | Bloco Vermelho |
| 11 | Ponto de Ônibus Central |
| 12 | Clínica de Fisioterapia |
| 13 | Centro Esportivo |
| 14 | Bloco Bege |
| 15 | Colégio Positivo Internacional |
| 16 | Bosque Eng. Civil |
| 17 | Bosque Eng. Mecânica |
| 18 | Ponto de Ônibus Leste |
| 19 | Biotério |


Funções implementadas:

- `inicializarGrafo` — prepara o grafo para uso
- `adicionarVertice` — cadastra um local pelo nome
- `adicionarAresta` — cria uma conexão bidirecional entre dois locais
- `exibirGrafo` — imprime todos os locais e suas conexões
- `consultarConexoes` — mostra os caminhos disponíveis a partir de um local
- `liberarGrafo` — libera a memória alocada
- Implementar BFS para encontrar o caminho com menos paradas entre dois pontos
- Implementar DFS para verificar se todos os locais estão conectados
- Adicionar um menu interativo para o usuário consultar rotas em tempo real
