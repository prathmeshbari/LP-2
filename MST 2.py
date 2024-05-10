import heapq

def prim(graph):
    mst = []
    visited = set()
    
    start_vertex = list(graph.keys())[0]  # Start from an arbitrary vertex
    visited.add(start_vertex)
    edges = [(cost, start_vertex, neighbor) for neighbor, cost in graph[start_vertex]]
    heapq.heapify(edges)
    
    while edges:
        cost, src, dest = heapq.heappop(edges)
        if dest not in visited:
            visited.add(dest)
            mst.append((src, dest, cost))
            for neighbor, n_cost in graph[dest]:
                if neighbor not in visited:
                    heapq.heappush(edges, (n_cost, dest, neighbor))
    
    return mst

# Function to take dynamic input for the graph
def take_input():
    graph = {}
    num_edges = int(input("Enter the number of edges: "))
    for _ in range(num_edges):
        src, dest, cost = input("Enter source, destination, and cost separated by space: ").split()
        cost = int(cost)
        if src not in graph:
            graph[src] = []
        if dest not in graph:
            graph[dest] = []
        graph[src].append((dest, cost))
        graph[dest].append((src, cost))  # Assuming undirected graph
    
    return graph

# Example usage:
graph = take_input()
mst = prim(graph)
print("Minimum Spanning Tree:")
for edge in mst:
    print(edge)
