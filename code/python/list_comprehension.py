a = list(map(lambda x: x+10, [1,2,3]))
print(a)

a = [n*2 for n in range(1,10+1) if n%2 == 1]
print(a)


# a = [(x,y,z) for x in range(5) for y in range(5) if x != y for z in range(5) if y != z]

# print(a)

a = [(x,y,z) for x in range(5)
             for y in range(5)
             if x != y 
             for z in range(5)
             if y != z]

print(a)