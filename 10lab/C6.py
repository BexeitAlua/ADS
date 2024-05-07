def min_operations_to_equal(A, B):
    operations = []
    while A != B:
        if B > A and B % 2 == 0:
            A *= 2
            operations.append(A)
        else:
            A -= 1
            operations.append(A)
    return operations


A, B = map(int, input().split())

operations = min_operations_to_equal(A, B)

print(len(operations))
print(*operations)
