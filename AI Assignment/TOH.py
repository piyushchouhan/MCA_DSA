def TowerOfHanoi(n, source, destination, temp):
    if n == 1:
        print(f"Move disk 1 from {source} to {destination}")
        return
    TowerOfHanoi(n-1, source, temp, destination)
    print(f"Move disk {n} from {source} to {destination}")
    TowerOfHanoi(n-1, temp, destination, source)

# Example usage
TowerOfHanoi(3, 'A', 'C', 'B')
