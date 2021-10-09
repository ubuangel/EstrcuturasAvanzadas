#matplotlib inline
import matplotlib
import numpy as np
import matplotlib.pyplot as plt


from input import mimodulo
from input import printe

A=[6,4,3,8,1]
def InsertionSort(A):
  for i in range(1,len(A)):
    current = A[i]
    j=i-1
    while j>=0 and A[j]>current:
      A[j+1]=A[j]
      j-=1
    A[j+1]= current


def merge(L,R):
  i=0
  j=0
  red=[]
  while i<len(L) and j<len(R):
    if L[i]<R[j]:
      red.append(L[i])
      i+=1
    else:
      red.append(R[j])
      j+=1
  while i<len(L):
    red.append(L[i])
    i+=1
  while j<len(R):
    red.append(R[j])
    j+=1
  return red

def mergesort(A):
  n=len(A)
  if n <= 1:
    return A
  L=mergesort(A[:round(n/2)])
  R=mergesort(A[round(n/2):n])
  return merge(L,R)


A=[27,17,2,4,52,3,4,3]
B=mergesort(A)
print(B)



InsertionSort(A)
print(A)


n_values_merge,t_values_merge=mimodulo(mergesort,1,1000000,1,numTrials=1,listMax=2000000)

n_values_insertion,t_values_insertion=mimodulo(InsertionSort,1,1000000,1,numTrials=1,listMax=2000000)

plt.plot(n_values_merge,t_values_merge,color="green",label="mergesort")
plt.plot(n_values_insertion,t_values_insertion,color="blue",label="insertion")

plt.xlabel(" n")
plt.ylabel("tiempo")
plt.legend()

plt.show()





