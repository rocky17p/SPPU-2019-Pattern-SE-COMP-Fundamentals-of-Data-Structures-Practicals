class Sorting:
    def __init__(self, size):
        self.size = size

    def input_array(self):
        array = []
        for i in range(self.size):
            y = int(input("element: "))
            array.append(y)
        return array

    def bubblesort(self,array):
        passes=0
        print("Original array is",array)
        for i in range(0,self.size):
            swapped=False
            if passes==0:
                pass
            else:
                print(f"{passes} : ",array)
            for j in range(i+1,self.size):
                if array[i] > array[j]:
                    array[i], array[j] = array[j],array[i]
                    swapped=True
            if swapped:
                passes+=1
        return array,passes

    def insertionsort(self, array):
        sorted_array = [array[0]]
        print(sorted_array)
        passes = 0
        for i in range(1, self.size):
            inserted = False
            if passes > 0:
                print(f"{passes}:", sorted_array)
            for j in range(passes + 1):
                if array[i] < sorted_array[j]:
                    sorted_array = sorted_array[:j] + [array[i]] + sorted_array[j:]
                    inserted = True
                    break
            if not inserted:
                sorted_array = sorted_array + [array[i]]
            passes += 1
        print(f"{passes}:", sorted_array)
        return sorted_array, passes

    def shellsort(self, array):
        gap = self.size // 2
        passes = 0
        while gap > 0:
            for i in range(gap, self.size):
                temp = array[i]
                j = i
                while j >= gap and array[j - gap] > temp:
                    array[j] = array[j - gap]
                    j -= gap
                array[j] = temp
            gap //= 2
            passes += 1
            print(f"Pass {passes} with gap {gap}: ", array)
        return array, passes

size = int(input("Enter the size of the array: "))
obj1 = Sorting(size)
array = obj1.input_array()
print("1 - Bubble Sort")
print("2 - Shell Sort")
print("3 - Insertion Sort")
operator = int(input("Enter the operation number to be performed: "))

if operator == 1:
    final_array, total_passes = obj1.bubblesort(array)
    print("Final sorted array is", final_array)
    print("Total passes are:", total_passes)
elif operator == 2:
    final_array, total_passes = obj1.shellsort(array)
    print("Final sorted array is", final_array)
    print("Total passes are:", total_passes)
elif operator == 3:
    final_array, total_passes = obj1.insertionsort(array)
    print("The sorted array is", final_array)
    print("The total passes are", total_passes)
else:
    print("Invalid operation number")