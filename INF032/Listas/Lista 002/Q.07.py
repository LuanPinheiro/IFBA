QtdFitas = int(input("Digite a Quantidade de Fitas: "))
Aluguel = float(input("Digite o Valor por Alguel: "))
FaturamentoAnual = (QtdFitas/3)*Aluguel * 12
print(f'Faturamento Anual: {FaturamentoAnual}')
Atraso = (QtdFitas/10)*(Aluguel + Aluguel*0.1)
print(f'Faturamento com Multas: {Atraso}')
QtdFinal = QtdFitas - QtdFitas*0.02 + QtdFitas*0.1
print(f'Quantidade de Fitas no Final do Ano: {QtdFinal}')
