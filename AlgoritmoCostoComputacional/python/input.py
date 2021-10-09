def mimodulo(myFn, startN=10, endN=100, stepSize=10, numTrials=20, listMax = 10):
    nValues = []
    tValues = []
    for n in range(startN, endN, stepSize):
       
        runtime = 0
        for t in range(numTrials):
            global lst
            lst = [ choice(range(listMax)) for i in range(n) ] # generate a random list of length n
            start = time.time()
            myFn( lst )
            end = time.time()
            runtime += (end - start) * 1000 # measure in milliseconds
        runtime = runtime/numTrials
        nValues.append(n)
        tValues.append(runtime)

    with open("inputs/"+"entrada", 'w') as f:

        for item in lst:
            f.write("%s " % item)    
    return nValues, tValues

def printe():
  print(lst)

lst=[]
