from time import time
from random import randint


class Analisador:
    """Clase creada para obtener los tiempos de ejecución
     de los siguientes algoritmos de clasificación:
    1.Built-in Python
    2.Quicksort
    3.Mergesort
    4.Seleccion
    ...
    """
    _tempo_total = 0
    _resultados = {
        'nativo': {},
        'quicksort': {},
        'mergesort': {},
        'seleccion': {},
        'insertion': {},
        'bubble': {},
        'shellsort':{},
        'heapsort':{}
       
    }


    # 
    def __init__(self, inicio: int = 2000, fim: int = 100000,
                 paso: int = 100, intervalo: tuple = (0, 200000)):
        """Sirve para iniciar el proceso de obtención de los tiempos de ejecución de cada algoritmo
         : param start: int, número inicial de elementos aleatorios en la lista, por defecto 2000
         : param end: int, número final de elementos aleatorios en la lista, por defecto 22000
         : param step: int, número de elementos incrementados en cada prueba, por defecto 2000
         : rango de parámetros: tupla, rango de números aleatorios, patrón (0, 20000)
        """
        inicio_exec = time()
        algoritmos = {
            'nativo': self._nativo,
            'quicksort': self._quicksort,
            'mergesort': self._mergesort,
            'seleccion': self._seleccion,
            'insertion': self._insertion,
            'bubble': self._bubble,
            'shellsort':self._shellsort
            #'heapsort':self._heapsort
           
        }
        for muestra in range(inicio, fim + 1, paso):
            array = [randint(intervalo[0], intervalo[1]) for a in range(muestra)]
            for nome_algo, algoritmo in algoritmos.items():
                self._temporizador(nome_algo, algoritmo, array, muestra)
        self._tempo_total = time() - inicio_exec
        print(f'tiempo total de ejecución: {self._tempo_total:.2f}s\n')

    def resultado(self) -> dict:
        """Sirve para devolver un diccionario con los datos de tiempo de
         ejecución de cada algoritmo en cada caso de prueba
         : return: dict, datos en tiempo de ejecución para cada algoritmo
        """
        return self._resultados

    @staticmethod
    def _temporizador(nome_algo: str, algoritmo, array: list, muestra: int) -> None:
        """Sirve para registrar el tiempo que tarda un algoritmo de clasificación en ejecutarse y clasificar una lista determinada.
         : param algo_nombre: str, nombre del algoritmo
         : algoritmo param: función, algoritmo a ejecutar
         : param array: lista, lista de elementos a ordenar
         : param sample: int, número de elementos de la lista
         : return: Ninguno
        """
        inicio_exec_algo = time()
        algoritmo(array)
        Analisador._resultados[nome_algo][muestra] = round(time() - inicio_exec_algo, 3)

    @staticmethod
    def _nativo(array: list) -> list:
        """Algoritmo de clasificación de Python incorporado, utilizado para ordenar listas
         : param array: lista, lista de elementos a ordenar
         : return: lista, lista de elementos ordenados
        """
        return sorted(array)

    @staticmethod
    def _quicksort(array: list) -> list:
        """Algoritmo de clasificación Quicksort, utilizado para ordenar listas
         : param array: lista, lista de elementos a ordenar
         : return: lista, lista de elementos ordenados
        """
        if len(array) <= 1:
            return array
        m = array[0]
        return Analisador._quicksort(
            [x for x in array if x < m]) + \
            [x for x in array if x == m] + \
            Analisador._quicksort([x for x in array if x > m])

    @staticmethod
    def _seleccion(array: list) -> list:
        """Selección de algoritmo de clasificación, utilizado para ordenar listas
         : param array: lista, lista de elementos a ordenar
         : return: lista, lista de elementos ordenados
        """
        r = []
        while array:
            m = min(array)
            r.append(m)
            array.remove(m)
        return r

    @staticmethod
    def _mergesort(array: list) -> list:
        """Algoritmo de clasificación Mergesort, utilizado para ordenar listas
         : param array: lista, lista de elementos a ordenar
         : return: lista, lista de elementos ordenados
        """
        if len(array) <= 1:
            return array
        else:
            m = len(array) // 2
            e = Analisador._mergesort(array[:m])
            d = Analisador._mergesort(array[m:])
            return Analisador._merge(e, d)

    @staticmethod
    def _merge(e:list , d: list) -> list:
        """Sirve para ayudar en Mergesort
         : param e: lista, lista izquierda
         : param d: list, List a la derecha
         : return: lista, lista de elementos ordenados
        """
        r = []
        i, j = 0, 0
        while i < len(e) and j < len(d):
            if e[i] <= d[j]:
                r.append(e[i])
                i += 1
            else:
                r.append(d[j])
                j += 1
        r += e[i:]
        r += d[j:]
        return r



    @staticmethod
    def _insertion(array: list)->list:
      for i in range(1, len(array)):   

          key_item = array[i]
          j = i - 1
          while j >= 0 and array[j] > key_item:

              array[j + 1] = array[j]

              j -= 1

          array[j + 1] = key_item

      return array




    @staticmethod
    def _shellsort(myList):
        gap = len(myList) // 2
        while gap > 0:
            for i in range(gap, len(myList)):
                currentItem = myList[i]
                j = i
                while j >= gap and myList[j - gap] > currentItem:
                    myList[j] = myList[j - gap]
                    j -= gap
                myList[j] = currentItem
            gap //= 2

        return myList





  

    @staticmethod
    def _bubble(array):

      n = len(array)


      for i in range(n):

          already_sorted = True


          for j in range(n - i - 1):

              if array[j] > array[j + 1]:

                  array[j], array[j + 1] = array[j + 1], array[j]


                  already_sorted = False

          if already_sorted:

              break

      return array


def _heapsort(alist):
        heapify(alist)              # create the heap
        end = len(alist) - 1
        while end > 0:
            alist[end], alist[0] = alist[0], alist[end]
            shiftDown(alist, 0, end - 1)
            end -= 1
  
def heapify(alist):
        ''' Esta función ayuda a mantener la propiedad del montón '''
        # start = (len(alist) - 2) // 2         (faster execution)
        start = len(alist) // 2
        while start >= 0:
            shiftDown(alist, start, len(alist) - 1)
            start -= 1

   
def shiftDown(alist, start, end):
        root = start
        while root * 2 + 1 <= end:
            child = root * 2 + 1
            # el niño derecho existe y es mayor que el niño izquierdo
            if child + 1 <= end and alist[child] < alist[child + 1]:
                child += 1
            # Si el hijo es mayor que la raíz (padre), entonces intercambie sus posiciones
            if child <= end and alist[root] < alist[child]:
                alist[root], alist[child] = alist[child], alist[root]
                root = child
            else:
                return



# verificar
from pandas import DataFrame
analise = Analisador()
L=[4,3,2,1,10]
print(analise._shellsort(L))


# Obtención de datos de ejecución de algoritmos


df = DataFrame.from_dict(analise.resultado())
print(df)



# gráfico comparativo
import matplotlib.pyplot as plt

plt.figure(figsize=(16, 9))
plt.plot(df, marker='.')
plt.title('Comparación entre algoritmos de clasificación', size=16)
plt.legend(('Nativo (Python)', 'Quicksort', 'Mergesort', 'Seleção','insertion'), fontsize=14)
plt.xlabel('Número de elementos', size=14)
plt.ylabel('Tiempo en segundos', size=14)
plt.grid()
plt.show()

