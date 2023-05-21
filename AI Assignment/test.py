import heapq

class Node:
    def __init__(self, state, parent=None, action=None, g=0, h=0):
        self.state = state
        self.parent = parent
        self.action = action
        self.g = g  # cost from the start node
        self.h = h  # heuristic estimate to the goal node
        self.f = g + h  # total estimated cost

    def __lt__(self, other):
        return self.f < other.f

def heuristic(state, goal):
    # Heuristic: Count the number of misplaced tiles
    misplaced = sum(s != g for s, g in zip(state, goal))
    return misplaced

def generate_neighbors(state):
    # Generate neighboring states for the 8-puzzle problem
    neighbors = []
    i = state.index(0)  # find the position of the empty tile (represented as 0)

    # Move the empty tile (0) to the left
    if i % 3 > 0:
        neighbor = list(state)
        neighbor[i], neighbor[i - 1] = neighbor[i - 1], neighbor[i]
        neighbors.append(tuple(neighbor))

    # Move the empty tile (0) to the right
    if i % 3 < 2:
        neighbor = list(state)
        neighbor[i], neighbor[i + 1] = neighbor[i + 1], neighbor[i]
        neighbors.append(tuple(neighbor))

    # Move the empty tile (0) up
    if i // 3 > 0:
        neighbor = list(state)
        neighbor[i], neighbor[i - 3] = neighbor[i - 3], neighbor[i]
        neighbors.append(tuple(neighbor))

    # Move the empty tile (0) down
    if i // 3 < 2:
        neighbor = list(state)
        neighbor[i], neighbor[i + 3] = neighbor[i + 3], neighbor[i]
        neighbors.append(tuple(neighbor))

    return neighbors

def astar(start, goal):
    start_node = Node(start, g=0, h=heuristic(start, goal))
    frontier = [start_node]
    heapq.heapify(frontier)
    explored = set()

    while frontier:
        current_node = heapq.heappop(frontier)

        if current_node.state == goal:
            return get_path(current_node)

        explored.add(current_node.state)

        for neighbor_state in generate_neighbors(current_node.state):
            if neighbor_state not in explored:
                neighbor_node = Node(neighbor_state, parent=current_node, g=current_node.g + 1, h=heuristic(neighbor_state, goal))
                heapq.heappush(frontier, neighbor_node)

    return None

def get_path(node):
    path = []
    while node is not None:
        path.append(node.state)
        node = node.parent
    path.reverse()
    return path

# Example usage
start_state = (1, 2, 3, 4, 5, 6, 0, 7, 8)
goal_state = (1, 2, 3, 4, 5, 6, 7, 8, 0)

path = astar(start_state, goal_state)
for state in path:
    print(state)