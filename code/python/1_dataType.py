import os
os.system("clear")
#python은 따로 자료형을 선언해주지 않아도 된다.

#숫자형 자료형은 아래와 같다.

num = 100 # 정수
f = 1.5 # 실수
binary = 0b1111 #2진수  
octal = 0o177 #8진수
hexadecimal = 0xBCC #16진수

#10진수 -> 2진수 변환 함수 bin()
binary = bin(num)
print("bin() 함수의 리턴 타입은 ",end="")
print(type(binary))
print("10진수 num의 2진수 변환 값은 : {} ".format(binary))

print()

octal = oct(num)
print("oct() 함수의 리턴 타입은 ",end="")
print(type(octal))
print("10진수 num의 8진수 변환 값은 : {} ".format(octal))

print()

hexadecimal = hex(num)
print("hex() 함수의 리턴 타입은 ",end="")
print(type(hexadecimal))
print("10진수 num의 16진수 변환 값은 : {} ".format(hexadecimal))

print()

#2,8,16진수 -> 10진수 변환 int(x,y) x:변환할 문자열 데이터, 변환할 진수
print("2진수 {}의 10진수 변환 값은 : {}".format(binary,int(binary,2)))
print("8진수 {}의 10진수 변환 값은 : {}".format(octal,int(binary,2)))
print("16진수 {}의 10진수 변환 값은 : {}".format(hexadecimal,int(binary,2)))


# # 출력하기 위해 print를 사용한다.

# print(1) #int type
# print("Hello World") #string type
# print(True) #boolean type

# #이렇게도 사용 할 수 있다.
# #{}에 차례차례 들어가게 된다.
# print("{} {} {}".format("hello","python","world"))

# #{}안에 숫자를 넣으면 숫자대로 들어가게 된다. index는 0부터 시작하는걸 유의해야한다.
# print("{2} {1} {0}".format("hello","python","world"))



