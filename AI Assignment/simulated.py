import random
import math

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

def simulated_annealing(n, initial_temperature, cooling_factor, iteration_limit):
    current_board = random_board(n)
    current_conflicts = conflicts(current_board)

    temperature = initial_temperature

    for iteration in range(iteration_limit):
        if current_conflicts == 0:
            break

        new_board = current_board.copy()
        col = random.randint(0, n - 1)
        new_board[col] = random.randint(0, n - 1)
        new_conflicts = conflicts(new_board)

        delta_conflicts = new_conflicts - current_conflicts

        if delta_conflicts < 0 or random.random() < math.exp(-delta_conflicts / temperature):
            current_board = new_board
            current_conflicts = new_conflicts

        temperature *= cooling_factor

    return current_board

def print_solution(board):
    n = len(board)
    for row in board:
        print("".join("Q" if col == row else "." for col in range(n)))

if __name__ == "__main__":
    n = int(input("Tell the no. of Queen: "))
    initial_temperature = 100
    cooling_factor = 0.99
    iteration_limit = 10000

    solution = simulated_annealing(n, initial_temperature, cooling_factor, iteration_limit)
    print_solution(solution)