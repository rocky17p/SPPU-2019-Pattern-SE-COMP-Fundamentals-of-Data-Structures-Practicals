class stringanalyser:
    def __init__(self,string,character,substring):
        self.string=string
        self.character=character
        self.subtring=substring

    def split(self):
        string_split = []
        current_word = ''
        for char in self.string:
            if char == ' ':
                if current_word:
                    string_split+=[current_word]
                    current_word = ''
            else:
                current_word += char
        if current_word:
            string_split+=[current_word]
        return string_split
#a) To display word with the longest length
    def length(self):
        len_list = []
        y =self.split()
        for i in y:
            count1 = 0
            for j in i:
                count1 += 1
            len_list += [count1]
        max_term = 0
        index_of_max_term = -1
        count = 0
        for i in len_list:
            count+= 1
        for i in range(count):
            if len_list[i] > max_term:
                max_term = len_list[i]
                index_of_max_term = i 
        return y[index_of_max_term]
#b)To determines the frequency of occurrence of particular character in the string
    def freq(self):
        count=0
        for i in self.string:
            if i==self.character:
                count+=1
        return count
#c) To check whether given string is palindrome or not
    def palin(self):
        y=self.string[::-1]
        if(self.string==y):
            print(f"{self.string}is a palindrome")
        else:
            print(f"{self.string} is not a palindrome")
#d) To display index of first appearance of the substring
    def sub(self):
        count=0
        for i in self.string:
            if i==self.subtring:
                break
            else:
                count+=1
        return count
#e) To count the occurrences of each word in a given string
    def e(self):
        words=self.split()
        word_count=[]
        for word in words:
            found=False
            for pair in word_count:
                if pair[0]==word:
                    pair[1]+=1
                    found=True
                    break
            if found==False:
                word_count.append([word,1])
        return word_count
string= input("Enter the string:\n")
substring=input("enter the substring:\n")
character=input("enter the character whose frequency is to be found:\n")
print("1-display word with the longest length")
print("2-the frequency of occurrence of particular character in the string")
print("3-to check whether entered string is palindrome or not")
print("4-to find index of first appearance of the substring")
print("5-to find occurrences of each word in a given string")
operation=int(input("enter the operation no to be performed\n"))
obj=stringanalyser(string,character,substring)
if operation==1:
    print("display word with the longest length:",obj.length())
if operation==2:
    print(f"the frequency of occurrence of character  {character} in the string",obj.freq())
if operation==3:
    obj.palin()
if operation==4:
    print(f"index of first appearance of the substring {substring} is",obj.sub())
if operation==5:
    print("occurrences of each word in a given string",obj.e())
