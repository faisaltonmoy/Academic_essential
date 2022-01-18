parent = [('parent', 'manjur', 'sohel'), ('parent', 'manjur', 'tufel'),
          ('parent', 'manjur', 'jerin'), ('parent', 'manjur', 'najnin'),
          ('parent', 'tufel', 'rifat'),  ('parent', 'jerin', 'raaj')]

male = [('male', 'manjur'), ('male', 'sohel'),
        ('male', 'tufel'), ('male', 'rifat'), ('male', 'raaj')]

female = [('female', 'jerin'), ('female', 'najnin')]

def findBr(): #brother
    X = str(input("Sibling:\n"))
    print('Brother:', end='\n')
    bl = True
    for i in range(len(parent)):
        if (parent[i][0] == 'parent') & (parent[i][2] == X):
            for j in range(len(parent)):
                if (parent[j][0] == 'parent') & (parent[j][1] == parent[i][1]) & (parent[i][2]!=parent[j][2]):
                    for k in range(len(male)):
                        if(male[k][0]=='male') & (male[k][1]==parent[j][2]):
                            print(male[k][1])
                            bl = False
    if (bl):
        print('N\A')

def findSr(): #sister
    X = str(input("Sibling:\n"))
    print('Sister:', end='\n')
    bl = True
    for i in range(len(parent)):
        if (parent[i][0] == 'parent') & (parent[i][2] == X):
            for j in range(len(parent)):
                if (parent[j][0] == 'parent') & (parent[j][1] == parent[i][1]) & (parent[i][2]!=parent[j][2]):
                    for k in range(len(female)):
                        if(female[k][0]=='female') & (female[k][1]==parent[j][2]):
                            print(female[k][1])
                            bl = False
    if(bl):
        print('N\A')

def findUl(): #uncle
    X = str(input("Nephew:\n"))
    print('Uncle:', end='\n')
    bl = True
    for i in range(len(parent)):
        if(parent[i][0]=='parent') & (parent[i][2]==X):#parent[i][1] parent
            for j in range(len(parent)):
                if (parent[j][0] == 'parent') & (parent[j][2]==parent[i][1]):#parent[j][1] grandparent
                    for k in range(len(parent)):
                        if (parent[j][0] == 'parent') & (parent[j][1] == parent[k][1]) & (parent[i][1]!=parent[k][2]): #parent[k][2] parent's sibling
                            for l in range(len(male)):
                                if(male[l][0]=='male') & (male[l][1]==parent[k][2]): #male[l][1] uncle
                                    print(male[l][1])
                                    bl = False
    if(bl):
        print('N/A')

def findUt(): #aunt
    X = str(input("Nephew:\n"))
    print('Aunt:', end='\n')
    bl = True
    for i in range(len(parent)):
        if(parent[i][0]=='parent') & (parent[i][2]==X):#parent[i][1] parent
            for j in range(len(parent)):
                if (parent[j][0] == 'parent') & (parent[j][2]==parent[i][1]):#parent[j][1] grandparent
                    for k in range(len(parent)):
                        if (parent[j][0] == 'parent') & (parent[j][1] == parent[k][1]) & (parent[i][1]!=parent[k][2]): #parent[k][2] parent's sibling
                            for l in range(len(female)):
                                if(female[l][0]=='female') & (female[l][1]==parent[k][2]): #female[l][1] aunt
                                    print(female[l][1])
                                    bl = False
    if(bl):
        print('N/A')

def Print():
    print('1: Brother, 2: Sister, 3: Uncle, 4: Aunt, Other character: Exit')
    x = input("press a character:\n")
    return x

x = Print()
while (1):
    if x == '1':
        findBr() #brother
    elif x == '2':
        findSr() #sister
    elif x == '3':
        findUl() #uncle
    elif x == '4':
        findUt() #aunt
    else:
      break
    x = Print()
