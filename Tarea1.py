#punto 1:

print("punto 1: \n")

mat=[[11, 23, 76, 34, 11],
     [14, 30, 92, 30, 101],
     [12, 45, 58, 92, 22],
     [74, 56, 49, 56, 100],
     [99, 5, 28, 47, 99]]

mat2 = [[1, 0, 0, 0],
        [0, 2, 0, 0], 
        [0, 0, 3, 0],
        [0, 0, 0, 4]]


def verificarDiagonales(matriz):
    lenght= len(matriz)

    for i in range(lenght):
        for j in range(lenght):
            if matriz[i][j] != 0 and i!=j:
                return False
    
    return True

print(verificarDiagonales(mat))
print(verificarDiagonales(mat2))

#punto 2

print("\npunto 2: \n")

array1=[42, 12, 90, 90, 13, 42]
array2=[50, 30, 20, 30, 50]

def esCapicua(lista):

    lenght= len(lista)

    for i in range(lenght):
        if(lista[i] != lista[(lenght-1)-i]):
            return False

    return True

print(esCapicua(array1))
print(esCapicua(array2))

#punto 3

print("\npunto 3: \n")

print("a:")

listaA = [40, 10, 22, 12, 33, 33, 33]
listaB = [41, 22, 31, 15, 13, 12, 33, 19]

def diferenciaListas(lista1, lista2):

    diferencia=[]
    for num in lista1:
        diferencia.append(num)
    #set(lista1).difference(lista2)

    for i in range(len(lista1)-1):
        for j in range(len(lista2)-1):
            if(lista1[i]==lista2[j]):
                if(lista1[i] in diferencia):
                    diferencia.remove(lista1[i])
                lista2.pop(j)
                
    return diferencia

respuesta1=diferenciaListas(listaA, listaB)
respuesta1.sort(reverse=True)
print(respuesta1)

respuesta2=diferenciaListas(listaB, listaA)
respuesta2.sort(reverse=True)
print(respuesta2)

print("\n b:")

def maximoLista(lista, maximo):
    while len(lista)>maximo:
        lista.pop()
    return lista

def armarLista():
    #largoLista=int(input())
    nums=input()
    lista=nums.split(" ")

    return lista

def impresionDatos():
    sucesiones=int(input())

    for i in range(sucesiones):

        listaBase1=armarLista()
        lista1=[]
        listaBase2=armarLista()
        lista2=[]

        for num in listaBase1:
            lista1.append(int(num))
        lista1.pop(0)

        for num in listaBase2:
            lista2.append(int(num))
        lista2.pop(0)

        #print(lista1)
        #print(lista2)

        diferencia=diferenciaListas(lista1, lista2)
        print(diferencia)


impresionDatos()

#punto 3

print("\npunto 3:\n")

def esPrimo(num):
    for i in range(2, num):
        if num%i==0:
            return False
    return True

def sumaDePrimos(primos):
    primosStr=[]
    sumaPrimos=[]
    for n in primos:
        primosStr.append(str(n))
    
    for i in primosStr:
        suma=0
        for j in i:
            suma+=int(j)

        if esPrimo(suma):
            sumaPrimos.append(i)

    return sumaPrimos
            


def mostrarPrimos(numero):
    primos=[]
    total=0
    primosSuma=[]

    if numero<2:
        return False

    for i in range(2,numero):
        if esPrimo(i):
            primos.append(i)
    
    primosSuma=sumaDePrimos(primos)

    print("Números primos entre 1 y " + str(numero) +":")

    for i in primos:
        print("-->" + str(i)+ ",")
    
    print("Números entre 1 y "+ str(numero)+ " con suma de dígitos con valor primo:")

    mensaje=""

    for i in primosSuma:
        mensaje+= str(i) + ", "
    
    print(mensaje)


mostrarPrimos(100)

            
            


