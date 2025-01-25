import random

def generate_test_cases():
    test_cases = []

    # Medium-sized cases
    test_cases.append([random.randint(0, 1000) for _ in range(1000)])  # Random numbers, 1000 elements
 
    return test_cases

# Generate and save test cases to a file
test_cases = generate_test_cases()
with open("test_cases.txt", "w") as f:
    for case in test_cases:
        f.write(",".join(map(str, case)) + "\n")

