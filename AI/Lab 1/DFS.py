#we represent the graph in adjacent list representation
G  = {
    'A' : ['B', 'C'],
    'B' : ['A', 'D', 'E'],
    'C' : ['A', 'F'],
    'D' : ['B', 'G'],
    'E' : ['B', 'D', 'G', 'H'],
    'F' : ['C'],
    'G' : ['D'],
    'H' : ['E']
    }

start = 'A'
goal = 'H'

def DFS(G, start, goal):
    #we maintain a stack which stores a tuple
    #containig vertex and path to that vertex
    stack = [(start, [start])]
    #we maintain a set of visited vertices
    visited = set()
    #we repeat the following until the stack is empty
    while stack:
        (poppedVertex, path) = stack.pop()
        if poppedVertex not in visited:
            #if the popped vertex is the goal we return the path
            if poppedVertex == goal:
                return path
            visited.add(poppedVertex)
            for vertex in G[poppedVertex]:
                if vertex not in visited and vertex not in stack:
                    stack.append((vertex, path + [vertex]))

#Driver Code
path = DFS(G, start, goal)
print(path)

    
    
