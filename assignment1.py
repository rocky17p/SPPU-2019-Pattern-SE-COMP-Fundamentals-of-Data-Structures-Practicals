Experiment No. 1 : In a second year computer engineering class, group A students play cricket, group B students play
                   badminton and group C students play football.
                   Write a python program using functions to compute following:
                   a) List of students who play both cricket and badminton.
                   b) List of students who play either cricket or badminton but not both.
                   c) Number of students who play neither cricket nor badminton.
                   d) Number of students who play cricket and football but not badminton.
(NOTE : While realising the group, duplicate entries should be avoided. Do not use SET built-in functions)

cricketlist=list(map(str,input("enter list of students playing cricket ").split()))
badmintonlist=list(map(str,input("enter list of students playing badminton ").split()))
footballlist=list(map(str,input("enter list of students playing football ").split()))
def intersection(a,b):
    result=[] 
    for i in a:
        for j in b:
            if(i==j):
                result+=[i]
    return result
print("a)List of students who play both cricket and badminton",*intersection(cricketlist,badmintonlist))
def uni(a,b):
    result=[]
    for i in a:
        result+=[i]
    for i in b:
        found=False
        for j in result:
            if i==j:
                found=True
                break
        if found ==False:
            result+=[i]
    return result
def b(a,b):
    x=intersection(a,b)
    y=uni(a,b)
    result3=[]
    for i in y:
        found=False
        for j in x:
            if i==j:
                found=True
                break
        if found==False:
            result3+=[i]
    return result3
print("b)List of students who play either cricket or badminton but not both",*b(cricketlist,badmintonlist))
def c(a,b,c):
    x=intersection(a,c)
    y=c
    result3=[]
    for i in y:
        found=False
        for j in x:
            if i==j:
                found=True
                break
        if found==False:
            result3+=[i]
    z=intersection(a,c)
    result4=[]
    for i in result3:
        found=False
        for j in z:
            if i==j:
                found=True
                break
        if found==False:
            result4+=[i]
    return len(result4)
print(" c) Number of students who play neither cricket nor badminton",c(cricketlist,badmintonlist,footballlist))
def d(a,b,c):
    x=uni(a,c)
    result=[]
    for i in x:
        found=False
        for j in b:
            if i==j:
                found=True
                break
        if found==False:
            result+=[i]
    return len(result)
print("d) Number of students who play cricket and football but not badminton",d(cricketlist,badmintonlist,footballlist))


