import random

# Parameters
k = 20         # population size
c = 0.7        # crossover rate (not directly used in this simplified version)
g = 50         # number of generations
m = 0.02       # mutation rate (2%)

gene_length = 5  # length of gene in bits (so a and b range 0-31)

# Binary to integer conversion
def bin_to_int(bin_str):
    return int(bin_str, 2)

# Integer to binary conversion with padding
def int_to_bin(val):
    return format(val, f'0{gene_length}b')

# Fitness function: maximize 3a^2 - b^3
def fitness(a, b):
    return 3 * (a ** 2) - (b ** 3)

# Logical operators for crossover
def logical_or(x, y):
    return x | y

def logical_and(x, y):
    return x & y

def logical_xor(x, y):
    return x ^ y

# Crossover function
def crossover(a, b):
    part1 = logical_and(logical_or(a, b), b)
    part2 = logical_or(logical_and(b, a), a)
    return logical_xor(part1, part2)

# Mutation function: flip a random bit in a or b
def mutate(val):
    bit_to_flip = 1 << random.randint(0, gene_length-1)
    return val ^ bit_to_flip

# Initialize population
population = []
for _ in range(k):
    a = random.randint(0, 2**gene_length - 1)
    b = random.randint(0, 2**gene_length - 1)
    population.append((a, b))

for generation in range(g):
    # Evaluate fitness
    pop_fitness = [(ind, fitness(ind[0], ind[1])) for ind in population]
    pop_fitness.sort(key=lambda x: x[1], reverse=True)  # maximize fitness
    
    # Selection: top 75%
    survivors = pop_fitness[:int(0.75 * k)]
    selected = [ind for ind, fit in survivors]
    
    # Crossover
    offspring = []
    for i in range(0, len(selected)-1, 2):
        a1, b1 = selected[i]
        a2, b2 = selected[i+1]
        
        # Perform crossover on a and b genes
        new_a = crossover(a1, b1)
        new_b = crossover(b2, a2)
        
        offspring.append((new_a, new_b))
    
    # Mutation on first 2% of offspring
    num_mutations = max(1, int(m * len(offspring)))
    for i in range(num_mutations):
        a, b = offspring[i]
        # Randomly choose to mutate a or b
        if random.random() < 0.5:
            a = mutate(a)
        else:
            b = mutate(b)
        offspring[i] = (a, b)
    
    # New population = survivors + offspring (fill population)
    population = selected + offspring
    # If population less than k, fill with random individuals
    while len(population) < k:
        population.append((random.randint(0, 2**gene_length - 1), random.randint(0, 2**gene_length - 1)))

# Final evaluation
pop_fitness = [(ind, fitness(ind[0], ind[1])) for ind in population]
pop_fitness.sort(key=lambda x: x[1], reverse=True)
best_individual, best_fit = pop_fitness[0]

print(f"Best individual: a={best_individual[0]}, b={best_individual[1]}")
print(f"Best fitness (maximized): {best_fit}")
print(f"Function value f(a,b) = 3a^2 - b^3 = {3*(best_individual[0]**2) - (best_individual[1]**3)}")
