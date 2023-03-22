import itertools

# Define the distance matrix for cities
# Replace the values with the actual distances between cities
distances = {
    '1': {'1': 0, '2': 10, '3': 15, '4': 20},
    '2': {'1': 10, '2': 0, '3': 35, '4': 25},
    '3': {'1': 15, '2': 35, '3': 0, '4': 30},
    '4': {'1': 20, '2': 25, '3': 30, '4': 0}
}

# Define the function to calculate the total distance for a given path
def get_total_distance(path):
    total_distance = 0
    for i in range(len(path)-1):
        total_distance += distances[path[i]][path[i+1]]
    return total_distance

# Take the starting node from user
start_node = input("Enter the starting node: ")

# Generate all possible permutations of the cities
cities = list(distances.keys())
cities.remove(start_node)
permutations = itertools.permutations(cities)

# Find the shortest path and total distance
shortest_path = None
shortest_distance = None
for permutation in permutations:
    path = [start_node] + list(permutation) + [start_node]
    total_distance = get_total_distance(path)
    if shortest_distance is None or total_distance < shortest_distance:
        shortest_distance = total_distance
        shortest_path = path

# Print the shortest path and total distance
print("Shortest path:", shortest_path)
print("Total distance:", shortest_distance)
