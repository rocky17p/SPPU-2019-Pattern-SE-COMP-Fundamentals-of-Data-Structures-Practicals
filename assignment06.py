class Sorting:
    def __init__(self, size):
        self.size = size

    def input_array(self):
        array = []
        for i in range(self.size):
            y = int(input("element: "))
            array.append(y)
        return array

    def partition(self, array, low, high):
        pivot = array[low]
        i = low
        j = high
        while j > i:
            while array[i] <= pivot and i < high:
                i += 1
            while array[j] > pivot and j > low:
                j -= 1
            if i < j:
                array[i], array[j] = array[j], array[i]
        array[low], array[j] = array[j], array[low]
        return j

    def quicksort(self, array, low, high):
        if low < high:
            pindex = self.partition(array, low, high)
            self.quicksort(array, low, pindex - 1)
            self.quicksort(array, pindex + 1, high)
        return array

size = int(input("Enter the length of array: "))
obj1 = Sorting(size)
print("Enter the array:")
array = obj1.input_array()
x = obj1.quicksort(array, 0, size - 1)
print("Sorted array:", x)
