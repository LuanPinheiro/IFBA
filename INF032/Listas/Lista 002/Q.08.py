NumeroConta = input("Digite o Número da Conta Corrente(3 Dígitos): ")
NumeroContaI = NumeroConta[::-1]
Verificador = int(NumeroConta) + int(NumeroContaI)
Verificador = int(Verificador % 1000 / 100) * 1 + int(Verificador % 100 / 10) * 2 + int(Verificador % 10) * 3
##Verificador = int(Verificador % 10)
print(f'O Dígito Verificador é:{Verificador%10}')
