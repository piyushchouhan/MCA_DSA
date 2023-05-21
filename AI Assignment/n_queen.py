def is_safe(board, row, col, n):
    # Check the current row on the left side
    for i in range(col):
        if board[row][i] == 'Q':
            return False

    # Check upper diagonal on the left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 'Q':
            return False

    # Check lower diagonal on the left side
    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 'Q':
            return False

    return True


def solve_n_queens_util(board, col, n):
    if col >= n:
        return True

    for i in range(n):
        if is_safe(board, i, col, n):
            board[i][col] = 'Q'

            if solve_n_queens_util(board, col + 1, n):
                return True

            board[i][col] = 0

    return False


def solve_n_queens(n):
    board = [[0 for _ in range(n)] for _ in range(n)]

    if not solve_n_queens_util(board, 0, n):
        print("Solution does not exist.")
        return None

    return board


def print_solution(board):
    if board is None:
        return

    for row in board:
        print(" ".join(str(cell) for cell in row))


if __name__ == "__main__":
    n = int(input("Tell the no. of Queen: "))
    solution = solve_n_queens(n)
    print_solution(solution)