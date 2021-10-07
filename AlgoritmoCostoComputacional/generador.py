import random
import sys
def salvarArquivo():
    elementos = []
    num_elementos=6
    for x in range(num_elementos):
        tmp = random.randint(0, num_elementos)
        elementos.append(tmp)
        
    #filename = "n"+str(size) + ordenacao
    with open("inputs/"+"nombre", 'w') as f:
        for item in elementos:
            f.write("%s " % item)
            
salvarArquivo()
