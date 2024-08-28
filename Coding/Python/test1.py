import string,random

def generate_licence(type):
    char = string.hexdigits
    license = ''.join(random.choice(char) for _ in range(5))
    return type+'_'+license

licence=generate_licence('car')
print(licence)

