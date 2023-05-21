import random

def random_board(n):
    return [random.randint(0, n - 1) for _ in range(n)]

def conflicts(board):
    n = len(board)
    conflicts = 0

    for i in range(n):
        for j in range(i + 1, n):
            if board[i] == board[j]:
                conflicts += 1
            if abs(board[i] - board[j]) == abs(i - j):
                conflicts += 1

    return conflicts

def hill_climbing(n, iteration_limit):
    current_board = random_board(n)
    current_conflicts = conflicts(current_board)

    for _ in range(iteration_limit):
        if current_conflicts == 0:
            break

        best_board = current_board
        best_conflicts = current_conflicts

        for col in range(n):
            original_row = current_board[col]
            for row in range(n):
                if row == original_row:
                    continue

                current_board[col] = row
                new_conflicts = conflicts(current_board)

                if new_conflicts < best_conflicts:
                    best_board = current_board.copy()
                    best_conflicts = new_conflicts

            current_board[col] = original_row

        if best_conflicts < current_conflicts:
            current_board = best_board
            current_conflicts = best_conflicts
        else:
            break

    return current_board

def print_solution(board):
    n = len(board)
    for row in board:
        print("".join("Q" if col == row else "." for col in range(n)))

if __name__ == "__main__":
    n = int(input("Tell the no. of Queen: "))
    iteration_limit = 1000

    solution = hill_climbing(n, iteration_limit)
    print_solution(solution)