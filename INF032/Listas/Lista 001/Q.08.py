numero = 123
centena = (numero%1000) / 100 
dezena = (numero%100) / 10 
unidade = numero%10
numeroI = centena*100 + dezena*10 + unidade
print("Numero Invertido")
print(numeroI)
#Os números estão sendo calculados como float, eu não sei como transformá-los em inteiro(ignorar o que vêm após a vírgula), que é o que está causando o problema
