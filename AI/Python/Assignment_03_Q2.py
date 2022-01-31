Graph = {'P': [['Q', 3], ['R', 6], ['Q', 1]],
        'Q': [['P', 2], ['T', 9], ['U', 6], ['V', 4]],
        'R': [['P', 1], ['V', 8]],
        'S': [['P', 6], ['V', 2]],
        'T': [['Q', 2]],
        'U': [['Q', 8]]}

heuristic = {'P': 18, 'Q': 12, 'R': 14, 'S': 3, 'T': 50, 'U': 25, 'V': 0}

cost = {'P': 0} 

def AStarSearch():
    global Graph,heuristic
    closed=[]
    opened=[['P',18]]

    '''FOR visited nodes'''
    while True:
        fn = [i[1] for i in opened]  
        chosen_index = fn.index(min(fn))
        node = opened[chosen_index][0]  
        closed.append(opened[chosen_index])
        del opened[chosen_index]
        if closed[-1][0] == 'V': 
            break
        for item in Graph[node]:
            if item[0] in [closed_item[0] for closed_item in closed]:
                continue
            cost.update({item[0]: cost[node] + item[1]})  
            fn_node = cost[node] + heuristic[item[0]] + item[1] 
            temp = [item[0], fn_node]
            opened.append(temp)  


    '''FOR optimal path'''
    trace_node = 'V'  
    optimal_sequence = ['V']  
    for i in range(len(closed) - 2, -1, -1):
        check_node = closed[i][0]  
        if trace_node in [children[0] for children in Graph[check_node]]:
            children_costs = [temp[1] for temp in Graph[check_node]]
            children_nodes = [temp[0] for temp in Graph[check_node]]
            
            if cost[check_node] + children_costs[children_nodes.index(trace_node)] == cost[trace_node]:
                optimal_sequence.append(check_node)
                trace_node = check_node
                optimal_sequence.reverse()  
                return closed, optimal_sequence

if __name__ == '__main__':
    visited_nodes, optimal_nodes = AStarSearch()
    print('visited nodes: ' + str(visited_nodes))
    print('optimal nodes sequence: ' + str(optimal_nodes))



