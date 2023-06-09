import random
import time

# Function to generate a random graph
def generate_random_graph(vertices, density):
    graph = Graph(vertices)
    
    for u in range(vertices):
        for v in range(u + 1, vertices):
            if random.random() < density:
                weight = random.randint(1, 10)
                graph.add_edge(u, v, weight)
    
    return graph