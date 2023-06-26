# Function to compare algorithm efficiencies
def compare_algorithm_efficiencies():
    vertices = [10, 50, 100]  # Different graph sizes
    densities = [0.2, 0.5, 0.8]  # Different graph densities
    
    for v in vertices:
        for d in densities:
            graph = generate_random_graph(v, d)
            
            start_time = time.time()
            prim_cost = graph.prim_mst()
            prim_time = time.time() - start_time
            
            start_time = time.time()
            kruskal_cost = graph.kruskal_mst()
            kruskal_time = time.time() - start_time
            
            print(f"Graph Size: {v}, Density: {d}")
            print("Prim's Algorithm:")
            print("MST Cost:", prim_cost)
            print("Runtime:", prim_time, "seconds")
            print("Kruskal's Algorithm:")
            print("MST Cost:", kruskal_cost)
            print("Runtime:", kruskal_time, "seconds")
            print()