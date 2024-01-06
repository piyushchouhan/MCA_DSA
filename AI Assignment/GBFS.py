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

def GreedyBestFirstSearch(start, goal, heuristic):
    frontier = PriorityQueueFrontier()
    frontier.add(Node(start, heuristic=heuristic(start)))

    explored = set()

    while not frontier.empty():
        node = frontier.remove()
        state = node.state

        if state == goal:
            path = []
            while node.parent is not None:
                path.append(node.action)
                node = node.parent
            path.reverse()
            return path

        explored.add(state)

        for neighbor_state, action in get_neighbors(state):
            if neighbor_state not in explored and not frontier.contains_state(neighbor_state):
                h_cost = heuristic(neighbor_state)  # Heuristic cost
                child_node = Node(neighbor_state, parent=node, action=action, cost=1, heuristic=h_cost)
                frontier.add(child_node)

    return None

# Example usage
def get_neighbors(state):
    if state == "A":
        return [("B", "A -> B"), ("C", "A -> C")]
    elif state == "B":
        return [("D", "B -> D"), ("E", "B -> E")]
    elif state == "C":
        return [("F", "C -> F")]
    elif state == "D":
        return []
    elif state == "E":
        return [("G", "E -> G")]
    elif state == "F":
        return [("G", "F -> G")]
    elif state == "G":
        return []
    else:
        return []

def heuristic(state):
    # This function should estimate the cost from the current state to the goal state
    heuristic_costs = {
        "A": 10,
        "B": 8,
        "C": 7,
        "D": 5,
        "E": 9,
        "F": 4,
        "G": 1
    }
    return heuristic_costs[state]

start_node = "A"
goal_node = "G"
solution = GreedyBestFirstSearch(start_node, goal_node, heuristic)

if solution is None:
    print("No path found")
else:
    print("Solution:", solution)
