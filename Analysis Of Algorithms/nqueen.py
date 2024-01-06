# nqueen
def solve_n_queens(n):
    def is_safe(board, row, col):
        # Check if a queen can be placed at the given position
        for i in range(row):
            # Check if there is a queen in the same column or diagonal
            if board[i] == col or board[i] - col == i - row or board[i] - col == row - i:
                return False
        return True
    
    def place_queen(board, row):
        if row == n:
            # All queens have been successfully placed, print the solution
            print(board)
        else:
            for col in range(n):
                if is_safe(board, row, col):
                    # Place the queen and move to the next row
                    board[row] = col
                    place_queen(board, row + 1)

    # Create an empty chessboard
    board = [0] * n
    place_queen(board, 0)

# Example usage
solve_n_queens(4)  # Solve the 4-Queen problem
