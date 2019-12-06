TempoViagem = int(input("Digite o Tempo Gasto na Viagem(Em Horas): "))
VelocidadeMedia = int(input("Digite a Velocidade Média: "))
Distancia = VelocidadeMedia*TempoViagem
LitrosGastos = Distancia / 12
print(f'Velocidade Média: {VelocidadeMedia} Distância:{Distancia} Tempo:{TempoViagem}')
print("Quantidade de Litros Gastos:")
print(LitrosGastos)



