from collections import deque

def bfs(capacity_a, capacity_b, target):
    visited = set()
    queue = deque([((0, 0), [])])

    while queue:
        (jug_a, jug_b), steps = queue.popleft()

        if (jug_a, jug_b) in visited:
            continue
        visited.add((jug_a, jug_b))

        if jug_a == target or jug_b == target:
            return steps

        # Fill jug A
        if jug_a < capacity_a:
            queue.append(((capacity_a, jug_b), steps + ["Fill A"]))

        # Fill jug B
        if jug_b < capacity_b:
            queue.append(((jug_a, capacity_b), steps + ["Fill B"]))

        # Empty jug A
        if jug_a > 0:
            queue.append(((0, jug_b), steps + ["Empty A"]))

        # Empty jug B
        if jug_b > 0:
            queue.append(((jug_a, 0), steps + ["Empty B"]))

        # Pour from jug A to jug B
        if jug_a > 0 and jug_b < capacity_b:
            pour = min(jug_a, capacity_b - jug_b)
            queue.append(((jug_a - pour, jug_b + pour), steps + ["Pour A to B"]))

        # Pour from jug B to jug A
        if jug_b > 0 and jug_a < capacity_a:
            pour = min(jug_b, capacity_a - jug_a)
            queue.append(((jug_a + pour, jug_b - pour), steps + ["Pour B to A"]))

    return None

capacity_a = 4
capacity_b = 3
target = 2
steps = bfs(capacity_a, capacity_b, target)

if steps:
    print("Solution found:")
    for step in steps:
        print(step)
else:
    print("No solution found.")
