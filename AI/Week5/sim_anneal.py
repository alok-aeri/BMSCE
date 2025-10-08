import random
import sys

# Set a higher recursion limit for potentially deeper searches
sys.setrecursionlimit(2000)

def cost(state):
    """
    Calculate the number of attacking pairs of queens in the current state.
    This is the objective function to be minimized.
    """
    attacking_pairs = 0
    n = len(state)
    for i in range(n):
        for j in range(i + 1, n):
            # Check for same row (Horizontal attack is not possible by state design)
            # state[i] == state[j] would mean two queens in the same row.
            # Check for diagonal attack:
            # The difference in rows (abs(state[i] - state[j])) equals the difference in columns (abs(i - j))
            if abs(state[i] - state[j]) == abs(i - j):
                attacking_pairs += 1
            # Note: The problem setup ensures only one queen per column.
    return attacking_pairs

def print_board(state):
    """Represent the state as an N x N board."""
    n = len(state)
    # The board array is typically indexed as board[row][col]
    board = [['.' for _ in range(n)] for _ in range(n)]
    for col in range(n):
        row = state[col]
        board[row][col] = 'Q'

    for row in board:
        print(" ".join(row))

def generate_random_state(n):
    """Generate a valid initial state (one queen per column) for an N x N board."""
    # Create a list of row indices and randomly shuffle them
    rows = list(range(n))
    random.shuffle(rows)
    # The resulting list/tuple is a valid state where index=column, value=row
    return tuple(rows)

def get_neighbors(state):
    """Generate all possible neighbors by swapping two queens (swapping their row values)."""
    neighbors = []
    n = len(state)
    state_list = list(state)
    
    # Iterate through all unique pairs of columns
    for i in range(n):
        for j in range(i + 1, n):
            neighbor = state_list[:]  # Create a copy of the current state
            # Swap the row positions of the queens in columns i and j
            neighbor[i], neighbor[j] = neighbor[j], neighbor[i]
            neighbors.append(tuple(neighbor))
    return neighbors

def hill_climbing(initial_state):
    """Hill climbing algorithm to solve the N-Queens problem."""
    current = initial_state
    
    print(f"--- N-Queens Hill Climbing (N={len(current)}) ---")
    print(f"Initial state (Cost: {cost(current)}):")
    print_board(current)
    print('-' * 20)

    # Hill Climbing main loop
    step = 0
    while True:
        neighbors = get_neighbors(current)
        
        # Select the neighbor with the minimum cost
        # The 'min' function handles ties arbitrarily, which is a simple implementation 
        # of the steepest-ascent/descent strategy.
        next_state = min(neighbors, key=lambda x: cost(x))
        next_cost = cost(next_state)
        current_cost = cost(current)

        step += 1
        print(f"Step {step}:")
        print(f"Next best state (Cost: {next_cost}):")
        # print_board(next_state) # Commented out to reduce verbose output
        
        if next_cost >= current_cost:
            # Found a local optimum (or global optimum)
            print("--- Search Terminated ---")
            if current_cost == 0:
                print("SUCCESS: Found Global Optimum (Cost=0).")
            else:
                print(f"FAILURE: Stuck at Local Optimum (Cost={current_cost}).")
            
            print_board(current)
            return current
        
        # Move to the better state
        current = next_state
        print(f"Moved to new state.")
        print('-' * 20)

if __name__ == "__main__":
    try:
        # 1. Generalized Input
        n_queens = int(input("Enter the number of queens (N): "))
        if n_queens <= 0:
            raise ValueError
    except ValueError:
        print("Invalid input. Please enter a positive integer for N.")
        sys.exit(1)

    # 2. Generalized Initial State Generation
    initial_state = generate_random_state(n_queens)

    # 3. Run Generalized Hill Climbing
    solution = hill_climbing(initial_state)
