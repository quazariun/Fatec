#!/usr/bin/python3

# Autores: Eduardo H.P. Souza e Lucas Rafael Andrade Barroso
# Turma 3ºB - Análise e Desenvolvimento de Sistemas

import time

from random import seed
from random import randint

seed(1323)

#Aqui vou gerar o vetor com números randômicos, passando o tamanho do vetor que eu quero gerar.
def generate_vector(len):
  vect = []
  
  for _ in range(len+1):
    vect += [randint(0,len)]
  
  return vect

#Aqui eu defino o tempo que eu quero rodar os testes.
time_for_tests = time.time() + 30
step_integers = 0


#FUNÇÕES DE ORDENAÇÃO E FUNÇÕES DE BUSCAS USADAS PARA GERAR O GRÁFICO

def insertion_sort(vect):
  num_of_searches = 0

  for i in range(1, len(vect)): 
    key = vect[i] 
    j = i-1

    while j >=0 and key < vect[j] : 
      vect[j+1] = vect[j] 
      j -= 1
      num_of_searches += 1
    vect[j+1] = key

  return num_of_searches



print("|   Step (N)            |     Number of Searches")

while time.time() <= time_for_tests:
  step_integers += 10000
  vect = generate_vector(step_integers)

  num_of_searches = insertion_sort(vect)

  
  print("|       % d         |       %d  " %(step_integers,num_of_searches))