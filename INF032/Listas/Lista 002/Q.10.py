Texto = "Python é muito legal"
Palavra1 = Texto[:6]
Palavra2 = Texto[7]
Palavra3 = Texto[9:14]
Palavra4 = Texto[15:20]
TamanhoFrase = len(Palavra1) + len(Palavra2) + len(Palavra3) + len(Palavra4)
print(Texto)
print(f'O Tamanho da Frase é: {TamanhoFrase}')
print(f'O Tamanho da Palavra 1 é: {len(Palavra1)}')
print(f'O Tamanho da Palavra 2 é: {len(Palavra2)}')
print(f'O Tamanho da Palavra 3 é: {len(Palavra3)}')
print(f'O Tamanho da Palavra 4 é: {len(Palavra4)}')
