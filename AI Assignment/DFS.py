import sys

class Node():
    def __init__(self, state, parent=None, action=None):
        self.state = state
        self.parent = parent
        self.action = action

class QueueFrontier():
    def __init__(self):
        self.frontier = []

    def add(self, node):
        self.frontier.append(node)

    def contains_state(self, state):
        return any(node.state == state for node in self.frontier)

    def empty(self):
        return len(self.frontier) == 0

    def remove(self):
        if self.empty():
            raise Exception("Empty frontier")
        else:
            node = self.frontier.pop(0)
            return node

def DFS(start, goal):
    frontier = QueueFrontier()
    frontier.add(Node(start))

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

        for neighbor_state in get_neighbors(state):
            if neighbor_state not in explored and not frontier.contains_state(neighbor_state):
                child_node = Node(neighbor_state, parent=node, action=get_action(state, neighbor_state))
                frontier.add(child_node)

    return None

# Example usage
def get_neighbors(state):
    if state == "A":
        return ["B", "C"]
    elif state == "B":
        return ["D", "E"]
    elif state == "C":
        return ["F"]
    elif state == "D":
        return []
    elif state == "E":
        return ["G"]
    elif state == "F":
        return ["G"]
    elif state == "G":
        return []
    else:
        return []

def get_action(state, neighbor_state):
    return f"{state} -> {neighbor_state}"

start_node = "A"
goal_node = "G"
solution = DFS(start_node, goal_node)

if solution is None:
    print("No path found")
else:
    print("Solution:", solution)
