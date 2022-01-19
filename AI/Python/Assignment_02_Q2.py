graph=[
    ('s','a',10), 
    ('s','c',20), 
    ('a','b',17), 
    ('c','a',40),
    ('b','e',28),
    ('b','d',15),
    ('c','d',33),
    ('d','e',12),
]

visited = [0] * len(graph)
all_paths = []

def pathFind(start,end, weight=[]):
    
    if start == end:
        all_paths.append(list(weight))
        
    i = 0
    child = ''
    while i <= len(graph)-1:
        if  visited[i] == 0 and graph[i][0] == start:
            visited[i] = 1
            child = graph[i][1]
            weight.append(( start,child,graph[i][2] , i))
            pathFind(child,end)
                 
        i+=1

    if len(weight) >= 1:
        visited[weight[len(weight)-1][3]] = 0
        weight.pop()
    

start = 's'
end = 'e'
pathFind(start,end)

print(f"\nStart node = {start} and End node = {end} \n")
for i,target_list in enumerate( all_paths ,1):
    print(
        f"Path {i} = {target_list} Length = { sum( [ p[2] for p in target_list] ) }"
        )   
