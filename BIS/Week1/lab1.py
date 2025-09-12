import random
import math

# Parameters
k = 20         # population size
c = 0.7        # crossover rate (not directly used)
g = 100        # max generations
m = 0.05       # mutation rate (5%)

gene_length = 5  # bits for a and b (0 to 31)

def bin_to_int(bin_str):
    return int(bin_str, 2)

def int_to_bin(val):
    return format(val, f'0{gene_length}b')

# Fitness function (to minimize)
def fitness(a, b):
    val = b**2 - 2*a
    return math.sqrt(val) if val >= 0 else float('inf')

# Logical operators
def logical_or(x, y):
    return x | y

def logical_and(x, y):
    return x & y

def logical_xor(x, y):
    return x ^ y

# Crossover function
def crossover(a, b):
    return logical_xor(a, b) + logical_and(b, a)

# Mutation: flip a random bit in a or b
def mutate(val):
    bit_to_flip = 1 << random.randint(0, gene_length - 1)
    return val ^ bit_to_flip

# Initialize population with random genes
population = [(random.randint(0, 2**gene_length - 1), random.randint(0, 2**gene_length - 1)) for _ in range(k)]

for generation in range(g):
    # Evaluate fitness for all individuals
    pop_fitness = [(ind, fitness(ind[0], ind[1])) for ind in population]
    pop_fitness.sort(key=lambda x: x[1])  # minimize fitness
    
    # Check convergence
    best_individual, best_fit = pop_fitness[0]
    if best_fit <= 5:
        print(f"Converged at generation {generation}")
        break
    
    # Selection: top 50%
    survivors = pop_fitness[:int(0.5 * k)]
    selected = [ind for ind, fit in survivors]
    
    # Crossover: pair up selected individuals
    offspring = []
    for i in range(0, len(selected) - 1, 2):
        a1, b1 = selected[i]
        a2, b2 = selected[i + 1]
        
        new_a = crossover(a1, b1) % (2**gene_length)  # ensure gene length bounds
        new_b = crossover(b2, a2) % (2**gene_length)
        
        offspring.append((new_a, new_b))
    
    # Mutation: first 5% of offspring
    num_mutations = max(1, int(m * len(offspring)))
    for i in range(num_mutations):
        a, b = offspring[i]
        if random.random() < 0.5:
            a = mutate(a)
        else:
            b = mutate(b)
        offspring[i] = (a, b)
    
    # New population = survivors + offspring
    population = selected + offspring
    
    # Fill population if less than k
    while len(population) < k:
        population.append((random.randint(0, 2**gene_length - 1), random.randint(0, 2**gene_length - 1)))

# Final result
best_individual, best_fit = min([(ind, fitness(ind[0], ind[1])) for ind in population], key=lambda x: x[1])
print(f"Best individual: a={best_individual[0]}, b={best_individual[1]}")
print(f"Minimum fitness value: {best_fit}")
print(f"Function value = sqrt(b^2 - 2a) = {math.sqrt(best_individual[1]**2 - 2*best_individual[0]) if best_individual[1]**2 - 2*best_individual[0] >= 0 else 'undefined'}")
