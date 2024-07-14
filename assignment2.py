string= input("Enter the string:\n")
substring=input("enter the substring:\n")
character=input("enter the character whose frequency is to be found:\n")
def split(x):
    string_split = []
    current_word = ''
    for char in x:
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
def length(x):
    len_list = []
    y = split(x)
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
print("word with the longest length is ",length(string))
#b)To determines the frequency of occurrence of particular character in the string
def freq(x,y):
    count=0
    for i in x:
        if i==y:
            count+=1
    return count
print(f"the frequency of occurence of character {character} is",freq(string,character))
#c) To check whether given string is palindrome or not
def palin(x):
    y=x[::-1]
    if(x==y):
        print(f"{x}is a palindrome")
    else:
        print(f"{x} is not a palindrome")
palin(string)
#d) To display index of first appearance of the substring
def sub(x,y):
    count=0
    for i in x:
        if i==y:
            break
        else:
            count+=1
    print(f"index of first appearance of the substring {y} is",count)
sub(string,substring)
#e) To count the occurrences of each word in a given string
def e(x):
    words=split(x)
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
print("ccurrences of each word in a given string",e(string))
