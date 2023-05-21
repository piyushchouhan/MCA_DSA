import sys
from queue import Queue

class Node:
    def __init__(self, state, parent=None, action=None):
        self.state = state
        self.parent = parent
        self.action = action

    def __eq__(self, other):
        return self.state == other.state

    def __hash__(self):
        return hash(str(self.state))

    def is_goal(self):
        goal_state = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]
        return self.state == goal_state

    def generate_successors(self):
        successors = []
        zero_row, zero_col = self.find_zero_position()

        # Move the empty space (zero) tile up
        if zero_row > 0:
            successors.append(self.create_successor(zero_row - 1, zero_col, "Up"))

        # Move the empty space (zero) tile down
        if zero_row < 2:
            successors.append(self.create_successor(zero_row + 1, zero_col, "Down"))

        # Move the empty space (zero) tile left
        if zero_col > 0:
            successors.append(self.create_successor(zero_row, zero_col - 1, "Left"))

        # Move the empty space (zero) tile right
        if zero_col < 2:
            successors.append(self.create_successor(zero_row, zero_col + 1, "Right"))

        return successors

    def create_successor(self, new_row, new_col, action):
        successor_state = [list(row) for row in self.state]
        successor_state[new_row][new_col], successor_state[self.zero_row][self.zero_col] = \
            successor_state[self.zero_row][self.zero_col], successor_state[new_row][new_col]
        return Node(successor_state, self, action)

    def find_zero_position(self):
        for i in range(3):
            for j in range(3):
                if self.state[i][j] == 0:
                    self.zero_row, self.zero_col = i, j
                    return i, j

    def path(self):
        path = []
        current_node = self
        while current_node.parent is not None:
            path.append(current_node.action)
            current_node = current_node.parent
        path.reverse()
        return path


def misplaced_tiles_heuristic(state):
    goal_state = [[0,1,2],[3,4,5],[6,7,8]]
    misplaced_tiles = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != goal_state[i][j]:
                misplaced_tiles += 1
    return misplaced_tiles


def solve_puzzle(initial_state):
    initial_node = Node(initial_state)
    frontier = Queue()
    frontier.put(initial_node)
    explored = set()

    while not frontier.empty():
        current_node = frontier.get()

        if current_node.is_goal():
            return current_node.path()

        explored.add(current_node)

        successors = current_node.generate_successors()
        for successor in successors:
            if successor not in explored:
                frontier.put(successor)

    return None


# Example usage
initial_state = [[8,2,4],[1,0,6],[5,7,3]]
solution = solve_puzzle(initial_state)
if solution is not None:
    print("Solution Path:", solution)
else:
    print("No solution found.")
