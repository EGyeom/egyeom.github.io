import os

cur_path = os.path.dirname(os.path.abspath(__file__)) # 현재 파일의 절대 경로의 폴더 경로를 가져온다.

# with open(cur_path+"/enToken.txt", 'w+') as f:
#     for i in token:
#         f.write(str(ord(i))+ '\n') # 문자 -> unicode 숫자로 변환

token = ''
with open(cur_path+"/enToken.txt", 'r+') as f:
    lines = f.readlines()
    for line in lines:
        line = line.strip() 
        token = token + chr(int(line))

print(token)