# Sure, here's a Python implementation of the 8-puzzle problem using the A* search algorithm with Manhattan distance as the heuristic function. 
#The initial state and final state are given in the code.

import heapq
# The initial and final states
initial_state = [[1, 2, 3], [0, 4, 6], [7, 5, 8]]
final_state = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]

# Function to find the position of a number in the puzzle
def find_position(puzzle, number):
    for i in range(len(puzzle)):
        for j in range(len(puzzle[i])):
            if puzzle[i][j] == number:
                return i, j

# Function to calculate the Manhattan distance between two positions
def manhattan_distance(pos1, pos2):
    return abs(pos1[0] - pos2[0]) + abs(pos1[1] - pos2[1])

# Function to calculate the heuristic value of a puzzle
def heuristic(puzzle):
    distance = 0
    for i in range(len(puzzle)):
        for j in range(len(puzzle[i])):
            number = puzzle[i][j]
            if number != 0:
                pos1 = (i, j)
                pos2 = find_position(final_state, number)
                distance += manhattan_distance(pos1, pos2)
    return distance

# Function to generate the possible next states of a puzzle
def generate_next_states(puzzle):
    next_states = []
    zero_pos = find_position(puzzle, 0)
    for i, j in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        new_i, new_j = zero_pos[0] + i, zero_pos[1] + j
        if 0 <= new_i < len(puzzle) and 0 <= new_j < len(puzzle[0]):
            new_puzzle = [row[:] for row in puzzle]
            new_puzzle[zero_pos[0]][zero_pos[1]] = new_puzzle[new_i][new_j]
            new_puzzle[new_i][new_j] = 0
            next_states.append(new_puzzle)
    return next_states

# The A* search algorithm
def a_star(initial_state, final_state):
    # The priority queue to store the states to be explored
    pq = []
    heapq.heappush(pq, (heuristic(initial_state), initial_state))
    
    # The set to store the explored states
    explored = set()
    
    # The dictionary to store the parent states
    parent = {str(initial_state): None}
    
    while pq:
        _, current_state = heapq.heappop(pq)
        if current_state == final_state:
            # Reconstruct the path from the final state to the initial state
            path = []
            while current_state is not None:
                path.append(current_state)
                current_state = parent[str(current_state)]
            path.reverse()
            return path
        explored.add(str(current_state))
        for next_state in generate_next_states(current_state):
            if str(next_state) not in explored:
                parent[str(next_state)] = current_state
                heapq.heappush(pq, (heuristic(next_state), next_state))
    
    return None

# Solve the puzzle and print the solution
solution = a_star(initial_state, final_state)
if solution:
    for state in solution:
        for row in state:
            print(row)
        print()
else:
    print("No solution found.")
