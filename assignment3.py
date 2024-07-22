class matrix:
    def __init__(self,a,b):
        self.a=a
        self.b=b
    def input_matrix(a,b):
        matrix1=[]
        for i in range(a):
            list1=[]
            for j in range(b):
                element=int(input(f"element {i}{j}:"))
                list1.append(element)
            matrix1.append(list1)
        for i in range(len(matrix1)):
            print(matrix1[i])
        return matrix1
    def subtraction(m1,m2):
        result=[]
        k=0
        for i in range(len(m1)):
            rowresult=[]
            for j in range(len(m1[i])):
                k=m1[i][j]-m2[i][j]
                rowresult.append(k)
            result.append(rowresult)
        return result
    def multiplication(m1,m2):
        resultmul=[]
        for i in range(len(m1)):
            l2=[]
            for j in range(len(m2[0])):
                k1=0
                for k in range(len(m2)):
                    k1 += m1[i][k]*m2[k][j]    
                l2.append(k1)
            resultmul.append(l2)
        return resultmul
    def transpose(m1):
        resulttrans=[]
        if len(m1)>=len(m1[1]):
            for i in range(len(m1)):
                l1=[]
                k=0
                for j in range(len(m1[i])):
                    k = m1[j][i]
                    l1.append(k)
                resulttrans.append(l1)
        else:
            for i in range(len(m1[1])):
                l1=[]
                k=0
                for j in range(len(m1)):
                    k = m1[j][i]
                    l1.append(k)
                resulttrans.append(l1)
        return resulttrans
        
print("enter dimension of first matrix")
a=int(input("enter no of rows "))
b=int(input("enter no of columns "))
m1=matrix.input_matrix(a,b)
print("1-additon")
print("2-subtraction")
print("3-multiplication")
print("4-transpose")
print("5-exit")
operation=int(input("enter the operation number"))
if(operation==1):
    print("enter dimensions of second matrix")
    c=int(input("enter no of columns "))
    d=int(input("enter no of columns "))
    if(a==c and b==d):
        print("addition is possible")
        m2=matrix.input_matrix(c,d)
        print("the addition of 2 matrices is ",matrix.addition(m1,m2))
    else:
        print("addition is not possible")
elif(operation==2):
    print("enter dimensions of second matrix")
    c=int(input("enter no of columns "))
    d=int(input("enter no of columns "))
    if(a==c and b==d):
        print("subtraction is possible")
        m2=matrix.input_matrix(c,d)
        print("the subtraction of matrices is",matrix.subtraction(m1,m2))
    else:
        print("subtraction not possible")
elif(operation==3):
    print("enter dimensions of second matrix")
    c=int(input("enter no of columns "))
    d=int(input("enter no of columns "))
    if(b==c):
        print("multiplication is possible")
        m2=matrix.input_matrix(c,d)
        print("the multiplication result is",matrix.multiplication(m1,m2))
    else:
        print("multiplication not possible")
elif(operation==4):
    print(f"the transpose the matrix {m1} is",matrix.multiplication(m1,m2))
else:
    pass



