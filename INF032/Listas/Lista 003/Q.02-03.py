Frutas=["Maçã","Melancia","Morango"]
Docinhos=["Brigadeiro","Beijinho"]
Feijoada=["Feijão","Mocotó","Bacon"]

Listona = [Frutas] + [Docinhos] + [Feijoada] #Lista com 3 Listas
print(Listona[1][0]) #Acessando o elemento Brigadeiro

Listona[1].append(Listona[1][0]) #Adicionando Brigadeiro na lista Docinhos

Listona.append("Bebidas") #Acrescentado Bebidas no final da lista
print(Listona)

#Questão 3
print("QUESTÃO 3:")
del Listona[:]
print(Listona)
