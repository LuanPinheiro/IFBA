Emprestimo = float(input("Digite o Valor do Empréstimo: "))
TaxaJuros = float(input("Digite a Taxa de Juros: "))
QtdMeses = int(input("Digite a Quantidade de Meses: "))
TaxaJuros = TaxaJuros/100
Juros = Emprestimo * TaxaJuros * QtdMeses
Montante = Emprestimo + Juros
print(f'Valor da Prestação: {Montante/QtdMeses}')
