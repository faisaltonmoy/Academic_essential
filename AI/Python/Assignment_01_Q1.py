parent = [('parent', 'karim', 'manjur'),
          ('parent', 'manjur', 'sohel'), ('parent', 'manjur', 'tofel'),
          ('parent', 'manjur', 'jerin'), ('parent', 'manjur', 'najnin'),
          ('parent', 'tofel', 'rifat'),  ('parent', 'jerin', 'raaj')]
          
X = str(input("Grandchildren:\n"))
print('Grandparent:', end='\n')
for i in range(len(parent)):
    if (parent[i][0] == 'parent') & (parent[i][2] == X):
        for j in range(len(parent)):
          if (parent[j][0] == 'parent') & (parent[i][1] == parent[j][2]):
            print(parent[j][1])
    i=i+1
