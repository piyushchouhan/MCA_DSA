import sys
import heapq

class Node():
    def __init__(self, state, parent=None, action=None, cost=0, heuristic=0):
        self.state = state
        self.parent = parent
        self.action = action
        self.cost = cost
        self.heuristic = heuristic

    def total_cost(self):
        return self.cost + self.heuristic

class PriorityQueueFrontier():
    def __init__(self):
        self.frontier = []
        self.counter = 0

    def add(self, node):
        heapq.heappush(self.frontier, (node.total_cost(), self.counter, node))
        self.counter += 1

    def contains_state(self, state):
        return any(node.state == state for _, _, node in self.frontier)

    def empty(self):
        return len(self.frontier) == 0

    def remove(self):
        if self.empty():
            raise Exception("Empty frontier")
        else:
            _, _, node = heapq.heappop(self.frontier)
            return node

def a_star(start_state, goal_state, get_neighbors, heuristic):
    start_node = Node(start_state, cost=0, heuristic=heuristic(start_state, goal_state))
    frontier = PriorityQueueFrontier()
    frontier.add(start_node)
    explored = set()

    while not frontier.empty():
        current_node = frontier.remove()

        if current_node.state == goal_state:
            actions = []
            while current_node.parent is not None:
                actions.append(current_node.action)
                current_node = current_node.parent
            actions.reverse()
            return actions

        explored.add(current_node.state)

        for neighbor, action, cost in get_neighbors(current_node.state):
            if neighbor not in explored and not frontier.contains_state(neighbor):
                new_cost = current_node.cost + cost
                new_heuristic = heuristic(neighbor, goal_state)
                new_node = Node(neighbor, current_node, action, new_cost, new_heuristic)
                frontier.add(new_node)

    return None  # No solution found
# Example usage
# Define the graph and heuristic function
graph = {
    'A': ['B', 'C'],
    'B': ['D'],
    'C': ['E'],
    'D': [],
    'E': ['F'],
    'F': ['G'],
    'G': []
}

def get_neighbors(state):
    return [(neighbor, neighbor, 1) for neighbor in graph.get(state, [])]

def heuristic(state, goal_state):
    # Example heuristic: Manhattan distance between states
    return abs(ord(state) - ord(goal_state))

# Run A* search
start_state = 'A'
goal_state = 'G'
actions = a_star(start_state, goal_state, get_neighbors, heuristic)
print(actions)