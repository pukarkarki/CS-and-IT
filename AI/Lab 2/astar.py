gScore = 0 #use this to index g(n)
fScore = 1 #use this to index f(n)
previous = 2 #use this to index previous node

inf = 10000 #use this for value of infinity

#we represent the graph usind adjacent list
#as dictionary of dictionaries
G = {
    'biratnagar' : {'itahari' :  22, 'biratchowk' : 30, 'rangeli': 25},
    'itahari' : {'biratnagar' : 22, 'dharan' : 20, 'biratchowk' : 11},
    'dharan' : {'itahari' : 20},
    'biratchowk' : {'biratnagar' : 30, 'itahari' :  11, 'kanepokhari' :10}, 
    'rangeli' : {'biratnagar' : 25, 'kanepokhari' : 25, 'urlabari' : 40}, 
    'kanepokhari' : {'rangeli' : 25, 'biratchowk' : 10, 'urlabari' : 12},
    'urlabari' : {'rangeli' : 40, 'kanepokhari' : 12, 'damak' : 6},
    'damak' : {'urlabari' : 6}
    }



def h(city):
    #returns straight line distance from a city to damak
    h = {
        'biratnagar' : 46,
        'itahari' : 39,
        'dharan' : 41,
        'rangeli' : 28,
        'biratchowk' : 29,
        'kanepokhari' : 17,
        'urlabari' : 6,
        'damak' : 0
        }
    return h[city]

def getMinimum(unvisited):
    #returns city with minimum f(n)
    currDist = inf
    leastFScoreCity = ''
    for city in unvisited:
        if unvisited[city][fScore] < currDist:
            currDist = unvisited[city][fScore]
            leastFScoreCity = city
    return leastFScoreCity
            
        


def aStar(G, start, goal):
    visited = {} #we declare visited list as empty dict
    unvisited = {} #we declare unvisited list as empty dict

    #we now add every city to the unvisited
    for city in G.keys():
        unvisited[city] = [inf, inf, ""]

    hScore = h(start)
    #for starting node, the g(n) is 0, so f(n) will be h(n)
    unvisited[start] = [0, hScore, ""]

    finished = False
    while finished == False:
        #if there are no nodes to evaluate in unvisited
        if len(unvisited) == 0:
            finished = True

        else:
            #find the node with lowest f(n) from open list
            currentNode = getMinimum(unvisited)
            if currentNode == goal:
                finished = True
                #copy data to visited list
                visited[currentNode] = unvisited[currentNode]

            else:
                #we examine the neighbors of currentNode
                for neighbor in G[currentNode]:
                    #we only check unvisited neighbors
                    if neighbor not in visited:
                        newGScore = unvisited[currentNode][gScore] + G[currentNode][neighbor]
                        if newGScore < unvisited[neighbor][gScore]:
                            unvisited[neighbor][gScore] = newGScore
                            unvisited[neighbor][fScore] = newGScore + h(neighbor)
                            unvisited[neighbor][previous] = currentNode
                            
                #we now add currentNode to the visited list
                visited[currentNode] = unvisited[currentNode]
                #we now remove  the currentNode from unvisited
                del unvisited[currentNode]
    return visited      
                
def findPath(visitSequence, goal):
    answer = []
    answer.append(goal)
    currCity = goal
    while visitSequence[currCity][previous] != '':
        prevCity = visitSequence[currCity][previous]
        answer.append(prevCity)
        currCity = prevCity
    return answer[::-1]
    

start = 'biratnagar'
goal = 'damak'
visitSequence = aStar(G, start, goal)
path = findPath(visitSequence, goal)
print(path)


