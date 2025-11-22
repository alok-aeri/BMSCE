import math

# Evaluate board (simple heuristic)
def evaluate(board):
    win_states = [
        [board[0][0], board[0][1], board[0][2]],  # Row A
        [board[1][0], board[1][1], board[1][2]],  # Row B
        [board[2][0], board[2][1], board[2][2]],  # Row C
        [board[0][0], board[1][0], board[2][0]],  # Col 1
        [board[0][1], board[1][1], board[2][1]],  # Col 2
        [board[0][2], board[1][2], board[2][2]],  # Col 3
        [board[0][0], board[1][1], board[2][2]],  # Diagonal
        [board[0][2], board[1][1], board[2][0]]   # Diagonal
    ]

    for line in win_states:
        if line == ['X', 'X', 'X']:
            return +10
        if line == ['O', 'O', 'O']:
            return -10
    return 0  # draw or unfinished

# Check if any moves are left
def is_moves_left(board):
    for row in board:
        if '_' in row:
            return True
    return False

# Alpha-beta minimax
def minimax(board, depth, alpha, beta, is_max):
    score = evaluate(board)

    if score == 10 or score == -10:
        return score
    if not is_moves_left(board):
        return 0

    if is_max:  # X's move
        best = -math.inf
        for i in range(3):
            for j in range(3):
                if board[i][j] == '_':
                    board[i][j] = 'X'
                    value = minimax(board, depth + 1, alpha, beta, False)
                    board[i][j] = '_'
                    best = max(best, value)
                    alpha = max(alpha, best)
                    if beta <= alpha:
                        return best  # prune
        return best

    else:  # O's move
        best = math.inf
        for i in range(3):
            for j in range(3):
                if board[i][j] == '_':
                    board[i][j] = 'O'
                    value = minimax(board, depth + 1, alpha, beta, True)
                    board[i][j] = '_'
                    best = min(best, value)
                    beta = min(beta, best)
                    if beta <= alpha:
                        return best  # prune
        return best

# Find best move for X
def find_best_move(board):
    best_val = -math.inf
    best_move = (-1, -1)

    for i in range(3):
        for j in range(3):
            if board[i][j] == '_':  # test move
                board[i][j] = 'X'
                move_val = minimax(board, 0, -math.inf, math.inf, False)
                board[i][j] = '_'
                if move_val > best_val:
                    best_move = (i, j)
                    best_val = move_val

    return best_move, best_val

# ------------------- MAIN PROGRAM -------------------

# Take user input
board = []
print("\nEnter current Tic-Tac-Toe board (use X, O, _):")
for row in ['A', 'B', 'C']:
    board.append(list(input(f"Row {row}: ").upper()))

# Show board
print("\nCurrent Board:")
for row in board:
    print(" ".join(row))

# Compute best move
best_move, best_val = find_best_move(board)
print(f"\nBest Move for X: Row {best_move[0]}, Column {best_move[1]}")
print(f"Heuristic Value: {best_val}")
