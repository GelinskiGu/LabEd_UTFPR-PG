1) Hoje você será o responsável por realizar o controle das filas de um supermercado.
Nesse supermercado há dois caixas, um dedicado a atender pessoas com idade
superior a 60 anos (idade > 60) e outro para os demais clientes. Para realizar tal
controle, você deverá criar um algoritmo que seja capaz de, ao receber a idade do
cliente, o direcione para a fila correta. Por fim, imprima o número de clientes na fila com
idade superior a 60, seguido da idade do último e do primeiro cliente dessa fila,
separados por espaço. Lembre-se de quebrar a linha após o último cliente. Em
seguida, realize o mesmo processo para a outra fila. Seu programa deverá ser
encerrado ao inserir a idade 0. Caso a fila esteja vazia, imprima 0 para todas as
informações.

2) Utilizando o código anterior, após ler as filas, leia um número N indicando o
número de atendimentos que serão realizados (N >= 0). Cada vez que um
cliente é atendido (por ordem de chegada) o mesmo deverá ser removido da
fila. Utilize a seguinte regra, atenda um cliente da fila de idoso (fila de idade
superior a 60) e depois um da fila de clientes (sempre primeiro um idoso,
depois um cliente), cada atendimento irá contar para os N atendimentos. Caso
uma da fila estiver vazia, o atendimento deverá ser direcionado para a fila que
ainda contém clientes, até que a mesma se encontre vazia ou que os N
atendimentos sejam cumpridos.
Por fim, imprima os mesmos dados do primeiro exercício.

