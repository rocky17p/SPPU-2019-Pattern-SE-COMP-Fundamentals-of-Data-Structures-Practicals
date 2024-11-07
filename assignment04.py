class search:
    def __init__(self,size,key):
        self.size=size
        self.key=key
    def input_array(self):
        array=[]
        for i in range(self.size):
            y=int(input())
            array+=[y]
        return array
    def linear(self,array):
        for i in range(self.size):
            if array[i]==self.key:
                return i
                break
        return -1
    def sentinel(self,array):
        array+=[self.key]
        i=0
        while(array[i]!=self.key):
            i+=1
        if i==self.size:
            return -1
        else:
            return i
    def sort(self,array):
        for i in range(0,self.size):
            for j in range(i+1,self.size):
                if array[i] >= array[j]:
                    array[i], array[j] = array[j],array[i]
        return array
    def binarysearch(self,array):
        low=0
        high=self.size-1
        while(high>=low):
            mid=(low+(high))//2
            if(array[mid]==self.key):
                return mid
            elif(array[mid]<key):
                low=mid+1
            else:
                high=mid-1
        return -1

   def fibonacci(self,array,key,n):
    b=0
    a=1
    f=a+b
    while(f<n):
        b=a
        a=f
        f=b+a
    offset=-1
    while(f>1):
        i=min(offset+b,n-1)
        if(array[i]<key):
            f=a 
            a=b
            b=f-a
            offset=i
        elif(array[i]>key):
            f=b
            a=a-b
            b=f-a
        else:
            return i
    if(a and array[offset+1]==key):
        return offset+1
    return -1
key=int(input("enter the roll no that is to be found "))
size=int(input("enter the no of students "))
obj=search(size,key)
array=obj.input_array()
print("1-linear search")
print("2-sentinel search")
print("3-binary search")
print("4-fibonacci search")
print("5-exit")
operation=int(input("enter the operation no"))
if(operation==1):
    print("the index by linear method is ",obj.linear(array))
elif(operation==2):
    print("the index by sentinel method is ",obj.sentinel(array))
elif(operation==3):
    sorted_array=obj.sort(array)
    print(sorted_array)
    print("the index by binary search is ",obj.binarysearch(sorted_array))
elif(operation==4):
    sorted_array=obj.sort(array)
    print(sorted_array)
    print("the index by fibonacci search is",obj.FibonacciSearch(sorted_array,key))

elif(operation==5):
    pass
else:
    print("Wrong operation number")
    pass
