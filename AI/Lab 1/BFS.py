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

def BFS(G, start, goal):
    #we maintain a queue which stores a tuple
    #containig vertex and path to that vertex
    queue = [(start, [start])]
    #we maintain a set of visited vertices
    visited = set()
    #we repeat the following until the queue is empty
    while queue:
        (poppedVertex, path) = queue.pop(0)
        if poppedVertex not in visited:
            #if the popped vertex is the goal we return the path
            if poppedVertex == goal:
                return path
            visited.add(poppedVertex)
            for vertex in G[poppedVertex]:
                if vertex not in visited and vertex not in queue:
                    queue.append((vertex, path + [vertex]))
#Driver Code
path = BFS(G, start, goal)
print(path)

    
    
