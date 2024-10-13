class matrix:
    def __init__(self, a, b):
        self.a = a#rows
        self.b = b#cols

    def length(self, m1):
        count = 0
        for i in m1:
            for j in i:
                count += 1
        return count

    def input_matrix(self, a, b):
        matrix1 = []
        for i in range(a):
            list1 = []
            for j in range(b):
                element = int(input(f"element {i}{j}:"))
                list1+=[element]
            matrix1+=[list1]
        for i in matrix1:
            for j in i:
                print(j,end="")
            print()
        return matrix1
    def addition(self, m1, m2):
        result = []
        k = 0
        for i in range(self.a):
            row_result = []
            for j in range(self.b):
                k = m1[i][j] + m2[i][j]
                row_result+=[k]
            result+=[row_result]
        return result

    def subtraction(self, m1, m2):
        result = []
        k = 0
        for i in range(self.a):
            row_result = []
            for j in range(self.b):
                k = m1[i][j] - m2[i][j]
                row_result+=[k]
            result+=[row_result]
        return result

    def multiplication(self, m1, m2):
        result_mul = []
        for i in range(self.a):
            l2 = []
            for j in range(self.b):
                k1 = 0
                for k in range(self.b):
                    k1 += m1[i][k] * m2[k][j]
                l2+=[k1]
            result_mul+=[l2]
        return result_mul

    def transpose(self, m1):
        result_trans = []
        for i in range(self.b):
            l1 = []
            for j in range(self.a):
                k = m1[j][i]
                l1+=[k]
            result_trans+=[l1]
        return result_trans

print("Enter dimensions of the first matrix:")
a = int(input("Enter the number of rows: "))
b = int(input("Enter the number of columns: "))
m1 = matrix(a,b).input_matrix(a, b)

print("1 - Addition")
print("2 - Subtraction")
print("3 - Multiplication")
print("4 - Transpose")
print("5 - Exit")
operation = int(input("Enter the operation number: "))

if operation == 1:
    print("Enter dimensions of the second matrix:")
    c = int(input("Enter the number of rows: "))
    d = int(input("Enter the number of columns: "))
    if a == c and b == d:
        print("Addition is possible.")
        m2 = matrix(c,d).input_matrix(c, d)
        print("The addition of the two matrices is:", matrix(a,b).addition(m1, m2))
    else:
        print("Addition is not possible.")
elif operation == 2:
    print("Enter dimensions of the second matrix:")
    c = int(input("Enter the number of rows: "))
    d = int(input("Enter the number of columns: "))
    if a == c and b == d:
        print("Subtraction is possible.")
        m2 = matrix().input_matrix(c, d)
        print("The subtraction of matrices is:", matrix(a,b).subtraction(m1, m2))
    else:
        print("Subtraction is not possible.")
elif operation == 3:
    print("Enter dimensions of the second matrix:")
    c = int(input("Enter the number of rows: "))
    d = int(input("Enter the number of columns: "))
    if b == c:
        print("Multiplication is possible.")
        m2 = matrix(a,b).input_matrix(c, d)
        print("The multiplication result is:", matrix(a,b).multiplication(m1, m2))
    else:
        print("Multiplication is not possible.")
elif operation == 4:
    print(f"The transpose of the matrix {m1} is:", matrix(a,b).transpose(m1))
else:
    pass
