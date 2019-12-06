dimensao1 = 15
dimensao2 = 10
dimensao3 = 13
VolumePote = (dimensao1 * dimensao2 + dimensao3)*74 / 100
bolinhaRaio = 1.2
volumeBolinha = (4 * 3 * 3.14 * bolinhaRaio**3)/3 #fórmula do volume da esfera
quantidadeBolinhas = VolumePote / volumeBolinha
print("Quantidade de bolinhas de queijo em um pote de sorvete de 2L:")
print(quantidadeBolinhas)
